#ifndef __VARIABLE_TABLE_HPP__
#define __VARIABLE_TABLE_HPP__

#include <vector>
#include "row.hpp"

namespace Pry {
    namespace variable {
        class Table {
        public:
            Table();

            void increment_depth();
            void decrement_depth();

            Variable* find(std::string name);
            void      define(std::string name, std::unique_ptr<Variable> variable);

            std::string as_string() const;
            friend std::ostream& operator<<(std::ostream& os, const Table& v);
        private:
            std::vector<std::unique_ptr<Row>> variable_stack;
        };
    }
}

#endif /* end of include guard: __VARIABLE_TABLE_HPP__ */
