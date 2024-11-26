#include "receive.h"
void Receiver::handlerDeposit(string str) {
  int sum = stoi(str);
  if (sum % 100 == 0 &&
      (sum == 5000 || sum == 2000 || sum == 1000 || sum == 500 || sum == 100)) {
    currentDeposit += sum;
    emitSignal((TYPE_SIGNAL)(&Receiver::signalADD), str);
    emitSignal((TYPE_SIGNAL)(&Receiver::signalPRINT),
               "The amount: " + to_string(currentDeposit));
  }
}
void Receiver::handlerEndDeposit(string str) {
  emitSignal((TYPE_SIGNAL)(&Receiver::signalDepositToCard),
             str + to_string(currentDeposit));
  emitSignal((TYPE_SIGNAL)(&Receiver::signalBalance), str);
  currentDeposit = 0;
}