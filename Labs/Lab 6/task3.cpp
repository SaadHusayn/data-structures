#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include "StackLL.h"

using namespace std;

float calculate(float operand1, float operand2, const string &operatorType)
{
    if (operatorType == "+")
        return operand1 + operand2;
    else if (operatorType == "-")
        return operand1 - operand2;
    else if (operatorType == "*")
        return operand1 * operand2;
    else if (operatorType == "/")
        return operand1 / operand2;
    return 0;
}

string evaluateExpression(const string &expression)
{
    stringstream inputStream(expression);
    string token;
    Stack<string> numberStack;
    Stack<string> operatorStack;

    while (inputStream >> token)
    {
        if (isdigit(token[0]) || (token[0] == '-' && token.size() > 1))
        {
            numberStack.push(token);
        }
        else if (token == "+" || token == "-" || token == "*" || token == "/")
        {
            operatorStack.push(token);
        }
        else if (token == "(")
        {
            operatorStack.push(token);
        }
        else if (token == ")")
        {
            while (operatorStack.peek() != "(")
            {
                float operand2 = stof(numberStack.peek());
                numberStack.pop();
                float operand1 = stof(numberStack.peek());
                numberStack.pop();
                string operation = operatorStack.peek();
                operatorStack.pop();
                float result = calculate(operand1, operand2, operation);
                numberStack.push(to_string(result));
            }
            operatorStack.pop();
        }
    }

    while (!operatorStack.isEmpty())
    {
        float operand2 = stof(numberStack.peek());
        numberStack.pop();
        float operand1 = stof(numberStack.peek());
        numberStack.pop();
        string operation = operatorStack.peek();
        operatorStack.pop();
        float result = calculate(operand1, operand2, operation);
        numberStack.push(to_string(result));
    }

    return numberStack.peek();
}

int main()
{
    string expression = "12 + 13 + 1 - 5 * ( 0.5 + 0.5 )";
    string result = evaluateExpression(expression);
    float finalResult = stof(result);
    cout << "X = 21 not 20 (There is error in question)" << endl;
    cout << fixed << setprecision(1) << "Result: " << finalResult << endl;

    return 0;
}
