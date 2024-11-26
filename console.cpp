#include "console.h"
using namespace std;
void Console::handlerText(string str) {
  string operation = str.substr(0, str.find(' '));
  if (operation == "Identification") {
    currentCard = str.substr(str.find(' ') + 1);
    emitSignal((TYPE_SIGNAL)(&Console::signalIdentificate), currentCard);
  } else if (operation == "SHOWTREE") {
    emitSignal((TYPE_SIGNAL)(&Console::signalShowTree));
    return;
  } else if (operation == "Turn") {
    emitSignal((TYPE_SIGNAL)(&Console::signalTurnOff));
    return;
  } else {
    if (!isAuth) {
      emitSignal((TYPE_SIGNAL)(&Console::signalPRINT), "Ready to work");

      else {
        if (operation == "End") {
          emitSignal((TYPE_SIGNAL)(&Console::signalPRINT), "Ready to work");
          isAuth = false;
        }

        if (operation == "Deposit") {
          if (str.substr(14, 2) == "to") {
            emitSignal((TYPE_SIGNAL)(&Console::signalEndDeposit), currentCard);
          } else {
            emitSignal((TYPE_SIGNAL)(&Console::signalDeposit), str.substr(14));
          }
        } else if (operation == "Withdraw") {
          emitSignal((TYPE_SIGNAL)(&Console::signalDrawMoney),
                     currentCard + str.substr(15));
        }
      }
    }
    emitSignal((TYPE_SIGNAL)(&Console::signalReadNEWcommand));
  }
  void Console::handlerSuccess(string str) { isAuth = true; }
  void Console::handlerNOT(string str) { isAuth = false; }