#include "basic-encryption.h"
// 33 - 126

// 93
char *encrypt(char *input, char *key)
{
  int len_input = strlen(input);
  int len_key = strlen(key);
  char* output = malloc(len_input+1);
  int j = 0;
  for (int i = 0; i < len_input; i++)
  {
    if (j==len_key)
    {
      j=0;
    }
    output[i] = encrypt_char(input[i],key[j]);
    j++;
  }
  output[len_input]='\0';
  return output;
}

char encrypt_char(char input_char,char input_key)
{
if (input_char >= 'A' && input_char <= 'Z')
{
  return ('A' + ((input_char - 'A' + input_key)%26));
}
else if (input_char >= 'a' && input_char <= 'z')
{
  return ('a' + ((input_char - 'a' + input_key)%26));
}
else if (input_char >= '0' && input_char <= '9')
{
  return ('0' + ((input_char - '0' + input_key)%26));
}
else return input_char;
}