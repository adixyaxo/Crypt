// This file would contain core cryptography logic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int clogic()
{
    char key[50];
    char file[256];
    printf("Enter the key for encryption/decryption: ");
    scanf(" %s", key);
    printf("Enter the file path of your message: ");
    scanf(" %s", file);

    FILE *fp = fopen(file, "r");
    if (fp == NULL)
    {
        printf("File not found!\n");
        return -1;
    }
    fclose(fp);

    file_encrypt_decrypt(file, key);
    return 0;
}