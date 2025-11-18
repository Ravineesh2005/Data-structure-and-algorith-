#include<stdio.h>

void swap2num(int *a,int *b){
	int temp =*b;
	*b = *a;
	*a = temp;
}	
void insertion_withoutswap( int * array, int n ) {
	for ( int k = 1; k < n; k++ ) {
		int tmp = array[k];
		for ( int j = k; j > 0; j-- ) {
			if ( array[j - 1] > tmp ) {
				array[j] = array[j - 1];
			} else {
				array[j] = tmp;
				break;
			}
		}
		if ( array[0] > tmp ) {
			array[0] = tmp; // only executed if tmp < array[0]
		}
	}
}


void insertion_withswap( int * array, int n ) {
	for ( int k = 1; k < n; k++ ) {

		for ( int j = k; j > 0; j-- ) {
			if( array[j - 1] > array[j] ) {
				swap2num(&array[j],&array[j-1]);
	                 		} 
		
	       	else  {
		        break;
		}
	
	}
}

}


void bubble( int * arr, int n ) {
	int temp;
	for ( int i = 0; i < n; i++ ) {

		for ( int j = 1; j < n; j++ ) {
			if ( arr[j - 1] > arr[j] ) {
			swap2num(&arr[j] , &arr[j - 1]);  
			} 
		}
	}
}

void print_arr(int A[] , int n){ 
	printf(" array is    ");
       for(int i = 0 ; i< n ; i++){
         printf("%d  ",A[i]);
       }
       printf("\n");
}
     int main(){


  int arr[] = {1,4,2,10,6,3,5,12};
   
    print_arr(arr,8);
    bubble(arr,8);
    print_arr(arr,8);
    return 0;
  }
