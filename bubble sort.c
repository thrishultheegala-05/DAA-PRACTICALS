
#include <stdio.h>

int main()
{   int n;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    
    int arr[n];
    int i=0;
    
    printf("enter %d elements: \n", n);
    
    for(i=0;i<n;i++){
    scanf("%d",&arr[i]);
    }
    
    printf("elements of array:\n");
    
    for(i=0;i<n;i++){
      printf("%d ",arr[i]);
    }
    
    for(int j=0;j<n-1;j++)
{
    int min_index=j;

    for(int k=j+1;k<n;k++)
    {
        if(arr[k]<arr[min_index])
        {
            min_index=k;
        }
    }

    int temp=arr[j];
    arr[j]=arr[min_index];
    arr[min_index]=temp;
}
    printf("\nsorted array:\n");
           
        for(i=0;i<n;i++){
         printf("%d ",arr[i]);
           }
           
     return 0;
}