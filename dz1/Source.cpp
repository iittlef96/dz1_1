#include <iostream>
#include <cstdlib>
#include <Windows.h>
using namespace std;

void RandArray(int arr[], int size);

int findMin(int arr[], int start);

int findMax(int arr[], int size);

int findMax(int arr[][3], int rows, int cols);

int findMax(int arr[][3][2], int x, int y, int z);

int findMax(int a, int b);

int findMax(int a, int b, int c);

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "\t\t\tЗадание №4 " << "\n\n";


    int arr[100];
    RandArray(arr, 100);

    int start = findMin(arr, 0);

    cout << "Поиция с которой начинается последователность из 10 чисел сумма которых минимальна :" << start << "\n\n";

    cout << "\t\t\tЗадание №5 " << "\n\n";

    int arr1[] = { 3, 9, 1 , 2, 3, 6, 6, 56, 78 };
    int arr2[2][3] = { {4, 8, 33}, {1, 2, 3} };
    int arr3[1][3][2] = { { {2, 1}, {1, 9}, {6, 6} } };

    cout << "Макс значение в одномерном массиве: ";
    cout << findMax(arr1, 9);
    cout << "\n";
    cout << "Макс значение в двумерном массиве: ";
    cout << findMax(arr2, 2, 3);
    cout << "\n";
    cout << "Макс значение в трехиернои масиве: ";
    cout << findMax(arr3, 1, 3, 2);
    cout << "\n";
    cout << "Макс значение дву чисел: ";
    cout << findMax(10, 5);
    cout << "\n";
    cout << "Макс значене трех чисел: ";
    cout << findMax(3, 7, 2);
    cout << "\n";



    system("pause");
    return 0;
}
void RandArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 100;
    }
}


int findMin(int arr[], int start) {
    if (start > 90) {
        return -1;
    }

    int minSum = arr[start] + arr[start + 1] + arr[start + 2] + arr[start + 3] + arr[start + 4] +
        arr[start + 5] + arr[start + 6] + arr[start + 7] + arr[start + 8] + arr[start + 9];

    int nextMinSumPos = findMin(arr, start + 1);

    if (nextMinSumPos == -1) {
        return start;
    }

    int nextMinSum = arr[nextMinSumPos] + arr[nextMinSumPos + 1] + arr[nextMinSumPos + 2] +
        arr[nextMinSumPos + 3] + arr[nextMinSumPos + 4] + arr[nextMinSumPos + 5] +
        arr[nextMinSumPos + 6] + arr[nextMinSumPos + 7] + arr[nextMinSumPos + 8] +
        arr[nextMinSumPos + 9];

    return (minSum < nextMinSum) ? start : nextMinSumPos;
}

int findMax(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int findMax(int arr[][3], int rows, int cols) {
    int max = arr[0][0];
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (arr[i][j] > max) {
                max = arr[i][j];
            }
        }
    }
    return max;
}

int findMax(int arr[][3][2], int x, int y, int z) {
    int max = arr[0][0][0];
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            for (int k = 0; k < z; ++k) {
                if (arr[i][j][k] > max) {
                    max = arr[i][j][k];
                }
            }
        }
    }
    return max;
}

int findMax(int a, int b) {
    return (a > b) ? a : b;
}

int findMax(int a, int b, int c) {
    return max(a, b), c;
}


