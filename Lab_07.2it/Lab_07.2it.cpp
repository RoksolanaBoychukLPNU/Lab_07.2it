#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

// формує матрицю a (k x n) випадковими числами з діапазону [Low; High]
void Create(int** a, const int k, const int n, const int Low, const int High)
{
    for (int i = 0; i < k; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

// виводить матрицю a у вигляді таблиці
void Print(int** a, const int k, const int n)
{
    cout << endl;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
            cout << setw(5) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

// шукає максимальний елемент рядка rowNo
int MaxInRow(int** a, const int rowNo, const int n)
{
    int max = a[rowNo][0];
    for (int j = 1; j < n; j++)
        if (a[rowNo][j] > max)
            max = a[rowNo][j];
    return max;
}

// шукає суму максимальних елементів по всіх рядках матриці
int SumRowMax(int** a, const int k, const int n)
{
    int S = 0;
    for (int i = 0; i < k; i++)
        S += MaxInRow(a, i, n);
    return S;
}

int main()
{
    srand((unsigned)time(NULL));

    int Low = -50;          // нижня межа діапазону значень
    int High = 50;          // верхня межа діапазону значень

    int k, n;               // k - кількість рядків, n - кількість стовпчиків
    cout << "k = "; cin >> k;
    cout << "n = "; cin >> n;

    int** a = new int* [k];  // динамічна матриця k x n
    for (int i = 0; i < k; i++)
        a[i] = new int[n];

    Create(a, k, n, Low, High);
    Print(a, k, n);

    for (int i = 0; i < k; i++)
        cout << "max in row " << i << " = " << MaxInRow(a, i, n) << endl;
    cout << "Sum of row maxima = " << SumRowMax(a, k, n) << endl;

    for (int i = 0; i < k; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}
