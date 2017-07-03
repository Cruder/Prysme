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
    }
}
