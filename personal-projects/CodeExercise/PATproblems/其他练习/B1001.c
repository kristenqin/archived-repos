#include<stdio.h>
int main(){
    int n,denom,count;
    scanf("%d",&n);
    denom = n%2;
    while(n>1)
        if(denom == 0) n = n/2;
        if(denom == 1) n = (3*n+1)/2;//如果上面的if判断语句执行完之后这个判断语句是否还会被执行
        count ++;
    }
    printf("%d",count);
    return 0;
}