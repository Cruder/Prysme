#include "list.hpp"

namespace Pry {
    namespace tree {
        List::List() : nodes {} {
        }

        void List::add_node(std::unique_ptr<node::Node> node) {
            nodes.push_back(std::move(node));
        }

        void List::exec() {
            for(auto& node : nodes) {
                node->exec();
            }
        }
    }
}
