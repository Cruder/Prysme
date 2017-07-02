#ifndef __VARIABLE_VARIABLE_HPP__
#define __VARIABLE_VARIABLE_HPP__

#include <string>
#include <variant>

namespace Pry {
    namespace variable {
        using PrimitiveType = std::variant<int, double, std::string, char>;

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
