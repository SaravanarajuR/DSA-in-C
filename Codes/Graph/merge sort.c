#include <stdio.h>
#include<stdlib.h>

int a[11];
int b[10];

void merging(int low, int mid, int high) {
   int l1=low;
   int l2=mid+1;
    int i=low;
       printf("\n");
   while(l1 <= mid && l2 <= high) {
      if(a[l1] <= a[l2]){
         b[i] = a[l1++];
      }
      else{
         b[i] = a[l2++];
   }
       i++;
   }
   
   while(l1 <= mid){   
      b[i++] = a[l1++];
   }

   while(l2 <= high){   
      b[i++] = a[l2++];
   }

   for(i = low; i <= high; i++){
      a[i] = b[i];
   }
      
      printf("\nsorting array:-");
       for(int i=low;i<=high;i++){
          printf("%d\t",a[i]); 
       }
           printf("\n");

}

void sort(int low, int high) {
   int mid;
   if(low < high) {
       printf("\nDivided array:-\t");
       for(int i=low;i<=high;i++){
          printf("%d\t",a[i]); 
       }
      mid = (low + high) / 2;
      sort(low, mid);
      sort(mid+1, high);
      merging(low, mid, high);
   } else { 
      return;
   }   
}

int main() { 
   int max;
   printf("Enter size");
   scanf("%d",&max);
   printf("Enter array");    
   for(int m=0;m<max;m++){
    scanf("%d",&a[m]);
   }
   
   printf("\nList before sorting\n");
   
   for(int i = 0; i < max; i++)
      printf("%d ", a[i]);
    printf("\n");
   sort(0, max-1);
    printf("\n");
   printf("List after sorting\n");
   
   for(int i = 0; i < max; i++)
      printf("%d ", a[i]);
}
