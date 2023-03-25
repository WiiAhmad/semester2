#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isOperand(char ch)
{
    return isalpha(ch) || isdigit(ch);
}

int evaluatePostfix(string postfix)
{
    stack<int> s;
    for (int i = 0; i < postfix.length(); i++)
    {
        if (postfix[i] == ',') // jika bertemu koma, skip ke operand/operator selanjutnya
        {
            continue;
        }
        else if (isdigit(postfix[i]))
        {
            int num = postfix[i] - '0';
            while (i + 1 < postfix.length() && isdigit(postfix[i + 1]))
            {
                num = num * 10 + (postfix[i + 1] - '0');
                i++;
            }
            s.push(num); // push angka ke dalam stack
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
    getline(cin, postfix);
    int result = evaluatePostfix(postfix);
    cout << "Hasil akhir: " << result << endl;
    return 0;
}