#include "function_declare.hpp"

namespace Pry {
    namespace node {
        FunctionDeclare::FunctionDeclare() :
            Node() {
        }

        FunctionDeclare::FunctionDeclare(std::string name, function::Table* t, Node* child) :
            Node(),
            table(t),
            name(name) {
            add_children(child);
        }

        Node* FunctionDeclare::exec() {
          auto var = std::make_unique<function::Function>(children[0]);
          table->define(name, std::move(var));

          return children[0];
        }

        std::string FunctionDeclare::type_string() const { return "FunctionDeclare"; }
    }
}
