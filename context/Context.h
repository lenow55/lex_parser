/**
 * Контекст определяет интерфейс, представляющий интерес для клиентов. Он также
 * хранит ссылку на экземпляр подкласса Состояния, который отображает текущее
 * состояние Контекста.
 */

class State;

class LexerContext {
  /**
   * @var State Ссылка на текущее состояние Контекста.
   */
 private:
  State *state_;

 public:
  LexerContext() : state_(nullptr) {}
  LexerContext(State *state) : state_(nullptr) {
    this->TransitionTo(state);
  }
  ~LexerContext() {
    delete state_;
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

