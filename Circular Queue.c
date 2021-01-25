#include<stdio.h>
int arr[100],f=-1,r=-1;

void enqueue(int n)
{
        if(f==(r+1)||((f==0)&&(r==(n-1))))
        {
                printf("Queue full!");
        }
        else
        {
                int el;
                printf("\nEnter element:");
                scanf("%d",&el);
                if((f==-1)&&(r==-1))
                {
                        f=0;
                        r=0;
                }
                else if(r==(n-1))
                {
                        r=0;
                }     
                else
                {
                        r++;
                }
                arr[r]=el;
        }   
}

void dequeue(int n)
{
        if((f==-1)&&(r==-1))
        {
                printf("Cannot remove element , queue is empty!");
        }
        else if((f==0)&&(r==0))
        {
                printf("Element removed is %d",arr[f]);
                f=-1;
                r=-1;
        }
        else if(f==(n-1))
        {
                printf("Element removed is %d",arr[f]);
                f=0;
        }
        else
        {
                printf("Element removed is %d",arr[f]);
                f++;
        }
        
}

void display(int n)
{
        if((f==-1)&&(r==-1))
        {
                printf("Queue is empty!");
        }
        else if ((f==0)&&(r==0))
        {
                printf("Only one element: %d",arr[0]);
        }
        
        else
        {
                if(f<r)
                {
                        for(int i=f;i<=r;i++)
                        {
                                printf("%d\t",arr[i]);
                        }
                }
                else
                {
                        for(int i=0;i<=r;i++)
                        {
                                printf("%d\t",arr[i]);
                        } 
                        for(int i=f;i<n;i++)
                        {
                                printf("%d\t",arr[i]);
                        }
                        
                }
                
        }
        
}

void main()
{
        int ch,n;
        printf("\nEnter array size:");
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
                case 2: dequeue(n);
                        break;
                case 3: display(n);
                        break;
                case 4: exit(0);
                default:printf("Invalid Entry!");
                        break;
        }
    }  
}


