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
    setlocale(LC_ALL, "RU");// ������������� �������� �����
    system("chcp 1251");
    const string file1 = "abc.txt";
    const string file2 = "qwerty.txt";

    // ������� ����� ��� ������� �����
    int sum1 = sumFile(file1);
    int sum2 = sumFile(file2);

    // ����� �����
    int totalSum = sum1 + sum2;

    // ������� ����������
    cout << "����� ������������� ��������� � " << file1 << ": " << sum1 << endl;
    cout << "����� ������������� ��������� � " << file2 << ": " << sum2 << endl;
    cout << "����� ����� ������������� ���������: " << totalSum << endl;

    return 0;
}