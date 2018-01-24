#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef enum { false = 0, true = !false } bool;

void swap(int *a, int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

int randint(int max){
  return rand() % max;
}

void print_array(int arr[], int n){
  for(int i = 0; i < n; i++){
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void bubbleSort(int arr[], int n){
  bool swapped = false;

  while(true) {
    //print_array(arr,n);
    swapped = false;

    for (int i = 1; i < n; i++){

      if(arr[i-1] > arr[i]){

	swap(&arr[i-1], &arr[i]);
	swapped = true;

	//print_array(arr,n);
      }
    } 

    if(!swapped){
      break;
    }

  }
}

int main(){
  const int n = 10;
  int nums[n];

  srand((unsigned)time(NULL));

  for(int i = 0 ; i < n; i++){
    nums[i] = randint(1000);
  }

  bubbleSort(nums, n);

  print_array(nums, n);
  


  return 0;
}
