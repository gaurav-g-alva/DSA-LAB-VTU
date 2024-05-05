#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int stack[MAX];
int top = -1;

//TO PUSH STACK ELEMENT 
void push(int item)
{
  if(top == MAX-1)
  {
    printf("\n~~~~Stack overflow~~~~");
    return;
  }
  top = top + 1 ;
  stack[top] = item;
}

//TO POP STACK ELEMENTS
int pop()
{
  int item;
  if(top == -1)
  {
    printf("\n~~~~Stack underflow~~~~");
    return -1;
  }
  item = stack[top];
  top = top - 1;
  return item;
}

//TO DISPLAY STACK CONTENTS
void display()
{
  int i;
  if(top == -1)
  {
    printf("\n~~~~Stack is empty~~~~");
    return;
  }
  printf("Stack elements are:\n ");
  for(i=top; i>=0 ; i--)
    printf("\n| %d |", stack[i]);
}

//TO CHECK WEATHER THE STACK ELEMENTS ARE PALINDROME
void palindrome()
{
  int flag=1,i;
  printf(" Stack content are : ");
  for(i=top; i>=0 ; i--)
  {
    printf("\n| %d |", stack[i]);
  }

  printf("\n\nReverse of stack content are :");

  for(i=0; i<=top; i++)
  {
    printf("\n| %d |", stack[i]);
  }
  for(i=0; i<=top/2; i++)
  {
    if( stack[i] != stack[top-i] )
    {
      flag = 0;
      break;
    }
  }
  if(flag == 1)
  {
    printf("\nIt is palindrome number");
  }
  else
  {
    printf("\nIt is not a palindrome number");
  }
}

//MAIN FUNCTION
void main()
{
  int choice, item;
  printf("~~~~~~ Menu ~~~~~~~ ");
  printf("\n >>1.PUSH AN ELEMENT ");
  printf("\n >>2.POP AN ELEMENT ");
  printf("\n >>3.PALINDROME DEMO ");
  printf("\n >>4.DISPLAY ");
  printf("\n >>5.EXIT ");
  while(1)
  {
    printf("\n Enter your choice : ");
    scanf("%d", &choice);
    switch(choice)
    {
      case 1: printf(" Enter an element to be pushed: ");
              scanf("%d", &item);
              push(item);
              break;
      case 2: item = pop();
              if(item != -1)
              printf(" Element popped is: %d\n", item);
              break;
      case 3: palindrome();
              break;
      case 4: display();
              break;
      case 5: printf(" EXIT ");
              exit(1);
      default:  printf(" Please enter valid choice ") ;
                break;
    }
  }
}
