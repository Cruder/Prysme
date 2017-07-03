#include <string>
#include "primitive_type.hpp"

struct primitive_type_value_to_string {
    inline std::string operator()(int arg) { return std::to_string(arg); }
    inline std::string operator()(char arg) { return std::to_string(arg); }
    inline std::string operator()(double arg) { return std::to_string(arg); }
    inline std::string operator()(std::string arg) { return arg; }
    inline std::string operator()(bool arg) { return arg ? "true" : "false"; }
};

struct primitive_type_type_to_string {
    inline std::string operator()(int arg) { return "Integer"; }
    inline std::string operator()(char arg) { return "Character"; }
    inline std::string operator()(double arg) { return "Decimal"; }
    inline std::string operator()(std::string arg) { return "String"; }
    inline std::string operator()(bool arg) { return "Boolean"; }
};

namespace Pry {
    namespace variable {
        namespace primitive_type {
            std::string as_string(const PrimitiveType& type) {
                return std::visit(primitive_type_value_to_string{}, type);
            }

            std::string class_string(const PrimitiveType& type) {
                return std::visit(primitive_type_type_to_string{}, type);
            }
        }
    }
}
