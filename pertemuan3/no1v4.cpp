#include <iostream>
#include <stack>
#include <string>

using namespace std;

int precedence(char c)
{
    if (c == '(' || c == ')')
    {
        return 0;
    }
    if (c == '^')
    {
        return 3;
    }
    if (c == '*' || c == '/')
    {
        return 2;
    }
    if (c == '+' || c == '-')
    {
        return 1;
    }
    return -1;
}

string infixToPostfix(string infix)
{
    stack<char> stack;
    string postfix;

    for (int i = 0; i < infix.length(); i++)
    {
        char c = infix[i];
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
            stack.pop();
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
    getline(cin, infix);

    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;

    // Loop table
    stack<char> stack;
    for (int i = 0; i < infix.length(); i++)
    {
        char c = infix[i];
        if (isalnum(c))
        {
            cout << i + 1 << "\t" << c << "\t" << stack.size() << "\t" << postfix << endl;
        }
        else if (c == '(')
        {
            stack.push(c);
            cout << i + 1 << "\t" << c << "\t" << stack.size() << "\t" << postfix << endl;
        }
        else if (c == ')')
        {
            while (!stack.empty() && stack.top() != '(')
            {
                stack.pop();
            }
            stack.pop();
            cout << i + 1 << "\t" << c << "\t" << stack.size() << "\t" << postfix << endl;
        }
        else
        {
            while (!stack.empty() && precedence(c) <= precedence(stack.top()))
            {
                stack.pop();
            }
            stack.push(c);
            cout << i + 1 << "\t" << c << "\t" << stack.size() << "\t" << postfix << endl;
        }
    }

    return 0;
}