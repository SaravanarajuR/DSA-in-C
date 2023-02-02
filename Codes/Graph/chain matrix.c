#include <stdio.h>
#include <stdlib.h>
int m[50][50], s[50][50];

void main() {
    int n, i, j, u, v, z, t, q, k, l;
    printf("Enter the No. of Chain Matrix: ");
    scanf("%d", &n);
    int p[n];
    printf("Enter the Matrix: \n");
    for(i=0; i<=n; i++) {
        printf("p[%d]: ", i);
        scanf("%d", &p[i]);
    }
    for(i=1; i<=n; i++) {
        m[i][i] =0;
    }
    for(l =2; l<=n; l++) {
        for(i=1; i<=n-l+1; i++) {
            j = i+l-1;
            m[i][j] = 999;
            for(k=i; k<=j-1; k++) {
                q = m[i][k] + m[k+1][j] + ((p[i-1])*(p[k])*(p[j]));
                printf("For k = %d, value of m[%d][%d] = %d\n", k, i, j, q);
                if(q<m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
            printf("The Cost Matrix is:\n");
            for(u=1; u<=n; u++) {
                for(v = 1; v<=n; v++) {
                    printf("%d\t", m[u][v]);
                }
               printf("\n");
            }
            printf("The Sequence Matrix is:\n");
            for(t=1; t<=n; t++) {
                for(z = 1; z<=n; z++) {
                    printf("%d\t", s[t][z]);
                }
                printf("\n");
            }
        }
    }
    printf("\nThe Cost of the Matrix Multiplication is: %d\n", m[1][n]);
}
