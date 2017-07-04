#ifndef __FUNCTION_ROW_HPP__
#define __FUNCTION_ROW_HPP__

#include <map>
#include <memory>
#include "function.hpp"

namespace Pry {
    namespace function {
        class Row {
        public:
            Row();

            Function* find(std::string name);
            void      define(std::string name, std::unique_ptr<Function> function);

            bool      is_exist(std::string name);

            std::string as_string() const;
            friend std::ostream& operator<<(std::ostream& os, const Row& v);
        private:
            std::map<std::string, std::unique_ptr<Function>> functions;
        };
    }
}

#endif /* end of include guard: __FUNCTION_ROW_HPP__ */
