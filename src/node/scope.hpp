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
            Scope(tree::List* list, variable::Table* table);
            virtual ~Scope();
            virtual Node* exec();

            virtual std::string as_string(std::size_t space = 0) const;
        protected:
            virtual std::string type_string() const;
        private:
            tree::List* list;
            variable::Table* table;
        };
    }
}

#endif /* end of include guard: __NODE_SCOPE_HPP__ */
