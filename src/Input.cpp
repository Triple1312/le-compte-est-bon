//
// Created by Phili on 8/24/2022.
//

#include "Input.h"
Input::Input() {
  std::string totall;
  this->values = std::vector<int>();

  std::cout << "give a total:" << std::endl;
  std::cin >> totall;
  this->total = std::stoi(totall);
  for (auto i=0; i < 6; i++) {
    std::cout << "give a number" << std::endl;
    std::string tmp;
    std::cin >> tmp;
    this->values.push_back(std::stoi(tmp));
  }
}
