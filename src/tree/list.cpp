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

        std::string List::as_string(std::size_t space) const {
            std::string str_space(space, ' ');
            std::string str = str_space + "List [\n";
            for(auto& node : nodes) { str += node->as_string(space + 2) + '\n'; }
            return str + str_space + ']';
        }

        std::ostream& operator<<(std::ostream& os, const List& list) {
            os << list.as_string();
            return os;
        }
    }
}
