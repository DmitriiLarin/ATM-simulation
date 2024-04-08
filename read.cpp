#include "read.h"
void Reader::handlerReadNEWcommand(string str) {
  string t;
  getline(cin, t);
  emitSignal((TYPE_SIGNAL)(&Reader::signalCONSOLE), t);
}
void Reader::handlerSETup(string str) {
  string t;
  while (true) {
    getline(cin, t);
    if (t == "End card loading") break;
    emitSignal((TYPE_SIGNAL)(&Reader::signalADDuser), t);
  }
  getline(cin, t);
  emitSignal((TYPE_SIGNAL)(&Reader::signalMONEY), t);
  getline(cin, t);
  emitSignal((TYPE_SIGNAL)(&Reader::signalPRINT), "Ready to work");
}
void Reader::handlerReadPIN(string str) {
  string t;
  getline(cin, t);
  if (t.substr(0, 8) != "PIN-code") {
    emitSignal((TYPE_SIGNAL)(&Reader::signalPRINT), "Ready to work");
    emitSignal((TYPE_SIGNAL)(&Reader::signalNOT));
    return;
  }
  string pin = t.substr(9);
  emitSignal((TYPE_SIGNAL)(&Reader::signalPIN), pin + str);
}