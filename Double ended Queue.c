#include<stdio.h>
int arr[100],t=0;

void enqueuefront(int n)
{
    int el;
    if(t==n)
    {
        printf("\nQueue full!");
    }
    else
    {
        for(int i=t;i>0;i--)
        {
            arr[t]=arr[t-1];
        }
        printf("\nEnter element: ");
        scanf("%d",&el);
        arr[0]=el;
        t++;
    }
}

void enqueueback(int n)
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

void dequeuefront()
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

void dequeueback()
{
    if(t<0)
    {
        printf("Queue empty!");
    }
    else
    {
        printf("Dequeued element: %d",arr[t-1]);
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
    int n,ch1,ch2;
    printf("\nEnter size of queue:");
    scanf("%d",&n);
    printf("\nDeQueue Menu\n1. Input restricted\n2. Output restricted\nEnter choice: ");
    scanf("%d",&ch1);
    if(ch1==1)
    {
        printf("\nMenu:\n1. Enqueue\n2. Dequeue(Front)\n3. Dequeue(Back)\n4. Display\n5. Exit");
        while(1)
        {
            printf("\nEnter choice:");
            scanf("%d",&ch2);
            switch(ch2)
            {
                case 1: enqueueback(n);
                        break;
                case 2: dequeuefront();
                        break;
                case 3: dequeueback();
                        break;
                case 4: display();
                        break;
                case 5: exit(0);
                default:printf("Invalid Entry!");
                        break;
            }
        }
    }
    else if(ch1==2)
    {
        printf("\nMenu:\n1. Enqueue(Front)\n2. Enqueue(Back)\n3. Dequeue\n4. Display\n5. Exit");
        while(1)
        {
            printf("\nEnter choice:");
            scanf("%d",&ch2);
            switch(ch2)
            {
                case 1: enqueuefront(n);
                        break;
                case 2: enqueueback(n);
                        break;
                case 3: dequeuefront();
                        break;
                case 4: display();
                        break;
                case 5: exit(0);
                default:printf("Invalid Entry!");
                        break;
            }
        }
    }
}