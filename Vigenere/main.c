#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include<string.h>

int main()
{
    char text[] = "SECRETTEXT";
    char key[] ="QWE";
    int textLength = strlen(text);
    char encryptedText[textLength], decryptedText[textLength];
    int keyLength = strlen(key);
    char newKey[textLength];
    int i, j;

    for(i = 0, j = 0; i < textLength; i++, j++){
        if(j == keyLength)
            j = 0;
        newKey[i] = key[j];
        printf("%c", newKey[i]);
    }
    newKey[i] = '\0';
    for(i = 0; i < textLength; i++)
        encryptedText[i] = ((text[i] + newKey[i]) % 26) + 'A';
    encryptedText[i] = '\0';
    printf("\nEncrypted: %s", encryptedText);

    for(i = 0; i < textLength; ++i)
        decryptedText[i] = (((encryptedText[i] - newKey[i]) + 26) % 26) + 'A';
    decryptedText[i] = '\0';
    printf("\nDecrypted: %s", decryptedText);
}
