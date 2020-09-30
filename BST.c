#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct list_node {
	int data;
	struct list_node *lptr;
	struct list_node *rptr;
}node;

node *insert_node(int value) {
	node *new_node = (node *)malloc(sizeof(node));
	new_node -> data = value;
	new_node -> lptr = NULL;
	new_node -> rptr = NULL;
	return new_node;
} 


node *BINSERT(node *head,int value) {
	
	node *parent = NULL,*current = NULL;
	if(head == NULL) {
		node *new_node = insert_node(value);
		return new_node;
	}
	else {
		parent = head;
		current = head;
	}
	
	while(current != NULL) {
		parent = current;
		if(value < current -> data)
			current = current -> lptr;
		else if(value > current -> data)
			current = current -> rptr;
		else {
			printf("No duplcicate key is allowed\n");
			exit(0);
		}
	}
	
	node *new_node = insert_node(value);
	
	if(value < parent -> data) {
		parent -> lptr = new_node;
		//printf("Inserted at left of %d\n",parent -> data);
	}
	else {
		parent -> rptr = new_node;
		//printf("Inserted at right %d\n",parent -> data);
	}
		
	return new_node;	

}

node *BDELETE(node *head,int value) {
	if(head == NULL) {
		printf("Node %d is not found in the tree\n",value);
		exit(0);
	}
	node *parent = head,*current = head;
	char direction = 'l';
	bool found = false; 
	
	while(!found && current != NULL) {
		if(value < current -> data) {
			parent = current;
			current = current -> lptr;
			direction = 'l';
		}
		else if(value > current -> data) {
			parent = current;
			current = current -> rptr;
			direction = 'r';
		}
		else 
			found = true;
	}
	
	if(found == false) {
		printf("Node %d is not found in the tree\n",value);
		exit(0);
	}
	
	node *temp = NULL,*suc = NULL,*pred = NULL;
	
	if(current -> lptr == NULL) 
		temp = current -> rptr;
	else if(current -> rptr == NULL)
		temp = current -> lptr;
	else {
		suc = current -> rptr;
		if(suc -> lptr == NULL) {
			suc -> lptr = current -> lptr;
			temp = suc;
		}
		else {
			pred = current -> rptr;
			suc = pred -> lptr;
			while(suc -> lptr != NULL) {
				pred = suc;
				suc = pred -> lptr;
			}
			pred -> lptr = suc -> rptr;
			suc -> lptr = current -> lptr;
			suc -> rptr = current -> rptr;
			temp = suc;
		}
	}
	if(direction == 'l') {
		if(value == head -> data)
			head = temp;
		parent -> lptr = temp;
	}
	else {
		parent -> rptr = temp;
	}
	
	return head;
}


void preorder(node **T) {
    if(T == NULL) {
        printf("Tree is empty\n");
        return;
    }
    printf("%d ",(*T) -> data);
    if((*T) -> lptr != NULL)
        preorder(&((*T) -> lptr));
    if((*T) -> rptr != NULL)
        preorder(&((*T) -> rptr));
    return;
}

void inorder(node **T) {
    if(T == NULL) {
        printf("Tree is empty\n");
        return;
    }
    if((*T) -> lptr != NULL)
        inorder(&((*T) -> lptr));
    printf("%d ",(*T) -> data);
    if((*T) -> rptr != NULL)
        inorder(&((*T) -> rptr));
    
    return;
}


int main() {
	int n,m,i,value;
	node *head = NULL; 
	
	scanf("%d",&n);
	scanf("%d",&value);
	head = BINSERT(head,value);
	
	for(i=1;i<n;i++) {
		scanf("%d",&value);
		BINSERT(head,value);
	}    
	
	scanf("%d",&m);
	for(i=0;i<m;i++) {
		scanf("%d",&value);
		head = BDELETE(head,value);
	}
	
	inorder(&head);
	printf("\n");
	preorder(&head);
	
    return 0;
}
