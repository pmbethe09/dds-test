
#include <iostream>

#include "include/dll.h"

#include <string.h>

static void PrintDDSDebugInfo(const struct futureTricks &fut) {
  printf("nodes=%d cards=%d\n", fut.nodes, fut.cards);
  for (int i = 0; i < fut.cards; ++i) {
    printf("i=%d suit=%d rank=%d equals=%d score=%d\n", i, fut.suit[i],
           fut.rank[i], fut.equals[i], fut.score[i]);
  }
}

int main(int argc, char **argv) {
  const int target = -1, solutions = 3, mode = 1;

  SetMaxThreads(0);

  struct dealPBN dds_deal;
  struct futureTricks fut;
  memset(&dds_deal, 0, sizeof(deal));
  memset(&fut, 0, sizeof(futureTricks));

  strcpy(dds_deal.remainCards, "N:KJ..5. QT...T 5..A.9 97.9..");
  dds_deal.first = 2;
  dds_deal.trump = 4;

  int rc = SolveBoardPBN(dds_deal, target, solutions, mode, &fut,
                   /* threadIndex */ 0);
  if (rc == RETURN_NO_FAULT) {
    PrintDDSDebugInfo(fut);
    return 0;
  }
  char line[80];
  ErrorMessage(rc, line);
  std::cerr << line << std::endl;
  return 1;
}