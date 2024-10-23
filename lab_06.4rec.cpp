#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;


void createArray(double* arr, int n) 
{
    for (int i = 0; i < n; ++i) 
    {
        cout << "Введіть елемент [" << i << "]: ";
        cin >> arr[i];
    }
}


void printArrayRec(double* arr, int n, int index = 0) 
{
    if (index == n) return;
    cout << fixed << setprecision(2) << arr[index] << " ";
    printArrayRec(arr, n, index + 1);
}


int findMinIndexRec(double* arr, int n, int index = 0, int minIndex = 0) 
{
    if (index == n) return minIndex;
    if (fabs(arr[index]) < fabs(arr[minIndex])) minIndex = index;
    return findMinIndexRec(arr, n, index + 1, minIndex);
}


double sumAfterFirstNegativeRec(double* arr, int n, int index = 0, bool foundNegative = false) 
{
    if (index == n) return 0;
    if (arr[index] < 0) foundNegative = true;
    if (foundNegative && index > 0) return fabs(arr[index]) + sumAfterFirstNegativeRec(arr, n, index + 1, foundNegative);
    return sumAfterFirstNegativeRec(arr, n, index + 1, foundNegative);
}


int compressArrayRec(double* arr, int n, double a, double b, int index = 0, int writeIndex = 0) 
{
    if (index == n) {
        
        for (int i = writeIndex; i < n; ++i) arr[i] = 0;
        return writeIndex; 
    }
    if (arr[index] < a || arr[index] > b) {
        arr[writeIndex] = arr[index];
        writeIndex++;
    }
    return compressArrayRec(arr, n, a, b, index + 1, writeIndex);
}

int main() 
{
    int n;
    double a, b;
    
    cout << "Введіть кількість елементів масиву: ";
    cin >> n;

    double* arr = new double[n];
    createArray(arr, n);

    cout << "\nПочатковий масив: ";
    printArrayRec(arr, n);
    cout << endl;

    
    int minIndex = findMinIndexRec(arr, n);
    cout << "Індекс мінімального за модулем елементу: " << minIndex << endl;

    
    double sum = sumAfterFirstNegativeRec(arr, n);
    cout << "Сума модулів після першого від'ємного елементу: " << sum << endl;

    
    cout << "Введіть межі інтервалу [a, b]: ";
    cin >> a >> b;

    int newSize = compressArrayRec(arr, n, a, b);

    cout << "\nМодифікований масив: ";
    printArrayRec(arr, newSize);
    cout << endl;

    delete[] arr;
    return 0;
}
