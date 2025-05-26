#include <iostream>
#include <fstream>
using namespace std;

double sumFile(const string& filename) {
    ifstream in(filename);
    double sum = 0.0;
    double number;

    while (in >> number) {
        if (number > 0) {
            sum += number;
        }
    }

    in.close();
    return sum;
}

int main()
{
    setlocale(LC_ALL, "RU");// использование русского языка
    system("chcp 1251");
    const string file1 = "abc.txt";
    const string file2 = "qwerty.txt";

    // Считаем сумму для каждого файла
    int sum1 = sumFile(file1);
    int sum2 = sumFile(file2);

    // Общая сумма
    int totalSum = sum1 + sum2;

    // Выводим результаты
    cout << "Сумма положительных элементов в " << file1 << ": " << sum1 << endl;
    cout << "Сумма положительных элементов в " << file2 << ": " << sum2 << endl;
    cout << "Общая сумма положительных элементов: " << totalSum << endl;

    return 0;
}