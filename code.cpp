#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string line;
    while (std::getline(std::cin, line)) {
        std::cout << line << std::endl;
    }
    return 0;
}
