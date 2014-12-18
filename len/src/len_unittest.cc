#include <limits.h>
#include "len.h"
#include "gtest/gtest.h"
#include "tiger_blue.h"

extern bool SHOW_USECASE;
extern bool LIST_USECASE;

TEST_F(TigerBlue, FET_01_NULL)
{
  usecase = "pass NULL and get LEN_CONST_ERROR_NULL returned.";
  if (LIST_USECASE) { itshowtime(); return; }
  if (SHOW_USECASE) { itshowtime(); }

  EXPECT_EQ(LEN_CONST_ERROR_NULL, len(NULL)) << whyfail();
}

TEST_F(TigerBlue, RAT_01_EmptyString_return_0)
{
  usecase = "pass empty string and get 0 returned.";
  if (LIST_USECASE) { itshowtime(); return; }
  if (SHOW_USECASE) { itshowtime(); }

  EXPECT_EQ(0, len("")) << whyfail();
}

TEST_F(TigerBlue, RAT_02_OneCharacter_return_1)
{
  usecase = "pass one character and get 1 returned.";
  if (LIST_USECASE) { itshowtime(); return; }
  if (SHOW_USECASE) { itshowtime(); }

  EXPECT_EQ(1, len("1")) << whyfail();
}

TEST_F(TigerBlue, FAST_01_255Characters_return_255)
{
  usecase = "pass long string in 255 chars and get 255 returned.";
  if (LIST_USECASE) { itshowtime(); return; }
  if (SHOW_USECASE) { itshowtime(); }

  int isize = LEN_CONST_MAX_SIZE;
  char* sz = (char*) malloc(sizeof(char)*(isize+1));
  if (NULL == sz) { FAIL() << "fail to malloc()"; }
  else { memset(sz,'a',isize); sz[isize] = 0; }

  EXPECT_EQ(LEN_CONST_MAX_SIZE, len(sz)) << whyfail();
}

TEST_F(TigerBlue, FAST_02_upper_bound_255)
{
  usecase = "at most 255 returned";
  if (LIST_USECASE) { itshowtime(); return; }
  if (SHOW_USECASE) { itshowtime(); }

  int isize = LEN_CONST_MAX_SIZE+1;
  char* sz = (char*) malloc(sizeof(char)*(isize+1));
  if (NULL == sz) { FAIL() << "fail to malloc()"; }
  else { memset(sz,'a',isize); sz[isize] = 0; }

  EXPECT_EQ(LEN_CONST_MAX_SIZE, len(sz)) << whyfail();
}
