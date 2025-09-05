# PTAB优美代码册

```c++
//数字分类
/*
链接：https://www.nowcoder.com/questionTerminal/473c219f9e4d4ab2851ed388895a9c86
来源：牛客网

给定一系列正整数，请按要求对数字进行分类，并输出以下5个数字：



A1 = 能被5整除的数字中所有偶数的和；

A2 = 将被5除后余1的数字按给出顺序进行交错求和，即计算n1-n2+n3-n4...；

A3 = 被5除后余2的数字的个数；

A4 = 被5除后余3的数字的平均数，精确到小数点后1位；

A5 = 被5除后余4的数字中最大数字。

输入描述:
每个输入包含1个测试用例。
每个测试用例先输入一个不超过1000的正整数N。
然后给出N个不超过1000的待分类的正整数。数字间以空格分隔。


输出描述:
对给定的N个正整数，按题目要求计算A1~A5并在一行中顺序输出。数字间以空格分隔，但行末不得有多余空格。
若其中某一类数字不存在，则在相应位置输出“N”。
*/
```

```c++
//优美解
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int c1=0,c2=0,c3=0,c4Num=0,c5=0;
    float c4=0;
    int n,x,i=1;
    cin>>n;
    while(n--)
    {
        cin>>x;
        switch(x%5)
        {
            case 0:if(x%2==0) c1+=x; break;
            case 1:c2+=(i*x);i=-i;break;
            case 2:c3++;break;
            case 3:c4+=x;c4Num++;break;
            case 4:if(x>c5)c5=x;break;
        }
    }
    (c1>0)?(cout<<c1<<" "):(cout<<"N ");
    (c2!=0)?(cout<<c2<<" "):(cout<<"N ");
    (c3>0)?(cout<<c3<<" "):(cout<<"N ");
    (c4>0)?(cout<<fixed<<setprecision(1)<<c4/c4Num<<" "):(cout<<"N ");
    (c5>0)?(cout<<c5):(cout<<"N");
    return 0;
}
```

```c++
//A+B>C?
/*
链接：https://www.nowcoder.com/questionTerminal/33ceeced8acc475aa0be9603936890a6
来源：牛客网

给定区间[-2的31次方, 2的31次方]内的3个整数A、B和C，请判断A+B是否大于C。

输入描述:
输入第1行给出正整数T(<=10)，是测试用例的个数。随后给出T组测试用例，每组占一行，顺序给出A、B和C。整数间以空格分隔。


输出描述:
对每组测试用例，在一行中输出“Case #X: true”如果A+B>C，否则输出“Case #X: false”，其中X是测试用例的编号（从1开始）。
*/
```

```c++
//优美解
#include <cstdio>
int main(){
       int n;
	long long A,B,C;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
        scanf("%lld %lld %lld",&A,&B,&C);
        printf("Case #%d: %s\n",i+1,(A+B)>C?"true":"false");
    }
	return 0;
}
```

