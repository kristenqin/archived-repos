# PTAB数素数

```c++
//题目分析
//两个数字之间的素数依次输出
//输出,空格间隔,结尾无空格,10个循环
int m,n;
int count,registernumber;
cin>>m>>n;
//计算左端数值
for(int x = 1;x < m*m;x++){
    count += Judge(x);
    if(count == m) registernumber = x;
}
//计算右端数值
for(int y = registernumber+1;y < n*n;y++){
    count += Judge(y);
    if(Judge(y) != 0) cout<<y;
    if(count == m-n+1) break;
}
//判断素数
int Judge(int number){
    if(number == 1) return void
    for(int i = 2;i<sqrt(number);i++){
        if(number % i == 0) break;
        else continue;
    }
    if(i < sqrt(number)) return 0;//这里两个条件这样写会好理解很多
    else return 1;
}

```

```c++
//代码部分
#include<iostream>
using namespace std;
int main(){
    //题目分析
    //两个数字之间的素数依次输出
    //输出,空格间隔,结尾无空格,10个循环
    int m,n;
    int count,registernumber = 0;
    int Judge(int number);
    cin>>m>>n;
    //计算左端数值
    for(int x = 1;x < m*m;x++){
        count += Judge(x);
        if(count == m) registernumber = x;
    }
    //计算右端数值
    for(int y = registernumber+1;y < n*n;y++){
        count += Judge(y);
        if(Judge(y) != 0) cout<<y;
        if(count == m-n+1) break;
    }
    //判断素数
    int Judge(int number){
        if(number == 1) return 0;
            for(int i = 2;i<sqrt(number);i++){
                if(number % i == 0) break;
                else continue;
            }
        if(i < sqrt(number)) return 0;//这里两个条件这样写会好理解很多
        else return 1;
    }
}
```

```c++
//代码修正
//代码部分
#include<iostream>
#include<cmath> 
using namespace std;
int Judge(int number){
	int i = 0;
        if(number == 1) return 0;
        else{
        	for(i = 2;i<number;i++){
                if(number % i == 0) break;
                else continue;
            }
		}
        if(i < number) return 0;//这里两个条件这样写会好理解很多
        else return 1;
}
int main(){
    //题目分析
    //两个数字之间的素数依次输出
    //输出,空格间隔,结尾无空格,10个循环
    int m,n;
    int count1 = 0;
	int count2 = 0;
	int registernumber = 0;
    cin>>m>>n;
    //计算左端数值
    for(int x = 1;x < m*m;x++){
        count1 += Judge(x);//统计第几个素数 
        if(count1 == m+1) registernumber = x;
    }
    //计算右端数值
    for(int y = registernumber+1;y < n*n;y++){
    	//为啥我在这里会用一个判断语句呢,感觉应该正常情况下应该想到的是循环语句 ,使用循环会限制判断的次数 
        if(count2 <= n-m){
	        	if(Judge(y)){
	        	cout<<y<<" "; 
				count2++; 
				if(count2 % 10 == 0) cout<<endl;  
			}
		}
		else if(count2 == m-n) break;
    }   
}
```

大致情况对了，但是边界条件不对

