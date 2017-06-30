#include <iostream>
#include "pry_driver.hpp"

int main(int argc, char* argv[]) {
    if(argc != 2) {
        return -1;
    }

    auto driver = Pry::Driver();
    try {
        driver.parse(std::string(argv[1]));
    } catch(const std::exception& ex) {
        std::cerr << "An error has occured: (" << ex.what() << ")" << std::endl;
        return -2;
    }

    return 0;
}
