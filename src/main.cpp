#include "functions.cpp"

int main() {
    const int n = 5; // Розмір матриці
    int **a = new int *[n];
    for (int i = 0; i < n; i++) {
        a[i] = new int[n];
    }

    // Генерація та друк початкової матриці
    Create(a, n);
    cout << "Original matrix:\n";
    Print(a, n);

    // Заміна елементів і друк результату
    Change(a, n);
    cout << "Modified matrix:\n";
    Print(a, n);

    // Очищення пам'яті
    for (int i = 0; i < n; i++) {
        delete[] a[i];
    }
    delete[] a;

    return 0;
}