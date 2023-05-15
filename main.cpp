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
///**
// * Базовый класс Состояния объявляет методы, которые должны реализовать все
// * Конкретные Состояния, а также предоставляет обратную ссылку на объект
// * Контекст, связанный с Состоянием. Эта обратная ссылка может использоваться
// * Состояниями для передачи Контекста другому Состоянию.
// */
//
//class ConcreteStateA : public State {
// public:
//  void Handle1() override;
//
//  void Handle2() override {
//    std::cout << "ConcreteStateA handles request2.\n";
//  }
//};
//
//class ConcreteStateB : public State {
// public:
//  void Handle1() override { std::cout << "ConcreteStateB handles request1.\n";
//  }
//  void Handle2() override {
//    std::cout << "ConcreteStateB handles request2.\n";
//    std::cout << "ConcreteStateB wants to change the state of the context.\n";
//    this->context_->TransitionTo(new ConcreteStateA);
//  }
//};
//
//void ConcreteStateA::Handle1() {
//  {
//    std::cout << "ConcreteStateA handles request1.\n";
//    std::cout << "ConcreteStateA wants to change the state of the context.\n";
//
//    this->context_->TransitionTo(new ConcreteStateB);
//  }
//}
//
///**
// * Клиентский код.
// */
//void ClientCode() {
//  LexerContext *context = new LexerContext(new ConcreteStateA);
//  context->Request1();
//  context->Request2();
//  delete context;
//}

int main() {
  return 0;
}
