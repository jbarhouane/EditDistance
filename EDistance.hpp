// Copyright[2023] <Jessica Barhouane>
#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <SFML/System.hpp>

class EDistance {
 public:
  // Constructors and Destructors
  EDistance(std::string leftString, std::string rightString, int leftLength, int rightLength) :
  strOne(leftString), strTwo(rightString), M(leftLength + 1), N(rightLength + 1) {
    EDMatrix = new int[M * N];
  }
  ~EDistance() {
    delete[] EDMatrix;
  }

  // Functions
  static int penalty(char a, char b);
  static int min(int a, int b, int c);
  int optDistance();
  std::string alignment();

 private:
  std::string strOne;
  std::string strTwo;
  std::string strAlign1;
  std::string strAlign2;
  std::string strResult;
  int* EDMatrix;
  int M;
  int N;
};
