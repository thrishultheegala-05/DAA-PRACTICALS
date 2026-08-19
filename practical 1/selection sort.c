
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
    
    for(int j=0;j<n;j++){
       for(int k=0;k<n-j-1;k++){
           if(arr[k]>arr[k+1])
           {
               int temp=arr[k];
               arr[k]=arr[k+1];
               arr[k+1]=temp;
           }
           
       }
      
    }
    printf("\nsorted array:\n");
           
        for(i=0;i<n;i++){
         printf("%d ",arr[i]);
           }
    
return 0;
}
