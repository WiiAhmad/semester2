#include <iostream>
#include <stack>

using namespace std;

bool isOperand(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

string postfixToInfix(string postfix)
{
    stack<string> s;

    for (int i = 0; i < postfix.length(); i++)
    {
        if (isOperand(postfix[i]))
        {
            string operand(1, postfix[i]);
            s.push(operand);
        }
        else
        {
            string operand2 = s.top();
            s.pop();
            string operand1 = s.top();
            s.pop();
            s.push("(" + operand1 + postfix[i] + operand2 + ")");
        }
    }

    return s.top();
}

int main()
{
    string postfix = "B,2,^,4,-,a,*,c,*,2,a,*,/,p,q,*,a,b,+,/,+";
    string infix = postfixToInfix(postfix);
    cout << "Infix: " << infix << endl;
    return 0;
}