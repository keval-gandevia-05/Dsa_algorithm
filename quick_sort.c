#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX1 10000
#define MAX2 1000000
#define MIN 1

void swap(int *a,int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quick_sort(int a[],int lower,int upper) {
    
    bool flag = true;
    if(lower < upper) {
        int i = lower;
        int j = upper + 1;
        int key = a[lower];
        while(flag) {
            i++;
            while(a[i] < key) 
                i++;
            j--;
            while(a[j] > key)
                j--;
            if(i < j)
                swap(&a[i],&a[j]);
            else
                flag = false;
        }
        swap(&a[lower],&a[j]);
        quick_sort(a,lower,j-1);
        quick_sort(a,j+1,upper);
    }
}


int main() {
    int i,n;
    scanf("%d",&n);
    if(n < 1) {
        printf("Size of array must be within [%d,%d]\n",MIN,MAX1);
        exit(0);
    }
    int a[n+1];
    for(i=1;i<=n;i++) {
        scanf("%d",&a[i]);
        if(a[i] < 1) {
            printf("Number must be within [%d,%d]\n",MIN,MAX2);
            exit(0);
        }
            
    }
    quick_sort(a,1,n);
    for(i=1;i<=n;i++)
        printf("%d ",a[i]);
    printf("\n");
    
    return 0;
}
