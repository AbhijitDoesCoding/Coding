#include<stdio.h>
 
int main()
{
    int test, num_box, max;
    int arr[20];
    int count;
    
    scanf("%d", &test);
    
    while(test--)
    {
        count=0;
        scanf("%d%d", &num_box, &max);
        for(int i=0; i<num_box; i++)
        {
            scanf("%d", &arr[i]);
            if(arr[i]==arr[i+1])
                count=1;
        }
        
        if(max<=num_box && max!=1)
        {
            if(count==0)
                printf("Yes\n");
            else
                printf("No\n");
        }
        
        else
            printf("No\n");
    }
    
    return 0;
    
}