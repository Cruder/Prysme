#ifndef  __NODE_DECLAREMENT_HPP__
#define  __NODE_DECLAREMENT_HPP__

#include "node.hpp"
#include "../variable/table.hpp"

namespace Pry {
    namespace node {
        class Declarement : public Node {
        public:
            Declarement();
            Declarement(std::string name, variable::Table* t,
                bool is_const = false, Node* child = nullptr);
            virtual Node* exec();
        private:
            variable::Table* table;
            std::string name;
            bool is_constant = false;
        };
    }
}

#endif /* end of include guard:  __NODE_DECLAREMENT_HPP__ */
