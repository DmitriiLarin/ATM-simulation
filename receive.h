#ifndef RECEIVER_H
#define RECEIVER_H
#include "constr.h"
class Receiver : public Base {
  int currentDeposit = 0;

 public:
  Receiver(Base *parent, string Name) : Base(parent, Name){};
  void signalDepositToCard(string &str) {}  // для добавления суммы набаланс
  void signalBalance(string &str) {}  // для получения баланса
  void signalADD(string &str) {}
  void handlerDeposit(string str);  // для добавления суммы на депозит
  void handlerEndDeposit(string str);  // для внесения обзей суммы
};
#endif