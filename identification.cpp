#include "identification.h"
using namespace std;
void Identification::handlerIdentificate(string str) {
emitSignal((TYPE_SIGNAL) (&Identification::signalPRINT),"Enter the PIN
code");
      emitSignal((TYPE_SIGNAL) (&Identification::signalReadPIN),str);
}
void Identification::handlerPIN(string str) {
  emitSignal((TYPE_SIGNAL)(&Identification::signalCheckPin), str);
}
void Identification::handlerCORRECT(string str) {
  emitSignal((TYPE_SIGNAL)(&Identification::signalPRINT), "Select the command");
  emitSignal((TYPE_SIGNAL)(&Identification::signalSuccess));
}