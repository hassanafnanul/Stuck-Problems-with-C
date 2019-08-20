#include<stdio.h>
#define max 10

int stuck[max], top = -1;

push(int data)
{
    if(top == max-1)
        printf("\nStuck Overflow.");
    else
        stuck[++top] = data;
}

pop()
{
    if(top == -1)
        printf("Stuck underflow.");
    else
        top--;
}

display()
{
    int i;
    if(top == -1)
        printf("Stuck Underflow.");
    else
        for(i=0; i<=top; i++)
            printf("%4d", stuck[i]);
}

main()
{
    int i, n, a, j, m;
    do
    {
        printf("Number of data:  ");
        scanf("%d", &n);
        printf("Submit Your Data:\n");
        for(i=0; i<n; i++)
        {
            scanf("%d", &a);
            push(a);
        }
        printf("\n\nCheck your data:  ");
        display();
        printf("\n\nNumber of data you wanna remove: ");
        scanf("%d", &m);
        for(j=0; j<m; j++)
            pop();
        printf("\n\nYour data after removing:  ");
        display();
        printf("\nDo you wanna continue? (y/n)\n\n");
    }
    while(getch() == 'y' || getch() == 'Y');
}
