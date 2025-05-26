#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

void removeExtraSpaces(const string& inputFile, const string& outputFile) {
    ifstream in(inputFile);
    ofstream out(outputFile);


    char current, previous = '\0';
    bool spaceFlag = false;

    while (in.get(current)) {
        if (isspace(current)) {
            if (!spaceFlag && !(previous == '\0' || ispunct(previous))) {
                out << ' ';
                spaceFlag = true;
            }
        }
        else {
            out << current;
            spaceFlag = false;
        }
        previous = current;
    }

    in.close();
    out.close();
}

int main() {
    setlocale(LC_ALL, "RU");// использование русского языка
    system("chcp 1251");

    string inputFileName = "a.txt";
    string outputFileName = "b.txt";

    removeExtraSpaces(inputFileName, outputFileName);

    cout << "Файл успешно обработан. Результат в " << outputFileName << endl;
    return 0;
}