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

  for(int j = 0; j < n; j++){
    swapped = false;

    for(int i = 1; i < n; i++){
      if(arr[i-1] > arr[i]){

	//print_array(arr,n);
	swap(&arr[i-1], &arr[i]);
	swapped = true;

      }
    } 

    if(!swapped){
      break;
    }

  }
}

int binarySearch(int arr[], int l, int r, int find){
  /*
    binary search returns the index of the number the user wants to find
  */
  while (l <= r){
    int mid = l + (r-l)/2;
    // printf("mid =  %d\n arr[mid] = %d\n", mid, arr[mid]);
    
    if (arr[mid] == find)
      return mid;

    if (arr[mid] < find)
      l = mid + 1;
    else
      r =  mid -  1;
      
  }
  
  return -1;

}

int main(){
  const int n = 100;
  int nums[n];

  srand((unsigned)time(NULL));

  for(int i = 0 ; i < n; i++){
    nums[i] = randint(1000);
  }

  bubbleSort(nums, n);

  print_array(nums, n);

  int requestNum, index;
  printf("What number would you like me to look for in the list ");
  scanf("%d", &requestNum);
  index = binarySearch(nums, 0, n, requestNum);
  if(index != -1){
    printf("The number %d was found at the index %d", requestNum, index);
  } else {
    printf("The number %d was not in the list", requestNum);
  }

  


  return 0;
}
