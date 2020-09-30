#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#define INT_MAX 10000000


int min_key(int key[],bool set[],int n) {
    int min = INT_MAX,index_min,i;
    for(i=0;i<n;i++) {
        if(set[i] != true && key[i] < min) {
            min = key[i];
            index_min = i;
        }
    }
    return index_min;
}

void print(int parent[],int n,int graph[][n],int source) {
    int i;
    for(i=0;i<n;i++) {
        if(i != source - 1)
            printf("%d-%d\t%d\n",i+1,parent[i]+1,graph[i][parent[i]]);
    }
}

void prim(int n,int graph[][n],int source) {
    
    int parent[n],key[n],i,j,index;
    bool set[n];
    for(i=0;i<n;i++) {
        key[i] = INT_MAX;
        set[i] = false;
    }
    
    key[source - 1] = 0;
    parent[source - 1] = -1;
    
    for(i=0;i<n;i++) {
        index = min_key(key,set,n);
        set[index] = true;
        for(j=0;j<n;j++) {
            if(graph[index][j] && (set[j] == false) && graph[index][j] < key[j]) {
                parent[j] = index;
                key[j] = graph[index][j];
            }
        }
    }
    
    print(parent,n,graph,source);
}

int main() {
    int n,i,j,source;
    scanf("%d",&n);
    int graph[n][n];
    
    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {
            scanf("%d",&graph[i][j]);
            
            if(j<i) {
                if(graph[j][i] != graph[i][j]) {
                    printf("Weight of the edge %d - %d must be same as edge %d - %d\n",i+1,j+1,j+1,i+1);
                    exit(0);
                }
            }
            
            if(j != i) {
                if(graph[i][j] < 0) {
                    printf("Weight of the edge %d - %d can not be negative\n",i+1,j+1);
                    exit(0);
                }
            }
            
            if(i == j) {
                if(graph[i][j] != 0) {
                    printf("Weight of the edge %d - %d must be 0\n",i+1,j+1);
                    exit(0);
                }
            }
        }
        
        
    }
    
    scanf("%d",&source);
    prim(n,graph,source);
    
    return 0;
}

