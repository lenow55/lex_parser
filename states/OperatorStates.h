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

#pragma once

#include "A_state.h"

class LexerContext;

class OperatorState : public State {
 public:
  ~OperatorState() override {}
  virtual void handle(char, LexerContext*) override;
};


class AssignState : public State {
 public:
  ~AssignState() override {}
  virtual void handle(char, LexerContext*) override;
};
