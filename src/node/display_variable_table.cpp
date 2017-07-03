#include <iostream>
#include "display_variable_table.hpp"

namespace Pry {
    namespace node {
        DisplayVariableTable::DisplayVariableTable() :
            Node() {
        }

        DisplayVariableTable::DisplayVariableTable(variable::Table* table) :
            Node(),
            table { table } {
        }

        Node* DisplayVariableTable::exec() {
            std::cout << *table << std::endl;
            return this;
        }

        std::string DisplayVariableTable::type_string() const { return "DisplayVariableTable"; }
    }
}
