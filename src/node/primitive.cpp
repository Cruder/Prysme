#include "primitive.hpp"

namespace Pry {
    namespace node {
        Primitive::Primitive() :
            Node() {
        }

        Primitive::Primitive(const Pry::variable::PrimitiveType& type) :
            Node(type) {
        }

        Node* Primitive::exec() {
            return this;
        }

        std::string Primitive::type_string() const { return "Primitive"; }
    }
}
