#include <iostream>
#include <fstream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    
    ifstream input("a1.txt");
    if (!input.is_open()) {
        cerr << "������ �������� ����� a1.txt" << endl;
        return 1;
    }

   
    ofstream output("a2.txt");
    if (!output.is_open()) {
        cout << "������ �������� ����� a2.txt" << endl;
        input.close();
        return 1;
    }

    double number;
    bool first_number = true;
    double min_val, max_val;

    // ���� min/max
    output << "���������� ����� a1.txt:" << endl;
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
    output << "����������� ��������: " << min_val << endl;
    output << "������������ ��������: " << max_val << endl;
    output << "����� ������������ � ������������� ��������: " << sum << endl;


    cout << "���������� ��������� � ���� a2.txt:" << endl;
    cout << "����������� ��������: " << min_val << endl;
    cout << "������������ ��������: " << max_val << endl;
    cout << "�����: " << sum << endl;

    input.close();
    output.close();

    return 0;
}