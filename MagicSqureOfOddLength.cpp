#include <iostream>
#include <vector>
using namespace std;

void generateMagicSquare(int n) {
    vector<vector<int>> magicSquare(n, vector<int>(n, 0));
    int number = 1;
    int i = 0, j = n / 2;

    while (number <= n * n) {
        magicSquare[i][j] = number;
        number++;
        int newI = (i - 1 + n) % n;
        int newJ = (j + 1) % n;

        if (magicSquare[newI][newJ] != 0) {
            i = (i + 1) % n;
        } else {
            i = newI;
            j = newJ;
        }
    }
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            cout << magicSquare[x][y] << "\t";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter an odd number :\n";
    cin >> n;

    if (n % 2 == 0) {
        cout << "Only odd numbers are allowed." << endl;
    } else {
        generateMagicSquare(n);
    }

    return 0;
}
