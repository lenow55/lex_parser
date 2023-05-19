#pragma once

#include "A_state.h"

class LexerContext;

class IdentifierState : public State {
 public:
  ~IdentifierState() override {}
  virtual void handle(char, LexerContext*) override;
};

