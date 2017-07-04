#ifndef __FUNCTION_TABLE_HPP__
#define __FUNCTION_TABLE_HPP__

#include <vector>
#include "row.hpp"

namespace Pry {
    namespace function {
        class Table {
        public:
            Table();

            void increment_depth();
            void decrement_depth();

            Function* find(std::string name);
            void      define(std::string name, std::unique_ptr<Function> function);

            std::string as_string() const;
            friend std::ostream& operator<<(std::ostream& os, const Table& v);
        private:
            std::vector<std::unique_ptr<Row>> function_stack;
        };
    }
}

#endif /* end of include guard: __FUNCTION_TABLE_HPP__ */
