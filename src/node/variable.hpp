#ifndef __NODE_VARIABLE_HPP__
#define __NODE_VARIABLE_HPP__

#include "node.hpp"
#include "../variable/table.hpp"

namespace Pry {
    namespace node {
        class Variable : public Node {
        public:
            Variable();
            Variable(std::string name, Pry::variable::Table* t);
            virtual Node* exec();
        private:
            std::string name;
            variable::Table* table;
        };
    }
}

#endif /* end of include guard: __NODE_VARIABLE_HPP__ */
