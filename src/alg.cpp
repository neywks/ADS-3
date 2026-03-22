// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
uint64_t max = num;
  
  while (num != 1) {
    if (num % 2 == 0) {
      num = num / 2;
    } else {
      num = 3 * num + 1;
    }
    if (num > max) {
      max = num;
    }
  }
  return max;
}

unsigned int collatzLen(uint64_t num) {
  unsigned int len = 1;

  while (num != 1) {
    if (num % 2 == 0) {
      num = num / 2;
    } else {
      num = 3 * num + 1;
    }
    ++len;
  }
  return len;
}

unsigned int seqCollatz(unsigned int *maxlen,
                        uint64_t lbound,
                        uint64_t rbound) {
  unsigned int count = 0;
  unsigned int mLen = 0;

  for (uint64_t i = lbound; i <= rbound; ++i) {
    unsigned int cLen = collatzLen(i);

    if (cLen > mLen) {
      mLen = cLen;
      count = 1;
    } else if (cLen == mLen) {
      ++count;
    }
  }
  if (maxlen != nullptr) {
    *maxlen = mLen;
  }
  return count;
}
