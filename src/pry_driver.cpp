#include "pry_driver.hpp"

Pry::Driver::Driver(const &std::string filename) {
    std::ifstream in_file(filename);

    if(!in_file.good()) { exit(EXIT_FAILURE); }

    scanner = make_unique<Pry::Scanner>(in_file);
    parser = make_unique<Pry::Parser>(parser.get(), *this);
}

void Pry::Driver::parse(const &std::string filename) {
    if(parser->parse() != 0) {
        std::cerr << "Parse failed" << std::endl;
    }
}
