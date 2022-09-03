#include <iostream>
#include "src/Problem.h"
#include "src/Agent.h"

int main() {
  std::cout << "Hello, World!" << std::endl;
  auto problem = std::make_shared<Problem>();
  Agent agent = Agent(problem);
  auto solution = agent.search();
  std::cout << "\n\nsolution: " << std::endl;
  if (solution)
    solution->printState();
  else
    std::cout << "no solutions found" << std::endl;
  std::cout << "states explored: " << problem->getStateCount() << std::endl;
  return 0;
}

