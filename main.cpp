// Copyright[2023] <Jessica Barhouane>
#include <iostream>
#include <fstream>
#include <string>
#include <SFML/System.hpp>
#include "EDistance.hpp"

int main(int argc, char* argv[]) {
  std::string GSOne, GSTwo;

  std::getline(std::cin, GSOne);
  std::getline(std::cin, GSTwo);

  sf::Clock clock;
  sf::Time t;

  EDistance compare(GSOne, GSTwo, GSOne.length(), GSTwo.length());
  std::cout << GSOne.length() << " " << GSTwo.length() << std::endl;
  std::cout << "Edit Distance = " << compare.optDistance() << std::endl;

  compare.alignment();
  std::string align = compare.alignment();
  std::cout << align << std::endl;

  t = clock.getElapsedTime();
  std::cout << "Execution time is " << t.asSeconds() << " seconds" << std::endl;

  return 0;
}
