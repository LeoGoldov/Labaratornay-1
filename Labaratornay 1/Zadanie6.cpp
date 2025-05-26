#include <iostream>
#include <fstream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    
    ifstream input("a1.txt");
    if (!input.is_open()) {
        cerr << "Ошибка открытия файла a1.txt" << endl;
        return 1;
    }

   
    ofstream output("a2.txt");
    if (!output.is_open()) {
        cout << "Ошибка создания файла a2.txt" << endl;
        input.close();
        return 1;
    }

    double number;
    bool first_number = true;
    double min_val, max_val;

    // ищем min/max
    output << "Содержимое файла a1.txt:" << endl;
    while (input >> number) {
        output << number << " "; 

        if (first_number) {
            min_val = max_val = number;
            first_number = false;
        }
        else {
            if (number < min_val) {
                min_val = number;
            }
            if (number > max_val) {
                max_val = number;
            }
        }
    }
    output << endl << endl;

    
    double sum = min_val + max_val;
    output << "Минимальное значение: " << min_val << endl;
    output << "Максимальное значение: " << max_val << endl;
    output << "Сумма минимального и максимального значений: " << sum << endl;


    cout << "Результаты сохранены в файл a2.txt:" << endl;
    cout << "Минимальное значение: " << min_val << endl;
    cout << "Максимальное значение: " << max_val << endl;
    cout << "Сумма: " << sum << endl;

    input.close();
    output.close();

    return 0;
}