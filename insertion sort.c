#include <stdio.h>

int main()
{
    int n;
    printf("Enter the number of elements:");
    scanf("%d",&n);

    int arr[n];
    int i=0;

    printf("enter %d elements:\n",n);

    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
     printf("elements of array:\n");

    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }

    for(int j=1;j<n;j++){
        int key=arr[j];
        int k=j-1;

        while(k>=0 && arr[k]>key){
            arr[k+1]=arr[k];
            k--;
        }

        arr[k+1]=key;
    }
        printf("\nsorted array:\n");

    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }

    return 0;
}