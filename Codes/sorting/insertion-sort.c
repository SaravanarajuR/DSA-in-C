#include <stdio.h>  
#include<stdlib.h>

void insert(int a[], int n)
{  
    int i, j, temp;  
    for (i = 1; i < n; i++) {  
        temp = a[i];  
        j = i - 1;  
  
        while(j>=0 && temp <= a[j]) 
        {    
            a[j+1] = a[j];     
            j = j-1;
            printArr(a, n);
            printf("\n");
        }    
        a[j+1] = temp;    
    }  
}  
  
void printArr(int a[], int n)
{  
    int i;  
    for (i = 0; i < n; i++)  
        printf("%d ", a[i]);
        printf("\n");
}  
  
int main()  
{  
    int n;
    printf("Enter the array size");
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("\nBefore sorting array elements are - \n");  
    printArr(a, n);  
    insert(a, n);  
    printf("\nAfter sorting array elements are - \n");    
    printArr(a, n);  
  
    return 0;  
}    
