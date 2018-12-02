/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 26

char* alphabet = "abcdefghijklmnopqrstuvwxyz";

int getPosition(char ch)
{
    char* letter = strchr(alphabet, ch);
    return letter - alphabet;
}

void printArray(char* str)
{
    int i = 0;
    for (i = 0; i < strlen(str); i++)
    {
        printf("%c", str[i]);
    }
}

char* encrypt(char plainText[], char key[])
{
    int i = 0;
    int j = 0;
    char* cipherText  = (char *) malloc(sizeof(char) * strlen(plainText) -1);

    for(i = 0; i < strlen(plainText); i++)
    {
        int plainLetterIndex = getPosition(tolower(plainText[i]));
        int keyLetterIndex = getPosition(tolower(key[j]));

        int index = (keyLetterIndex - plainLetterIndex + SIZE) % SIZE;

        cipherText[i] = alphabet[index];
        j++;
        if(j == strlen(key))
        {
            j = 0;
        }

    }

    return cipherText;

}

char* decrypt(char cipherText[], char key[])
{
    int i = 0;
    int j = 0;
    char* plainText  = (char *) malloc(sizeof(char) * strlen(cipherText) -1);

    for(i = 0; i < strlen(cipherText); i++)
    {
        int cipherLetterIndex = getPosition(tolower(cipherText[i]));
        int keyLetterIndex = getPosition(tolower(key[j]));

        int index = (keyLetterIndex - cipherLetterIndex + SIZE) % SIZE;

        plainText[i] = alphabet[index];
        j++;
        if(j == strlen(key))
        {
            j = 0;
        }
    }
    return plainText;
}


int main()
{
    char* text = "secrettext";
    char* key = "key";
    char* cipherText = encrypt(text, key);
    printf("Encrypted %s is: ", text);
    printArray(cipherText);
    
    printf("\n");
    char* plainText = decrypt(cipherText, key);
    printf("Decrypted %s is: ", cipherText);
    printArray(plainText);


    return 0;
}