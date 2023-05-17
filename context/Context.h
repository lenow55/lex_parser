/**
 * Контекст определяет интерфейс, представляющий интерес для клиентов. Он также
 * хранит ссылку на экземпляр подкласса Состояния, который отображает текущее
 * состояние Контекста.
 */

#pragma once

#include "TokenBuilder.h"
#include <cstddef>

using std::size_t;

class State;
class TokenBuilder;

class LexerContext {
  /**
   * @var State Ссылка на текущее состояние Контекста.
   */
 private:
  State *state_;
  size_t line_number_;
  size_t column_number_;
  TokenBuilder *token_builder_;

 public:
  LexerContext() : state_(nullptr), line_number_(0), column_number_(0),
    token_builder_(nullptr){}
  LexerContext(State *state) : state_(nullptr), line_number_(0), column_number_(0) {
    this->TransitionTo(state);
  }
  ~LexerContext() {
    delete state_;
    delete token_builder_;
  }
  /**
   * Контекст позволяет изменять объект Состояния во время выполнения.
   */
  void TransitionTo(State *state) {
    std::cout << "Context: Transition to " << typeid(*state).name() << ".\n";
    if (this->state_ != nullptr)
      delete this->state_;
    this->state_ = state;
    this->state_->set_context(this);
  }
  /**
   * Контекст делегирует часть своего поведения текущему объекту Состояния.
   */
  void Request1() {
    this->state_->Handle1();
  }
};

