#include "function.hpp"

namespace Pry {
    namespace function {
        Function::Function(node::Node* node) : node { node } {
        }

        node::Node* Function::exec() {
            return node->exec();
        }

        std::string Function::as_string() const {
            return "Function []";
        }

        std::ostream& operator<<(std::ostream& os, const Function& v) {
            os << v.as_string();
            return os;
        }
    }
}
