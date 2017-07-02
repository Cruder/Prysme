#ifndef __NODE_SCOPE_HPP__
#define __NODE_SCOPE_HPP__

#include "node.hpp"
#include "../tree/scope.hpp"
#include "../variable/table.hpp"

namespace Pry {
    namespace node {
        class Scope : public Node {
        public:
            Scope();
            Scope(tree::Scope* scope, variable::Table* table, Node* node);
            virtual Node* exec();
        private:
            tree::Scope* scope;
            variable::Table* table;
        };
    }
}

#endif /* end of include guard: __NODE_SCOPE_HPP__ */
