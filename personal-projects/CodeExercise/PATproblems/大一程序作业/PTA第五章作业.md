# PTA第五章作业

## 基础题目

==<img src="C:\Users\lenovo\AppData\Roaming\Typora\typora-user-images\image-20211104080238283.png" alt="image-20211104080238283" style="zoom:33%;" />==

![image-20211104080653876](C:\Users\lenovo\AppData\Roaming\Typora\typora-user-images\image-20211104080653876.png)

不能理解这种函数调用的方式

这段代码在dev中无法运行

```c++
//代码修改
#include<iostream>
#include<cstdio>
using namespace std;
int func(int x = 0, int y = 0){//void改为int就不会出现operator的报错了
	int m;
	m = x + y;
}
int main(){
	cout<<func(1,2)<<endl;
	cout<<func(1)<<endl;
	cout<<func(1,2,3)<<endl;
	return 0;
}
```

```c++
//函数定义相关--错误示范
#include<iostream>
#include<cstdio>
using namespace std;
int func(int x, int y){
	int y = 10;
	return x + y;
}
int main(){
	cout<<func(1,4)<<endl;
	return 0;
}
```



![image-20211104081540810](C:\Users\lenovo\AppData\Roaming\Typora\typora-user-images\image-20211104081540810.png)

```c++
//传地址
void fun(int &x)
{
  ...
}
int main()
{
   ...
   int a =10;
   fun(&a);
   ...
}
//传值
void fun(int x)
{
  ...
}
int main()
{
   ...
   int a =10;
   cout << fun(a);
   ...
}
//不能理解为什么主函数直接向被调函数进行传值,但是值不会返回? 之前貌似没有编程试过
```



## 欠缺知识点

### 函数部分

1. 函数重载
2. 函数值改变相关
3. 函数调用相关
4. 函数返回值
5. 引用, 指针



## 编程题

### 函数部分

```c++
//数字中某个数字的个数
int CountDigit(int number,int digit){
    int i = 1;
    int count = 0;
    int bit;
    if(number == 0 && digit == 0){
        return 1;
    }
    else{
        for(i = 1; number != 0;i++){
            bit = number%10;
            if(bit < 0) bit = (-1)*bit;
            if(bit == digit) count++;
            number = number / 10;
        }
        return count;
    } 
}
//没有考虑到负数的情况
//没有考虑所有位置上没有digit的情况
//1位正数和1位负数的情况??
//全0的情况
```

![image-20211104092919787](C:\Users\lenovo\AppData\Roaming\Typora\typora-user-images\image-20211104092919787.png)

```c++
//看这个测试点的提示条件, 有的提示不是很能理解
//运行超时这个提示理解无能
//自己想测试数据的时候不知道怎么想, 感觉脑子不是很清楚, 尤其是什么边界情况之类的.
```

```c++
//使用函数求余弦函数的近似值
//cos函数循环定义
double funcos(double e, double x)
{
    int n,k = 0;
    double item = 1.0;//这个的绝对值小于e,e是用户自己输入的精度
    int denominator;
    double productx = 1.0;
    double sum = 1.0;
    int pre = 1;
    int i = 1;
    if(k > 0)
    {
        for(k = 1;item < e;k++)
        {
            denominator = 1;
            productx = 1.0;
            n = 2*k;//倍数问题
            pre = pre* (-1);
            //分母的阶乘
            //if(n ==0) denominator = 1;这里k从一开始就能减少很多分类讨论
            for(i = 1;i <= n;i++)
            {
                denominator *= i;
                productx *= x;
            }
            item = productx / denominator * pre;
            sum += item;
            if(item < 0) item = -item;
        }
    }
    else sum = 1.0;//感觉这么写虽然和公式有那味,但是感觉和题目要求不是很照应
    return sum;
}
```

![image-20211104105610530](C:\Users\lenovo\AppData\Roaming\Typora\typora-user-images\image-20211104105610530.png)

