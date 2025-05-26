#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int main() {
    system("chcp 1251");
    setlocale(LC_ALL, "Russian");

    // Открытие файла с данными
    ifstream input("customers.txt");
    ofstream output("stavropol_customerc.txt");
    if (!input.is_open()) {
        cout << "Ошибка открытия файла customers.txt" << endl;
        return 1;
    }

    cout << "Покупатели из Ставрополя:" << endl;
    cout << "-------------------------" << endl;

    string line;
    while (getline(input, line)) {
        // Разбиваем строку на поля
        stringstream ss(line);
        string field;
        vector<string> fields;
        while (getline(ss, field, ';')) {
            fields.push_back(field);
        }

        // Проверяем поля
        if (fields.size() < 19) {
            cerr << "Недостаточно полей в строке: " << line << endl;
            continue;
        }

        // Проверяем Ставрополь
        if (fields[15] == "Ставрополь") {

           
            cout << fields[0] << " " << fields[1] << " " << fields[2] << ", тел.: " << fields[10] << endl;

          
            output << fields[0] << ";" << fields[1] << ";" << fields[2] << ";"
                << fields[3] << ";" << fields[10] << ";"
                << fields[15] << ", " << fields[16] << ", " << fields[17] << "-" << fields[18] << endl;
        }
    }

    input.close();
    output.close();

    cout << "-------------------------" << endl;
    cout << "Результаты сохранены в файл stavropol_customers.txt" << endl;

    return 0;
}