#ifndef __VARIABLE_VARIABLE_HPP__
#define __VARIABLE_VARIABLE_HPP__

#include <string>

namespace pry {
    namespace variable {
        class Variable {
        public:
            Variable(std::string value, std::string type, bool is_constant = false);
            void update(const std::string& _value);
            std::string as_string() const;
            friend std::ostream& operator<<(std::ostream& os, const Variable& v);
        private:
            std::string value;
            std::string type;
            bool        is_constant;
        };
    }
}

#endif /* end of include guard: __VARIABLE_VARIABLE_HPP__ */
