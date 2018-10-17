#ifndef binary_operation_node_Header
#define binary_operation_node_Header

#include "expression-element-node.h"

namespace expcounter {
    
    class BinaryOperationNode: 
        public ExpressionElementNode
    {
        public:
            BinaryOperationNode(
                char op, ExpressionElementNode *l, ExpressionElementNode *r);

            virtual double value();
    
        private:
            char binary_op;
            ExpressionElementNode *left;
            ExpressionElementNode *right;
            BinaryOperationNode(const BinaryOperationNode& n);
            BinaryOperationNode();
            BinaryOperationNode &operator=(const BinaryOperationNode& n);

    };
}

#endif