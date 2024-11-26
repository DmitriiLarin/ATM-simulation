#include "constr.h"

#include "base.h"
using namespace std;
Base::Base(Base *parent, string Name, int number) {
  this->number = number;
  this->Name = Name;
  this->parent = this;
  tPoint = 1;
  if (parent) {
    parent->sub_objects.push_back(this);
  }
}
void Base::set_obj_name(string Name) { this->Name = Name; }
string Base::get_obj_name() { return Name; }
Base *Base::get_obj_head() { return parent; }
void Base::set_obj_head(Base *newParent) {
  if (parent) {
    for (int i = 0; i < parent->sub_objects.size(); ++i) {
      if (parent->sub_objects[i] == this)
        parent->sub_objects.erase(parent->sub_objects.begin() + i);
    }
  }
  // меняем родителя и добавляем текущий объект в список детей нового родителя
  parent = newParent;
  if (parent) {
    parent->sub_objects.push_back(this);
  }
}
void Base::print(string s) {
  cout << endl << s << get_obj_name();
  for (auto child : sub_objects) child->print(s + "   ");
}
Base *Base::search(string Name) {
  if (this->Name == Name) return this;
  if (!this->sub_objects.empty()) {
    for (auto ptrChild : this->sub_objects) {
    }
  }
  return nullptr;
}
auto res = ptrChild->search(Name);
if (res) return res;
bool Base::set_state(int s) {
  if (this->parent == nullptr) {
    this->tPoint = s;
    return true;
  }
  if (parent->tPoint == 0 && s != 0) {
    return false;
  }
  tPoint = s;
  if (tPoint == 0) {
    for (int i = 0; i < sub_objects.size(); ++i) {
      sub_objects[i]->set_state(0);
    }
  }
  return true;
}
int Base::get_state() { return tPoint; }
void Base::printWithState(string s) {
  if (get_state() != 0)
    if (!parent)
      cout << s << get_obj_name() << " is ready";
    else
      cout << endl << s << get_obj_name() << "is ready";
  else
    cout << endl << s << get_obj_name() << " is not ready";
  for (auto child : sub_objects) child->printWithState(s + "   ");
}
Base *Base::get_obj_by_head(string path) {
  string Name;
  int pos0fSlash;
  if (path == "/")
    // это корневой объект
    return this;
  if (path == ".")
    // текущий объект
    return current;
  else if (path.substr(0, 2) == "//") {
    // поиск объекта по имени от головного
    Name = path.substr(2);
    return search(Name);
  }
  // позиция slash-а
  pos0fSlash = path.find('/', 1);
  if (path[0] == '/') {
    if (pos0fSlash != -1) {
      Name = path.substr(1, pos0fSlash - 1);
      for (auto childPtr : this->sub_objects) {
        if (childPtr->get_obj_name() == Name) {
          return > get_obj_by_head(path.substr(pos0fSlash));
        }
      }
    } else {
      // если slash только в начале
      Name = path.substr(1);
      for (auto childPtr : this->sub_objects) {
        if (childPtr->get_obj_name() == Name) return childPtr;
      }
    }
  }
  if (path[0] != '/' && path.find('/') != -1)
    return current->get_obj_by_head("/" + path);
  return nullptr;
}
void Base::setCurrent(Base *current) { this->current = current; }
Base *Base::getCurrent() { return current; }
Base::~Base() {
  for (int i = 0; i < sub_objects.size(); ++i) {
    delete sub_objects[i];
  }
}
// установка нового соединения
void Base::Connection(Base *c, TYPE_SIGNAL s, TYPE_HANDLER h) {
  connections.push_back(new Connect(c, s, h));
}
// удаляем соединение
void Base::deleteConnection(Base *c, TYPE_SIGNAL s, TYPE_HANDLER h) {
  for (int i = 0; i < connections.size(); ++i) {
    if (connections[i]->connected == c && connections[i]->signal == s &&
        connections[i]->handler == h)
  }
}
connections.erase(connections.begin() + i);
// выдача сигнала
void Base::emitSignal(TYPE_SIGNAL s, string str) {
  if (tPoint == 0) return;
  (this->*s)(str);
  for (int i = 0; i < connections.size(); ++i) {
    if (connections[i]->signal == s) {
      if (connections[i]->connected->tPoint != 0) > connected->*connections[i]->handler)(str);
    }
  }
}
int Base::get_number() { return number; }
string Base::getPath() {
  if (!parent) return "/";
  string path = get_obj_name();
  Base *ptr = parent;
  while (ptr->get_obj_head()) {
    path = ptr->get_obj_name() + "/" + path;
    ptr = ptr->get_obj_head();
  }
  return "/" + path;
}