#include <stdio.h>
#include<stdlib.h>

struct node{
  int info;
  struct node* next;
}*head=,*n,*tptr,*ttptr;

void insbeg(){
  n=(struct node*)malloc(sizeof(struct node));
  printf("\nEnter value: ");
  scanf("%d",&n->info);
  n->next=head;
  head=n;
}

void insend(){
  n=(struct node*)malloc(sizeof(struct node));
  printf("\nEnter value: ");
  scanf("%d",&n->info);
  tptr=head;
  while(tptr->next!=NULL){
    tptr=tptr->next;
  }
  tptr->next=n;
  n->next=NULL;
}

void inspos(){
  int val;
  printf("\nEnter value after which new node should be inserted: ");
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
    n->next=tptr->next;
    tptr->next=n;
  }

}

void delbeg(){
  if(head==NULL){
    printf("Enmpty List!");
  }
  else{
    tptr=head;
    head=head->next;
    free(tptr);
  }
}

void delend(){
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

void delpos(){
  if(head==NULL){
    printf("Enmpty List!");
  }
  else{
    int val;
    printf("\nEnter value which should be deleted: ");
    scanf("%d",&val);
    tptr=head;
    while(tptr->info!=val && tptr->next!=NULL){
      tptr=tptr->next;
    }
    if(tptr->next==NULL){
      printf("\nValue not in list!");
    }
    else{
      ttptr=head;
      while(ttptr->next!=tptr){
        ttptr=ttptr->next;
      }
      ttptr->next=tptr->next;
      free(tptr);
    }
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
