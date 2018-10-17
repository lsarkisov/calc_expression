#include "binary-operation-node.h"

namespace expcounter {

    inline BinaryOperationNode::BinaryOperationNode(
        char op, ExpressionElementNode *l, ExpressionElementNode *r) :
        binary_op(op), left(l), right(r)
    {
    }

    double BinaryOperationNode::value()
    {
        double leftVal = left->value();
        double rightVal = right->value();
        double result;
        
        switch (binary_op)
        {
            case '+':
                result = leftVal + rightVal;
                break;

            case '-':
                result = leftVal - rightVal;
                break;

            case '*':
                result = leftVal * rightVal;
                break;

            case '/':
                result = leftVal / rightVal;
                break;

        }

        return result;
    } 
}