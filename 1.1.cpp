#include <cmath>
#include <iostream>
using namespace std;

/**
* \brief Функция расчета по заданной формуле.
* \param x Первый параметр функции.
* \param y Второй параметр функции.
* \return Значение функции.
*/
const double getA(const double x, const double y, const double z);

/**
* \brief Функция расчета по заданной формуле.
* \param x Первый параметр функции.
* \param z Второй параметр функции.
* \return Значение функции.
*/
const double getB(const double x, const double y, const double z);

/**
* \brief Точка входа в программу.
* \return Возвращает 0 в случае успеха.
*/
int main()
{
    const auto x = 1.7;
    const auto y = 1.08;
    const auto z = 0.5;
    const auto a = getA(x, y, z);
    const auto b = getB(x, y, z);
    std::cout << "x = " << x << " y = " << y << " z = " << z << "\n";
    std::cout << "a = " << a << " b = " << b << std::endl;
    return 0; 
}
    const double getA(const double x, const double y, const double z)
{
    return sin(x) / sqrt(pow (y, 2) + pow(sin(x), 2)) - pow(x,2) * y * z;
}
    const double getB(const double x, const double y, const double z)
{
return exp(-z*x) * sqrt(x+1) + exp(-y*x);
}
