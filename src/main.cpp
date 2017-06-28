#include <iostream>

#include "pry_driver.hpp"

int main(int argc, char* argv[]) {
    if(argc != 2) {
        return -1;
    }

    auto driver = Pry::Driver();
    driver.parse(std::string(argv[1]));

    return 0;
}
