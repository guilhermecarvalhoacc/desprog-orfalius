#include <stdio.h>
#include <stdbool.h>



void sort(int *V, int n, int k) {
    int output[n];
    int C[k];
    int j = 0;

    for (int i=0; i < n; i++) {
            C[V[i] - 1] = 1;
    }

    for (int i=0; i < k; i++) {
        if (C[i] == true) {
            output[j] = i+1;
            j+=1;
        }
    }

    for (int i=0; i < n+1; i++) {
        V[i] = output[i];
    }
}

int get_max(int a[], int n) {  
   int max = a[0];  
   for(int i = 1; i<n; i++) {  
      if(a[i] > max)  
         max = a[i];  
   }  
   return max; //maximum element from the array  
}  


int main() {

    int v[]   = {4,15,12,1,26,2,3};
    int n = sizeof(v) / sizeof(v[0]);
    int k     = get_max(v, n);

    sort(v, n, k);

    for (int i=0; i < n; i++) {
        printf("%d, ", v[i]);
    }

    printf("\n");

    return 0;
}
