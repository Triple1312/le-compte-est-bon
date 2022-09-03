#ifndef LE_COMPTE_EST_BON_SRC_STATE_H_
#define LE_COMPTE_EST_BON_SRC_STATE_H_

#include <vector>
#include <memory>
#include "Operation.h"

struct State {
  const std::vector<int> remaining;
  std::string equation;
  const int value;
  float priority;

 public:
  State(int value, std::string equation, std::vector<int> remaining);

  void printState() const;

};

struct CompareStateHeuristics {
  bool operator()(std::shared_ptr<State> &lhs, std::shared_ptr<State> &rhs);
};

#endif //LE_COMPTE_EST_BON_SRC_STATE_H_
