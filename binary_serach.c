#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int binary_search(int a[],int n,int no) {
    int index = -1;
    int low = 1;
    int high = n;
    while(low <= high) {
        int middle = low + (high - low) / 2;
        if(no < a[middle])  
            high = middle - 1;
        else if(no > a[middle]) {
            low = middle + 1;
        }
        else if(no == a[middle]) {
            index = middle;
            break;
        }
    }
    //printf("Returning index\n");
    return index;
}

int main() {
    int n,i,m,prev,no;
    scanf("%d",&n);
    int a[n+1];
    for(i=1;i<=n;i++) {
        scanf("%d",&a[i]);
        if(i == 1) {
            prev = a[1];
        }
        if(i != 1) {
            if(prev <= a[i]) {
                prev = a[i];
            }
            else if(prev > a[i]) {
                printf("Numbers are not in ascending order\n");
                exit(0);
            }
        }
    }
    scanf("%d",&m);
    for(i=0;i<m;i++) {
        scanf("%d",&no);
        printf("%d ",binary_search(a,n,no));
    }
}
