#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian"); 
    system("chcp 1251");

    ifstream in;

    in.open("abc.txt");
    if (!in.is_open()) {
        cout << "Ошибка открытия файла!" << endl;
        return 1;
    }

    double number;
    int count5 = 0;
    double sum = 0;

    while (in >> number) {
        if (number == 5.0) {
            count5++;
        }
        if (number > 0) {
            sum += number;
        }
    }  

    in.close();

    cout << "Количество элементов, равных 5: " << count5 << endl;
    cout << "Сумма положительных элементов: " << sum << endl;

    return 0;
}
