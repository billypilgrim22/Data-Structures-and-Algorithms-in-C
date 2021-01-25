#include<stdio.h>
int arr[100],t=0;

void enqueue(int n)
{
    int el;
    if(t==n)
    {
        printf("\nQueue full!");
    }
    else
    {
        printf("\nEnter element");
        scanf("%d",&el);
        arr[t++]=el;
    }
    
}

void dequeue()
{
    if(t<0)
    {
        printf("Queue empty!");
    }
    else
    {
        printf("Dequeued element: %d",arr[0]);
        for(int i=0;i<t;i++)
            arr[i]=arr[i+1];
        t--;
    }
}

void display()
{
    for(int i=0;i<t;i++)
        printf("%d\t",arr[i]);
}

void main()
{   
    int n,ch;
    printf("\nEnter size of queue:");
    scanf("%d",&n);
    printf("\nMenu:\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit");
    while(1)
    {
        printf("\nEnter choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: enqueue(n);
                    break;
            case 2: dequeue();
                    break;
            case 3: display();
                    break;
            case 4: exit(0);
            default:printf("Invalid Entry!");
                    break;
        }
    }
}