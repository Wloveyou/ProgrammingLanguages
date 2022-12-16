#include <iostream>
#include <cmath>

using namespace std;

/**
 * \brief функция определения текущего элемента ряда.
 * param k - переменная для вычисления элемента ряда.
 * \return значение текущего элемент ряда.
*/
double getCurrent(const int k);

/**
 * \brief функция вычисления суммы первых n элементов ряда.
 * param n - количество элементов ряда.
 * param k - переменная для вычисления элемента ряда.
 * \return сумма первых n элементов ряда.
 */
double getSumm1(int n, int k);

/**
 * \brief вычисление суммы членов ряда не меньших числа e.
 * param e - константа по условию.
 * param k - переменная для вычисление элемента ряда.
 * \return сумма членов ряда не меньших числа e.
*/
double getSumm2(double e, int k);

/**
 * \brief точка входа в программу.
 * return 0 в случае успеха.
*/
int main()
{
    setlocale(LC_ALL, "Russian");
    int n;
    double e = 0.0;
    int k = 0;
    cout << "Введите количество членов ряда" << endl;
    cin >> n;
    cout << "Введите e ";
    cin >> e;
    cout << getSumm1(n, k) << endl;
    cout << getSumm2(e, k);
    return 0;
}

double getCurrent(const int k) {
    return (1.0 + k) / pow(((k + 2) + 1), 2);
}

double getSumm1(int n, int k) {
    double sum1 = 0.0;
    for (int i = 1; i <= n; i++) {
        sum1 = sum1 + getCurrent(k);
        k = k + 1;
    }
    return sum1;
}

double getSumm2(double e, int k) {
    double cur;
    double sum2 = 0.0;
    cur = getCurrent(k);
    while (cur > e) {
        sum2 = sum2 + cur;
        k++;
        cur = getCurrent(k);
    }
    return sum2;
}
