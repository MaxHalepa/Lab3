#include <iostream>
#include <cmath>
#include <windows.h>

using namespace std;

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    int array_size = 0;

    cout << "Розмір масиву:";
    cin >> array_size;

    double x[array_size];
    double y[array_size];

    for(int i = 0; i < array_size; i++) {
        cout << " - введіть значення (" << i << "):";
        cin >> x[i];

        if (x[i] >= 0 && x[i] < 1)
            y[i] = 1 - sqrt(x[i]) + sin(x[i]) - log(1 - x[i]);
        else
            y[i] = NAN;
    }

    cout << "Значення Y це:" << endl;
    for(int i = 0; i < array_size; i++) {
        if (isnan(y[i]))
            cout << " - nan" << endl;
        else
            cout << " - значення елементу (" << i << ") is: " << y[i] << endl;
    }
}
/*
 * Test 1
 * Длина - 2
 * Ввод1 - 0.5
 * Ввод2 - 1
 * Результат: 1) 1.46547 ; 2)nan
 *
 * Test 2
 * Длина - 3
 * Ввод1 - 0
 * Ввод2 - -0.1
 * Ввод3 - 0.2
 * Результат: 1) 1 ; 2)nan ; 3)0.974599
 *
 * Test 3
 * Длина - 2
 * Ввод1 - 0.45
 * Ввод2 - 0.9
 * Результат: 1) 1.36198 ; 2)3.13723
 */
