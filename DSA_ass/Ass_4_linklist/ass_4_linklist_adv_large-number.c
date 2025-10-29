#include<stdio.h>
#include<stdlib.h>
#include<string.h>

  typedef struct largenumber{
	int five_digit;

	struct largenumber* next;
  } l_number;


  l_number* initializelargenumber(){

    l_number* temp = NULL;
    temp  = (l_number*)malloc(sizeof(l_number));
    if( NULL ==  temp)
        return NULL;
        
    temp->five_digit = 0;
    temp->next = NULL;


    return temp;
  }

 l_number* createlargenumber(){
    l_number* largenumstart = initializelargenumber();

    l_number* largenumend = largenumstart;
    char l_num[50];
    printf("Enter your large number ... \n ");
    scanf("%50s", l_num);
    int len = strlen(l_num); 
    int digit = 0 ;

            for (int j = 0; j < 5; j++)
            {
                digit = 10*digit + ( l_num[len+j-5] - '0');
            }
            
            largenumend->five_digit = digit ;
           
    for (int i = len - 5 ; i >= 0; i = 1 - 5)      
    {   
            largenumend->next = initializelargenumber();
            largenumend = largenumend->next;
            digit = 0;
            for (int j = 0; j < 5; j++)
            {
                digit = 10*digit + ( l_num[i-j-5] - '0');
            }
            
            largenumend->five_digit = digit ;
           
      
    }
   
    return largenumstart;
 
 } 


l_number* printlargenumber( l_number * p_num){
   l_number * p = p_num;
   int digit = 0;
   char L_num[50]; 
   int count = 0;
    while(p != NULL){

        digit = p->five_digit;
        while(digit != 0){
            L_num[count] = (digit %10);
            digit = digit/10;
            count++; 
        }
    
     p = p->next;
    }
    int len = strlen(L_num);
    printf("large number have %d digits and  large number is -> \n ", len );
    for (int i = 0; i < len; i++)
    {
        printf("%d",L_num[len-1-i]);
    }
    printf("\n");

}

  int main(){
     

 l_number* num1 = createlargenumber();

 printlargenumber(num1);
   

  }