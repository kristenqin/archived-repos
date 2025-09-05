//思路：判断，字符串当作数组处理，先后顺序用位置变量处理
//条件三感觉比较迷惑人
#include<stdio.h>
#include<string.h>
int main(){
    int n,i,m,j;
    scanf("%d",&n);
    char s[10][100];
    int n_p,n_t,n_a;
    int flag_p,flag_t,len;
    while(m = n-1){//是在整个大循环内部的
        scanf("%s",s[m]);//定义数组，对数组的操作不习惯//数组为什么要定义成这样
        len = strlen(s[m]);
    }
    for(i = 1;i<=10;i++){
        n_p = 0, n_t = 0, n_a = 0;//为什么答案最后定义了一个other
        flag_p = 0, flag_t = 0;//为什么这里没有对这两个变量进行初始化以及没有对A的位置进行定义//为什么每次循环都要初始化一遍这个变量呢
        for(int j = 0; j < len; j++){
            if(s[i][j] == 'P'){
                n_p ++;
                flag_p = i;
            }
            else if(s[i][j] == 'T'){ //if和if else语句的区别
                n_t ++;
                flag_t = i;
            }
            else if(s[i][j] != 'A'){
                n_a ++;
            }
            //题解给的判断条件是如果不是A才会自增，自己还是没有对所有可能输入的数据形式进行思考
            //为什么不对A进行记录
            //上述三个条件语句中判断是否为A字符的必须放在最后，不然P和T会干扰
        }
        if((n_p != 1)||(n_t != 1)||n_a||(flag_t-flag_p <= 1))
            printf("NO");
            //n_a单独作为条件即可
        else if((flag_t-flag_p-1)*flag_p == (len - flag_t - 1))
            printf("YES");
        else 
            printf("NO");
    }
    return 0;
}
//初始位置从零开始和初始位置从1开始没有区别，在最开始写题的时候不要考虑这些细节
//这道题的思路是根据所有测试数据找出筛选程序
//自己看到题目的时候想的是正确的测试数据，不会想到要统计各个字母的个数，思维方式是将数据和正确的去比较得出yes或者no
//题目中哪些条件是判断yes，哪些条件是判断no
//该题解中将第三条作为正确判断，其他两条作为错误判断