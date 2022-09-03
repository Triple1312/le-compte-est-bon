#include "Agent.h"

Agent::Agent(std::shared_ptr<Problem> problem) : problem(std::move(problem)){
}


/// this function will explore the entire tree not returning a valid answer /// nu nog BFS
std::shared_ptr<State> Agent::search() {
//  auto start_state = std::make_shared<State>(0, "0", this->problem->values);
//  this->states.emplace(start_state);
  for (auto i = 0; i < problem->values.size(); i++ ) {
     std::vector<int> rem;
     for (auto j = 0; j < problem->values.size(); j++ ) {
         if(i!=j) {
            rem.push_back(problem->values[j]);
         }
     }
     this->states.emplace(std::make_shared<State>(problem->values[i], std::to_string(problem->values[i]), rem));
  }
  std::shared_ptr<State> goal = nullptr;



  while (!this->states.empty()) {
    auto state = this->states.top();
    this->states.pop();
    auto successors = this->problem->getSuccessors(*state);
    if (successors.empty()) {
       std::cout << "states: " << this->states.size() << std::endl;
       continue;
    }
    for (auto succ : successors) {
      if (this->problem->isGoalState(*succ))
        return succ;
      succ->priority = this->heuristic(*succ);
      this->states.push(succ);
    }
  }
  return goal;
}

float Agent::heuristic(const State &state) {
  return abs(this->problem->total - state.value)/2;
//return 1;
}

float AAgent::heuristic(const State &state) {
  return 0;
}
