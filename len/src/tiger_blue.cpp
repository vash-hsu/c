#include "gtest/gtest.h"
#include <stdio.h>
#include <stdlib.h>
#include "tiger_blue.h"

bool SHOW_USECASE = false;
bool LIST_USECASE = false;

void printUsage()
{
  fprintf(stdout,"Usage: \n"
                 "       --help     show usage\n"
                 "       --show     show test case description during testing\n"
                 "       --list     list test case and description\n"
         );
}

GTEST_API_ int main(int argc, char **argv)
{
  //::testing::GTEST_FLAG(output) = "xml:./";
  SHOW_USECASE = false;

  for(int i=0; i<argc; i++)
  {
    if (0==strncmp("--help",argv[i],strlen("--help"))) { printUsage(); exit(0); }
    else if (0==strncmp("--show",argv[i],strlen("--show"))) { SHOW_USECASE  = true; }
    else if (0==strncmp("--list",argv[i],strlen("--list"))) { LIST_USECASE  = true; }
  }
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
