#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isOperand(char operand)
{
    if ((operand >= 'a' && operand <= 'z') || (operand >= 'A' && operand <= 'Z') || (operand >= '0' && operand <= '9'))
    {
        return true;
    }
    else
    {
        return false;
    }
}

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

void valinTable(int i, string infix, vector<char> &stack, vector<char> &postfix)
{
    string strPost, strStack;
    for (char c : postfix)
    {
        strPost += c;
    }
    for (char c : stack)
    {
        strStack += c;
    }
    cout << "tabel ke =" << i << "Expression =" << infix[i] << "Stack =" << strStack << "Postfix =" << strPost << endl;
}

int main()
{
    string infix;
    vector<char> stack, postfix;
    cout << "Enter the infix expression: ";
    getline(cin, infix);
    for (int i = 0; i < infix.length(); i++)
    {
        if (isOperand(infix[i]))
        {
            postfix.push_back(infix[i]);
        }
        else if (stack.size() == 0)
        {
            stack.push_back(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while (stack[stack.size() - 1] != '(')
            {
                postfix.push_back(stack.back());
                stack.pop_back();
            }
            stack.pop_back();
        }
        else if (precedence(infix[i]) > precedence(stack[stack.size() - 1]))
        {
            stack.push_back(infix[i]);
        }
        else
        {
            while (precedence(infix[i]) <= precedence(stack[stack.size() - 1]) && stack.size() != 0 && stack[stack.size() - 1] != '(')
            {
                postfix.push_back(stack.back());
                stack.pop_back();
            }
            stack.push_back(infix[i]);
        }
        valinTable(i, infix, stack, postfix);
    }
    while (!stack.empty())
    {
        postfix.push_back(stack.back());
        stack.pop_back();
    }
    string strPost;
    for (char c : postfix)
    {
        strPost += c;
    }
    cout << "Postfix Expression: " << strPost << endl;
    return 0;
}