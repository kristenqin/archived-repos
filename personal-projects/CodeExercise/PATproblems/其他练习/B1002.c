/*读入一个正整数 n，计算其各位数字之和，用汉语拼音写出和的每一位数字。

输入格式：
每个测试输入包含 1 个测试用例，即给出自然数 n 的值。这里保证 n 小于 10^100

输出格式：
在一行内输出 n 的各位数字之和的每一位，拼音数字间有 1 空格，但一行中最后一个拼音数字后没有空格。
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    int sum0,sum1 = 0;
    int num[100],num1[100];
    int i,j = 1;
    scanf("%d",&sum0);
    while(sum0>=0){
        num[i] = sum0 % 10;
        sum0 /= 10;
        sum1 = sum1 + num[i];
        i++;
    }
    while(sum1>=0){
        num1[j] = sum1 % 10;
        sum1 /= 10;
        j++;
    }
    while(j>0){
        switch(num1[j]){
            case 0: printf("ling"); break;
            case 1: printf("yi"); break;
            case 2: printf("er"); break;
            case 3: printf("san"); break;
            case 4: printf("si"); break;
            case 5: printf("wu"); break;
            case 6: printf("liu"); break;
            case 7: printf("qi"); break;
            case 8: printf("ba"); break;
            case 9: printf("jiu"); break;
        }
        if(j>1) printf(" ");
        j--;
    }
    return 0;
}
//break语句不熟
//for和while的边界条件不熟