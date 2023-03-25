#include <iostream>
#include <stack>
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

void valinTable(int i, string infix, stack<char> &st, string postfix)
{
    string strStack;
    while (!st.empty())
    {
        strStack += st.top();
        st.pop();
    }
    cout << "tabel ke =" << i << endl;
    cout << "Expression =" << infix[i] << endl;
    cout << "Stack =" << strStack << endl;
    cout << "Postfix =" << postfix << endl;
}

int main()
{
    string infix;
    stack<char> st;
    string postfix = "";
    cout << "Enter the infix expression: ";
    getline(cin, infix);
    for (int i = 0; i < infix.length(); i++)
    {
        if (isOperand(infix[i]))
        {
            postfix += infix[i];
        }
        else if (st.empty())
        {
            st.push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while (st.top() != '(')
            {
                postfix += st.top();
                st.pop();
            }
            st.pop();
        }
        else if (precedence(infix[i]) > precedence(st.top()))
        {
            st.push(infix[i]);
        }
        else
        {
            while (!st.empty() && precedence(infix[i]) <= precedence(st.top()) && st.top() != '(')
            {
                postfix += st.top();
                st.pop();
            }
            st.push(infix[i]);
        }
        valinTable(i, infix, st, postfix);
    }
    while (!st.empty())
    {
        postfix += st.top();
        st.pop();
    }
    cout << "Postfix Expression: " << postfix << endl;
    return 0;
}