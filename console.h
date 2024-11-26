#ifndef CONSOLE_H
#define CONSOLE_H
#include "constr.h"
class Console : public Base {
  bool isAuth = false;  // для обработки при правильном пин-коде
  string currentCard;

 public:
  Console(Base *parent, string Name) : Base(parent, Name) {}
  void signalReadNEWcommand(string &str) {}  // метод сигнала для считывания
                                             // новой строки
  void signalTurnOff(string &str) {
  }  // метод сигнала для вывода сообщения о выключении банкомата
  void signalDeposit(string &str) {
  }  // метод сигнала для добавления суммы набаланс пользователя
  void signalEndDeposit(string &str) {
  }  // метод сигнала для окончания внесения денег
  void signalDrawMoney(string &str) {}  // метод сигнала для выдачи денег
  void signalIdentificate(string &str) {}  // метод сигнала для запроса пин-кода
  void signalShowTree(string &str) {
  }  // метод сигнала для вывода иерархии объектов
  void handlerText(string str);  // метод обработчика для обработки новых команд
  void handlerSuccess(string str);  // метод
                                    //  обработчика для установки
                                    //  состоянияаторизированного пользователя
  void handlerNOT(string str);  // метод обработчика для установки состояния не
                                // авторизированного пользователя
};
#endif