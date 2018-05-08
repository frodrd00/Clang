#include "FindNamedClassAction.h"
#include <clang/Tooling/Tooling.h>

//bin/main "namespace n { namespace m { class C {}; } }"

int main(int argc, char **argv) {
  if (argc > 1) {
    clang::tooling::runToolOnCode(new cFindNamedClassAction, argv[1]);
  }
}
