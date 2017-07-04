#include "while.hpp"

namespace Pry {
    namespace node {
        While::While() :
            Node() {
        }

        While::While(Node* cond, Node* child) :
            Node() {
            add_children(cond);
            add_children(child);
        }

        Node* While::exec() {
            while(std::get<bool>(children[0]->exec()->value)) {
                value = children[1]->exec()->value;
            }

            return this;
        }

        std::string While::type_string() const { return "While"; }
    }
}
