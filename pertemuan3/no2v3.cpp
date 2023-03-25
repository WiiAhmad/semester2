#include <iostream>
#include <stack>
#include <string>

using namespace std;

int precedence(char op)
{
    if (op == '(')
    {
        return 4;
    }
    if (op == '^' || op == '%')
    {
        return 3;
    }
    if (op == '*' || op == '/')
    {
        return 2;
    }
    if (op == '+' || op == '-')
    {
        return 1;
    }
    if (op == ')')
    {
        return 0;
    }
    return -1;
}

bool isOperand(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
    {
        return true;
    }
    else
    {
        return false;
    }
}

string infixToPostfix(string infix)
{
    stack<char> st;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++)
    {
        char ch = infix[i];

        if (isOperand(ch))
        {
            postfix += ch;
        }
        else if (st.empty())
        {
            st.push(ch);
        }
        else if (ch == ')')
        {
            while (st.top() != '(')
            {
                postfix += st.top();
                st.pop();
            }
            st.pop();
        }
        else if (precedence(ch) > precedence(st.top()))
        {
            st.push(ch);
        }
        else
        {
            while (!st.empty() && precedence(ch) <= precedence(st.top()) && st.top() != '(')
            {
                postfix += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }

    while (!st.empty())
    {
        postfix += st.top();
        st.pop();
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

    return 0;
}