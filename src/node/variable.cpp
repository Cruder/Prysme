#include "variable.hpp"
#include "primitive.hpp"

namespace Pry {
    namespace node {
        Variable::Variable() :
            Node() {
        }

        Variable::Variable(std::string name, variable::Table* t) :
            Node(),
            name { name },
            table(t) {
        }

        Node* Variable::exec() {
            auto node = new Primitive(table->find(name)->value);
            node->add_children(this);
            return node;
        }
    }
}
