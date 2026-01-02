// =============================================================
//  Project: Crypto (Polyalphabetic Cipher)
//  Language: C (Standard)
// =============================================================

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function Prototypes
void encrypt(const char *key, const char *filename); // declare encrypt function
void decrypt(const char *key, const char *filename); // declare decrypt function
void remove_newline(char *str);

// Helper to clean input strings (removes the 'Enter' key press)
void remove_newline(char *str)
{
    str[strcspn(str, "\n")] = 0;
}

// =============================================================
//  FUNCTION: ENCRYPT
// =============================================================
void encrypt(const char *key, const char *filename)
{
    // 1. OPEN SOURCE FILE
    // "r" = Read mode. Returns NULL if file doesn't exist.
    FILE *fp_in = fopen(filename, "r");
    if (fp_in == NULL)
    {
        printf("Error: File '%s' not found!\n", filename);
        return;
    }

    // 2. PREPARE OUTPUT FILENAME
    // We create a buffer large enough for "encrypted_" + filename
    char output_filename[300] = "encrypted_";
    strcat(output_filename, filename); // Appends filename to "encrypted_"

    // 3. OPEN OUTPUT FILE
    // "w" = Write mode. Creates file if not exists, overwrites if it does.
    FILE *fp_out = fopen(output_filename, "w");
    if (fp_out == NULL)
    {
        printf("Error creating output file.\n");
        fclose(fp_in);
        return;
    }

    // 4. PROCESS FILE CHAR BY CHAR
    int ch; // Use 'int' because fgetc returns EOF (-1) which doesn't fit in char
    int i = 0;
    int key_len = strlen(key);

    printf("Encrypting...\n");

    // FIX: fgetc only takes the file pointer as an argument.
    // It reads one character and moves the cursor forward.
    while ((ch = fgetc(fp_in)) != EOF)
    {
        // LOGIC: (Current Char + Key Char) % 256
        // The % 256 wraps the value around if it exceeds 255 (ASCII limit)
        // We cast to (unsigned char) to ensure positive values.
        char encrypted_char = (char)((ch + key[i]) % 256);

        fputc(encrypted_char, fp_out); // Write result to file

        // Cycle through the key
        i++;
        if (i >= key_len)
            i = 0;
    }

    printf("Done! Saved as: %s\n", output_filename);

    // 5. CLEANUP
    // Always close files to flush buffers and free memory
    fclose(fp_in);
    fclose(fp_out);
}

// =============================================================
//  FUNCTION: DECRYPT
// =============================================================
void decrypt(const char *key, const char *filename)
{
    FILE *fp_in = fopen(filename, "r");
    if (fp_in == NULL)
    {
        printf("File not found!\n");
        return;
    }

    char output_filename[300] = "decrypted_";
    strcat(output_filename, filename);

    FILE *fp_out = fopen(output_filename, "w");

    int ch;
    int i = 0;
    int key_len = strlen(key);

    printf("Decrypting...\n");

    while ((ch = fgetc(fp_in)) != EOF)
    {
        // LOGIC: Reverse the math.
        // We add 256 before modulo to handle negative results during subtraction.
        // Example: If (5 - 10) = -5, (-5 + 256) % 256 gives us the correct positive wrap-around.
        char decrypted_char = (char)((ch - key[i] + 256) % 256);

        fputc(decrypted_char, fp_out);

        i++;
        if (i >= key_len)
            i = 0;
    }

    printf("Done! Saved as: %s\n", output_filename);

    fclose(fp_in);
    fclose(fp_out);
}

// =============================================================
//  MAIN & MENU
// =============================================================
int main()
{
    char key[100];
    char filename[256];
    int option;

    // Using a loop instead of recursion to prevent stack overflow
    while (1)
    {
        printf("\n=== Crypto Tool ===\n");
        printf("1. Encrypt\n2. Decrypt\n3. Exit\nOption: ");
        scanf("%d", &option);

        // Clear input buffer (catch the newline left by scanf)
        while (getchar() != '\n')
            ;

        if (option == 3)
            break;

        printf("Enter Key: ");
        // fgets is safer than scanf ("%s") because it allows spaces in keys
        fgets(key, sizeof(key), stdin);
        remove_newline(key);

        printf("Enter Filename: ");
        fgets(filename, sizeof(filename), stdin);
        remove_newline(filename);

        if (option == 1)
            encrypt(key, filename);
        else if (option == 2)
            decrypt(key, filename);
        else
            printf("Invalid option.\n");
    }

    return 0;
}