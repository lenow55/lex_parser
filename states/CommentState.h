#include "A_state.h"

class CommentOperatorState : public State {
    public:
        ~CommentOperatorState() override {}
        virtual void handle(char, LexerContext*) override;
};

class CommentState : public State {
    public:
        ~CommentState() override {}
        virtual void handle(char, LexerContext*) override;
};

class CommentEndState : public State {
    public:
        ~CommentEndState() override {}
        virtual void handle(char, LexerContext*) override;
};
