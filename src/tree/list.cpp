#include "list.hpp"
#include <iostream>

namespace Pry {
    namespace tree {
        List::List() : nodes {} {
        }

        List::~List() {
            for(auto& node : nodes) {
                delete node;
            }
        }

        void List::add_node(node::Node* node) {
            nodes.push_back(node);
        }

        variable::PrimitiveType List::exec() {
            node::Node* ret;
            for(auto& node : nodes) {
                ret = node->exec();
            }
            return ret->value;
        }
    }
}
