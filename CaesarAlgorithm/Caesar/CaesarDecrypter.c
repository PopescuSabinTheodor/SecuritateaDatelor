int main()
{
	int index;
	int key;
    char text[100];
    char encryptedText[100];
    char ch;

    printf("Enter text: ");
    gets(text);
    printf("Enter key: ");
    scanf("%d", &key);

    printf("Enter encrypted text: ");
    gets(text);
    printf("Enter key: ");
    scanf("%d", &key);

    for(index = 0; text[index] != '\0'; ++index){
        ch = text[index];

        if(ch >= 'a' && ch <= 'z'){
            ch = ch - key;

            if(ch < 'a')
                ch = ch + 'z' - 'a' + 1;

            text[index] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z'){
            ch = ch - key;

            if(ch < 'A')
                ch = ch + 'Z' - 'A' + 1;


            text[index] = ch;
        }
    }

    printf("Decrypted text: %s", text);
}
