#include "Problem.h"
#include <utility>
#include "random.hpp"

using Random = effolkronium::random_thread_local;

std::vector<std::shared_ptr<State>> Problem::getSuccessors(const State& state) {
   std::vector<std::shared_ptr<State>> ret;
   if (state.remaining.empty()) {
//      std::cout << "empty";
      return ret;
   }


   std::vector<std::string> split;
   std::string tmp = state.equation;
   std::string ops = "";
   std::string getal = "";
//   std::cout << kuk.size() << std::endl;
   for (char i : tmp) {
      if (i == '+' || i == '-' || i == '*') {
         if (getal != "") {
            split.push_back(getal);
            getal = "";
         }
         split.emplace_back(1,i);
      }
      else if(i == ' ' and getal != "") {
         split.push_back(getal);
         getal = "";
      }
      else {
         getal+=i;
      }
   }
   if (getal != "") {
      split.push_back(getal);
   }

   for (auto i = 0; i < split.size(); i++) {
      if (split[i] != "+" and split[i] != "-" and split[i] != "*") {
         if (i%3 == 1) continue;
         for (auto k : operations) {
            auto split2 = split;
            for (auto l = 0; l < state.remaining.size(); l++) {
               split2.insert(split2.begin() + i +1, std::string(1,k));
               split2.insert(split2.begin()+ i +1, std::to_string(state.remaining[l]));
               auto tmp_vec = std::vector<int>();
               for (int j = 0; j < state.remaining.size(); j++ ) {
                  if (j!=l) {
                     tmp_vec.push_back(state.remaining[j]);
                  }
               }
               std::string new_eq = "";
               for ( auto m : split2) {
                  new_eq += m + ' '; // todo is de laatste spatie wel nodig ?
               }
               auto state_new = std::make_shared<State>(calc_post_fix(new_eq), new_eq, tmp_vec);
               ret.emplace_back(state_new);
//                  this->explored.emplace_back(state_new); //todo
               split2 = split;
            }
         }
      }
   }

  return ret;
}

bool Problem::isGoalState(const State& state) const {
  return state.value == this->total;
}
Problem::Problem(int total, std::vector<int> values, std::string operations) :
  total(total),
  values(std::move(values)),
  operations(operations){
}

Problem::Problem(std::string operations) :
  operations(operations),
  total(Random::get(101, 999)){
  auto vec = std::vector<int>();
  std::vector<int> game_numbers{ 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 7, 8, 8, 9, 9, 10, 10, 25, 50, 75, 100};
  for (auto i = 0; i < 6; i++) {
     int size = game_numbers.size()-1;
     auto rand = Random::get(0, size);
      vec.push_back(game_numbers[rand]);
      game_numbers.erase(game_numbers.begin() + rand);
  }

  this->values = vec;
   std::cout << "problem:   " << this->total << std::endl;
   for (auto j : this->values) {
      std::cout << j << "  ";
   }
   std::cout << "\n =========================================================" << std::endl;
}

Problem::Problem() : Problem("+-*"){
}

Problem::Problem(Input &input) : Problem(input.total, input.values, "+-*"){
}
int Problem::getStateCount() {
  return this->explored.size();
}
