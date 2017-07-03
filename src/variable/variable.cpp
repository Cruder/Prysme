#include "variable.hpp"

namespace Pry {
    namespace variable {
        Variable::Variable(const PrimitiveType& value, bool is_constant) :
            value { value },
            is_constant { is_constant } {
        }

        void Variable::update(const std::string& _value) {
            value = _value;
        }

        std::string Variable::as_string() const {
            return "Variable [value -> " + primitive_type::as_string(value) +
                ", type -> " + primitive_type::class_string(value) +
                ", is constant? " +  (is_constant ? "true" : "false") + "]";
        }

        std::ostream& operator<<(std::ostream& os, const Variable& v) {
            os << v.as_string();
            return os;
        }
    }
}
