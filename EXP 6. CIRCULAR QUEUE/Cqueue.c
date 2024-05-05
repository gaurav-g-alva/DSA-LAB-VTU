#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define QUEUE_SIZE 5

void InsertRear(char [],int*,int*,char);
char DeleteFront(char[],int*,int*);
void Display(char [],int,int);
bool QueueFull(int,int);
bool QueueEmpty(int,int);

int main()
{
    char myQueue[QUEUE_SIZE];
    int iFront=-1,iRear=-1;
    int iChoice;
    char cElem;
    printf("\n QUEUE OPERATIONS \n");
	printf("=====================");
	printf("\n1.Q INSERT \n2.Q DELETE \n3.Q DISPLAY \n4.Exit \n");
    for(;;)
    {
	    
	    printf(" Enter your choice : ");
	    scanf("%d",&iChoice);
	    getchar();	
	    switch(iChoice)
	    {
		    case 1: if(!QueueFull(iFront,iRear))
		            {
		                printf(" Enter an element : ");
		                scanf("%c",&cElem);
		                InsertRear(myQueue,&iFront,&iRear,cElem);
                        printf("\n");
		            }
		            else
		            {
		                printf(" Queue is Full \n");
		            }

			        break;
		    case 2: if(!QueueEmpty(iFront,iRear))
		            {
		                cElem = DeleteFront(myQueue,&iFront,&iRear);
		                printf(" Deleted element is %c \n", cElem);
		            }
		            else
		            {
		                printf(" Queue is Empty \n");
		            }

			        break;
		    case 3: if(!QueueEmpty(iFront,iRear))
		            {
		                printf(" Contents of the Queue is: \n");
		                Display(myQueue,iFront,iRear);
		            }
		            else
		            {
		                printf(" Queue is Empty  \n");
		            }

			        break;
			
		    case 4: printf("EXIT");
                    exit(0);
		
		    default: printf(" Invalid choice \n");

			    break;
	    }
    }
    return 0;
}

bool QueueFull(int front,int rear)
{
    if((rear+1)%QUEUE_SIZE==front)
        return true;
    else
        return false;
}

bool QueueEmpty(int front,int r)
{
    if(front==-1)
        return true;
    else
        return false;
}

void InsertRear(char queue[],int *front,int *rear,char cVal)
{
    if(*front==-1)
    {
        *front=*front+1;
        *rear=*rear+1;
    }
    else
        *rear=(*rear+1)%QUEUE_SIZE;
        
    queue[*rear]=cVal;
}

char DeleteFront(char queue[],int *front,int *rear)
{
    char cElem;
    cElem=queue[*front];
    
    if(*front==*rear)
    {
        *front=-1;
        *rear=-1;
    }
    else
    {
        *front=(*front+1)%QUEUE_SIZE;
    }
    return cElem;
}

void Display(char queue[],int front,int rear)
{
    int i;
    if(front<=rear)
    {
        for(i=front;i<=rear;i++)
        {
            printf("%c \t",queue[i]);
        }
        printf("\n");    
    }
    else
    {
        for(i=front;i<=QUEUE_SIZE-1;i++)
        {
            printf("%c \t",queue[i]);
        }
        for(i=0;i<=rear;i++)
        {
            printf("%c \t",queue[i]);
        }
        printf("\n");    
    }
}
