#include "assignment.hpp"
#include "../variable/constant_exception.hpp"

namespace Pry {
    namespace node {
        Assignment::Assignment() :
            Node() {
        }

        Assignment::Assignment(std::string name, variable::Table* t, Node* child) :
            Node(),
            table(t),
            name(name) {
            if(child) {
                add_children(child);
            }
        }

        Node* Assignment::exec() {
            auto var = table->find(name);
            if(var->is_constant) {
                throw variable::ConstantException(name);
            }
            auto child = children[0]->exec();

            var->value = child->value;
            value = child->value;
            return this;
        }

        std::string Assignment::type_string() const { return "Assignment"; }
    }
}
