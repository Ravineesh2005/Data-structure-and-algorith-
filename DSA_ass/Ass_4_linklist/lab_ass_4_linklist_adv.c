#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct largenumber {
    int five_digit;
    struct largenumber* next;
} l_number;

l_number* initializelargenumber() {
    l_number* temp = (l_number*)malloc(sizeof(l_number));
    if (temp == NULL)
        return NULL;

    temp->five_digit = 0;
    temp->next = NULL;
    return temp;
}

l_number* createlargenumber() {
    l_number* largenumstart = initializelargenumber();
    l_number* largenumend = largenumstart;

    char l_num[50];
    printf("Enter your large number ...\n");
    scanf("%50s", l_num);
    int len = strlen(l_num);

    int start = len -1;
    while (start >= 0) {
        int digit = 0;
        for (int j = 0; j < 5 && start - j >= 0; j++) {
            digit = digit * 10 + (l_num[start - j] - '0');
        }

        largenumend->five_digit = digit;

        start -= 5;
        if (start >= 0) {
            largenumend->next = initializelargenumber();
            largenumend = largenumend->next;
        }
    }

    return largenumstart;
}

void printlargenumber(l_number* p_num) {
    l_number* p = p_num;
    char L_num[50];
    int count = 0;

    while (p != NULL) {
        int digit = p->five_digit;
        int temp[5], temp_count = 0;

        while (digit != 0) {
            temp[temp_count++] = digit % 10;
            digit /= 10;
        }

        for (int i = temp_count - 1; i >= 0; i--) {
            L_num[count++] = temp[i] + '0';
        }

        p = p->next;
    }

    printf("Large number has %d digits and is ->\n", count);
    for (int i = 0; i < count; i++) {
        printf("%c", L_num[count - i -1]);
    }
    printf("\n");
}
    
  // l_number* addlargenumber(l_number* num1 , l_number* num2){
  //   l_number* N1 = num1;
  //   l_number* N2 = num2;
  //   int carry = 0 ;
  //   int sum_num = 0;
  //   int num =0 ;
  //   l_number* sum_largenmber = initializelargenumber();
  //   l_number* sum= sum_largenmber;
  //   sum_num  = N1->five_digit + N2->five_digit ;
  //   num = sum_num%100000;
  //   carry = sum_num / 100000;
  //   sum->five_digit = num;
  //   N1 = N1->next;
  //   N2 = N2->next;

  //   while((N1 != NULL)&& (N2 != NULL)){
       
  //     sum->next = initializelargenumber();
  //     sum = sum->next;
  //     sum_num  = N1->five_digit + N2->five_digit ;
  //     num = sum_num%100000;
  //     carry = sum_num / 100000;
  //     sum->five_digit = num;
  //     N1 = N1->next;
  //     N2 = N2->next;
  //   }    
  
  //   if(N1 == NULL){
  //     while(N2 != NULL){

  //       sum->next = initializelargenumber();
  //       sum = sum->next;
  //       sum_num  =  N2->five_digit + carry;
  //       num = sum_num%100000;
  //       carry = sum_num / 100000;
  //       sum->five_digit = num;
  //       N2 = N2->next;
  //     }
  //   }

  //   if(N2 == NULL){
  //     while(N1 != NULL){

  //       sum->next = initializelargenumber();
  //       sum = sum->next;
  //       sum_num  =  N1->five_digit + carry;
  //       num = sum_num%100000;
  //       carry = sum_num / 100000;
  //       sum->five_digit = num;
  //       N1 = N1->next;
  //     }
  //   }

  //     return sum_largenmber;

  // }

  
l_number* addlargenumber(l_number* num1, l_number* num2) {

    l_number* N1 = num1;
    l_number* N2 = num2;

    int carry = 0; 

  
    l_number* result_start = initializelargenumber();
    l_number* current = result_start;

    
    while (N1 != NULL || N2 != NULL || carry > 0) {

        int val1 = (N1 != NULL) ? N1->five_digit : 0;
        int val2 = (N2 != NULL) ? N2->five_digit : 0;
     
    //    int val1 = 0, val2 = 0;

    //     if (N1 != NULL) {
    //         val1 = N1->five_digit;
    //     }
    //     if (N2 != NULL) {
    //         val2 = N2->five_digit;
    //     }

      
        int total = val1 + val2 + carry;

  
        current->five_digit = total % 100000;

      
        carry = total / 100000;

      
        if (N1 != NULL) N1 = N1->next;
        if (N2 != NULL) N2 = N2->next;

    
        if (N1 != NULL || N2 != NULL || carry > 0) {
            current->next = initializelargenumber();
            current = current->next;
        }
    }

    return result_start;
}


l_number* deductlargenumber(l_number* num1, l_number* num2) {
    l_number* N1 = num1;
    l_number* N2 = num2;
    int borrow = 0;

    l_number* start = initializelargenumber();
    l_number* current = start;

    while (N1 != NULL || N2 != NULL) {
        int val1 = 0, val2 = 0;

        if (N1 != NULL)
         val1 = N1->five_digit;

        if (N2 != NULL) 
        val2 = N2->five_digit;

        val1 -= borrow;

        if (val1 < val2) {
            val1 += 100000;
            borrow = 1;
        } else {
            borrow = 0;
        }

        current->five_digit = val1 - val2;

        N1 = (N1 != NULL) ? N1->next : NULL;
        N2 = (N2 != NULL) ? N2->next : NULL;

        // if (N1 != NULL) N1 = N1->next;
        // if (N2 != NULL) N2 = N2->next;

        if (N1 != NULL || N2 != NULL) {
            current->next = initializelargenumber();
            current = current->next;
        }
    }

    return start;
}




int main() {
    l_number* num1 = createlargenumber();
    l_number* num2 = createlargenumber();
    // printlargenumber(num1);
    // printlargenumber(num2);
    l_number* sum = addlargenumber(num1,num2);
    l_number* deduct = deductlargenumber(num1,num2);
    printlargenumber(sum);
    printlargenumber(deduct);
    return 0;
}
