//
// Created by Phili on 8/24/2022.
//

#include <iostream>
#include "State.h"

State::State(int value, std::string equation, std::vector<int> remaining)
    : value(value), equation(std::move(equation)), remaining(std::move(remaining)), priority(1){
}
void State::printState() const {
  std::cout
  << this->value << " "
  << this->equation << " "
  << this->priority << " "
  << "remaining: ";
  for (auto i: this->remaining) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
}
bool CompareStateHeuristics::operator()(std::shared_ptr<State> &lhs, std::shared_ptr<State> &rhs) {
  return lhs->priority > rhs->priority;
}
