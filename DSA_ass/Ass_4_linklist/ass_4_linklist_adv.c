#include<stdio.h>
#include<stdlib.h>
#include<string.h>

  typedef struct polynomiallinkedlist{
	int coff;
	int power;
	struct polynomiallinkedlist* next;
  } polynomial;


  polynomial* creatpolynomiallinklist(int coff ,int power){

	polynomial * start = NULL;
	start = (polynomial*)malloc(sizeof(polynomial));

	if(NULL == start){
		printf(" Memory allocation for node failled ../n");
		return NULL;
	}

	start->coff = coff;
	start->power = power;
        start->next = NULL;

	return start;

    }

   polynomial* addNodepolynomial(polynomial * start , int coff, int power ){
          
         polynomial* p = NULL;
             p = start;

	 polynomial* temp = NULL ;
	 temp = (polynomial*)malloc(sizeof(polynomial));

	 if(temp == NULL){
		 printf(" Memory allocation for new node failled ..\n");
		return start;
	 }

       temp->coff = coff;
       temp->power = power;       
       temp->next = NULL;
       
       if(power>p->power){
	       temp->next = start;
	       start = temp;
	       return start;
	      }

       if(power == p->power){
	       p->coff = p->coff + coff;
	       free(temp);
	       return start;
       }
      polynomial* prev = NULL;

       while((NULL != p)){
             
          if(power == p->power){
              p->coff = p->coff + coff;
	      free(temp);
	      return start;
	  }

	 if(p->power < power){
	   
		 prev->next = temp;
		 temp->next = p;
		 return start;
	 }
	prev = p;
	p = p->next;   
      
       }
             
       prev->next = temp;

      return start;
    
    }

   void printpolynomial(polynomial* start){

           if(start == NULL)
		   return;
       polynomial* P = start;
	   printf(" ploynomial -> ");
   
	   while(P){

		  printf(" %dX^%d + ",P->coff,P->power);

		  P= P->next;
	   }

	   printf(" end \n");

   }
  //  polynomial* Addpolynomial 

   int main(){


   polynomial* p1 = creatpolynomiallinklist(23,6);
   p1 =   addNodepolynomial(p1,23,4);
   p1 =   addNodepolynomial(p1,23,4);
   p1 =   addNodepolynomial(p1,23,7);
   p1 =   addNodepolynomial(p1,23,5);
   p1 =   addNodepolynomial(p1,23,7);
   p1 =   addNodepolynomial(p1,23,8);
    
    
      
   polynomial* p2 = creatpolynomiallinklist(23,6);
      p2 =   addNodepolynomial(p2,23,4);
      p2 =   addNodepolynomial(p2,23,4);
      p2 =   addNodepolynomial(p2,23,7);
      p2 =   addNodepolynomial(p2,23,5);
      p2 =   addNodepolynomial(p2,23,7);
      p2 =   addNodepolynomial(p2,23,8);
     printpolynomial(p2);


   return 0;
   }





