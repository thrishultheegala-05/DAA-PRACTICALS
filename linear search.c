#include <stdio.h>
int main() {
int arr[]={10,20,30,40,50};
int n =5;
int num = 30;
for (int i = 0; i<n; i++)
{
    
    if (arr[i]==num){
        printf("number is found");
        return 0;
        
    }
}
    printf("not found");
    
}