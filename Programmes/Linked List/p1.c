#include<stdio.h>
#include<stdlib.h>


struct Node
{
    int data;
    struct Node* next;
    
} ;


struct Node* createlinkedlist(  int A[] ,int n){
   struct Node* p = (struct Node*)malloc(sizeof(struct Node));
   struct Node* last;
 
   p->data = A[0];
   p->next = NULL;
   last = p;
   for (int i = 1; i < n; i++)     
   {
    
   struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    //tempary node 
    temp->data = A[i];
    temp->next = NULL;    
   // last node pointing to next 
    last->next = temp;
    last = temp;

   }
return p;
}
void displaylist(struct Node *head){
       struct Node* R = head;
   while (R != NULL)
   {
    printf("%d ->",R->data);
    R = R->next;
   }
   printf("\n");    
   }
int Countlink( struct Node* p ){
    struct Node* R = p;
    int c =0 ;
    while (R)
    {
        c++;
        R = R->next;
    }
  return c;  

}

int Maxeleinlink( struct Node* p ){
    struct Node* R = p;
    int max = -32769 ;
    while (R)
    {
        if (R->data>max)
        {
            max = R->data;
        }
        
        R = R->next;
    }
  return max;  

}

int Searchinlink( struct Node* p, int key ){
    struct Node* R = p;
    while (R)
    {
        if (R->data == key)
        return 1;

        R = R->next;
    }
  return 0;  

}

int insertion ( struct Node * p , int value, int index){

    struct Node * R = p; 
     struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    
    temp->data = value;
if(index<1){
   temp->next = p;
   p = temp;

}
else{
   for (int i = 0; i < index-1; i++)
   {
    R = R->next;
   }
   

    temp->next = R->next;
    R->next = temp; 
}
}

int deletation( struct Node * p , int value){

    struct Node * R = p; 
     struct Node* prev;

     if(p->data == value){
      p = p->next;
      free(R);
      return 1;
     }
     prev = R;
     R = R->next ;

   while (R)
   {
    if(R->data = value){
     prev->next = R->next;
     free(R);
     return 1;
    }
     prev = R;
     R = R->next ;
   }
   
   return 0;


}


int Isshorted( struct Node* p ){
    struct Node* R = p;
    int x = -32769;
    while (R)
    {
        if (R->data < x)
        return 0;
        x = R->data;
        R = R->next;
    }
  return 1;  

}

void Reversig(struct Node* p){
    struct Node * R = p;
    struct Node * q = NULL;
    struct Node * f = NULL;
    while (R)
    {
        q = R;
        f = R;
        R = R->next;
        q->next = f;
    }
    p = q;

}

int main(){

    int A[] = {1  ,2,3,4,5,6,67};
   struct Node* head = createlinkedlist(A,5);

   displaylist(head);
   
   printf("%d\n",Countlink(head));
   int Max = Maxeleinlink(head);
   printf("%d\n",Max);

   
   printf("%d\n", Searchinlink(head,11 ));
   printf("%d\n", Isshorted(head ));
   insertion(head,10,1);
   displaylist(head);

   Reversig(head);
   displaylist(head);

    return 0;

   }
   


   


