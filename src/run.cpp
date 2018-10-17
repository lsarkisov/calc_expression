#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stack>
#include <exception>

#include "numeric-element-node.cpp"
#include "binary-operation-node.cpp"
#include "binary-expression-builder.cpp"


namespace expcounter {

    double run(const std::string& file_name){
        
        NumericElementNode num1(10);
        NumericElementNode num2(20);
        BinaryOperationNode n('+', &num1, &num2);
        BinaryExpressionBuilder b;

        std::string expression;

        std::ifstream file(file_name);
        
        if (file.is_open()) {
            std::string line;
            
            while (getline(file, line)) {
                expression = line.c_str();
            }
            
            file.close();
        }

        BinaryOperationNode *root = b.parse(expression);

        return root->value();
    }
}