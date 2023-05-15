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

class ConcreteStateA : public State {
 public:
  void Handle() override {
    std::cout << "ConcreteStateA handles request2.\n";
  }
};
