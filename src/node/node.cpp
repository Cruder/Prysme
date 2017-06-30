#include "node.hpp"

namespace Pry {
    namespace node {
        Node::Node() : children() {
        }

        Node::~Node() {
            for(auto& c : children) {
                delete c;
            }
        }

        void Node::add_children(Node* child) {
            children.push_back(child);
        }

        void Node::add_children(std::vector<Node*> child) {
            for(auto& c : child) {
                add_children(c);
            }
        }

        Node* Node::exec() {
            return nullptr;
        }
    }
}
