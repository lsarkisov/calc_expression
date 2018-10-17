#ifndef binary_expression_node_Header
#define binary_expression_node_Header

namespace expcounter
{
    class BinaryExpressionBuilder
    {
        public:
            class NotWellFormed: 
                public std::exception
            {
                public:
                    virtual const char* what() const throw ()
                    {
                        return "The expression is not valid";
                    }

            };

            BinaryOperationNode *parse(std::string& istr) noexcept(false);
        
        private:
            std::stack<char> operatorStack;
            std::stack<ExpressionElementNode *> operandStack;
            void processOperator(char op);
            void processRightParenthesis();
            void doBinary(char op);
            int precedence(char op);

    };

} // namespace expcounter

#endif