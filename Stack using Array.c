#include<stdio.h>
int arr[100],el,t=0;

void push(int n)
{
    if(t==n)
    {
        printf("Stack Overflow!");
     
    }
    else
    {   printf("\nEnter element:");
        scanf("%d",&el);
        arr[t++]=el;
    }
}

void pop()
{
    if(t<0)
    {
        printf("Stack empty!");
    }
    else
        printf("\nElement popped is %d",arr[--t]);
}

void display()
{
    for(int i=0;i<t;i++)
    {
        printf("%d\t",arr[i]);
    }
}

int main()
{
    int n;
    printf("Enter size:");
    scanf("%d",&n);
    printf("Menu:\n1. Push\n2. Pop\n3. Display\n4. Exit");
    int ch;
    while(1)
    {
        printf("\nEnter choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: push(n);
                    break;
            case 2: pop();
                    break;
            case 3: display();
                    break;
            case 4: exit(0);
            default:printf("Invalid entry");
                    break;
        }
    }
    
}