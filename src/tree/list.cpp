#include "list.hpp"

namespace pry {
    namespace tree {
        List::List() : nodes {} {
        }

        void List::add_node(std::unique_ptr<Node> node) {
            nodes.push_back(std::move(node));
        }

        void List::exec() {
            for(auto& node : nodes) {
                node->exec();
            }
        }
    }
}
