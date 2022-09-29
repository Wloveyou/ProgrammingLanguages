#define _USE_MATH_DEFINES // for C++
#include <cmath>
#include <iostream>
/**
* \brief Функция расчета по заданной формуле.
* \param x Первый параметр функции.
* \param y Второй параметр функции.
* \return Значение функции.
*/
double getA(double x, double y, double z);

/**
* \brief Функция расчета по заданной формуле. * \param x Первый параметр функции.
* \param z Второй параметр функции.
* \return Значение функции.
*/
double getB(double x, double y, double z);

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
    return 0; }
double getA(double x, double y, double z){
    return sin (x) / pow( pow (y, 2) + pow ( sin(x), 2),1.0/2) - pow( x,2) * y * z;
}

double getB( double x, double y, double z)
{
    return exp(-z*x) * pow( x+1, 1.0/2) + exp(-y*x);
}
