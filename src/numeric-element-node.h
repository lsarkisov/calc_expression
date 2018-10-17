#ifndef numeric_element_node_Header
#define numeric_element_node_Header

#include "expression-element-node.h"

namespace expcounter {
    class NumericElementNode: 
        public ExpressionElementNode

    {
        public:
            NumericElementNode(double val);
            virtual double value();

        private:
            double number;
            NumericElementNode(const NumericElementNode& n);
            NumericElementNode();
            NumericElementNode&operator=(const NumericElementNode& n);

    };
}

#endif