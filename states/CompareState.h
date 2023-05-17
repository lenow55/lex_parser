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

class AssignOperatorStateFirst : public State {
 public:
  ~AssignOperatorStateFirst() override {}
  virtual void handle(char, LexerContext*) override;
};



class AssignOperatorStateSecond : public State {
 public:
  ~AssignOperatorStateSecond() override {}
  virtual void handle(char, LexerContext*) override;
};

