#include <iostream> 
#include <string> 
#include <ctime> 
 
using namespace std; 
 
/** 
 * \brief Проверка ввода размера массива. 
 * \return Размер массива. 
 */ 
size_t GetSize(); 
 
/** 
 * \brief Нахождение суммы положительных элементов, значения которых состоят из двух цифр. 
 * \param myArray массив. 
 * \param size размер массива. 
 * \return Cумма положительных элементов, значения которых состоят из двух цифр. 
 */ 
int SumPosElements(const int* myArray, const size_t size); 
 
/** 
 * \brief Заполнение массива случайными числами. 
 * \param size размер массива. 
 * \param minValue минимальное значение элементов массива. 
 * \param maxValue максимальное значение элементов массива. 
 * \return заполненный массив. 
 */ 
int* FillRandomArray(size_t size, int minValue, int maxValue); 
 
/** 
 * \brief Вывод массива на консоль. 
 * \param myArray массив. 
 * \param size размер массива. 
 */ 
void ArrayPrint(const int* myArray, size_t size); 
 
/** 
 * \brief Нахождение номера первой пары соседних элементов с разными знаками, сумма которых меньше заданного числа. 
 * \param myArray массив. 
 * \param size размер массива. 
 * \return Hомер первой пары соседних элементов с разными знаками, сумма которых меньше заданного числа. 
 */ 
int NumPair(const int* myArray, const size_t size); 
 
/** 
 * \brief Умножение всех чётных положительных элементов на последни элемент массива. 
 * \param myArray массив. 
 * \param size размер массива. 
 * \return Массив с четными элементами, умноженными на последний элемент массива. 
 */ 
int* EvenMultiplyLast(int* myArray, const size_t size); 
 
/** 
 * \brief Метод, возвращающий заполненный пользователем массив. 
 * \param size размер массива. 
 * \param minValue минимальное значение элементов массива. 
 * \param maxValue максимальное значение элементов массива. 
 * \return заполненный массив. 
 */ 
int* FillUserArray(size_t size); 
 
/** 
 * \brief Варианы ввода массива. 
 */ 
enum class ArrayInputWay 
{ 
    random, 
    keyboard 
}; 
 
/** 
 * \brief Точка входа в программу. 
 * \return 0, в случае успеха. 
 */ 
int main() 
{ 
    size_t size = GetSize(); 
 
    if (size == 0) 
        return 1; 
         
    cout << "Как вы хотите заполнить массив?\n"; 
    cout << static_cast<int>(ArrayInputWay::random) << " - random,\n"; 
    cout << static_cast<int>(ArrayInputWay::keyboard) << " - keyboard.\n"; 
    cout << "Ваш выбор: "; 
    int choice; 
    cin >> choice; 
         
    const auto chosen = static_cast<ArrayInputWay>(choice); 
    int* myArray = nullptr; 
     
    auto minValue = 0; 
    auto maxValue = 0; 
    cout << "Введите диапазон чисел массива (сначала минимум, потом максимум) " << endl; 
    cin >> minValue >> maxValue; 
    if (maxValue <= minValue) 
    { 
        cout << "Введен неправильный диапазон!" << endl; 
    } 
     
    switch (chosen) 
    { 
    case ArrayInputWay::random: 
    { 
        myArray = FillRandomArray(size, minValue, maxValue); 
        break; 
    } 
    case ArrayInputWay::keyboard: 
    { 
        myArray = FillUserArray(size); 
        break; 
    } 
    } 
     
    ArrayPrint( myArray, size); 
     
    cout << "Сумма положительных элементов, значения которых состоят из двух цифр:" << endl;    
    cout << SumPosElements(myArray, size); 
    cout << endl; 
     
    cout << "Mассив с четными элементами, умноженными на последний элемент массива: "; 
         
    ArrayPrint(EvenMultiplyLast(myArray, size), size); 
     
    cout << "Hомер первой пары соседних элементов с разными знаками, сумма которых меньше заданного числа" << endl; 
    cout << NumPair(myArray,size); 
     
    if (myArray != nullptr) {  
             
        delete[] myArray; 
        myArray = nullptr; 
         
    } 
    return 0; 
     
} 
 
size_t GetSize(){ 
    int size = 0; 
    cout << "Введите размер массива"<< endl; 
    cin >> size; 
    if (size <= 0) 
    { 
        cout<< "Введён неверный размер"; 
        return 0; 
    } 
    else  
     return size; 
}; 
 
int SumPosElements(const int* myArray, const size_t size){ 
    auto sum = 0;
for (size_t index = 0; index < size; index++){ 
        if ((myArray[index] > 0) && (myArray[index] / 100 == 0) && (myArray[index] / 10 != 0 )) { 
            sum = sum + myArray[index]; 
        } 
    } 
    return sum; 
} 
 
int NumPair(const int* myArray, const size_t size ) { 
    int num = 0; 
    int digit = 0; 
    cout << "Введите число" << endl; 
    for (size_t index = 1; index < size; index = index + 2) { 
        num+=1; 
        if (( myArray[index-1] * myArray[index] < 0) && (myArray[index-1] + myArray[index] < digit) ) { 
            break; 
        } 
    } 
    return num; 
} 
 
int* EvenMultiplyLast(int* myArray, const size_t size ) 
{ 
    if (myArray == nullptr) 
        cout << "Массив пуст"; 
 
    for (size_t index = 0; index < size; index++) { 
        if (myArray[index] % 2 == 0) { 
            myArray[index] = myArray[index] * myArray[size-1]; 
        } 
    } 
    return myArray; 
     
} 
 
void ArrayPrint(const int* myArray, const size_t size) 
{ 
    if (myArray == nullptr) 
    { 
        cout << "Массива не существует"; 
    } 
    else { 
        cout << "\nМассив:\n"; 
        for (size_t index = 0; index < size; index++) { 
            cout << myArray[index] << " "; 
        } 
        cout << "\n"; 
 
    } 
} 
 
int* FillRandomArray(const size_t size, const int minValue, const int maxValue) 
{ 
    srand(time(NULL)); 
    const auto area = abs(minValue) + abs(maxValue) + 1; 
    auto* array = new int[size]; 
    for (size_t index = 0; index < size; index++) { 
        array[index] = rand() % area + minValue; 
        cout << array[index] << endl; 
    } 
 
    return array; 
} 
 
int* FillUserArray(const size_t size) 
{ 
    auto* array = new int[size]; 
    cout << "Введите элементы массива" << "\n"; 
    for (size_t index = 0; index < size; index++) 
    { 
        cin >> array[index]; 
    } 
    return array; 
}
