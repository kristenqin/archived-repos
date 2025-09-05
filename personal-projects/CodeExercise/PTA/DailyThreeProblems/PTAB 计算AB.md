# PTAB 计算A/B

```c++
//题目分析
//数据类型
//long long int
//数据处理
A = B * Q + R;
//输出
Q R
```

```c++
//代码部分
#include<iostream>
using namespace std;
int main(){
    long long int A,Q,R;
    int B;
    cin>>A>>B;
    R = A % B;
    Q = (A - R) / B;
    
    cout<<Q<<" "<<R;
    
    return 0;
}
```

![image-20211109201645022](D:\CPrograming\MyPic\image-20211109201645022.png)

可能是1000位数太大了

什么情况下整数生命不能处理数据, 需要使用字符串类型进行处理

需要一篇总结文章

```c++
//修正----没有过
#include<iostream>
using namespace std;
int main(){
    char A,Q,R;
    int B;
    cin>>B;
    A = gets();
    R = puts((A -'0') % B);
    Q = puts((A - R) / B);
    cout<<Q<<R;
    return 0;
}
```

```c++
//为什么这段代码在dev cpp上编译需要时间很长
//手除算法的实现过程
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s,c = "";
    int n, tmp,res = 0;
    cin >> s >> n;
    for (size_t i = 0; i < s.size();i++)
    {
        tmp = res * 10 + (s[i] - '0');
        res = tmp % n;
        if (i == 0 && tmp / n == 0)continue;
        c.append(1, tmp / n + '0');
    }
    cout << c + " " << res << endl;
    return 0;
}
```

```c++
//没看懂的代码
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	string a;
	int b,temp=0;
	cin>>a>>b;
    //flag的作用是什么
	bool flag=false;
	for(int i=0;i<a.length();i++)
	{
		temp=temp*10+a[i]-'0';
        //不理解这个判断语句以及flag的使用技巧
		if(temp/b==0&&flag==false) continue;
		else if(temp/b&&flag==false)
		{
			printf("%d",temp/b);
			flag=true;
		}
		else//这个else是什么意思
		{
			printf("%d",temp/b);
			flag=true;
		}
		temp%=b;//感觉这里临界条件特别难在脑子里面迅速反应出来
	}
    
    //余数为0的情况
	if(flag==false) printf("0");
	//余数非零情况输出
	printf(" %d",temp);
	
	return 0;
}
```

```c++
#include <iostream>
#include <string>
#include <queue>
using namespace std;
//没看懂这里bool用处
bool isZero(string s){
    for(int i=0; i< s.length() ; i++){
        if(s[i] != '0')
            return false;
    }
    return true;
}

int main()
{
    queue<int> que;
    string str;
    int b,rest,shi,ge,yu,gao,shang;
    cin>>str>>b;
    rest = 0;
    yu =0;
    if(str.length() == 1){
        gao = str[0] - '0';
        yu = gao %b;
        que.push(gao/b);
    }
    else{
        for(int i =0;i<str.length();i++){
            int temp = (str[i] -'0') + yu*10;
            yu = temp % b ;

            shang = temp /b;
            if(!(i==0&& shang ==0)){

                que.push(shang);

            }

        }

    }
    string s;
    char re;
    while(!que.empty()){
        re = que.front() + '0';
        s =s+re;
        que.pop();
    }

    cout<<s;
    cout<<" "<<yu;

    return 0;
}
```

```c++
#include<stdio.h>
#include<string.h>
int main()
{
	char a[1002]={0};//注意这种数组的初始化方式
	int b;
	scanf("%s",a);
	scanf("%d",&b);
	int len=strlen(a),h=a[0]-'0',q=0;//初始化len为A的位数，h为A的首位，q为0，因为对于第一位来说没有进位 
	if(len==1)//如果A只有一位
	{
		printf("%d %d\n",h/b,h%b);	
		return 0;//main函数return 0；程序直接结束 
	}
	if(h/b==0)//A有多位并且首位比B小 
		q=h;
	else//A有多位并且首位比B大 
	{
		printf("%d",h/b);
		q=h%b;
	}
	int i=1;
	while(a[i]!=0)//字符数组结束标志为ASCII码值0
	{
		h=a[i++]-'0';
		printf("%d",(q*10+h)/b);
		q=(q*10+h)%b;
	}
	printf(" %d\n",q);	//注意%d前面有空格
	return 0; 
}
```

## 分析

- [ ] 需要自己手动再实现一遍