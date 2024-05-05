#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char str[50], pat[50], rep[50];
int start = 0, patternfound = 0;
int lasts, lastp, lastr;

void replacepattern()
{
    int i, j;
    lastr = strlen(rep)-2;
    if(lastp != lastr)
    {
        printf("\nInvalid length of replace string");
        exit(0);
    }
    else
    {
        i = start;
        for(j=0; j<=lastr; j++)
        {
            str[i] = rep[j];
            i++;
        }
    }
    return;
}

void findpattern()
{
    int i, j, inmatch;
    lasts = (strlen(str))-2;
    lastp = (strlen(pat))-2;
    int endmatch;
    for(endmatch = lastp; endmatch<=lasts; endmatch++, start++)
    {
        if(str[endmatch] == pat[lastp])
        {
            inmatch = start;
            j=0;
            while(j<lastp)
            {
                if(str[inmatch] == pat[j])
                {
                    inmatch++;
                    j++;
                }
                else
                {
                    break;
                }
            }
            if(j == lastp)
            {
                patternfound = 1;
                replacepattern();
            }
        }
    }
    return;
}

void main()
{
    printf("\n ENTER THE MAIN STRING (STR) : ");
    fgets(str, 50, stdin);

    printf("\n ENTER THE PATTERN TO BE MATCHED (PTR) : ");
    fgets(pat, 50, stdin);
    
    printf("\n ENTER THE STRING TO BE REPLACED (REP) : ");
    fgets(rep, 50, stdin);

    printf("\n THE STRING BEFORE MATCH IS :\n %s", str);

    findpattern();
            
    if(patternfound == 0)
        printf("\n THE PATTERN IS NOT FOUND IN THE MAIN STRING ");
    else
        printf("\n THE STRING AFTER PATTERN MATCH AND REPLACE IS : %s ",str);
    return;
}
