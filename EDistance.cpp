// Copyright[2023] <Jessica Barhouane>
#include <iostream>
#include <algorithm>
#include <array>
#include <string>
#include <iomanip>
#include <SFML/System.hpp>
#include "EDistance.hpp"


int EDistance::penalty(char a, char b) {
  if (a == b) {
    return 0;
  }
  return 1;
}

int EDistance::min(int a, int b, int c) {
  return std::min(std::min(a, b), c);
}

int EDistance::optDistance() {
  int i, j, cost;
  EDMatrix[(M - 1) * N + (N - 1)] = 0;

  for (i = 0; i < N; i++) {
    EDMatrix[(M - 1) * N + i] = 2 * (N - 1 - i);
  }

  for (j = 0; j < M; j++) {
    EDMatrix[j * N + (N - 1)] = 2 * (M - 1 - j);
  }

  for (i = M - 2; i >= 0; i--) {
    for (j = N - 2; j >= 0; j--) {
      cost = penalty(strOne[i], strTwo[j]);
      EDMatrix[i * N + j] = min(EDMatrix[(i + 1) * N + (j + 1)] + cost,
      EDMatrix[i * N + (j + 1)] + 2, EDMatrix[(i + 1) * N + j] + 2);
    }
  }
  return EDMatrix[0];
}

std::string EDistance::alignment() {
  int i = 0, j = 0;
  strAlign1 = "";
  strAlign2 = "";
  std::string strResult = "";
  std::string space = " ";

  while (i < M - 1 && j < N - 1) {
    if ((EDMatrix[(i + 1) * N + (j + 1)] + penalty(strOne[i],
    strTwo[j])) - EDMatrix[i * N + j] == 0) {
      strAlign1 += strOne[i];
      strAlign2 += strTwo[j];
      i++;
      j++;
    } else if ((EDMatrix[(i + 1) * N + j] + 2) - EDMatrix[i * N + j] == 0) {
      strAlign1 += strOne[i];
      strAlign2 += '-';
      i++;
    } else if ((EDMatrix[i * N + (j + 1)] + 2) - EDMatrix[i * N + j] == 0) {
      strAlign1 += '-';
      strAlign2 += strTwo[j];
      j++;
    }
  }

  auto calcCost = [&](char m, char n) -> int {
    if (m == '-' || n == '-') {
      return 2;
    } else {
      return penalty(m, n);
    }
  };

  for (size_t k = 0; k < strAlign1.length(); k++) {
    int cost = calcCost(strAlign1[k], strAlign2[k]);
    strResult += strAlign1[k] + space + strAlign2[k] + space + std::to_string(cost) + '\n';
  }

  return strResult;
}
