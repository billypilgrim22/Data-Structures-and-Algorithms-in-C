#include <stdio.h>
#include<stdlib.h>

struct node{
  int info;
  struct node* next;
}*head=NULL,*n,*tptr,*ttptr;


void push(){
  n=(struct node*)malloc(sizeof(struct node));
  printf("\nEnter value: ");
  scanf("%d",&n->info);
  if(head==NULL){
    head=n;
    n->next=NULL;
  }
  else{
    tptr=head;
    while(tptr->next!=NULL){
      tptr=tptr->next;
    }
    tptr->next=n;
    n->next=NULL;
  }
}

void pop(){
  if(head==NULL){
    printf("Enmpty List!");
  }
  else{
    tptr=head;
    while(tptr->next->next!=NULL){
      tptr=tptr->next;
    }
    ttptr=tptr->next;
    tptr->next=NULL;
    free(ttptr);
  }
}

void display(){
  if(head==NULL){
    printf("Enmpty List!");
  }
  else{
    tptr=head;
    while(tptr!=NULL){
      printf("%d -> ",tptr->info);
      tptr=tptr->next;
    }
  }
}

int main(){
    int ch;
    printf("Stack Menu\n1.Push\n2.Pop\n3.Display\n4.Exit");
    while(1){
        printf("\nEnter choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1: push();
                break;
        case 2: pop();
                break;
        case 3: display();
                break;
        case 4: exit(0);
                break;
        default:printf("\nInvalid Entry!");
                break;
        }
    }
    return 0;
}
