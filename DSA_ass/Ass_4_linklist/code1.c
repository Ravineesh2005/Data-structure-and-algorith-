#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct listNode
{
    int data;
    struct listNode * next;
} node ;

node* addnode(node * start, int n1){

    node*p = start ;
    
    node * temp = (node*)malloc(sizeof(node));
    temp->data =n1; 
    temp->next = NULL;
while(p->next != NULL){
    p = p->next;
}
p->next = temp;
return start;
}
node* addmorenode(node* start){

    node * p = start;
    int data ;
    int choice = 1;
    while (choice== 1 ){

        node * temp = (node*)malloc(sizeof(node));
        printf("enter data for your node \n");
        scanf("%d",&data);
        temp->data = data;
        temp->next = NULL;  
        p->next = temp;
        p = temp;
        printf("enter 1 to aad more node \n ");
        scanf("%d",&choice);
    }

    return start;
}

void print(node* start){
    node *p = start;
    printf(" your link list .....\n ");
    while(p != NULL){
        printf ( "  %d  " , p->data);
        p = p->next;
    } 
     printf("\n");
}

int main(){

    node * start = (node*)malloc(sizeof(node));
    start->data = 1;
    start->next = NULL;
    start = addmorenode(start);
     print(start);
     
     start = addnode(start , 5);
     print(start);
// node *p = start;
// while ( p != NULL){

// }


} 