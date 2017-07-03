#ifndef __VARIABLE_PRIMITIVE_TYPE_HPP__
#define __VARIABLE_PRIMITIVE_TYPE_HPP__

#include <variant>

namespace Pry {
    namespace variable {
        using PrimitiveType = std::variant<int, bool, double, std::string, char>;
        namespace primitive_type {
            std::string as_string(const PrimitiveType& type);
            std::string class_string(const PrimitiveType& type);
        }
    }
}

#endif /* end of include guard: __VARIABLE_PRIMITIVE_TYPE_HPP__ */
