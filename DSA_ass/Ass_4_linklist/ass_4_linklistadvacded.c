#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct largenumber{
    int digit;
    struct largenumber* next;
}node;

node* addnumberNode(node* num, int d){
    node* temp = (node*)malloc(sizeof(node));
    if(temp == NULL)
        return NULL;
    temp->digit = d; temp->next = NULL;

    if(num==NULL)
        return temp;
    
    node* ptr= num;
    while(ptr->next!=NULL)
        ptr=ptr->next;
    ptr->next=temp;
    return num;
}

void printNum(node* num){
    node* ptr=num;
    while(ptr!=NULL){
        printf("%d", ptr->digit);
        ptr = ptr->next;
    }
}

node * reverseList(node* start){
    if(start==NULL || start->next==NULL)
        return start;
    node *prev = NULL;
    node *curr = start;
    node *next = NULL;

    while (curr != NULL) {
        next = curr->next;  
        curr->next = prev; 
        prev = curr;       
        curr = next;       
    }

    return prev;  
}

node* addLists(node* num1, node* num2){
    if(num1==NULL)
        return num2;
    if(num2==NULL)
        return num1;
    
    num1 = reverseList(num1);
    num2 = reverseList(num2);
    int carry = 0, s;

    node* ptr1 = num1; node* ptr2 = num2;  node* sum = NULL;
    while(ptr1!=NULL && ptr2!=NULL){
        s=ptr1->digit + ptr2->digit + carry;
        carry = s/10;
        s%=10;
        sum = addNode(sum, s);
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    while(ptr1!=NULL){
        s=ptr1->digit + carry;
        carry = s/10;
        s%=10;
        sum = addNode(sum, s);
        ptr1 = ptr1->next;
    }
    while(ptr2!=NULL){
        s=ptr2->digit + carry;
        carry = s/10;
        s%=10;
        sum = addNode(sum, s);
        ptr2 = ptr2->next;
    }

    if(carry!=0)
        sum = addNode(sum, carry);

    num1 = reverseList(num1);
    num2 = reverseList(num2);
    sum = reverseList(sum);

    return sum;
}

int compareLists(node* n1, node* n2) {
    int len1 = 0, len2 = 0;
    node* p1 = n1; node* p2 = n2;

    while(p1!=NULL){ 
        len1++; 
        p1 = p1->next;
    }
    while(p2){
        len2++; 
        p2 = p2->next;
    }

    if(len1>len2) 
        return 1;
    if(len1<len2) 
        return -1;
    
    p1 = n1; p2 = n2;
    while(p1!=NULL && p2!=NULL) {
        if(p1->digit>p2->digit) 
            return 1;
        if(p1->digit<p2->digit) 
            return -1;
        p1 = p1->next; 
        p2 = p2->next;
    }
    
    return 0;
}

node* subtractLists(node* num1, node* num2, int* isNegative){

    if(num1 == NULL){
        *isNegative = 1;
        return num2;
    } 
    if(num2 == NULL){
        *isNegative = 0;
        return num1;
    }

    int cmp = compareLists(num1, num2);
    if (cmp < 0) {
        *isNegative = 1;
        node* temp = num1;
        num1 = num2;
        num2 = temp;
    } 
    else
        *isNegative = 0;
    
    num1 = reverseList(num1);
    num2 = reverseList(num2);
        
    int borrow = 0, d;
    node* diff = NULL;
    node* ptr1 = num1; node* ptr2 = num2;
    while(ptr2!=NULL){
        d= ptr1->digit - ptr2->digit - borrow;
        if(d<0){
            d+=10;
            borrow = 1;
        }
        else
            borrow = 0;
        diff = addNode(diff, d);
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    while(ptr1!=NULL){
        d= ptr1->digit - borrow;
        if(d<0){
            d+=10;
            borrow = 1;
        }
        else
            borrow = 0;
        diff = addNode(diff, d);
        ptr1 = ptr1->next;
    }

    diff = reverseList(diff);

    while(diff!=NULL && diff->digit == 0 && diff->next != NULL) {
        node* temp = diff;
        diff = diff->next;
        free(temp);
    }

    return diff;

}

void freeList(node* head){ 
    node* temp; 
    while(head!=NULL){ 
        temp = head; head = head->next; 
        free(temp); 
    } 
}


  typedef struct polynomiallinkedlist{
	int cofficient;
	int power;
	struct polynomiallinkedlist* next;
  } polynode;

  polynode* creatpolynomiallinklist(int coff ,int power){

	polynode * start = NULL;
	start = (polynode*)malloc(sizeof(polynode));

	if(NULL == start){
		printf(" Memory allocation for node failled ../n");
		return NULL;
	}

	start->cofficient = coff;
	start->power = power;
        start->next = NULL;

	return start;

    }

   polynomial* addNodepolynomial(polynomial * start , int coff, int power ){
          
         polynomial* P = NULL;
             P = start;
	 while(P->next){
          
           P = P->next;
 
        }

	 polynomial* temp = NULL ;
	 temp = (polynomial*)malloc(sizeof(ploynomial));

	 if(temp == NULL){
		 printf(" Memory allocation for new node failled ..\n");
		return start;
	 }
      
       temp->cofficient = coff;
       temp->power = power;       
       temp->next = NULL;

       P->next = temp;
       
      return start;
    
    }

   void printpolynomial(polynomial* start){

           if(start == NULL)
		   return;
       ploynomial* P = start;
	   printf(" ploynomial -> ");
   
	   while(P){

		  printf(" %dX^%d + ",P->cofficient,P->power);

		  P= P->next;
	   }

	   printf(" end /n");

   }
















