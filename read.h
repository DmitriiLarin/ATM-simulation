#ifndef READ_H
#define READ_H
#include "constr.h"
class Reader : public Base {
 public:
  Reader(Base *parent, string Name) : Base(parent, Name) {}
  void signalCONSOLE(string &str) {}  // для передачи новой команды
  void signalADDuser(string &str) {}  // добавление нового пользователя
  void signalMONEY(string &str) {}  // информация о купюрах
  void signalPIN(string &str) {
  }  // отправка сигнала дл проверки корректности пин-кожа
  void signalNOT(string &str) {}  // статус не авторизации сигналов
};
#endif