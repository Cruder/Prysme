#include "function_call.hpp"

namespace Pry {
    namespace node {
        FunctionCall::FunctionCall() :
            Node() {
        }

        FunctionCall::FunctionCall(std::string name, function::Table* table) :
            Node(),
            table(table),
            name(name) {
        }

        Node* FunctionCall::exec() {
          auto var = table->find(name);

          return var->exec();
        }

        std::string FunctionCall::type_string() const { return "FunctionCall"; }
    }
}
