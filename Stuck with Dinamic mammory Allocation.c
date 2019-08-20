#include<stdio.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head;
int top = -1;

push(int a)
{
    struct node *temp, *var;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = a;
    temp->next = NULL;
    top++;

    if(head == NULL)
        head = temp;
    else
    {
        var = head;
        while(var->next != NULL)
            var = var->next;
        var->next = temp;
    }
}

pop()
{
    int j= -1;
    struct node *i = head;
    if(top == -1)
        printf("Stuck underflow.");
    else
    {
        top--;
        while(j != top-1)
        {
            j++;
            i = i->next;
        }
        i->next = NULL;
    }

}

display()
{
    int j= -1;
    struct node *i = head;
    while(j != top)
    {
        printf("%d   ", i->data);
        j++;
        i = i->next;
    }
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
