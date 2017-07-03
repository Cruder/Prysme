#ifndef __VARIABLE_VARIABLE_HPP__
#define __VARIABLE_VARIABLE_HPP__

#include <string>
#include <variant>
#include "primitive_type.hpp"

namespace Pry {
    namespace variable {
        class Variable {
        public:
            PrimitiveType value;
        public:
            Variable(const PrimitiveType& value, bool is_constant = false);
            void update(const std::string& _value);

            std::string as_string() const;
            friend std::ostream& operator<<(std::ostream& os, const Variable& v);
        private:
            bool is_constant;
        };
    }
}

#endif /* end of include guard: __VARIABLE_VARIABLE_HPP__ */
