#include <memory>
#include <iostream>
#include <valarray>
#include "Operation.h"



int calc_post_fix(const std::string& equation) {
   std::vector<int> temp; // log is mss niet het beste
   std::string getal;
   for (auto i : equation) {
      if (i == ' ') {
         if (getal != "") {
            temp.push_back(std::stoi(getal));
            getal = "";
         }
      }
      else if (i == '+') {
         int te = temp[temp.size()-2] + temp[temp.size()-1];
         temp.pop_back(); temp.pop_back();
         temp.push_back(te);
      }
      else if (i == '-') {
         int te = temp[temp.size()-2] - temp[temp.size()-1];
         temp.pop_back(); temp.pop_back();
         temp.push_back(te);
      }
      else if (i == '*') {
         int te = temp[temp.size()-2] * temp[temp.size()-1];
         temp.pop_back(); temp.pop_back();
         temp.push_back(te);
      }
      else {
         getal += i;
      }
   }
   if (temp.size() > 1) {
      std::cout << "insufficient size calculating equation" << std::endl;
   }
   return temp[0];
}

std::string post_to_infix(const std::string& equation) {
   std::vector<std::string> numbers;
   std::vector<std::string> operators;
   std::string getal;
   for (auto i = 0; i < equation.size(); i++) {
      if (i == ' ') {
         if (!getal.empty()) {
            numbers.push_back(getal);
            getal = "";
         }
      }
      else if (i == '+') {
         operators.emplace_back("+");
         if (!getal.empty()) {
            numbers.push_back(getal);
            getal = "";
         }
      }
      else if (i == '-') {
         operators.emplace_back("-");
         if (!getal.empty()) {
            numbers.push_back(getal);
            getal = "";
         }
      }
      else if (i == '*') {
         operators.emplace_back("*");
         if (!getal.empty()) {
            numbers.push_back(getal);
            getal = "";
         }
      }
      else {
         getal += i;
      }
   }
}

int calcu(const std::string& kuk) { // no spaces allowed
   std::vector<int> numbers;
   std::string tmp = kuk;
   std::string ops = "";
   std::string getal = "";
//   std::cout << kuk.size() << std::endl;
   for (char i : tmp) {
      if (i == '+' || i == '-' || i == '*') {
         numbers.push_back(std::stoi(getal));
         getal = "";
         ops.push_back(i);
      }
      else {
         getal+=i;
      }
   }
   numbers.push_back(std::stoi(getal));

   int pri = 2;
   while (pri > 0) {
      for (auto j = 0; j < ops.size(); j++) {
         if (ops[j] == '*' && pri == 2) {
            numbers[j] = numbers[j] * numbers[j+1];
            numbers.erase(numbers.begin()+j+1);
            ops.erase(ops.begin()+j);
            continue;
         }
         if (ops[j] == '/' && pri == 2) {
            numbers[j] = numbers[j] / numbers[j+1];
            numbers.erase(numbers.begin()+j+1);
            ops.erase(ops.begin()+j);
            continue;
         }
         if (ops[j] == '+' && pri == 1) {
            numbers[j] = numbers[j] + numbers[j+1];
            numbers.erase(numbers.begin()+j+1);
            ops.erase(ops.begin()+j);
            continue;
         }
         if (ops[j] == '-' && pri == 1) {
            numbers[j] = numbers[j] - numbers[j+1];
            numbers.erase(numbers.begin()+j+1);
            ops.erase(ops.begin()+j);
            continue;
         }
      }
      pri--;
   }
   return numbers[0];
}
