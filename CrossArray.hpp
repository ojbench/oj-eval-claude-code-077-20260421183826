#ifndef CROSSARRAY_HPP
#define CROSSARRAY_HPP

namespace sjtu {
    class CrossArray {
    private:
        int **data;
        int *row_sizes;
        int max_lines;
        int current_lines;

        void clear() {
            if (data) {
                for (int i = 0; i < current_lines; ++i) {
                    if (data[i]) {
                        delete[] data[i];
                    }
                }
                delete[] data;
            }
            if (row_sizes) {
                delete[] row_sizes;
            }
        }

        void copyFrom(const CrossArray &o) {
            max_lines = o.max_lines;
            current_lines = o.current_lines;
            data = new int*[max_lines];
            row_sizes = new int[max_lines];
            for (int i = 0; i < max_lines; ++i) {
                if (i < current_lines && o.data[i]) {
                    row_sizes[i] = o.row_sizes[i];
                    data[i] = new int[row_sizes[i]];
                    for (int j = 0; j < row_sizes[i]; ++j) {
                        data[i][j] = o.data[i][j];
                    }
                } else {
                    data[i] = nullptr;
                    row_sizes[i] = 0;
                }
            }
        }

    public:
        explicit CrossArray(int lines) : max_lines(lines), current_lines(0) {
            data = new int*[max_lines];
            row_sizes = new int[max_lines];
            for (int i = 0; i < max_lines; ++i) {
                data[i] = nullptr;
                row_sizes[i] = 0;
            }
        }

        CrossArray(const CrossArray &o) {
            copyFrom(o);
        }

        CrossArray &operator=(const CrossArray &o) {
            if (this != &o) {
                clear();
                copyFrom(o);
            }
            return *this;
        }

        CrossArray &WhichGreater(CrossArray &o) {
            long long count1 = 0;
            for (int i = 0; i < current_lines; ++i) {
                count1 += row_sizes[i];
            }
            long long count2 = 0;
            for (int i = 0; i < o.current_lines; ++i) {
                count2 += o.row_sizes[i];
            }
            if (count2 > count1) {
                return o;
            } else {
                return *this;
            }
        }

        bool IsSame(const CrossArray &o) {
            return this == &o;
        }

        bool InsertArrays(const int *Input, int size) {
            if (current_lines >= max_lines) {
                return false;
            }
            data[current_lines] = new int[size];
            row_sizes[current_lines] = size;
            for (int j = 0; j < size; ++j) {
                data[current_lines][j] = Input[j];
            }
            current_lines++;
            return true;
        }

        void AppendArrays(const int *Input, int Line, int size) {
            if (Line < 0 || Line >= current_lines || data[Line] == nullptr) {
                return;
            }
            int new_size = row_sizes[Line] + size;
            int *new_row = new int[new_size];
            for (int j = 0; j < row_sizes[Line]; ++j) {
                new_row[j] = data[Line][j];
            }
            for (int j = 0; j < size; ++j) {
                new_row[row_sizes[Line] + j] = Input[j];
            }
            delete[] data[Line];
            data[Line] = new_row;
            row_sizes[Line] = new_size;
        }

        void DoubleCrossLength() {
            int new_max_lines = max_lines * 2;
            int **new_data = new int*[new_max_lines];
            int *new_row_sizes = new int[new_max_lines];
            for (int i = 0; i < new_max_lines; ++i) {
                if (i < max_lines) {
                    new_data[i] = data[i];
                    new_row_sizes[i] = row_sizes[i];
                } else {
                    new_data[i] = nullptr;
                    new_row_sizes[i] = 0;
                }
            }
            delete[] data;
            delete[] row_sizes;
            data = new_data;
            row_sizes = new_row_sizes;
            max_lines = new_max_lines;
        }

        const int *AtArray(int i) {
            if (i < 0 || i >= max_lines) {
                return nullptr;
            }
            return data[i];
        }

        int &At(int i, int j) {
            return data[i][j];
        }

        ~CrossArray() {
            clear();
        }
    };
}

#endif
