#ifndef ISSUANCE_H
#define ISSUANCE_H
#include "constr.h"
// объект для выдачи денег, который выдает сигнал, содержащий количество купюр
// возвращаемой суммы или информацию о возможности ее получения
class Issuancer : public Base {
 public:
  Issuancer(Base *parent, string Name) : Base(parent, Name){};
  void signalWithdrawMoneyToApp(string &str) {
  }  // метод сигнала для выдачи денег
  void handlerDrawMoney(
      string str);  // метод обработчика сигнала для отправки сигнала системе
};
#endif