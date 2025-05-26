#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// Читаем матрицу из файла
vector<vector<int>> read_mat(ifstream& f, int rows, int cols) {
    vector<vector<int>> mat(rows, vector<int>(cols));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            f >> mat[i][j]; // Просто читаем числа подряд
        }
    }
    return mat;
}

// Проверяем есть ли такая матрица уже в списке
bool is_inside(vector<vector<vector<int>>> all_mats, vector<vector<int>> one_mat) {
    for (auto m : all_mats) {
        if (m == one_mat) { // Если нашли такую же
            return true;
        }
    }
    return false; // Если не нашли
}

int main() {
    // Чтобы русский язык работал
    setlocale(LC_ALL, "Russian");

    // Открываем первый файл
    ifstream f1;
    f1.open("file1.txt");
    if (!f1) {
        cout << "Не получилось открыть file1.txt!" << endl;
        return 1;
    }

    // Читаем сколько матриц и их размер
    int k, m, n;
    f1 >> k >> m >> n;

    // Тут будем хранить все матрицы из 1 файла
    vector<vector<vector<int>>> mats1;

    // Читаем k матриц
    for (int i = 0; i < k; i++) {
        mats1.push_back(read_mat(f1, m, n));
    }
    f1.close();

    //  второй файл
    ifstream f2;
    f2.open("file2.txt");
    if (!f2) {
        cout << "Не получилось открыть file2.txt!" << endl;
        return 1;
    }

    int l;
    f2 >> l >> m >> n;

    // Матрицы из второго файла
    vector<vector<vector<int>>> mats2;

    for (int i = 0; i < l; i++) {
        mats2.push_back(read_mat(f2, m, n));
    }
    f2.close();

    // Добавляем в mats2 то чего нет
    for (auto mat : mats1) {
        if (!is_inside(mats2, mat)) {
            mats2.push_back(mat);
            l++; // Увеличиваем счетчик
        }
    }

    // Записываем обратно во второй файл
    ofstream f2_out;
    f2_out.open("file2.txt");
    if (!f2_out) {
        cout << "Не получилось записать в file2.txt!" << endl;
        return 1;
    }

    // Сначала размерности
    f2_out << l << " " << m << " " << n << endl;

    // Потом все матрицы
    for (auto mat : mats2) {
        for (auto row : mat) {
            for (int x : row) {
                f2_out << x << " ";
            }
            f2_out << endl;
        }
        f2_out << endl; // Пустая строка между матрицами
    }
    f2_out.close();

    // Выводим что получилось
    cout << "В первом файле было:" << endl;
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

    cout << "Во втором файле теперь:" << endl;
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