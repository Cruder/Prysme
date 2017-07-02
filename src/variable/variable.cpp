#include "variable.hpp"

struct primitive_type_value_to_string {
    inline std::string operator()(int arg) { return std::to_string(arg); }
    inline std::string operator()(char arg) { return std::to_string(arg); }
    inline std::string operator()(double arg) { return std::to_string(arg); }
    inline std::string operator()(std::string arg) { return arg; }
};

struct primitive_type_type_to_string {
    inline std::string operator()(int arg) { return "Integer"; }
    inline std::string operator()(char arg) { return "Character"; }
    inline std::string operator()(double arg) { return "Decimal"; }
    inline std::string operator()(std::string arg) { return "String"; }
};

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
            std::string val = std::visit(primitive_type_value_to_string{}, value);
            std::string type = std::visit(primitive_type_type_to_string{}, value);
            return "Variable [value -> " + val +
                ", type -> " + type +
                ", is constant? " +  (is_constant ? "true" : "false") + "]";
        }

        std::ostream& operator<<(std::ostream& os, const Variable& v) {
            os << v.as_string();
            return os;
        }
    }
}
