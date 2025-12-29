// This file would contain core cryptography logic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void choice();

void encrypt(const char *key, const char *file)
{
    FILE *fp = fopen(file, "r");
    if (fp == NULL)
    {
        printf("File not found!\n");
        choice();
    }

    char ch;

    char output_file[260] = "encrypted_";

    strcat(output_file, file);

    FILE *fp2 = fopen(output_file, "w");

    int i = 0;
    int len = strlen(key);

    while (fgets(&ch, sizeof(ch), fp) != NULL)
    {

        char encrypted_char = ch + key[i];
        fputc(encrypted_char, fp2);

        i++;

        if (i >= len)
            i = 0;
    }
}

void decrypt(const char *key, const char *file)
{
    // Decryption logic goes here
}

void choice()
{
    printf("Welcome to the Cryptography Tool\n");
    char key[50];
    char file[256];
    printf("Enter the key for encryption/decryption: ");
    scanf(" %s", key);
    printf("Enter the file path of your message: ");
    scanf(" %s", file);
    printf("Choose an option:\n");
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    int option;
    scanf("%d", &option);
    if (option == 1)
    {
        encrypt(key, file);
    }
    else if (option == 2)
    {
        decrypt(key, file);
    }
    else
    {
        printf("Invalid option. Please try again.\n");
        choice();
    }
}
