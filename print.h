#ifndef PRINT_H
#define PRINT_H
#include "constr.h"
// объект для вывода состояния или результата операции
class Printer : public Base {
 public:
  Printer(Base *parent, string Name) : Base(parent, Name){};
  void handlerPRINT(string str);  // метод обработчика сигнала для вывода
                                  // переданного сообщения
  void handlerTurnOff(string str);  // метод обработчика сигнала для вывода
                                    // сообщения о выключении банкомата
};
#endif