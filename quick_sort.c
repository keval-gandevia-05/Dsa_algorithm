#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
void swap(int *i,int *j)
{
    int temp=*i;
    *i=*j;
    *j=temp;
}
void quicksort(int *arr,int lb,int ub)
{
    if(lb<ub)
    {
        
        int start=lb;
        int end=ub;
        int pivot=arr[lb];
        short flag=1;
        while(flag)
        {
            
            start++;
            while(arr[start]<pivot)
            {
                start++;
            }
            
            while(arr[end]>pivot)
             {
                end--;
            }
            if(start<end)
            {
                swap(&arr[start],&arr[end]);
            }   
            else
            {
                flag=0;
            }
        
        }
        swap(&arr[lb],&arr[end]);
        quicksort(arr,lb,end-1);
        quicksort(arr,end+1,ub);
        
    }
}
int main()
{
    
    int no;
    scanf("%d",&no);
    if(no==0)
    {
        printf("Size of array must be within [1,10000]");
        exit(0);
    }
    int *arr=(int*)malloc(no*sizeof(int));
    for(int i=0;i<no;i++)
    {
        scanf("%d",&arr[i]);
        if(arr[i]<0)
        {
            printf("Number must be within [1,1000000]");
            exit(0);
        }
    }
    quicksort(arr,0,no-1);
    
    for(int i=0;i<no;i++)
    {
        printf("%d ",arr[i]);
    }

}
