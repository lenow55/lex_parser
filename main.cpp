/* Fig.: main
 * ======================================================
 * Filename: main.cpp
 * =====================================================
 * Abstract: Основной исполняемый модуль
 * лаборатоной лексическому анализатору
 * Description: парсит входной файл и выводит файл-таблицу
 * лексем
 * Author: Новиков Илья
 * Platform: Linux
 ==================================================== */

#include "A_state.h"
#include <fstream>
#include <iostream>
#include "Context.h"

using std::cout;

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cout << "Usage: ./program <in_file> <out_file>\n";
        return 1;
    }

    const char* filename = argv[1];
    std::ifstream file(filename);

    if (!file.is_open()) {
        cout << "Failed to open file: " << filename << "\n";
        return 1;
    }

    char ch;
    while (file.good()) {
        cout << ch;
    }

    file.close();
    return 0;
}
