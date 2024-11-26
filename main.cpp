#include "base.h"
int main() {
  cl_application ob_cl_application;
  ob_cl_application.build_tree_objects();
  ob_cl_application.exec_app();
  return 0;
}