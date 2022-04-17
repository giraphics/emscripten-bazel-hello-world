#include <iostream>
#include <string>

#include "dog.h"
using namespace std;

Dog::Dog(string n): name(n) {}

string Dog::getGreeting () {
  return "My name is " + name + ", hello from C++!";
}

void Dog::makeSound () {
  cout << "bark!" << '\n';
}
