// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
  if (num == 0) {
    return 0;
  }
  
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
  if (num == 0) {
    return 0;
  }
  
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
  unsigned int count = lbound;
  unsigned int mLen = 1;

  for (uint64_t i = lbound; i <= rbound; ++i) {
    unsigned int cLen = collatzLen(i);

    if (len > mLen) {
      mLen = len;
      count = i;
    } 
  }
*maxlen = mLen;
return count;
}
