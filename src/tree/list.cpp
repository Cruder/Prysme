#include "list.hpp"
#include <iostream>

namespace Pry {
    namespace tree {
        List::List() : nodes {} {
        }

        List::~List() {
            std::cout << "should be at the end " << std::endl;
            for(auto& node : nodes) {
                delete node;
            }
        }

        void List::add_node(node::Node* node) {
            nodes.push_back(node);
        }

        void List::exec() {
            for(auto& node : nodes) {
                node->exec();
            }
        }
    }
}
