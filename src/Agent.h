#ifndef LE_COMPTE_EST_BON_SRC_AGENT_H_
#define LE_COMPTE_EST_BON_SRC_AGENT_H_

#include <memory>
#include <queue>
#include "Problem.h"

class Agent {
  std::shared_ptr<Problem> problem;
  std::priority_queue< std::shared_ptr<State>, std::vector<std::shared_ptr<State>>, CompareStateHeuristics> states;
//  std::vector<std::shared_ptr<State>> deprecated; // not really needed, Problem remembers all states
  virtual float heuristic(const State &state);

 public:
  explicit Agent(std::shared_ptr<Problem> problem);

  std::shared_ptr<State> search();

};

class BFSAgent : Agent {

};


class AAgent : Agent {

  float heuristic(const State& state) override;

};

#endif //LE_COMPTE_EST_BON_SRC_AGENT_H_
