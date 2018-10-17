#include "binary-expression-builder.h"

namespace expcounter {

    int BinaryExpressionBuilder::precedence(char op)
    {
        enum
        {
            lowest, mid, highest
        };

        switch (op)
        {
            case '+':
            case '-':
                return mid;

            case '/':
            case '*':
                return highest;

            default:
                return lowest;

        }

    }

    BinaryOperationNode *BinaryExpressionBuilder::parse(std::string& str)
            noexcept(false)
    {

        std::istringstream istr(str);
        char token;
        while (istr >> token)
        {
            switch (token)
            {
                case '+':
                case '-':
                case '*':
                case '/':
                    processOperator(token);
                    break;

                case ')':
                    processRightParenthesis();
                    break;

                case '(':
                    operatorStack.push(token);
                    break;

                default:

                    istr.putback(token);
                    double number;
                    
                    istr >> number;

                    NumericElementNode *newNode = new NumericElementNode(number);
                    operandStack.push(newNode);
                    continue;

            } // end switch

        } // end while

        while (!operatorStack.empty())
        {
            doBinary(operatorStack.top());
            operatorStack.pop();

        }

        if (operandStack.size() != 1)
        {
            throw NotWellFormed();
        }

        ExpressionElementNode *p = operandStack.top();
        
        return static_cast<BinaryOperationNode *> (p);
    }

    void BinaryExpressionBuilder::processOperator(char op)
    {
        int opPrecedence = precedence(op);

        while ((!operatorStack.empty()) && (opPrecedence <= precedence(
                operatorStack.top())))
        {
            doBinary(operatorStack.top());
            operatorStack.pop();

        }
        
        operatorStack.push(op);
    }

    void BinaryExpressionBuilder::processRightParenthesis()
    {
        while (!operatorStack.empty() && operatorStack.top() != '(')
        {
            doBinary(operatorStack.top());
            operatorStack.pop();
        }

        operatorStack.pop();

    }

    void BinaryExpressionBuilder::doBinary(char op)
    {
        ExpressionElementNode *right = operandStack.top();
        operandStack.pop();

        ExpressionElementNode *left = operandStack.top();
        operandStack.pop();

        BinaryOperationNode *p = new BinaryOperationNode(operatorStack.top(), left, right);
        operandStack.push(p);

    }  
}