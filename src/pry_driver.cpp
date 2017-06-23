#include <fstream>
#include <stdlib.h>
#include "pry_driver.hpp"

Pry::Driver::Driver() {
}

void Pry::Driver::parse(const std::string& filename) {
    std::ifstream in_file(filename);

    if(!in_file.good()) { exit(-1); }

    scanner = new Pry::Scanner(&in_file, nullptr);
    parser = new Pry::Parser(*scanner, *this);

    if(parser->parse() != 0) {
        std::cerr << "Parse failed" << std::endl;
    }
}
