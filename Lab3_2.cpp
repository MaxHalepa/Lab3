#include <iostream>
#include <cmath>
#include <windows.h>

using namespace std;

int main(){

    SetConsoleOutputCP(CP_UTF8);

    int array_size = 0;
    cout << endl << "Введіть довжину масиву: ";
    cin >> array_size;

    int array[array_size];
    for(int i = 0; i < array_size; i++){
        cout << " - введіть значення("<< i + 1 <<"): ";
        cin >> array[i];
    }

    int min, min_abs, max = array[0];
    int max_idx = 0;
    int sum_after_first_zero_item = 0;
    int is_zero_item = false;

    // Для пошуку мін та макс можна починати з i = 1
    for(int i = 0; i < array_size ;i++) {
        // Пошук мінімального елементу
        if (array[i] < min)
            min = array[i];

        // Пошук мінімального елементу по модулю
        if (abs(array[i]) < abs(min_abs))
            min_abs = abs(array[i]);

        // Пошук елементу після першого 0
        if (array[i] == 0 && is_zero_item == false)
            is_zero_item = true;

        // Сумуємо мінімум та мінімум по модулю
        if (is_zero_item == true)
            sum_after_first_zero_item += array[i];

        // Пошук максимуму
        if (max < array[i]) {
            max = array[i];
            max_idx = i;
        }
    }

    int d[array_size - 1];
    for (int i = 0, offset = i + max_idx + 1; i < array_size - 1; i++, offset++) {
        if (offset >= array_size)
            offset = 0;
        d[i] = array[offset];
    }

    cout << endl << "\tРезультати: " << endl;
    cout << "1) Сума мінімального та мінімального по модулю значення: " << min + min_abs << endl;
    cout << "2) Сума модулів елементів масиву, розташованих після першого елементу, рівного нулю: " << sum_after_first_zero_item << endl;
    cout << "3) Перші числа після максимального, та перед максимальним: " ;
    for(int i = 0; i < array_size - 1; i++){
        if(i != array_size - 2)
            cout << d[i] << ", ";
        else
            cout << d[i] << "; ";
    }

    return 0;
}

/*
 * Test 1
 * Длина - 2
 * Ввод1 - 0
 * Ввод2 - 1
 * Результати:
 *1) Сума мінімального та мінімального по модулю значення: -0
 *2) Сума модулів елементів масиву, розташованих після першого елементу, рівного нулю: 1
 *3) Перші числа після максимального, та перед: 0
 *
 * Test 2
 * Длина - 3
 * Ввод1 - -8
 * Ввод2 - 3
 * Ввод3 - 1
 * Результати:
 *1) Сума мінімального та мінімального по модулю значення: -7
 *2) Сума модулів елементів масиву, розташованих після першого елементу, рівного нулю: 0
 *3) Перші числа після максимального, та перед: 1, -8
 *
 * Test 3
 * Длина - 5
 * Ввод1 - 6
 * Ввод2 - 0
 * Ввод3 - 8
 * Ввод4 - -3
 * Ввод5 - 0
 * Результати:
 *1) Сума мінімального та мінімального по модулю значення: -3
 *2) Сума модулів елементів масиву, розташованих після першого елементу, рівного нулю: 5
 *3) Перші числа після максимального, та перед максимальним: -3, 0, 6, 0;
 */




