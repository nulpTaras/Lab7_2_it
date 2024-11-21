#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <climits>
using namespace std;

// Генерація матриці
void Create(int **a, const int n, const int Low = 1, const int High = 10) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = Low + rand() % (High - Low + 1);
        }
    }
}

// Друк матриці
void Print(int **a, const int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(4) << a[i][j];
        }
        cout << endl;
    }
    cout << endl;
}
int FindMinAboveSecondaryDiagonal(int **a, const int n, int &minRow, int &minCol) {
    int min = INT_MAX; // Початково — максимально можливе значення
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i + j < n - 1 && a[i][j] < min) { // Елементи над побічною діагоналлю
                min = a[i][j];
                minRow = i;
                minCol = j;
            }
        }
    }
    return min;
}

int FindMaxBelowSecondaryDiagonal(int **a, const int n, int &maxRow, int &maxCol) {
    int max = INT_MIN; // Початково — мінімально можливе значення
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i + j > n - 1 && a[i][j] > max) { // Елементи під побічною діагоналлю
                max = a[i][j];
                maxRow = i;
                maxCol = j;
            }
        }
    }
    return max;
}

void Change(int **a, const int n) {
    int minRow, minCol, maxRow, maxCol;
    int min = FindMinAboveSecondaryDiagonal(a, n, minRow, minCol);
    int max = FindMaxBelowSecondaryDiagonal(a, n, maxRow, maxCol);

    // Заміна значень
    a[minRow][minCol] = max;
    a[maxRow][maxCol] = min;

    cout << "Min: " << min << " (row: " << minRow << ", col: " << minCol << ")" << endl;
    cout << "Max: " << max << " (row: " << maxRow << ", col: " << maxCol << ")" << endl;
    cout << "Sum of Min and Max: " << min + max << endl;
}
