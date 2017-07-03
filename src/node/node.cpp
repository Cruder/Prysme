#include "node.hpp"

namespace Pry {
    namespace node {
        Node::Node() : value(), children() {
        }

        Node::Node(const Pry::variable::PrimitiveType& value) :
            value(value), children() {
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

        std::string Node::as_string(std::size_t space) const {
            std::string str_space(space, ' ');
            std::string str = str_space + type_string() + " [\n";
            for(auto& c : children) { str += c->as_string(space + 2) + '\n'; }
            return str + str_space + "]";
        }

        std::string Node::type_string() const { return "Node"; }
    }
}
