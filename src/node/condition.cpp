#include "condition.hpp"
#include <iostream>

namespace Pry {
    namespace node {
        Condition::Condition() :
            Node() {
        }

        Condition::Condition(Node* cond, Node* child1, Node* child2) :
            Node() {
            add_children(cond);
            if(child1) { add_children(child1); }
            if(child2) { add_children(child2); }
        }

        Node* Condition::exec() {
            children[0]->exec();
            std::cout << "cond -> " << std::get<int>(children[0]->value) << std::endl;
            if(std::get<int>(children[0]->value) == 0) {
                if(children.size() > 1) { value = children[1]->exec()->value; }
            } else {
                if(children.size() > 2) { value = children[2]->exec()->value; }
            }

            return this;
        }
    }
}
