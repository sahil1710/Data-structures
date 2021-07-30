#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int n, i, j, r;
    char str2[50], temp;
    printf("Enter total number of words:\n");
    scanf("%d", &n);
    system("clear");
    char word[n][50];

    for (i = 0; i < n; i++)
    {
        printf("Enter word-%d:\n", i + 1);
        scanf("%s",&word[i]);
    }
    system("clear");

    srand(time(0));
    r = rand() % n;
    printf("Enter word:\n");
    scanf("%s", &str2);

    for (i = 0; i < (strlen(word[r]) - 1); i++)
    {
        for (j = i + 1; j < strlen(word[r]); j++)
        {
            if (word[r][i] > word[r][j])
            {
                temp = word[r][i];
                word[r][i] = word[r][j];
                word[r][j] = temp;
            }
        }
    }

    for (i = 0; i < (strlen(str2) - 1); i++)
    {
        for (j = i + 1; j < strlen(str2); j++)
        {
            if (str2[i] > str2[j])
            {
                temp = str2[i];
                str2[i] = str2[j];
                str2[j] = temp;
            }
        }
    }

    system("clear");

    if(strcmp(word[r],str2)==0){
        printf("Strings are anagram.\n");
    }

    else{
        printf("Strings are not anagram.\n");
    }
}