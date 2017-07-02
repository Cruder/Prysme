#include "list.hpp"

namespace Pry {
    namespace tree {
        List::List() : nodes {} {
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
