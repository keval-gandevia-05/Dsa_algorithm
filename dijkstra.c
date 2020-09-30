#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#define INT_MAX 10000000

int min_distance(int distance[],bool set[],int n) {
    int min = INT_MAX,index_min,i;
    for(i=0;i<n;i++) {
        if(set[i] != true && distance[i] <= min) {
            min = distance[i];
            index_min = i;
        }
    }
    return index_min;
}

void print_path(int path[],int no) {
    if(path[no] == -1) 
        return;
    print_path(path,path[no]);
    printf("->%d",no+1); 
}

void print(int distance[],int n,int path[],int source) {
    int i;
    for(i=0;i<n;i++) {
        printf("%d %d %d",i+1,distance[i],source);
        print_path(path,i);
        printf("\n");
    }
}

void dijkstra(int n,int graph[][n],int source) {
    
    int distance[n],path[n],i,index,j;
    bool set[n];
    for(i=0;i<n;i++) {
        distance[i] = INT_MAX;
        set[i] = false;
    }
    distance[source-1] = 0;
    path[source-1] = -1;
    
    for(i=0;i<n;i++) {
        index = min_distance(distance,set,n);
        set[index] = true;
        for(j=0;j<n;j++) {
            if(graph[index][j] != -1 && (set[j] == false) 
            && distance[index] + graph[index][j] < distance[j]) {
                path[j] = index;
                distance[j] = distance[index] + graph[index][j];
            }
        }
    }
    print(distance,n,path,source);
}


int main() {
    int n,i,j,source;
    scanf("%d",&n);
    int graph[n][n];
    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {
            scanf("%d",&graph[i][j]);
            if(j != i) {
                if(graph[i][j] == 0) {
                    printf("Weight of the edge %d <-> %d can not be 0\n",i+1,j+1);
                    exit(0);
                }
                if(graph[i][j] < 0 && graph[i][j] != -1) {
                    printf("Weight of the edge %d <-> %d can not be negative\n",i+1,j+1);
                    exit(0);
                }
            }
            
            if(i == j) {
                if(graph[i][j] != 0) {
                    printf("Weight of the edge %d <-> %d must be 0\n",i+1,j+1);
                    exit(0);
                }
            }
        }
    }
    scanf("%d",&source);
    dijkstra(n,graph,source);
    
    return 0;
}
