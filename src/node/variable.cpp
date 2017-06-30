#include "variable.hpp"

namespace Pry {
    namespace node {
        Variable::Variable() :
            Node() {
        }

        Variable::Variable(variable::Variable* v) :
            Node(),
            variable(v) {
        }

        Node* Variable::exec() {
            return this;
        }
    }
}
