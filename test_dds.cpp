
#include <string.h>

#include <iostream>

#include "include/dll.h"
#include "gtest/gtest.h"

static void PrintDDSDebugInfo(const struct futureTricks &fut) {
  printf("nodes=%d cards=%d\n", fut.nodes, fut.cards);
  for (int i = 0; i < fut.cards; ++i) {
    printf("i=%d suit=%d rank=%d equals=%d score=%d\n", i, fut.suit[i],
           fut.rank[i], fut.equals[i], fut.score[i]);
  }
}

enum class Suit {
  SPADES = 0,
  HEARTS = 1,
  DIAMONDS = 2,
  CLUBS = 3,
  NOTRUMP = 4
};

enum class Compass { NORTH = 0, EAST = 1, SOUTH = 2, WEST = 3 };

TEST(TestDDS, Solve) {
  const int target = -1, solutions = 3, mode = 1;

  SetMaxThreads(0);

  struct dealPBN dds_deal;
  struct futureTricks fut;
  memset(&dds_deal, 0, sizeof(deal));
  memset(&fut, 0, sizeof(futureTricks));

  strcpy(dds_deal.remainCards, "N:KJ..5. QT...T 5..A.9 97.9..");
  dds_deal.currentTrickSuit[0] = static_cast<int>(Suit::DIAMONDS);
  dds_deal.currentTrickRank[0] = 14; // rank('A');

  dds_deal.first = static_cast<int>(Compass::SOUTH);
  dds_deal.trump = static_cast<int>(Suit::NOTRUMP);

  int rc = SolveBoardPBN(dds_deal, target, solutions, mode, &fut,
                         /* threadIndex */ 0);
  char line[80];
  ErrorMessage(rc, line);
  EXPECT_EQ(RETURN_NO_FAULT, rc) << line;
  if (rc == RETURN_NO_FAULT) {
    PrintDDSDebugInfo(fut);
  }
  EXPECT_EQ(3, fut.score[0]);
}
