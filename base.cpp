#include "base.h"

#include "console.h"
#include "identification.h"
#include "issuance.h"
#include "print.h"
#include "read.h"
#include "receive.h"
using namespace std;
void cl_application::build_tree_objects() {
  // инициализация объектов
  Reader *reader =
      new Reader(this, "Reader");  // объект для чтения команд и данных
  Console *console = new Console(
      this, "Console");  // объект для обработки сигналов - нажатия кнопок
  Identification *identification =
      new Identification(this, "Identifier");  // объект идентификации карты
  Receiver *receiver = new Receiver(this, "Receiver");  // объект для приема
                                                        // денег
  Issuancer *issuancer =
      new Issuancer(this, "Issuanser");  // объект для выдачи денег
  Printer *printer = new Printer(
      this, "Printer");  // объект для вывода состояния или результата
  // установка соединения
  TYPE_SIGNAL signal;
  TYPE_HANDLER handler;
  // сигналы
  signal = SIGN(cl_application::signalReadNEWcommand);
  handler = HAND(Reader::handlerReadNEWcommand);
  Connection(reader, signal, handler);
  signal = SIGN(cl_application::signalSETup);
  handler = HAND(Reader::handlerSETup);
  Connection(reader, signal, handler);
  signal = SIGN(cl_application::signalPRINT);
  handler = HAND(Printer::handlerPRINT);
  Connection(reader, signal, handler);
  signal = SIGN(cl_application::signalCORRECT);
  handler = HAND(Identification::handlerCORRECT);
  Connection(identification, signal, handler);
  signal = SIGN(Reader::signalCONSOLE);
  handler = HAND(Console::handlerText);
  reader->Connection(console, signal, handler);
  signal = SIGN(Reader::signalADDuser);
  handler = HAND(cl_application::handlerADDuser);
  reader->Connection(this, signal, handler);
  signal = SIGN(Reader::signalMONEY);
  handler = HAND(cl_application::handlerMONEY);
  reader->Connection(this, signal, handler);
  signal = SIGN(Reader::signalPRINT);
  handler = HAND(Printer::handlerPRINT);
  reader->Connection(printer, signal, handler);
  signal = SIGN(Reader::signalPIN);
  handler = HAND(Identification::handlerPIN);
  reader->Connection(identification, signal, handler);
  signal = SIGN(Reader::signalNOT);
  handler = HAND(Console::handlerNOT);
  reader->Connection(console, signal, handler);
  signal = SIGN(Console::signalReadNEWcommand);
  handler = HAND(Reader::handlerReadNEWcommand);
  console->Connection(reader, signal, handler);
  signal = SIGN(Console::signalTurnOff);
  handler = HAND(Printer::handlerTurnOff);
  console->Connection(printer, signal, handler);
  signal = SIGN(Console::signalPRINT);
  handler = HAND(Printer::handlerPRINT);
  console->Connection(printer, signal, handler);
  signal = SIGN(Console::signalDeposit);
  handler = HAND(Receiver::handlerDeposit);
  console->Connection(receiver, signal, handler);
  signal = SIGN(Console::signalEndDeposit);
  handler = HAND(Receiver::handlerEndDeposit);
  console->Connection(receiver, signal, handler);
  signal = SIGN(Console::signalDrawMoney);
  handler = HAND(Issuancer::handlerDrawMoney);
  console->Connection(issuancer, signal, handler);
  signal = SIGN(Console::signalIdentificate);
  handler = HAND(Identification::handlerIdentificate);
  console->Connection(identification, signal, handler);
  signal = SIGN(Console::signalShowTree);
  handler = HAND(cl_application::handlerShowTree);
  console->Connection(this, signal, handler);
  signal = SIGN(Receiver::signalDepositToCard);
  handler = HAND(cl_application::handlerDepositToCard);
  receiver->Connection(this, signal, handler);
  signal = SIGN(Receiver::signalBalance);
  handler = HAND(cl_application::handlerBalance);
  receiver->Connection(this, signal, handler);
  signal = SIGN(Receiver::signalPRINT);
  handler = HAND(Printer::handlerPRINT);
  receiver->Connection(printer, signal, handler);
  signal = SIGN(Receiver::signalADD);
  handler = HAND(cl_application::handlerADD);
  receiver->Connection(this, signal, handler);
  signal = SIGN(Issuancer::signalWithdrawMoneyToApp);
  handler = HAND(cl_application::handlerWithdrawMoneyToApp);
  issuancer->Connection(this, signal, handler);
  signal = SIGN(Identification::signalReadPIN);
  handler = HAND(Reader::handlerReadPIN);
  identification->Connection(reader, signal, handler);
  signal = SIGN(Identification::signalCheckPin);
  handler = HAND(cl_application::handlerCheckPin);
  identification->Connection(this, signal, handler);
  signal = SIGN(Identification::signalSuccess);
  handler = HAND(Console::handlerSuccess);
  identification->Connection(console, signal, handler);
  signal = SIGN(Identification::signalPRINT);
  handler = HAND(Printer::handlerPRINT);
  identification->Connection(printer, signal, handler);
}
int cl_application::exec_app() {  // обработка вводимых команд, отправление
                                  // сигналов
  emitSignal((TYPE_SIGNAL)(&cl_application::signalSETup));
  emitSignal((TYPE_SIGNAL)(&cl_application::signalReadNEWcommand));
  return 0;
}
void cl_application::handlerADDuser(
    string str) {  // обработчик сигнала для добавления нового пользователя
  string card = str.substr(0, 19);
  string pin = str.substr(20, 4);
  int balance = stoi(str.substr(25));
  users.push_back({card, pin, balance});
}
void cl_application::handlerMONEY(
    string str) {  // обработчик сигнала для добавления информации о купюрах
  money.amount0f5000 = stoi(str.substr(0, str.find(' ')));

  str = str.substr(str.find(' ') + 1);
  money.amount0f2000 = stoi(str.substr(0, str.find(' ')));
  str = str.substr(str.find(' ') + 1);
  money.amount0f1000 = stoi(str.substr(0, str.find(' ')));
  str = str.substr(str.find(' ') + 1);
  money.amount0f500 = stoi(str.substr(0, str.find(' ')));
  str = str.substr(str.find(' ') + 1);
  money.amount0f100 = stoi(str.substr(0, str.find(' ')));
}
void cl_application::handlerADDuser(
    string str) {  // обработчик сигнала для добавления нового пользователя
  string card = str.substr(0, 19);
  string pin = str.substr(20, 4);
  int balance = stoi(str.substr(25));
  users.push_back({card, pin, balance});
}
void cl_application::handlerMONEY(
    string str) {  // обработчик сигнала для добавления информации о купюрах
  money.amount0f5000 = stoi(str.substr(0, str.find(' ')));
  str = str.substr(str.find(' ') + 1);
  money.amount0f2000 = stoi(str.substr(0, str.find(' ')));
  str = str.substr(str.find(' ') + 1);
  money.amount0f1000 = stoi(str.substr(0, str.find(' ')));
  str = str.substr(str.find(' ') + 1);
  money.amount0f500 = stoi(str.substr(0, str.find(' ')));
  str = str.substr(str.find(' ') + 1);
  money.amount0f100 = stoi(str.substr(0, str.find(' ')));
}

