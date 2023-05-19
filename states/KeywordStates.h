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

//по букве e
class Else1State : public State {
 public:
  ~Else1State() override {}
  virtual void handle(char, LexerContext*) override;
};

//по el
class Else2State : public State {
 public:
  ~Else2State() override {}
  virtual void handle(char, LexerContext*) override;
};

//по els
class Else3State : public State {
 public:
  ~Else3State() override {}
  virtual void handle(char, LexerContext*) override;
};

//по else
class Else4State : public State {
 public:
  ~Else4State() override {}
  virtual void handle(char, LexerContext*) override;
};

//по i
class If1State : public State {
 public:
  ~If1State() override {}
  virtual void handle(char, LexerContext*) override;
};

//по if
class If2State : public State {
 public:
  ~If2State() override {}
  virtual void handle(char, LexerContext*) override;
};

//по t
class Then1State : public State {
 public:
  ~Then1State() override {}
  virtual void handle(char, LexerContext*) override;
};

//по th
class Then2State : public State {
 public:
  ~Then2State() override {}
  virtual void handle(char, LexerContext*) override;
};

//по the
class Then3State : public State {
 public:
  ~Then3State() override {}
  virtual void handle(char, LexerContext*) override;
};

//по then
class Then4State : public State {
 public:
  ~Then4State() override {}
  virtual void handle(char, LexerContext*) override;
};
