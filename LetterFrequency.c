/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>


int main()
{
	int index;

    char* text = "AAABCDDDFEEECAZZXHHHHHHHHHHHHHHH";
    char frequency[26][1];
    int i = 0;
    for (i = 0; i < 26; i++)
        frequency[i][0] = 0;
    for(index = 0; text[index] != '\0'; ++index)
        frequency[text[index]-65][0]++;
    
    for(i = 0; i < 26; i++)
        printf("%c : %d \n", i+65, (int)frequency[i][0]);
}