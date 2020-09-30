#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
void c_p_c()
{
    
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}


void djikstra(int no,int src_node,int bitmaps[][no],int graph[no][no],bool visited[no],int distances[no])
{
    int cur_node=src_node;
    distances[src_node]=0;
    int n_visited=0;
    bitmaps[src_node][0]=src_node+1;
    while(n_visited<no)
    {
        visited[cur_node]=true;
        int cur_dist=distances[cur_node];
        //traverse the adjacency list of current node
        for(int i=0;i<no;i++)
        {
            if(graph[cur_node][i]!=-1)
            {
                if((graph[cur_node][i]+cur_dist)<distances[i])
                {
                    distances[i]=graph[cur_node][i]+cur_dist;
                    
                    int k;
                    for( k=0;k<no;k++)
                    {
                        if(bitmaps[cur_node][k]!=-1)
                        {
                            bitmaps[i][k]=bitmaps[cur_node][k];
                        }
                        else
                        {
                            break;
                        }
                        
                        
                        
                    }
                    bitmaps[i][k]=i+1;
                    bitmaps[i][k+1]=-1;

                }
            }
        }
        //now select the node with least distance
        int min=INT_MAX;
        int min_index=-1;
        for(int i=0;i<no;i++)
        {
            if(distances[i]<min && visited[i]==false)
            {
                min=distances[i];
                min_index=i;
            }
        }
        

        cur_node=min_index;
        n_visited++;
        
    }
}
int main()
{
    c_p_c();
    int no;
    scanf("%d",&no);
    int arr[no][no];
    int bitmaps[no][no];
    for(int i=0;i<no;i++)
    {
        for(int j=0;j<no;j++)
        {
            scanf("%d",&arr[i][j]);
            if(i==j&&arr[i][j]!=0)
            {
                printf("Weight of the edge 1 <-> 1 must be 0");
                exit(0);
            }
            
            if(arr[i][j]<0 && arr[i][j]!=-1)
            {
                printf("Weight of the edge 1 <-> 3 can not be negative");
                exit(0);
            }
            if(arr[i][j]==0&&i!=j)
            {
                printf("Weight of the edge 1 <-> 2 can not be 0");
                exit(0);
            }
        }
    }
    for(int i=0;i<no;i++)
    {
        for(int j=0;j<no;j++)
        {
            bitmaps[i][j]=-1;
        }
    }
    int distance[no];
    bool visited[no];
    for(int i=0;i<no;i++)
    {
        distance[i]=99999;
        visited[i]=false;
    }
    int src;
    scanf("%d",&src);
    djikstra(no,src-1,bitmaps,arr,visited,distance);
    for(int i=0;i<no;i++)
    {
        int cntr=0;
        printf("%d\t%d\t",i+1,distance[i]);
        for(int j=0;j<no;j++)
        {
            
            if(bitmaps[i][j]==-1)
            {
                break;
            }
            else if(bitmaps[i][j+1]!=-1)
            {
                printf("%d->",bitmaps[i][j]);
            }
            else
            {
                printf("%d",bitmaps[i][j]);
            }
            
        }
       
        printf("\n");
    }
}
