# PTAB部分A+B

## 题目分析及代码

```c++
//题目描述
/*
 * 部分A+B
 * 题目描述
 * 正整数A的“DA（为1位整数）部分”定义为由A中所有DA组成的新整数PA。
 * 例如：给定A = 3862767，DA = 6，则A的“6部分”PA是66，因为A中有2个6。
 * 现给定A、DA、B、DB，请编写程序计算PA + PB。
 * 输入描述:
 * 输入在一行中依次给出A、DA、B、DB，中间以空格分隔，其中0 < A, B < 1010。
 * 输出描述:
 * 在一行中输出PA + PB的值。
 * 输入例子:
 * 3862767 6 13530293 3
 * 输出例子:
*/
```



```c++
//题目分析
//输入数字,计算的DA,组成的PA
#include<iostream>
#include<cmath>
using namespace std;
int SolveP(int inputnumber,int d){
    int temp = 0;
    int count = 0;
    int p = 0;
    while(inputnumber != 0){
        temp = inputnumber % 10;
        if(temp == d) count++;
        inputnumber /= 10;
    }
    while(count--){
        p += d*pow(10,count);
    }
    return p;
}

int main(){
    int A,B;
    int p1,p2;
    int d1,d2;
    int sum;
    
    cin>>A>>d1>>B>>d2;
    p1 = SolveP(A,d1);
    p2 = SolveP(B,d2);
    sum = p1 + p2;
    
    cout<<sum;  
    
    return 0;
}

//输出PA+PB
```

## 答案

```c++
//更简单的代码
#include <cstdio>
using namespace std;
int getP(int a,int da)
{
    int sum=0;
    while(a)
    {
        int r=a%10;
        if(r==da)
        {
            sum=sum*10+da;
        }
        a/=10;
    }
    return sum;
}
int main()
{
    int a,da,b,db;
    scanf("%d%d%d%d",&a,&da,&b,&db);
    printf("%d",getP(a,da)+getP(b,db));
    return 0;
} 
```

```c++
//思路很有趣的代码
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int main() {
    bool taga = false;
    bool tagb = false;
    string a,b;
    char da,db;
    string pa,pb;
    int sum =0;
    int m,n;
    cin>>a>>da>>b>>db;
    for(int i=0; i<a.length();i++){
        if(a[i] == da){
            pa += a[i];
            taga = true;
        }
 
    }
    if (!taga)
        pa = '0';
 
 
    for (int j = 0; j <b.length() ; ++j) {
        if (b[j]==db){
            pb += b[j];
            tagb = true;
        }
    }
    if (!tagb)
        pb = '0';
 
    stringstream ss;
    ss<<pa;
    ss>>m;
    stringstream sb;
    sb<<pb;
    sb>>n;
    sum = m+n;
    cout<<sum;
    return 0;
}
```

```c++
//有趣的代码
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string a,b;
    long long n,m,sum = 0,_sum = 0;
    cin >> a >> n >> b >> m;
    for(unsigned int i = 0; i < a.size(); i++) if((a[i]-'0') == n) sum = sum*10+(a[i]-'0');
    for(unsigned int i = 0; i < b.size(); i++) if((b[i]-'0') == m) _sum = _sum*10+(b[i]-'0');
    cout << sum+_sum << endl;

    return 0;
}
```

## 问题点

![image-20211109201002611](D:\CPrograming\MyPic\image-20211109201002611.png)

自己的问题程序并没有判出来

还是浙大的系统更好