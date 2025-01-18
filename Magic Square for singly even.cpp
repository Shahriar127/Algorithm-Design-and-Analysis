#include <bits/stdc++.h>
using namespace std;
int main()
{

    int i, j, n, m, a, b, c, x, num = 1;

    while (1)
    {
        cout << "Enter the size of sigly even magic square : ";
        cin >> n;

        if (n % 4 && n % 2 == 0 && n >= 6)
        {
            break;
        }
        else
        {
            cout << "Enter valid singly even size (n is not divisible by 4) \n";
        }
    }
    int ar[n + 1][n + 1];
    memset(ar, 0, sizeof(ar));

    x = n / 2;
    i = 2;
    j = x / 2;

    while (num <= x * x)
    {
        a = i;
        b = j;
        i--;
        if (i < 1)
            i = x;
        j++;
        if (j > x)
            j = 1;

        if (ar[i][j] == 0)
        {
            ar[i][j] = num;
            ar[i][j + x] = num + (x * x * 2);
            ar[i + x][j] = num + (x * x * 3);
            ar[i + x][j + x] = num + (x * x);
        }
        else

        {
            i = a + 1;
            if (i > x)
                i = 1;
            j = b;

            ar[i][j] = num;
            ar[i][j + x] = num + (x * x * 2);
            ar[i + x][j] = num + (x * x * 3);
            ar[i + x][j + x] = num + (x * x);
        }
        num++;
    }

    c = (x + 1) / 2;
    for (i = 1; i <= x; i++)
    {
        if (i == c)
            swap(ar[i][c], ar[i + x][c]);
        else
            swap(ar[i][c - 1], ar[i + x][c - 1]);
        for (j = 1; j <= c - 2; j++)
        {
            swap(ar[i][j], ar[i + x][j]);
            swap(ar[i][n - j + 1], ar[i + x][n - j + 1]);
        }
    }

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {

            cout << setw(4) << ar[i][j] << " |";
        }
        cout << endl;
    }
}
