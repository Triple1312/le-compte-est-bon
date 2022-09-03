#include <iostream>
#include <thread>
//#include <chrono>
#include "src/Problem.h"
#include "src/Agent.h"
#include <time.h>

//#include "src/random.hpp"

int runtest(std::vector<std::tuple<int, std::shared_ptr<State>>> *tries) {
   clock_t clo = clock();
  while (true) {
    auto problem = std::make_shared<Problem>();
    Agent agent = Agent(problem);
    auto solution = agent.search();
    if (solution) {
      tries->push_back(std::tuple<int, std::shared_ptr<State>>(problem->getStateCount(), solution));
      break;
    }
    std::cout << "failed" << std::endl;
  }
  std::cout << clock() -clo << std::endl;
  return 1;
}

int main() {

  std::vector<std::tuple<int, std::shared_ptr<State>>> tries;
  std::vector<std::thread> threads;
  int amount = 1;


  for (auto count = 0; count < amount; count++) {
    std::thread t(runtest, &tries);
    threads.push_back(std::move(t));
    std::this_thread::sleep_for(std::chrono::nanoseconds(10));
  }
  std::cout << "constructed " << amount << " threads" << std::endl;
  for (auto i=0; i < threads.size(); i++) {
    threads[i].join();
    std::cout << "completed: " << tries.size() << std::endl;
  }
  for (auto j : tries) {
    std::get<1>(j)->printState();
  }

  std::cout << "complete: " << std::endl;
  int avgc = 0;
  for (auto i : tries) {
    avgc += std::get<0>(i);
  }

  std::cout << "average states explored  " << avgc/amount << std::endl;

  return 0;
}