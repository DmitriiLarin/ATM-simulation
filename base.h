#ifndef APPLICATION_H
#define APPLICATION_H
#include "constr.h"
class cl_application : public Base {
  struct User {
    string card, pin;
    int balance = 0;
  };
  vector<User> users;
  struct Money {
    int amount0f5000 = 0;
    int amount0f2000 = 0;
    int amount0f1000 = 0;
    int amount0f500 = 0;
    int amount0f100 = 0;
  } money;

 public:
  cl_application() : Base(nullptr, "ATM"){};
  void build_tree_objects();  // построение иерархии
  int exec_app();
  int getCurrentSum();  // метод для подсчета общей суммы денег
  void signalReadNEWcommand(string &str) {}  // сигнал для чтения новой строки
  void signalSETup(string &str) {}  // сигнал для настройки автомата
  void signalCORRECT(string &str) {}  // метод для проверки корректности пин-кода
  void handlerADDuser(string str);  // обработчик сигнала для добавления нового пользователя
  void handlerMONEY(
      string str);  // обработчик сигнала для дбавлении информации о купюрах
  void handlerDepositToCard(string str);  // обработчик сигнала
  void handlerBalance(string str);  // обработчик, передающий баланс карты
  void handlerWithdrawMoneyToApp(string str);  // обработчик для выдачи денег
  void handlerCheckPin(
      string str);  // обработчик для проверки корректности пин-кода и отправки
                    // обратно void handlerShowTree(string str);
  void handlerADD(string str);
};
#endif