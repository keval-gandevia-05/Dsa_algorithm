#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
void b_sort(int *arr,int arr_len,int no_to_search)
{
    int middle;
    int left=0;
    int right=arr_len;
    int ans_flag=0;
    while(left<=right)
    {
        
        middle=floor((left+right)/2);
        // printf("for:%d ",arr[middle]);
        if(arr[middle]==no_to_search)
        {
            ans_flag=-1;
            printf("%d ",middle);
            return;
        }
        else if(no_to_search>arr[middle])
        {
            left=middle+1;
        }
        else
        {
            right=right-1;
        }
        
    }
    if(ans_flag==0)
    {
        printf("-1 ");
    }
}
void main()
{
    int no;
    scanf("%d",&no);
    int *arr=(int *)malloc(no*sizeof(int));
    int prev=-1;
    int temp;
    int no_to_search_cnt;
    int *no_search_array;
    for(int i=0;i<no;i++)
    {
        scanf("%d",&temp);
        if(temp>prev)
        {
            prev=temp;
        }
        else
        {
            printf("Numbers are not in ascending order");
            exit(0);
        }
        arr[i]=temp;
        
    }
    scanf("%d",&no_to_search_cnt);
    no_search_array=(int *)malloc(no_to_search_cnt* sizeof(int));
    for(int i=0;i<no_to_search_cnt;i++)
    {
        scanf("%d",&no_search_array[i]);

    }
    
    for(int i=0;i<no_to_search_cnt;i++)
    {
        b_sort(arr,no,no_search_array[i]);
    }
}
