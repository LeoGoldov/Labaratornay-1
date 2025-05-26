#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// ������ ������� �� �����
vector<vector<int>> read_mat(ifstream& f, int rows, int cols) {
    vector<vector<int>> mat(rows, vector<int>(cols));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            f >> mat[i][j]; // ������ ������ ����� ������
        }
    }
    return mat;
}

// ��������� ���� �� ����� ������� ��� � ������
bool is_inside(vector<vector<vector<int>>> all_mats, vector<vector<int>> one_mat) {
    for (auto m : all_mats) {
        if (m == one_mat) { // ���� ����� ����� ��
            return true;
        }
    }
    return false; // ���� �� �����
}

int main() {
    // ����� ������� ���� �������
    setlocale(LC_ALL, "Russian");

    // ��������� ������ ����
    ifstream f1;
    f1.open("file1.txt");
    if (!f1) {
        cout << "�� ���������� ������� file1.txt!" << endl;
        return 1;
    }

    // ������ ������� ������ � �� ������
    int k, m, n;
    f1 >> k >> m >> n;

    // ��� ����� ������� ��� ������� �� 1 �����
    vector<vector<vector<int>>> mats1;

    // ������ k ������
    for (int i = 0; i < k; i++) {
        mats1.push_back(read_mat(f1, m, n));
    }
    f1.close();

    //  ������ ����
    ifstream f2;
    f2.open("file2.txt");
    if (!f2) {
        cout << "�� ���������� ������� file2.txt!" << endl;
        return 1;
    }

    int l;
    f2 >> l >> m >> n;

    // ������� �� ������� �����
    vector<vector<vector<int>>> mats2;

    for (int i = 0; i < l; i++) {
        mats2.push_back(read_mat(f2, m, n));
    }
    f2.close();

    // ��������� � mats2 �� ���� ���
    for (auto mat : mats1) {
        if (!is_inside(mats2, mat)) {
            mats2.push_back(mat);
            l++; // ����������� �������
        }
    }

    // ���������� ������� �� ������ ����
    ofstream f2_out;
    f2_out.open("file2.txt");
    if (!f2_out) {
        cout << "�� ���������� �������� � file2.txt!" << endl;
        return 1;
    }

    // ������� �����������
    f2_out << l << " " << m << " " << n << endl;

    // ����� ��� �������
    for (auto mat : mats2) {
        for (auto row : mat) {
            for (int x : row) {
                f2_out << x << " ";
            }
            f2_out << endl;
        }
        f2_out << endl; // ������ ������ ����� ���������
    }
    f2_out.close();

    // ������� ��� ����������
    cout << "� ������ ����� ����:" << endl;
    cout << k << " " << m << " " << n << endl;
    for (auto mat : mats1) {
        for (auto row : mat) {
            for (int x : row) {
                cout << x << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    cout << "�� ������ ����� ������:" << endl;
    cout << l << " " << m << " " << n << endl;
    for (auto mat : mats2) {
        for (auto row : mat) {
            for (int x : row) {
                cout << x << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}