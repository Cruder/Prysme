#include "variable.hpp"

namespace Pry {
    namespace variable {
        Variable::Variable(std::string value, std::string type, bool is_constant) :
            value { value },
            type { type },
            is_constant { is_constant } {
        }

        void Variable::update(const std::string& _value) {
            value = _value;
        }

        std::string Variable::as_string() const {
            return value + " | " + type + " | is const? " + (is_constant ? "true" : "false");
        }

        std::ostream& operator<<(std::ostream& os, const Variable& v) {
            os << v.as_string();
            return os;
        }
    }
}
