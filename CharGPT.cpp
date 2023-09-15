#include <stdio.h>

int main() {
    int num;
    int bit_count = 0;

    printf("请输入一个整数：");
    scanf("%d", &num);

    int temp = num >> 31;
    bit_count = (((~num) & temp) | (num & (~temp))) >> 31;
    bit_count += 1;

    printf("用二的补码表达这个数所需的最多位数为：%d\n", bit_count);

    return 0;
}
