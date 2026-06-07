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
      len++;
  }
  return len;
}

unsigned int seqCollatz(unsigned int *maxlen,
                        uint64_t lbound,
                        uint64_t rbound) {
  uint64_t best_num = lbound;
  unsigned int best_len = 0;
  for (uint64_t i = lbound; i <= rbound; i++) {
      unsigned int len = collatzLen(i);
      if (len > best_len) {
          best_len = len;
          best_num = i;
      }
  }
  *maxlen = best_len;
  return best_num;
}
