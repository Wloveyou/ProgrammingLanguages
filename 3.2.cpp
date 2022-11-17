#include <iostream>
#include <cmath>

using namespace std;

/**
 * \brief Функция для нахождения текущего элемента.
 * \param k Переменная элемента ряда.
 * \return Возвращает значение текущего элемента.
**/
double getCurrentNum(const size_t k);

/**
 * \brief Функция для вычисления суммы первых n элементов ряда.
 * \param n Количество элементов ряда.
 * \param k Переменная элемента ряда.
 * \return Возвращает сумму первых n элементов ряда.
 **/
double getSumN(const int n);

/**
 *\brief Функция для вычисления суммы членов ряда не меньших числа e.
 *\param e Заданное число.
 *\param k Переменная элемента ряда.
 *\return Возвращает сумму членов ряда не меньших числа e.
**/
double getSumE(const size_t k, double e);

/**
 * \brief Точка входа в программу
 * \return В случае успеха возвращает 0
 */

int main()
{
    size_t k = 1;
    int n;
    double e = 0.0;

    cout << "Введите количество членов ряда: ";
    cin >> n;
    cout << "\nВведите значение e: ";
    cin >> e;

    cout << "\nСумма первых n членов: " << getSumN(n);
    cout << "\nСумма членов не меньших числа е: " << getSumE(k, e) << endl;

    return 0;
}

double getCurrentNum(const size_t k)
{
    return 1 + k  / pow(((k+2)+1),2);
}

double getSumN(const int n)
{
    double sum = 0.0;
    for (int i = 1; i <= n; i++)
    {
        size_t k = k + 1;
        sum = sum + getCurrentNum(k);
    }

    return sum;
}

double getSumE(size_t k, double e)
{
    double sum = 0;
    double current = getCurrentNum(k);

    while (abs(current) > e)
    {
        sum += current;
        k++;
        current = getCurrentNum(k);
    }

    return sum;
}
