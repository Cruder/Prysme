#include <iostream>
#include "display_variable.hpp"

namespace Pry {
    namespace node {
        DisplayVariable::DisplayVariable() :
            Node() {
        }

        DisplayVariable::DisplayVariable(const std::string& name, variable::Table* table) :
            Node(),
            name { name },
            table { table } {
        }

        Node* DisplayVariable::exec() {
            std::cout << name << " -> " << *table->find(name) << std::endl;
            return this;
        }

        std::string DisplayVariable::type_string() const { return "DisplayVariable"; }
    }
}
