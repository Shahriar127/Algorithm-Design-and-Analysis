#include <iostream>
#include <vector>
using namespace std;

void generateOddMagicSquare(int n, vector<vector<int>> &magicSquare, int rowOffset, int colOffset) {
    int number = 1;
    int i = 0, j = n / 2;

    while (number <= n * n) {
        magicSquare[rowOffset + i][colOffset + j] = number++;
        int newI = (i - 1 + n) % n;
        int newJ = (j + 1) % n;

        if (magicSquare[rowOffset + newI][colOffset + newJ] != 0) {
            i = (i + 1) % n;
        } else {
            i = newI;
            j = newJ;
        }
    }
}

void generateSinglyEvenMagicSquare(int n) {
    vector<vector<int>> magicSquare(n, vector<int>(n, 0));

    int k = n / 2;
    int quadrantSize = k * k;

    generateOddMagicSquare(k, magicSquare, 0, 0);
    generateOddMagicSquare(k, magicSquare, 0, k);
    generateOddMagicSquare(k, magicSquare, k, 0);
    generateOddMagicSquare(k, magicSquare, k, k);

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            magicSquare[i][j + k] += 2 * quadrantSize;
            magicSquare[i + k][j] += 3 * quadrantSize;
            magicSquare[i + k][j + k] += quadrantSize;
        }
    }

    int numCols = k / 2;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < numCols; j++) {
            swap(magicSquare[i][j], magicSquare[i + k][j]);
        }
        for (int j = n - numCols; j < n; j++) {
            swap(magicSquare[i][j], magicSquare[i + k][j]);
        }
    }

    int mid = numCols;
    swap(magicSquare[mid][0], magicSquare[mid + k][0]);
    swap(magicSquare[mid][mid], magicSquare[mid + k][mid]);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << magicSquare[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;

    if (n % 2 == 0 && n % 4 != 0) {
        generateSinglyEvenMagicSquare(n);
    } else {
        cout << "Input must be a singly even number." << endl;
    }

    return 0;
}
