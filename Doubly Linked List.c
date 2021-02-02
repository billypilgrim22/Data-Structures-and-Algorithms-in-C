#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node* prev;
    struct node* next;
}*head=NULL,*tptr,*n;

void insbeg(){
    n=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter value: ");
    scanf("%d",&n->info);
    if(head==NULL){
      head=n;
      n->prev=NULL;
      n->next=NULL;
    }
    else{
      n->next=head;
      n->next->prev=n;
      n->prev=NULL;
      head=n;
    }
}

void insend(){
    n=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter value: ");
    scanf("%d",&n->info);
    if(head==NULL){
        head=n;
        n->prev=NULL;
    }
    else{
        tptr=head;
        while(tptr->next!=NULL){
            tptr=tptr->next;
        }
        n->prev=tptr;
        tptr->next=n;
        n->next=NULL;
    }
}

void inspos(){
    int val;
    printf("\nEnter value after which element should be added: ");
    scanf("%d",&val);
    tptr=head;
    while(tptr->info!=val && tptr!=NULL){
        tptr=tptr->next;
    }
    if(tptr==NULL){
        printf("\nValue not in list!");
    }
    else{
        n=(struct node*)malloc(sizeof(struct node));
        printf("\nEnter value: ");
        scanf("%d",&n->info);
        n->prev=tptr;
        n->next=tptr->next;
        tptr->next->prev=n;
        tptr->next=n;
    }
}

void delbeg(){
    if(head==NULL){
        printf("\nEmpty list!");
    }
    else{
        tptr=head;
        if(tptr->next==NULL){
          head=NULL;
          free(tptr);
        }
        else{
          head=tptr->next;
          tptr->next->prev=NULL;
          free(tptr);
        }
    }
}

void delend(){
    if(head==NULL){
        printf("\nEmpty list!");
    }
    else{
        tptr=head;
        if(tptr->next==NULL){
          head=NULL;
          free(tptr);
        }
        else{
          while(tptr->next!=NULL){
            tptr=tptr->next;
          }
          tptr->prev->next=NULL;
          free(tptr);
        }
    }
}

void delpos(){
    if(head==NULL){
        printf("\nEmpty list!");
    }
    else{
        int val;
        printf("\nEnter value of element to be deleted: ");
        scanf("%d",&val);
        tptr=head;
        while(tptr->info!=val && tptr!=NULL){
            tptr=tptr->next;
        }
        if(tptr==NULL){
            printf("\nValue not in list!");
        }
        else{
            tptr->prev->next=tptr->next;
            tptr->next->prev=tptr->prev;
            free(tptr);
        }
    }
}

void display(){
    if(head==NULL){
        printf("\nEmpty list!");
    }
    else{
        tptr=head;
        printf("\nForward: ");
        while(tptr!=NULL){
            printf("%d ->",tptr->info);
            tptr=tptr->next;
        }
        tptr=head;
        while(tptr->next!=NULL){
            tptr=tptr->next;
        }
        printf("\nBackward: ");
        while(tptr!=NULL){
            printf(" <- %d",tptr->info);
            tptr=tptr->prev;
        }
    }
}

int main(){
    int ch;
    printf("Linked List Menu\n1.Insbeg\n2.Insend\n3.Inspos\n4.Delbeg\n5.Delend\n6.Delpos\n7.Display\n8.Exit");
    while(1){
        printf("\nEnter choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1: insbeg();
                break;
        case 2: insend();
                break;
        case 3: inspos();
                break;
        case 4: delbeg();
                break;
        case 5: delend();
                break;
        case 6: delpos();
                break;  
        case 7: display();
                break;
        case 8: exit(0);
        default:printf("\nInvalid Entry!");
                break;
        }
    }
    return 0;
}