void cl_application::handlerDepositToCard(string str) {
  for (int i = 0; i < users.size(); ++i) {
    if (users[i].card == str.substr(0, 19)) {
      users[i].balance += stoi(str.substr(19));
    }
  }
}

void cl_application::handlerBalance(string str) {
  for (int i = 0; i < users.size(); ++i) {
    if (users[i].card == str)
      emitSignal((TYPE_SIGNAL)(&cl_application::signalPRINT),
                 "Card balance " + to_string(users[i].balance));
  }
}

void cl_application::handlerWithdrawMoneyToApp(string str) {
  string card = str.substr(0, 19);
  int sum = stoi(str.substr(19));
  int tmpSum = sum;
  if (sum > getCurrentSum()) {
    emitSignal((TYPE_SIGNAL)(&cl_application::signalPRINT),
               "There is not enough money in the ATM");
    return;
  }
  for (int i = 0; i < users.size(); ++i) {
    if (users[i].card == card) {
      if (users[i].balance < sum) {
        emitSignal((TYPE_SIGNAL)(&cl_application::signalPRINT),
                   "There is not enough money on the card");
        return;
      }
    }
  }
  vector<int> withdrawMoney = {0, 0, 0, 0, 0};
  while (sum > 0) {
    if (sum >= 5000) {
      sum -= 5000;
      withdrawMoney[0] += 1;
    } else if (sum >= 2000) {
      sum -= 2000;
      withdrawMoney[1] += 1;
    } else if (sum >= 1000) {
      sum -= 1000;
      withdrawMoney[2] += 1;
    } else if (sum >= 500) {
      sum -= 500;
      withdrawMoney[3] += 1;
    } else if (sum >= 100) {
      sum -= 100;
      withdrawMoney[4] += 1;
    } else {
      emitSignal((TYPE_SIGNAL)(&cl_application::signalPRINT),
                 "There is not enough money in the ATM");
      return;
    }
  }
  if (money.amount0f2000 < withdrawMoney[0] money.amount0f2000 <
          withdrawMoney[1] ||
      money.amount0f1000 < withdrawMoney[2] ||
      money.amount0f500 < withdrawMoney[3] ||
      money.amount0f100 < withdrawMoney[4]) {
    emitSignal((TYPE_SIGNAL)(&cl_application::signalPRINT),
               "There is not enough money in the ATM");
    return;
  }

  emitSignal((TYPE_SIGNAL)(&cl_application::signalPRINT),
             "Take the money: 5000 * " + to_string(withdrawMoney[0]) +
                 " rub., 2000 * " + to_string(withdrawMoney[1]) +
                 " rub., 1000 * " + to_string(withdrawMoney[2]) +
                 " rub., 500 * " + to_string(withdrawMoney[3]) +
                 " rub., 100 *" + to_string(withdrawMoney[4]) + " rub.");
  // вычет из баланса
  for (int i = 0; i < users.size(); ++i) {
    if (users[i].card == card) {
      users[i].balance -= tmpSum;
    }
  }
}

int cl_application::getCurrentSum() {
  // возврат текущей суммы денег
  return money.amount0f100 * 100 + money.amount0f500 * 500 +
         money.amount0f1000 * 1000 + money.amount0f 2000 * 2000 +
         money.amount0f 5000 * 5000;
}
void cl_application::handlerCheckPin(string str) {
  string pin = str.substr(0, 4);
  string card = str.substr(4);
  for (int i = 0; i < users.size(); ++i) {
    if (users[i].card == card) {
      if (users[i].pin == pin)
        emitSignal((TYPE_SIGNAL)(&cl_application::signalCORRECT));
      return;
    }
  }
}
void cl_application::handlerShowTree(string str) {
  printWithState("");
  cout << endl;
}
void cl_application::handlerADD(string str) {
  if (str == "5000") money.amount0f5000 += 1;
  if (str == "2000") money.amount0f2000 += 1;
  if (str == "1000") money.amount0f1000 += 1;
  if (str == "500") money.amount0f500 += 1;
  if (str == "100") money.amount0f100 += 1;
}