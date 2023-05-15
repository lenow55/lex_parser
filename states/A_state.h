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

#include <iostream>

class LexerContext;

class State {
  /**
   * @var Context
   */
 protected:
  LexerContext *context_;

 public:
  virtual ~State() {
  }

  void set_context(LexerContext *context) {
    this->context_ = context;
  }

  virtual void Handle() = 0;
};
