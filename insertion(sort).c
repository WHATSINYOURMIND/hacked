//insertion  sort 
#include <stdio.h>

void printArray(int *arr,int size){
	int i;
    for( i=0; i<size;i++){
        printf("%d\t",arr[i]);
       
    }
}
 void insertionSort(int *arr,int size){
 	int i;
  
  //loop for passes
    for( i=1;i<size;i++) {
        // loop for each pass 

           int temp=arr[i];
            int j=i-1;
            while(j>=0 && arr[j]>temp)// for ascending order A[j]<temp
        {
            arr[j+1]=arr[j];
            j--;
        }
           arr[j+1]=temp; 
        }
    }
 
int main(){
    //sorted            unsorted
    //0   1    2        3  4   5
    //12  54  65       7  23  9
    int arr[]= { 12,54,65,7,23,9};
    int size=6;
    printArray(arr,size);
    insertionSort(arr,size);
     printf("\n\nSorted Array : \n");
    printArray(arr,size);
    return 0;
}


//Dry run 
  // -1   0    1   2   3   4   5
   //      12,| 54, 65, 07, 23, 09 --> i=1, key=54, j=0
   //      12,| 54, 65, 07, 23, 09 --> 1st pass done (i=1)!

   //      12, 54,| 65, 07, 23, 09 --> i=2, key=65, j=1
   //      12, 54,| 65, 07, 23, 09 --> 2nd pass done (i=2)!

   //      12, 54, 65,| 07, 23, 09 --> i=3, key=7, j=2
   //      12, 54, 65,| 65, 23, 09 --> i=3, key=7, j=1
   //      12, 54, 54,| 65, 23, 09 --> i=3, key=7, j=0
   //      12, 12, 54,| 65, 23, 09 --> i=3, key=7, j=-1
   //      07, 12, 54,| 65, 23, 09 --> i=3, key=7, j=-1--> 3rd pass done (i=3)!

   // Fast forwarding and 4th and 5th pass will give:
   //      07, 12, 54, 65,| 23, 09 --> i=4, key=23, j=3
   //      07, 12, 23, 54,| 65, 09 --> After the 4th pass

   //      07, 12, 23, 54, 65,| 09 --> i=5, key=09, j=4
   //      07, 09, 12, 23, 54, 65| --> After the 5th pass
