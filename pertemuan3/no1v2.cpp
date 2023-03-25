#include <iostream>
#include <stack>
#include <string>
using namespace std;

int precedence(char prec)
{
    if (prec == '(')
    {
        return 4;
    }
    else if (prec == '^' || prec == '%')
    {
        return 3;
    }
    else if (prec == '*' || prec == '/')
    {
        return 2;
    }
    else if (prec == '+' || prec == '-')
    {
        return 1;
    }
    else if (prec == ')')
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

string infixToPostfix(const std::string &infix)
{
    stack<char> stack;
    string postfix;

    for (char c : infix)
    {
        if (isalnum(c))
        {
            postfix += c;
        }
        else if (c == '(')
        {
            stack.push(c);
        }
        else if (c == ')')
        {
            while (!stack.empty() && stack.top() != '(')
            {
                postfix += stack.top();
                stack.pop();
            }
            if (!stack.empty())
            {
                stack.pop();
            }
        }
        else
        {
            while (!stack.empty() && precedence(c) <= precedence(stack.top()))
            {
                postfix += stack.top();
                stack.pop();
            }
            stack.push(c);
        }
    }
    while (!stack.empty())
    {
        postfix += stack.top();
        stack.pop();
    }
    return postfix;
}

int main()
{
    string infix;
    cout << "Enter infix expression: ";
    getline(std::cin, infix);

    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << std::endl;

    return 0;
}