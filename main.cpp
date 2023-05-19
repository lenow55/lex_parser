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
#include <exception>
#include <fstream>
#include <iostream>
#include <string>
#include "Context.h"

using std::cout;
using std::cerr;
using std::endl;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "Usage: ./program <in_file>\n";
        return 1;
    }

    const string filename = argv[1];
    LexerContext* mainContext = new LexerContext;
    try {
        mainContext->initState();
        mainContext->initTokenBuilder();
        mainContext->setFile(filename);
        mainContext->processFile();
        mainContext->closeFile();
    }
    catch (std::exception ex) {
        delete mainContext;
        cerr << ex.what() << endl;
    }
    return 0;
}
