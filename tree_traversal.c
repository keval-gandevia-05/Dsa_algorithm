#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct list_node {
    int number;
    struct list_node *left;
    struct list_node *right;
}node;

node *insert_node(int value) {
    //printf("Yes\n");
    node *new_node = (node *)malloc(sizeof(node));
    new_node -> number = value;
    new_node -> left = NULL;
    new_node -> right = NULL;
    return new_node;
}

void insert_link(node **p,node **l,node **r,int left_child,int right_child) {
    
    if(left_child == 0 && right_child == 0) {
        //printf("No child\n");
        (*p) -> left = NULL;
        (*p) -> right = NULL;
        return;
    }
    else if(left_child == 0 && right_child != 0) {
        //printf("left child is empty\n");
        (*p) -> left = NULL;
        (*p) -> right = (*r);
        return;
    }
    else if(left_child != 0 && right_child == 0) {
        //printf("Right child is empty\n");
        (*p) -> left = (*l);
        (*p) -> right = NULL;
        return;
    }
    else {
        //printf("Left and right both are exist\n");
        (*p) -> left = (*l);
        (*p) -> right = (*r);
        return;
    }
}

/*void display(node *nd) {
    printf("%d -> ",nd -> number);
    
    if(nd -> left != NULL)
        printf("%d -> ",nd -> left -> number);
    if(nd -> right != NULL)
        printf("%d -> ",nd -> right -> number);
    printf("\n");
    //printf("%d %d %d\n",nd -> number,nd -> left -> number,nd -> right -> number);
}*/

void preorder(node **T) {
    if(T == NULL) {
        printf("Tree is empty\n");
        return;
    }
    printf("%d ",(*T) -> number);
    if((*T) -> left != NULL)
        preorder(&((*T) -> left));
    if((*T) -> right != NULL)
        preorder(&((*T) -> right));
    return;
}

void inorder(node **T) {
    if(T == NULL) {
        printf("Tree is empty\n");
        return;
    }
    if((*T) -> left != NULL)
        inorder(&((*T) -> left));
    printf("%d ",(*T) -> number);
    if((*T) -> right != NULL)
        inorder(&((*T) -> right));
    
    return;
}

void postorder(node **T) {
    if(T == NULL) {
        printf("Tree is empty\n");
        return;
    }
    if((*T) -> left != NULL)
        postorder(&((*T) -> left));
    if((*T) -> right != NULL)
        postorder(&((*T) -> right));
    printf("%d ",(*T) -> number);
    
    return;
}

int main() {
    int root_index;
    int n,p,l,r,i;
    scanf("%d",&n);
    node *head[n+1];
    int visited[n+1];
    for(i=1;i<=n;i++) {
        visited[i] = 0;
    }
    for(i=1;i<=n;i++) {
        head[i] = insert_node(i);
    }
    for(i=1;i<=n;i++) {
        scanf("%d %d %d",&p,&l,&r);
        if(l != 0)
            visited[l]++;
        if(r != 0)
            visited[r]++;
        insert_link(&head[p],&head[l],&head[r],l,r);
        if(i == 1) {
            root_index = p;
            visited[p]++;
        }
        if(visited[root_index] != 1) {
            printf("Tree can not contain loop\n");
            exit(0);
        }
        else if(visited[l] == 2 || visited[r] == 2) {
            printf("Right node is already a child node\n");
            exit(0);
        }
    }
    /*for(i=1;i<=n;i++) {
        display(head[i]);
    } */
    node *root = head[root_index];
    preorder(&root);
    printf("\n");
    inorder(&root);
    printf("\n");
    postorder(&root);
    printf("\n");
         
    return 0;
}
