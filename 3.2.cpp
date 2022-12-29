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
double getSumE(const double e); 
 
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
    cout << "\nСумма членов не меньших числа е: " << getSumE(e) << endl; 
 
    return 0; 
} 
 
double getCurrentNum(const size_t k) 
{ 
    return 1.0*(k + 2) / (k + 3) * (1 + k); 
} 
 
double getSumN(const int n) 
{ 
    double sum = 0.0; 
    for (size_t k = 1; k <= n; k++) 
    { 
        sum = sum + getCurrentNum(k); 
    } 
 
    return sum; 
} 
 
double getSumE(const double e) 
{ 
    int k = 1;
    double sum = 0; 
    double current = getCurrentNum(k); 
 
    while (abs(current) > e) 
    { 
        sum += current; 
        k += 1; 
    } 
 
    return sum; 
}
