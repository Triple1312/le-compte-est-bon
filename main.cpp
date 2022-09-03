#include <iostream>
#include "src/Input.h"
#include "src/Problem.h"
#include "src/Agent.h"

int main() {
  std::cout << "Hello, World!" << std::endl;
  std::srand( time(0));
  Input inp = Input();
  auto problem = std::make_shared<Problem>(inp);
  Agent agent = Agent(problem);
  auto solution = agent.search();
  std::cout << "\n\nsolution: " << std::endl;
  solution->printState();

  std::cout << "states explored: " << problem->getStateCount() << std::endl;
  return 0;
}

