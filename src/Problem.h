#ifndef LE_COMPTE_EST_BON_SRC_PROBLEM_H_
#define LE_COMPTE_EST_BON_SRC_PROBLEM_H_

#include <memory>
#include "State.h"
#include "Input.h"

class Problem {
 public:
  std::vector<int> values;
  int total;
  std::string operations;
  std::vector<std::shared_ptr<State>> explored;
  int tmp = 0;

  Problem(int total, std::vector<int> values, std::string operations);

  explicit Problem(std::string operations);

  explicit Problem(Input& input);

  Problem();

  std::vector<std::shared_ptr<State>> getSuccessors(const State&);

  bool isGoalState(const State&) const;

  int getStateCount();

};

#endif //LE_COMPTE_EST_BON_SRC_PROBLEM_H_
