#ifndef  __NODE_FUNCTION_DECLARE_HPP__
#define  __NODE_FUNCTION_DECLARE_HPP__

#include "node.hpp"
#include "../function/table.hpp"

namespace Pry {
    namespace node {
        class FunctionDeclare : public Node {
        public:
            FunctionDeclare();
            FunctionDeclare(std::string name, function::Table* t, Node* child);
            virtual Node* exec();
        protected:
            virtual std::string type_string() const;
        private:
            function::Table* table;
            std::string name;
        };
    }
}

#endif /* end of include guard:  __NODE_FUNCTION_DECLARE_HPP__ */
