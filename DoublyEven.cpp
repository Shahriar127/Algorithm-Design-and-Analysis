#include <iostream>
using namespace std;


void generateMagicSquare(int n) {
    int square[n][n] = {0};

    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            square[i][j] = (n * i) + j + 1;
        }
    }

    //4 size mini-squre
    int size = n / 4; 
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
             
            square[i][j] = (n * n + 1) - square[i][j]; 
            square[i][n - 1 - j] = (n * n + 1) - square[i][n - 1 - j];  
            square[n - 1 - i][j] = (n * n + 1) - square[n - 1 - i][j];  
            square[n - 1 - i][n - 1 - j] = (n * n + 1) - square[n - 1 - i][n - 1 - j];
        }
    }
    //mid squre
    
    for (int i = size; i < 3 * size; i++) {
        for (int j = size; j < 3 * size; j++) {
            square[i][j] = (n * n + 1) - square[i][j];
        }
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << square[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n; 
    generateMagicSquare(n);
    return 0;
}
