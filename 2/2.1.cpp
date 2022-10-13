#include <iostream>
using namespace std;

/**
 * \brief Считывает переменную из консоли.
 * \param message Побуждающее сообщение для пользователя.
 * \return Значение переменной.
 */

double getVariable(const string& message);

/**
 * \brief Определяет сумму чисел a и b.
 * \param a Значение пермененной a.
 * \param b Значение переменной b.
 * \return Сумма a и b.
 */

const double getSumm(const double a, const double b);

/**
 * \brief Определяет разность чисел a и b.
 * \param a Значение пермененной a.
 * \param b Значение переменной b.
 * \return Разность a и b.
 */

const double getDiff(const double a, const double b);

/**
 * \brief Определяет среднее арифметическое значение чисел a и b.
 * \param a Значение пермененной a.
 * \param b Значение переменной b.
 * \return Среднее арифметическое значение a и b.
 */

const double getAv(const double a, const double b);


enum class userInput
{
    SUMM,
    DIFF,
    AVG
};

int main()
{
    double a = getVariable("Введите значение перменной a: ");
    double b = getVariable("Введите значение перменной b: ");
    cout << "Введите число, соответствующее заданию:\n"
    << static_cast<int>(userInput::SUMM) << " - Вычисляет сумму чисел a и b.\n"
    << static_cast<int>(userInput::DIFF) << " - Вычисляет разность чисел a и b.\n"
    << static_cast<int>(userInput::AVG) << " - Вычисляет среднее арифметическое значение чисел a и b.\n";

    int input = 0;
    cin >> input;
    const auto choice = static_cast<userInput>(input);
    cout << "\n";

    switch(choice)
    {
        case userInput::SUMM:
        {
            const double t = getSumm(a, b);
            cout << "Сумма равна = " << t << endl;
            break;
        }

        case userInput::DIFF:
        {
            const double t = getDiff(a, b);
            cout << "Разность a - b = " << t << endl;
            cout << "Разность b - a = " << (-1)*t << endl;
            break;
        }
        case userInput::AVG:
        {
            const double t = getAv(a, b);
            cout << "Среднее арифметическое a и b = " << t << endl;
            break;
        }
    }

    return 0;
}

double getVariable(const string& message)
{
    cout << message;
    double variable = 0.0;
    cin >> variable;
    return variable;
}

const double getSumm(const double a, const double b)
{
    return (a + b);
}

const double getDiff(const double a, const double b)
{
    return (a - b);
}

const double getAv(const double a, const double b)
{
    const double t = (a + b) / 2.0;
    return t;
}
