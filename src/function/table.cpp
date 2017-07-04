#include "not_found_exception.hpp"
#include "table.hpp"

namespace Pry {
    namespace function {
        Table::Table() : function_stack() {
            increment_depth();
        }

        void Table::increment_depth() {

            function_stack.push_back(std::make_unique<Row>());
        }

        void Table::decrement_depth() {
            if(function_stack.size() == 1) { return; }

            function_stack.pop_back();
        }

        Function* Table::find(std::string name) {
            for(auto& row : function_stack) {
                if(row->is_exist(name)) {
                    return row->find(name);
                }
            }

            throw NotFoundException(name);
        }

        void Table::define(std::string name, std::unique_ptr<Function> function) {
            function_stack.back()->define(name, std::move(function));
        }

        std::string Table::as_string() const {
            std::string t = "Table [\n";
            for(auto& row : function_stack) { t += '\t' + row->as_string() + '\n'; }
            t += "]";

            return t;
        }

        std::ostream& operator<<(std::ostream& os, const Table& v) {
            os << v.as_string();
            return os;
        }
    }
}
