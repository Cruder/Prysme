#include "scope.hpp"

namespace Pry {
    namespace node {
        Scope::Scope() :
            Node() {
        }

        Scope::Scope(tree::List* list, variable::Table* table) :
            Node(),
            list(list),
            table(table) {
        }

        Scope::~Scope() {
            delete list;
        }

        Node* Scope::exec() {
            table->increment_depth();
            value = list->exec();
            table->decrement_depth();
            return this;
        }

        std::string Scope::as_string(std::size_t space) const {
            std::string str_space(space, ' ');
            std::string str = str_space + type_string() + " [\n";
            str += list->as_string(space + 2) + '\n';
            return str + str_space + "]";
        }

        std::string Scope::type_string() const { return "Scope"; }
    }
}
