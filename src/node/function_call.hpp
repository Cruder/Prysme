#ifndef  __NODE_FUNCTION_CALL_HPP__
#define  __NODE_FUNCTION_CALL_HPP__

#include "node.hpp"
#include "../function/table.hpp"

namespace Pry {
    namespace node {
        class FunctionCall : public Node {
        public:
            FunctionCall();
            FunctionCall(std::string name, Pry::function::Table* table);
            virtual Node* exec();
        protected:
            virtual std::string type_string() const;
        private:
            function::Table* table;
            std::string name;
        };
    }
}

#endif /* end of include guard:  __NODE_FUNCTION_CALL_HPP__ */
