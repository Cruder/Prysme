#include "not_found_exception.hpp"
#include "table.hpp"

namespace pry {
    namespace variable {
        Table::Table() : variable_stack() {
            incrementDepth();
        }

        void Table::incrementDepth() {

            variable_stack.push_back(std::make_unique<Row>());
        }

        void Table::decrementDepth() {
            if(variable_stack.size() == 1) { return; }

            variable_stack.pop_back();
        }

        Variable* Table::find(std::string name) {
            for(auto& row : variable_stack) {
                if(row->is_exist(name)) {
                    return row->find(name);
                }
            }

            throw NotFoundException(name);
        }

        void Table::define(std::string name, std::unique_ptr<Variable> variable) {
            variable_stack.back()->define(name, std::move(variable));
        }
    }
}
