#ifndef IDENTIFICETION_H
#define IDENTIFICETION_H
#include "constr.h"
using namespace std;
class Identification : public Base {
 public:
  Identification(Base *parent, string Name) : Base(parent, Name){};
  void signalReadPIN(string &str) {}  // метод сигнала для считывания пин-кода
  void signalCheckPin(string &str) {}  // метод сигнала для проверки пин-кода
  void signalSuccess(string &str) {}  // метод сигнала для проверки состояния
  void handlerIdentificate(string str);  // метод обработчика для отправки
                                         // сигнала для считывания пин-кода
  void handlerPIN(
      string str);  // метод обработчика для проверки корректностипин - кода
  void handlerCORRECT(string str);  // метод обработчика для отправки сигнала
                                    // консоли об успешной авторизации
};
#endif