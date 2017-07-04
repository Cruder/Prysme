#include "for.hpp"

namespace Pry {
    namespace node {
        For::For() :
            Node() {
        }

        For::For(Node* cond, Node* child, Node* pre, Node* post) :
            Node() {
            add_children(cond);
            add_children(child);
            add_children(pre);
            add_children(post);
        }

        Node* For::exec() {
            children[2]->exec();
            while(std::get<bool>(children[0]->exec()->value)) {
                value = children[1]->exec()->value;
                children[3]->exec();
            }

            return this;
        }

        std::string For::type_string() const { return "For"; }
    }
}
