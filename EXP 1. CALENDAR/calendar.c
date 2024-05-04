#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Day 
{
 char* daynamw;
 int date;
 char* activity;
};

struct Day* createDay() 
{
    struct Day* newDay = (struct Day*)malloc(sizeof(struct Day));
    newDay->daynamw = (char*)malloc(20 * sizeof(char));
    newDay->activity = (char*)malloc(100 * sizeof(char));
    printf(" >>> ENTER DATE : ");
    scanf("%d", &(newDay->date));
    printf(" >>> ENTER DAY NAME : ");
    scanf("%s", newDay->daynamw);
    printf(" >>> ENTER DAY ACTIVITY : ");
    scanf(" %[^\n]", newDay->activity);
    return newDay;
}

void read(struct Day* calendar[], int size) 
{
    for (int i = 0; i < size; i++) 
    {
        printf(" >>> ENTER DETAILS OF DAY %d :\n", i + 1);
        calendar[i] = createDay();
    }
}

void display(struct Day* calendar[], int size) 
{
    printf("\n\t*******\tWEEK'S ACTIVITY DETAILS\t*******\n");
    printf("+-------+-----------------------+---------------+---------------+\n");
    printf("|   DAY\t|\tDAY NAME \t|\tDATE\t| ACTIVITY\t|\n");
    printf("+-------+-----------------------+---------------+---------------+\n");
    for (int i = 0; i < size; i++) 
    {
        printf("|   %d\t|\t%-10s\t|\t%d\t| %-10s\t|\n",i + 1,calendar[i]->daynamw,calendar[i]->date,calendar[i]->activity);
    }
    printf("+-------+-----------------------+---------------+---------------+\n");
}

void freeMemory(struct Day* calendar[], int size) 
{
    for (int i = 0; i < size; i++) 
    {
        free(calendar[i]->daynamw);
        free(calendar[i]->activity);
        free(calendar[i]);
    }
}


int main() 
{
    int weekSize;
    printf(" >>> ENTER THE NO OF DAYS : ");
    scanf("%d",&weekSize);
    struct Day* week[weekSize];
    read(week, weekSize);
    display(week, weekSize);
    freeMemory(week, weekSize);
    return 0;
}