#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CONST_COMMAND_LINE_MAX_LEN 1024

#ifdef _MSC_VER
#include <cstdarg>
#define snprintf c99_snprintf
inline int c99_vsnprintf(char* str, size_t size, const char* format, va_list ap)
{
  int count = -1;
  if (size != 0)
    count = _vsnprintf_s(str, size, _TRUNCATE, format, ap);
  if (count == -1)
    count = _vscprintf(format, ap);
  return count;
}
inline int c99_snprintf(char* str, size_t size, const char* format, ...)
{
  int count;
  va_list ap;
  va_start(ap, format);
  count = c99_vsnprintf(str, size, format, ap);
  va_end(ap);
  return count;
}
#endif // _MSC_VER

#ifdef BUILDNUM
const int buildnumber = BUILDNUM;
#else
const int buildnumber = 1000;
#endif // BUILDNUM

const char cszBanner[] = "This program is designed for KerKer only.";


#if defined(_WIN32) || defined(__WIN32__) || defined(_WIN64) || defined(_WIN64_)
const char cszCommand[] = "start";
#endif // _WIN32

#ifdef __APPLE__
#include "TargetConditionals.h"
#if TARGET_OS_MAC
const char cszCommand[] = "start";
#endif // TARGET_OS_MAC
#endif // __APPLE__

#ifdef __linux__
const char cszCommand[] = "start";
#endif // __linux__

int write_eicar()
{
  int result = 0;
  const char* payload[] = {"X5O!P%@AP[4\\PZX54(P^)7CC)7}$",
                           "EICAR-STANDARD-ANTIVIRUS-TEST-FILE",
                           "!$H+H*"};
  FILE* fptr = NULL;
  fptr = fopen("eicar.com","w");
  if (NULL != fptr)
  {
    for (int i=0; i < 3; i++)
    {
      fprintf(fptr, "%s", payload[i]);
    }
      fclose(fptr);
  }
  return result;
}


int perform_web_browsing()
{
  char target[] = "https://www.google.com.tw";
  char buffer[64] = {0};
  int result = 0;
  snprintf(buffer, 64, "%s %s", cszCommand, target);
  printf("%s\n", buffer);
  result += system(buffer);
  return result;
}

int main(int argc, char** argv)
{
  printf("%s %d\n", cszBanner, buildnumber);
  int result = 0;
  result += write_eicar();
  result += perform_web_browsing();
  return result;
}
