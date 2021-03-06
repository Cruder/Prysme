#include <fstream>
#include <stdlib.h>
#include "pry_driver.hpp"

namespace Pry {
    Driver::Driver() :
        variables(std::make_unique<variable::Table>()),
        functions(std::make_unique<function::Table>()),
        scope(std::make_unique<tree::Scope>(&node_list)) {
    }

    void Driver::parse(const std::string& filename) {
        std::ifstream in_file(filename);

        if(!in_file.good()) { exit(-1); }

        scanner = new Scanner(&in_file, nullptr);
        parser = new Parser(*scanner, *this);

        if(parser->parse() != 0) {
            std::cerr << "Parse failed" << std::endl;
        }

        if(tree_view) { std::cout << node_list << std::endl; }
        node_list.exec();
    }
}
