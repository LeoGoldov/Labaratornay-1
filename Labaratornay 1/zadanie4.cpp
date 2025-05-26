#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int countPositions(const string& filename) {
    ifstream file(filename);
    int count = 0;
    int number;
    int position = 1; // Позиции считаем с 1 (как в обычном понимании)

    if (!file.is_open()) {
        cout << "Ошибка открытия файла: " << filename << endl;
        return -1; // Возвращаем -1 в случае ошибки
    }

    while (file >> number) {
        if (position % 2 != 0 && number < 0) {
            count++;
        }
        position++;
    }

    file.close();
    return count;
}

int main() {
    setlocale(LC_ALL, "RU");// использование русского языка
    system("chcp 1251");
    string filename = ("c.txt");

    int result = countPositions(filename);

    if (result != -1) {
        cout << "Количество отрицательных чисел на нечетных позициях: " << result << endl;
    }

    return 0;
}