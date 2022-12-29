#define _USE_MATH_DEFINES

#include <cmath>
#include <iostream>

using namespace std;

/**
* \brief Функция для рассчета y1
* \param x Значение x
* \return Возвращает значение y1
**/
double GetFirst(const double x, const double a);

/**
* \brief Функция для рассчета y2*
* \param x Значение x
* \return Возвращает значение y2
**/
double GetSecond(const double x, const double a);

/**
 * \brief Точка входа в программу.
 */
int main()
{
    setlocale(LC_ALL, "Russian");
    const double a = 2;
    double x;

    cout << "Введите чилсо x = ";
    cin >> x;
    if (x > a)
    {
        auto first = GetFirst(x, a);
        cout << first;
    }
    else
    {
        auto second = GetSecond(x, a);
        cout << second;
    }
}

double GetFirst(const double x, const double a)
{
    double k = 3.0;
    return sin(x) / cos(x) + M_PI / k;
}
double GetSecond(const double x, const double a)
{
    return sin(x) * a;
}
