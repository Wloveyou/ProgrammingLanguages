#include <iostream>
#include <cmath>
#include <limits>
using namespace std;

/**
 * \breaf Проверка y при заданоом x.
 * @param x Параметр функциию
 * @return true Если y существует при заданном x.
 */
bool IsExists(const double x);

/**
 * /breaf Функиця расчета по заданной формуле
 * @param x Параметр функции
 * @return true Если y существует при заданном x.
 */
double Calculation(const double x);

/**
 * /breaf Точка входа в прогрраму.
 * @return Возвращает 0 в случае успешного выполнения.
 */
int main()
{
    const double xStart = 1;
    const double xFinish = 2;
    const double step = 0.1;
    double x = xStart;

    while(x < xFinish + step )
    {
        if (IsExists(x))
        {
            const double y = Calculation(x);
            cout << x << " " << "\n";
        } else
        {
            cout << x << " " << "Нет значения \n";
        }
        x += step;
    }

    return 0;
}

bool IsExists(const double x)
{
    return (abs(cos(x)) > numeric_limits<double>::min());

}

double Calculation (const double x)
{
    return (cos(x) - exp(-(pow(x,2))/2) + x - 1);
}
