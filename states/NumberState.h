#pragma once

#include "A_state.h"

class LexerContext;

class NumberState : public State {
 public:
  ~NumberState() override {}
  virtual void handle(char, LexerContext*) override;
};

