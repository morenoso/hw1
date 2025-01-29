#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  ULListStr dat;
  dat.push_back("4");
  dat.push_back("5");
  dat.push_back("6");
  dat.push_back("7");
  dat.push_back("8");
  dat.push_back("9");
  dat.push_back("0");
  //std::cout << dat.head_->val[4] << std::endl;
  std::cout << dat.back() << std::endl;
  dat.pop_back();
  std::cout << dat.back() << std::endl;
  dat.clear();
  dat.push_front("4");
  dat.push_front("3");
  dat.push_front("2");
  dat.push_front("1");
  dat.push_front("0");
  dat.push_front("9");
  std::cout << dat.front() << std::endl;
  dat.pop_front();
  std::cout << dat.front() << std::endl;
  dat.clear();
}
