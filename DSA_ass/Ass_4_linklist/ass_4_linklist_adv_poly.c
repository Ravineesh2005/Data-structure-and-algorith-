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

		  printf("[ %dX^%d ] + ",P->coff,P->power);

		  P= P->next;
	   }

	   printf(" end \n");

   }

    polynomial* Addpolynomial(polynomial* poly1 , polynomial* poly2 ){
        
      if ( (poly1 == NULL)&&(poly2 == NULL))
        return NULL;

        if(poly1 == NULL)
        return poly2;
       
        if(poly2 == NULL)
        return poly1;

       polynomial * polysum = NULL;
       polysum = (polynomial*)malloc(sizeof(polynomial));
       polynomial *  p1 = poly1;
       polynomial *  p2 = poly2;
       
      if(p1->power == p2->power){
        polysum->power = p1->power ;
        polysum->coff = p1->coff + p2->coff;
        p1 = p1->next;
        p2 = p2->next;
      }

      else if(p1->power > p2->power){
        polysum->power = p1->power ;
        polysum->coff = p1->coff ;
           p1 = p1->next;
      }

      else if(p1->power < p2->power){
        polysum->power = p2->power ;
        polysum->coff =  p2->coff;
           p2 = p2->next;
      }

      polysum->next = NULL;
      polynomial* psum = polysum;

      while((p1 != NULL )&&(p2 != NULL)){

         if(p1->power == p2->power){

          polynomial* temp1 = NULL;
          temp1 = (polynomial*)malloc(sizeof(polynomial));

          temp1->power = p1->power ;
          temp1->coff = p1->coff + p2->coff;
          temp1->next = NULL;
          psum->next = temp1;
          psum = psum->next;
          p1 = p1->next;
          p2 = p2->next;
       if((p1 == NULL)||(p2 == NULL))
       break;
      }

       if(p1->power > p2->power){
          polynomial* temp2 = NULL;
          temp2 = (polynomial*)malloc(sizeof(polynomial));

          temp2->power = p1->power ;
          temp2->coff = p1->coff ;
          temp2->next = NULL;
          psum->next = temp2;
          psum = psum->next;
          p1 = p1->next;
          if((p1 == NULL)||(p2 == NULL))
          break;
       
      }

      if(p1->power < p2->power){
           polynomial* temp3 = NULL;
          temp3 = (polynomial*)malloc(sizeof(polynomial));

          temp3->power = p2->power ;
          temp3->coff =  p2->coff;
          temp3->next = NULL;
          psum->next = temp3;
          psum = psum->next;
          p2 = p2->next;
          if((p1 == NULL)||(p2 == NULL))
          break;
      }

      } 
       if(p1 == NULL){

        while(p2 != NULL){
           polynomial* temp3 = NULL;
          temp3 = (polynomial*)malloc(sizeof(polynomial));

          temp3->power = p2->power ;
          temp3->coff =  p2->coff;
          temp3->next = NULL;
          psum->next = temp3;
          psum = psum->next;
          p2 = p2->next;
        }
       } 

       if(p2 == NULL){

        while(p1 != NULL){
             polynomial* temp2 = NULL;
          temp2 = (polynomial*)malloc(sizeof(polynomial));

          temp2->power = p1->power ;
          temp2->coff = p1->coff ;
          temp2->next = NULL;
          psum->next = temp2;
          psum = psum->next;
          p1 = p1->next;
        }
       } 


      return polysum;

    } 

    polynomial* deductpolynomial(polynomial* poly1 , polynomial* poly2 ){
        
      if ( (poly1 == NULL)&&(poly2 == NULL))
        return NULL;

        if(poly1 == NULL)
        return poly2;
       
        if(poly2 == NULL)
        return poly1;

       polynomial * polydeduct = NULL;
       polydeduct = (polynomial*)malloc(sizeof(polynomial));
       polynomial *  p1 = poly1;
       polynomial *  p2 = poly2;
       
      if(p1->power == p2->power){
        polydeduct->power = p1->power ;
        polydeduct->coff = p1->coff - p2->coff;
        p1 = p1->next;
        p2 = p2->next;
      }
      else if(p1->power > p2->power){
        polydeduct->power = p1->power ;
        polydeduct->coff = p1->coff ;
           p1 = p1->next;
      }

      else if(p1->power < p2->power){
        polydeduct->power = p2->power ;
        polydeduct->coff =  -p2->coff;
           p2 = p2->next;
      }

      polydeduct->next = NULL;
      polynomial* psum = polydeduct;

      while((p1 != NULL )&&(p2 != NULL)){

         if(p1->power == p2->power){

          polynomial* temp1 = NULL;
          temp1 = (polynomial*)malloc(sizeof(polynomial));

          temp1->power = p1->power ;
          temp1->coff = p1->coff - p2->coff;
          temp1->next = NULL;
          psum->next = temp1;
          psum = psum->next;
          p1 = p1->next;
          p2 = p2->next;
       if((p1 == NULL)||(p2 == NULL))
       break;
      }

       if(p1->power > p2->power){
          polynomial* temp2 = NULL;
          temp2 = (polynomial*)malloc(sizeof(polynomial));

          temp2->power = p1->power ;
          temp2->coff = p1->coff ;
          temp2->next = NULL;
          psum->next = temp2;
          psum = psum->next;
          p1 = p1->next;
          if((p1 == NULL)||(p2 == NULL))
          break;
       
      }

      if(p1->power < p2->power){
           polynomial* temp3 = NULL;
          temp3 = (polynomial*)malloc(sizeof(polynomial));

          temp3->power = p2->power ;
          temp3->coff =  -p2->coff;
          temp3->next = NULL;
          psum->next = temp3;
          psum = psum->next;
          p2 = p2->next;
          if((p1 == NULL)||(p2 == NULL))
          break;
      }

      } 
       if(p1 == NULL){

        while(p2 != NULL){
           polynomial* temp3 = NULL;
          temp3 = (polynomial*)malloc(sizeof(polynomial));

          temp3->power = p2->power ;
          temp3->coff =  -p2->coff;
          temp3->next = NULL;
          psum->next = temp3;
          psum = psum->next;
          p2 = p2->next;
        }
       } 

       if(p2 == NULL){

        while(p1 != NULL){
             polynomial* temp2 = NULL;
          temp2 = (polynomial*)malloc(sizeof(polynomial));

          temp2->power = p1->power ;
          temp2->coff = p1->coff ;
          temp2->next = NULL;
          psum->next = temp2;
          psum = psum->next;
          p1 = p1->next;
        }
       } 


      return polydeduct;

    } 

     polynomial* constructpoly1(){

            int R = 1;
       polynomial* p1 = NULL;

     printf(" constrct polynomial 1st \n");
       int c;
       int p;
       while(R == 1){
          if(p1 == NULL){
         printf("Enter power  : ");
          scanf("%d",&p);
          printf("Enter cofficient : ");
          scanf("%d",&c);
          p1 = creatpolynomiallinklist(c,p);
        }
        else{
          printf("Enter power  : ");
          scanf("%d",&p);
          printf("Enter cofficient : ");
          scanf("%d",&c);
          p1 =   addNodepolynomial(p1,c,p);
        }  
        printf("enter 1 to add more term  \n ");
        scanf("%d",&R);
       }
    return p1;
     }


     polynomial* constructpoly2(){

            int R = 1;
       polynomial* p2 = NULL;

     printf(" constrct polynomial 2nd \n");
       int c;
       int p;
       while(R == 1 ){
          if(p2== NULL){
         printf("Enter power  : ");
          scanf("%d",&p);
          printf("Enter cofficient : ");
          scanf("%d",&c);
          p2 = creatpolynomiallinklist(c,p);
        }
        else{
          printf("Enter power  : ");
          scanf("%d",&p);
          printf("Enter cofficient : ");
          scanf("%d",&c);
          p2 =   addNodepolynomial(p2,c,p);
        }  
        printf("enter 1 to add more term  \n ");
        scanf("%d",&R);
       }
    return p2;
     }


   int main(){
    polynomial* p1 = NULL;
    polynomial* p2 = NULL; 
   int choice = 0;

           do {
        printf(" \n----------------------------------------\n");
        printf(" POLYNOMIAL OPERATIONS MENU\n");
        printf(" ----------------------------------------\n");
        printf(" 1. to construct polynomial 1 (P1) , ");
        printf(" 2. to construct Polynomial 2 (P2)\n");
        printf(" 3. Print Polynomial 1 (P1) , ");
        printf(" 4. Print Polynomial 2 (P2)\n");
        printf(" 5. Add Polynomials (P1 + P2) , ");
        printf(" 6. Deduct Polynomials (P1 - P2)\n");
        printf(" 0. Exit\n");
        printf(" Enter your choice: ");
        
        scanf("%d",&choice);

        switch(choice){
          case 1:
              p1 = constructpoly1();
              break;
          case 2:
              p2 = constructpoly2();
              break; 
          case 3:
              printf("\n--- POLYNOMIAL 1 ---\n");
              printpolynomial(p1);
              break;
          case 4:
              printf("\n--- POLYNOMIAL 2 ---\n");
              printpolynomial(p2);
              break;
            case 5:
                printf("\n--- RESULT OF ADDITION (P1 + P2) ---\n");
                 polynomial* res1 = Addpolynomial(p1, p2);
                printpolynomial(res1);
                break;
            case 6:
                printf("\n--- RESULT OF DEDUCTION (P1 - P2) ---\n");
               polynomial* res2 = deductpolynomial(p1, p2);
                printpolynomial(res2);
               
                break;
            case 0:
                printf("\nExiting program.\n");
                break;
            default:
                printf("\nInvalid choice. Please enter a number between 0 and 4.\n");
        }
    } while(choice != 0);
   return 0;
   }





