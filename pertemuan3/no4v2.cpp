#include <iostream>
using namespace std;

void hanoi(int n, char a, char b, char c)
{
    if (n == 1)
    {
        cout << " | Pindah Bagian atas Disc dari " << a << " ke " << c << "	|" << endl;
    }
    else
    {
        hanoi(n - 1, a, c, b);
        hanoi(1, a, b, c);
        hanoi(n - 1, b, a, c);
    }
}

int main()
{
    int n;
    cout << " ========================================" << endl;
    cout << " |		Program Hanoi		|" << endl;
    cout << " |					|" << endl;
    cout << " | Masukan Jumlah Disc = ";
    cin >> n;
    cout << " ========================================" << endl;
    cout << endl;
    hanoi(n, 'A', 'B', 'C');
    cout << " ========================================" << endl;
    cout << endl;
}