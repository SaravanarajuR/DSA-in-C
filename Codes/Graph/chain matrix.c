#include <stdio.h>
int n=100;
   int minMul[10][10];
int MatrixChainMultuplication(int arr[], int n) {
   int j, q;
   for (int i = 1; i < n; i++){
      minMul[i][i] = 0;
}
   for (int L = 2; L < n; L++) {
      for (int i = 1; i <= n - L; i++) {
         j = i + L - 1;
         minMul[i][j] = 99999999;
         for (int k = i; k <j; k++) {
            q = minMul[i][k] + minMul[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
            printf("A[%d][%d]=%d\n",i,j,q);
            if (q < minMul[i][j])
            minMul[i][j] = q;
         }
        printf("the minimum value is %d\n",minMul[i][j]);

      }
       for(int i=1;i<n;i++){
      for(int j=1;j<n;j++){
       printf("%d\t",minMul[i][j]);
       }
       printf("\n");
  }
   printf("\n");
  
   }
   return minMul[1][n - 1];
}
int main(){
   int arr[10],size;
   printf("enter the size :");
   scanf("%d",&size);
   for(int i=0;i<size;i++){
       printf("p%d :",i);
       scanf("%d",&arr[i]);
   }
   
  // int size = sizeof(arr) / sizeof(arr[0]);
   printf("Minimum number of multiplications required for the matrices multiplication is %d ",    MatrixChainMultuplication(arr, size));
   getchar();
   return 0;
}
