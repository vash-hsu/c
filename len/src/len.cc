#include "len.h"
#include <string.h>


short int len(const char* buffer)
{
  if (NULL == buffer) {  return LEN_CONST_ERROR_NULL; }
  return strlen(buffer);
}

