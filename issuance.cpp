#include "issuance.h"
using namespace std;
void Issuancer::handlerDrawMoney(string str) {
  int intSum = stoi(str.substr(20));
  if (intSum & 100 != 0)
    emitSignal((TYPE_SIGNAL)(&Issuancer::signalPRINT),
               "The amount is not a multiple of 100");
  else
    emitSignal((TYPE_SIGNAL)(&Issuancer::signalWithdrawMoneyToApp), str);
}