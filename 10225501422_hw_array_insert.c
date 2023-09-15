#include <stdio.h>
#define SIZE 11
int main()
{
    int bajianArray[SIZE] = {11, 12, 15, 19, 23, 26, 29, 38, 40, 100};
    int temp1, temp2, number;
    printf("\narray is:\n");
    for (int i = 0; i < 10; i++)
        printf("%5d", bajianArray[i]);
    printf("\n\nplease input the number to be inserted:");
    scanf("%d", &number);

    int count=10;
    while (bajianArray[count-1]>number && count>=1)
    {
        bajianArray[count]=bajianArray[count-1];
        count--;
    }
    bajianArray[count]=number;

    for (int i = 0; i < 11; i++)
        printf("%5d", bajianArray[i]);
    printf("\n");
    return 0;
}