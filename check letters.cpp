#include<stdio.h>
int main()
{
    int numbers[4], i, j;
    int arr2[4], k = 0, k1 = 0;
    int flag = 0;
    char PrintChar;

    for (i = 0; i < 4; i++)
    {
        printf("Enter number#1 ");
        scanf("%d", &numbers[i]);
    }
    
    for(i = 0; i < 4; i++)
    {
       for(j = 0; j < 4; j++)
       {
           flag = 0;
           if(i != j && numbers[i] == numbers[j]) //i != j does not compare with the same number, same position
           {
               for(k1 = 0; k1 < k; k1++)
                   if(arr2[k1] == numbers[j]) //only checks if it is repeated.
                     flag = 1;
               if(flag != 1)
                   arr2[k++] = numbers[j];
           }
       }
    }
    for(i = 0; i < k; i++)
      printf("Number %d has duplicate values\n",arr2[i]);
    return 0;
}