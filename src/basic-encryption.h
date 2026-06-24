#ifndef BASIC_H
#define BASIC_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/random.h>
#include <string.h>
char *encrypt(char *input,char* key);
char encrypt_char(char input_char,char input_key);
char *decrypt(char *cypher_text, char* key);
#endif