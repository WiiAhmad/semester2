#include <iostream>
#include <stack>
#include <string>

using namespace std;

int evaluatePostfix(string postfix)
{
    stack<int> s;
    for (int i = 0; i < postfix.length(); i++)
    {
        if (postfix[i] == ',')
        {
            continue;
        }
        else if (isdigit(postfix[i]))
        {
            s.push(postfix[i] - '0'); // ubah karakter menjadi integer dan push ke dalam stack
        }
        else
        {
            int op2 = s.top();
            s.pop();
            int op1 = s.top();
            s.pop();
            switch (postfix[i])
            {
            case '+':
                s.push(op1 + op2);
                break;
            case '-':
                s.push(op1 - op2);
                break;
            case '*':
                s.push(op1 * op2);
                break;
            case '/':
                s.push(op1 / op2);
                break;
            }
        }
    }
    return s.top();
}

int main()
{
    string postfix;
    cout << "Masukkan ekspresi postfix: ";
    cin >> postfix;
    int result = evaluatePostfix(postfix);
    cout << "Hasil akhir: " << result << endl;
    return 0;
}