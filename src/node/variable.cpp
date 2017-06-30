#include "variable.hpp"

namespace Pry {
    namespace node {
        Variable::Variable(variable::Variable* v) :
            Node(),
            variable(v) {
        }

        Node* Variable::exec() {
            return dynamic_cast<Node*>(this);
        }
    }
}
