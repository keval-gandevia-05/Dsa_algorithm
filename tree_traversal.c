#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void make_binary_tree(int *root_list,int *left,int *right,int root_data,int *arr,int insert_at,int len)
{
    int base_index;
    for(int i=0;i<len;i++)
    {
        if(root_list[i]==root_data)
        {
            base_index=i;
            break;
        }
    }
    int value=root_list[base_index];
    int left_child=(insert_at*2)+1;
    int right_child=(insert_at*2)+2;
    arr[insert_at]=value;
    if(left[base_index]!=0)
    {
        make_binary_tree(root_list,left,right,left[base_index],arr,left_child,len);
    }
    
    if(right[base_index]!=0)
    {
        make_binary_tree(root_list,left,right,right[base_index],arr,right_child,len);
    }
    
}

void preorder(int *arr,int node_index)
{
    int left=node_index*2+1;
    int right=node_index*2+2;
    printf("%d ",arr[node_index]);
    if(arr[left]!=-1)
    {
        preorder(arr,left);
    }
    if(arr[right]!=-1)
    {
        preorder(arr,right);
    }
    
}

void postorder(int *arr,int node_index)
{
    if(node_index==-1)
        return;
    int left=node_index*2+1;
    int right=node_index*2+2;
    
    if(arr[left]!=-1)
    {
        
        
        postorder(arr,left);
    }
    if(arr[right]!=-1)
    {
        
        postorder(arr,right);
        
    }
    printf("%d ",arr[node_index]);
}

void inorder(int *arr,int node_index)
{
   int val=arr[node_index];
   int left=(2*node_index)+1;
   int right=(2*node_index)+2;
   if(arr[left]!=-1)
   {
       inorder(arr,left);
   }
   printf("%d ",val);
   if(arr[right]!=-1)
   {
       inorder(arr,right);
   }
    
}
void main()
{
    int no;
    scanf("%d",&no);
    int *root=(int *)malloc(no*sizeof(int));
    int *left=(int *)malloc(no*sizeof(int));
    int *right=(int *)malloc(no*sizeof(int));
    int *arr=(int *)malloc(200*sizeof(int));
    int *visited_right=(int *)malloc((no+1)*sizeof(int));
    int *visited=(int *)malloc((no+1)*sizeof(int));
    for(int i=0;i<no+1;i++)
    {
        visited[i]=0;
        visited_right[i]=0;

    }
    int insert_at=0;
    int root_data;
    int r,l,rt;
    
    for(int i=0;i<no;i++)
    {
        scanf("%d%d%d",&r,&l,&rt);
        root[i]=r;
        if(i==0)visited[r]++;
        left[i]=l;
        right[i]=rt;  
        if(visited_right[rt]!=0 && rt!=0)
        {
            printf("Right node is already a child node");
            exit(0);
        }   
        else
        {
            if(rt!=0)
            {
                visited_right[rt]++;
            }
               
        }
        
       if(l!=0)
       {
           if(visited[l]==0)
           {
               visited[l]++;
           }
           else
           {
               printf("Tree can not contain loop");
               exit(0);
           }
           
       }
       if(rt!=0)
       {
           if(visited[rt]==0)
           {
               visited[rt]++;
           }
           else
           {
               printf("Tree can not contain loop");
               exit(0);
           }
           
       }
       
       
        
        
    }
    

    for(int i=0;i<200;i++)arr[i]=-1;

    root_data=root[0];
    make_binary_tree(root,left,right,root_data,arr,0,no);
    preorder(arr,0);
    printf("\n");    
    inorder(arr,0);
    printf("\n");
    postorder(arr,0);  
    
    
}
