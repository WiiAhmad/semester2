#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<char, int> precedence_map = {
    {'+', 1},
    {'-', 1},
    {'*', 2},
    {'/', 2},
    {'^', 3}};

int evaluatePostfix(string postfix)
{
    stack<int> s;
    for (int i = 0; i < postfix.length(); i++)
    {
        if (isdigit(postfix[i]))
        {
            s.push(postfix[i] - '0'); // ubah karakter menjadi integer dan push ke dalam stack
        }
        else if (isalpha(postfix[i]))
        {
            cout << "Masukkan nilai " << postfix[i] << ": ";
            int val;
            cin >> val;
            s.push(val);
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
            case '^':
                s.push(pow(op1, op2));
                break;
            }
        }
    }
    return s.top();
}

int main()
{
    string postfix = "b2^4-a*c*2a*/pq*a+b+/+";
    int result = evaluatePostfix(postfix);
    cout << "Hasil akhir: " << result << endl;
    return 0;
}