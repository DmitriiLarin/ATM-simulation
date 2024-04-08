#ifndef CLASS_H
#define CLASS_H
#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Base;
class Base;
typedef void (Base::*TYPE_SIGNAL)(string &);
typedef void (Base::*TYPE_HANDLER)(string);
#define SIGN(s) (TYPE_SIGNAL)(&s)
#define HAND(h) (TYPE_HANDLER)(&h)
class Base {
  struct Connect {
    Base *connected;     // объект, принимающий сигнал
    TYPE_SIGNAL signal;  // указатель на метод, отправляющий сигнал TYPE_HANDLER
                         // handler;//указатель на метод, принимающий сигнал
    Connect(Base *c, TYPE_SIGNAL s, TYPE_HANDLER h)
        : connected(c), signal(s), handler(h){};
  };
  int number;
  vector<Connect *> connections;  // связь текущего объекта
  string Name;
  Base *parent;
  vector<Base *> sub_objects;
  int tPoint;
  Base *current;

 public:
  Base(Base *parent, string Name = "", int number = 1);
  ~Base();
  string get_obj_name();
  void set_obj_name(string Name);
  Base *get_obj_head();
  void set_obj_head(Base *newParent);
  void print(string s);
  Base *search(string Name);
  bool set_state(int tPoint);
  void printWithState(string s);
  int get_state();
  Base *get_obj_by_head(string path);
  void setCurrent(Base *current);
  Base *getCurrent();
  void Connection(Base *c, TYPE_SIGNAL s, TYPE_HANDLER h);
  void deleteConnection(Base *c, TYPE_SIGNAL s, TYPE_HANDLER h);
  void emitSignal(TYPE_SIGNAL s, string str = "");
  int get_number();
  string getPath();
  void signalPRINT(string &str) {}
};
#endif