#include "scope.hpp"

namespace Pry {
    namespace node {
        Scope::Scope() :
            Node() {
        }

        Scope::Scope(tree::Scope* scope, variable::Table* table, Node* node) :
            Node() {

        }


        Node* Scope::exec() {
            auto list = new List();
            table->increment_depth();
            scope->increment_depth(list);
            return this;
        }
    }
}
