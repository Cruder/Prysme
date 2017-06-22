#include <fstream>
#include "pry_driver.hpp"

Pry::Driver::Driver() {
}

void Pry::Driver::parse(const std::string& filename) {
    std::ifstream in_file(filename);

    if(!in_file.good()) { exit(EXIT_FAILURE); }

    scanner = std::make_unique<Pry::Scanner>(in_file);
    parser = std::make_unique<Pry::Parser>(*this, parser.get());

    if(parser->parse() != 0) {
        std::cerr << "Parse failed" << std::endl;
    }
}