![image-20211104105744169](C:\Users\lenovo\AppData\Roaming\Typora\typora-user-images\image-20211104105744169.png)



```c++
//这道题写得很不顺
//但是第一次答案过得还行
//一些双精度变量定义初始值感觉比较麻烦
//变量的定义比较复杂
```

### 完整编程

#### 第一道题

```c++
//题目分析
//到底是不是太胖了
//标准体重应该是其身高（单位：厘米）减去100、再乘以0.9所得到的公斤数。
standard = (height - 100)*0.9;
unit == gongin;
shijin = gongjin/2;
//真实体重与标准体重误差在10%以内都是完美身材（即 | 真实体重 − 标准体重 | < 标准体重×10%）。
//已知市斤是公斤的两倍。
cin>>realweight;
subtract = realweight/2 - standard;
if(subtract < 0) subtract = (-1)*subtract;
if(subtract < 0.1*standard) cout<<"You are tai shou le!"<<endl;
if(subtract == 0.1*standard) cout<<"You are wan mei!"<<endl;
if(subtract > 0.1*standard) cout<<"You are tai pang le!"<<endl;
```

```c++
//代码部分
#include<iostream>
using namespace std;

void Judge(int height,int weight){
    double standard;
    double subtract;
    
    subtract = weight/2 - standard;
    if(subtract < 0) subtract = (-1)*subtract;
    if(subtract < 0.1*standard) cout<<"You are tai shou le!"<<endl;
    if(subtract == 0.1*standard) cout<<"You are wan mei!"<<endl;
    if(subtract > 0.1*standard) cout<<"You are tai pang le!"<<endl;
}

int main(){
    int N,H,W;
    cin>>N;
    int i = 0;
    for(i = 0;i < N;i++){
        cin>>H>>W;
        Judge(H,W);
    }
    return 0;
}
```

![image-20211104112326063](C:\Users\lenovo\AppData\Roaming\Typora\typora-user-images\image-20211104112326063.png)

```c++
//这次程序的输出格式没有要求很严格
```

#### 第二道题

```c++
//递归实现逆序输出整数
//不使用递归方式
int n;
cin>>n;
while(n){
    cout<<n%10;
    n = n/10;
}
return 0;
//函数部分
void reverse(int n){
    while(n){
        cout<<n%10;
        n /= 10;
    }
}
```

```c++
//代码部分
#include<iostream>
using namespace std;

void reverse(int n){
    while(n){
        cout<<n%10;
        n /= 10;
    }
}
int main(){
    int n;
    cin>>n;
    reverse(n);
    return 0;
}
```

==???这个方法就是递归吗???==

==我不理解==

#### 第三道题

```c++
//判断素数
#include<cmath>
sqrt(number);
void(int number){
    if(number == 1) cout<<"No"<<endl;
    else{
        int i = 0;
        for(i = 2;i < sqrt(number);i++){
            if(number%i == 0) break;
        }
        if(i >= sqrt(number)) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}
//第一行给出一个正整数N（≤ 10），
int N;
//随后N行，每行给出一个小于231的正整数。
int i;
int number;
for(i = 0;i < N;i++){
    cin>>number;
    Judge(number);
}
//判断
//输出
```

```c++
//代码部分
#include<iostream>
#include<cmath>
using namespace std;

void Judge(int number){
    if(number == 1) cout<<"No"<<endl;
    else{
        int i = 0;
        for(i = 2;i < sqrt(number);i++){//不同类型的不知道是否可以进行比较
            if(number%i == 0) break;
        }
        if(i >= sqrt(number)) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}
int main(){
    int N,i,number;
    cin>>N;
    for(i = 0;i < N;i++){
        cin>>number;
        Judge(number);
	}
    return 0;
}
```

![image-20211104115809375](C:\Users\lenovo\AppData\Roaming\Typora\typora-user-images\image-20211104115809375.png)

