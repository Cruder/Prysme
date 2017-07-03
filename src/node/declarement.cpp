#include "declarement.hpp"

namespace Pry {
    namespace node {
        Declarement::Declarement() :
            Node() {
        }

        Declarement::Declarement(std::string name, variable::Table* t, bool is_const, Node* child) :
            Node(),
            table(t),
            name(name),
            is_constant(is_const) {
            if(child) {
                add_children(child);
            }
        }

        Node* Declarement::exec() {
            value = children[0]->exec()->value;
            auto var = std::make_unique<variable::Variable>(value, is_constant);
            table->define(name, std::move(var));

            return this;
        }

        std::string Declarement::type_string() const { return "Declarement"; }
    }
}
