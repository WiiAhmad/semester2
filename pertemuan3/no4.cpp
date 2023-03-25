#include <iostream>
#include <stack>

using namespace std;

void TowerOfHanoi(int n, stack<int> &A, stack<int> &B, stack<int> &C)
{
    if (n > 0)
    {
        TowerOfHanoi(n - 1, A, C, B);
        int disk = A.top();
        A.pop();
        C.push(disk);
        cout << "Move disk " << disk << " from rod " << char(A.get_id() + 'A') << " to rod " << char(C.get_id() + 'A') << endl;
        TowerOfHanoi(n - 1, B, A, C);
    }
}

int main()
{
    int n = 3;

    stack<int> A, B, C;
    A.set_id(0);
    B.set_id(1);
    C.set_id(2);

    for (int i = n; i >= 1; i--)
    {
        A.push(i);
    }

    TowerOfHanoi(n, A, B, C);

    return 0;
}