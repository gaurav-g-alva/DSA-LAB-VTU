#include<stdio.h>
#include<math.h>
void tower(int n, char A,  char B, char c);

void main()
{
    int n;
    printf("\nEnter the number of disks: ");
    scanf("%d", &n);
    tower(n, 'A', 'B', 'C'); 
    printf("\nTotal number of moves = %0.0f", pow(2,n)-1 );
}

void tower(int n, char A,  char B, char c)    
{
    if(n == 1)
    {
        printf("\nMove disk %d from %c peg to %c peg", n,  A,  c);
        return;
    }
    tower(n-1, A,  c,  B); 
    printf("\nMove disk %d from %c peg to %c peg", n, A,  c);
    tower(n-1, B, A, c);
}
