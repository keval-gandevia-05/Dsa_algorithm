#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

typedef struct edge {
    int destin;
    struct edge *next;
}edge;

typedef struct list_node {
    bool reach;
    int number;
    edge *list_ptr;
}node;


int f=0,r=0;
int queue[MAX];

void enqueue(int value) {
    r++;
    queue[r] = value;
    if(f == 0)
        f = 1;
}

int dequeue() {
    int y;
    y = queue[f];
    if(f == r) {
        f = r = 0;
        return y;
    }
    f = f + 1;
    return y;
}

node *insert_node(int n) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node -> reach = false;
    new_node -> number = n;
    new_node -> list_ptr = NULL;
    return new_node;
}

void insert_edge(node **ptr,int node2) {
    edge *new_edge = (edge *)malloc(sizeof(edge));
    new_edge -> destin = node2;
    if((*ptr) -> list_ptr == NULL) {
        new_edge -> next = NULL;
        (*ptr) -> list_ptr = new_edge;
        return;
    }
    edge *temp = (*ptr) -> list_ptr,*prev = (*ptr) -> list_ptr ;
    while(temp != NULL && temp -> destin <= node2) {
        prev = temp;
        temp = temp -> next;
    }
    new_edge -> next = prev -> next;
    prev -> next = new_edge;
    
    return;
}

/*void display(node *nd) {
    printf("Node is %d -> ",nd -> number);
    edge *ptr = nd -> list_ptr;
    //printf("%p %p",ptr,nd -> list_ptr);
    while(ptr != NULL) {
        printf("%d ",ptr -> destin);
        ptr = ptr -> next;
    }
    printf("\n");
}*/

void BFS(node **ptr,int index) {
    ptr[index] -> reach = true; 
    enqueue(index);
    
    while(f != 0) {
        index = dequeue();
        printf("%d ",index);
        edge *link = ptr[index] -> list_ptr;
        while(link != NULL) {
            if(! ptr[link -> destin] -> reach) {
                ptr[link -> destin] -> reach = true;
                enqueue(link -> destin);
            }
            link = link -> next;
        }
    }
    printf("\n");
}

void DFS(node **ptr,int index) {
    printf("%d ",index);
    ptr[index] -> reach = true;
    edge *link = ptr[index] -> list_ptr;
    while(link != NULL) {
        if(! ptr[link -> destin] -> reach) {
            DFS(ptr,link -> destin);
        }
        link = link -> next;
    }
    
}

int main() {
    int i,n,m,start,node1,node2;
    scanf("%d %d",&n,&m);
    node *head[n+1];
    for(i=1;i<=n;i++)
        head[i] = insert_node(i);
    
    for(i=0;i<m;i++) {
        scanf("%d %d",&node1,&node2);
        insert_edge(&head[node1],node2);
        insert_edge(&head[node2],node1);
    }
    /*for(i=1;i<=n;i++) {
        display(head[i]);
    }*/
    scanf("%d",&start);
    BFS(head,start);
    /*for(i=1;i<=n;i++)
        printf("%d ",head[i] -> reach);
    printf("\n");*/
    for(i=1;i<=n;i++) {
        head[i] -> reach = false;
    }
    DFS(head,start);
    
    return 0;
}
