#include <string>

#include "../../cpp/dog.h"
#include "emscripten/bind.h"

using namespace emscripten;
using namespace std;

EMSCRIPTEN_BINDINGS (c) {
  class_<Dog>("Dog")
    .constructor<string>()
    .function("makeSound", &Dog::makeSound)
    .function("getGreeting", &Dog::getGreeting);
}
