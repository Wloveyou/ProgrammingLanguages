#define _USE_MATH_DEFINES

#include <cmath>
#include <iostream>

using namespace std;

/**
*\brief Рассчитывает площадь прямоугольного треугольника
 * \param a Значение катета a
 * \param b Значение катета b
 * \return Площадь прямоугольного треугольника
 */
double getSquare(const double a, const double b);

/**
 * \brief Точка входа в программу.
 * \return Возвращает 0 в случае успешного выполнения.
 */
int main() {
	setlocale(LC_ALL, "Russian");
	double a, b;
	cout << "Введите значение катета a и катета b и нажмите Enter: \n";
	cin >> a >> b;
	const auto square = getSquare(a, b);
	cout << "Катет a = " << a << "\nКатет b = " << b << "\nПлощадь S = " << square;
	return 0;
}

double getSquare(const double a, const double b) 
{ 
	return (a * b)/2.0;
}
