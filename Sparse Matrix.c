#include<stdio.h>
int arr[100][100],sm[100][3],c=0,r=1;

void sparse(int m,int n)
{   
    sm[0][0]=m;
    sm[0][1]=n;
    sm[0][2]=c;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(arr[i][j]!=0)
            {
                sm[r][0]=i;
                sm[r][1]=j;
                sm[r][2]=arr[i][j];
                r++;
            }
        }
    }
}

void display()
{ 
    printf("\nSparse Matrix:\n");
    printf("R   C   V\n");
    for(int i=0;i<r;i++)
    {   
        printf("\n");
        for(int j=0;j<3;j++)
        {
            printf("%d\t",sm[i][j]);
        }
    }
}

int main()
{
    int n,m;
    printf("Enter number of rows and columns of array: ");
    scanf("%d%d",&m,&n);
    printf("\nEnter array elements: ");
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&arr[i][j]);
            if(arr[i][j]!=0)
                c++;
        }
    }
    sparse(m,n);
    display();
}
