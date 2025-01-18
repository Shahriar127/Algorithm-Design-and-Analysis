
import java.util.*;

public class MagicSqureOfOddLength {
    static void generateMagicSquare(int n) {
        int[][] magicSquare = new int[n][n];
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

        System.out.println("Magic Square of size " + n + ":");
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                System.out.print(magicSquare[i][j] + "\t");
            }
            System.out.println();
        }

        System.out.println("Sum of each row, column, and diagonal: " + n * (n * n + 1) / 2);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter an odd number for magic square size: ");
        int n = sc.nextInt();

        if (n % 2 == 0) {
            System.out.println("Only odd numbers are allowed.");
        } else {
            generateMagicSquare(n);
        }
        sc.close();
    }
}
