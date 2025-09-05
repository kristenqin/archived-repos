# PTA第五章上机练习

## 第一道题

```c++
//题目分析
//一天有24小时，钟却是只在后半天敲1~12下。
//例如在23:00敲钟，就是“当当当当当当当当当当当”，而到了23:01就会是“当当当当当当当当当当当当”。
//输入格式
#include<iostream>
#include<cstdio>
int main(){
    scanf("%d")
}
//对输入格式的实现不熟悉
//按照数字类型输入
char blank;
int h1,h2;
int m1,m2;
int hour,minute;
cin>>h1>>h2>>blank>>m1>>m2;
cout<<h1<<h2<<blank<<m1<<m2;
//修正
char time[5];
for(int i = 0;i < 5;i++){
    cin>>time[i];
}
int hour = (time[0]-'0')*10 + (time[1]-'0');
int minute = (time[3]-'0')*10 + (time[4]-'0');

//判断条件设置
//大于12敲,小于等于12不敲
if(hour <= 12&hour >= 0){
    cout<<"Only";
    for(int m = 0;m < 5;m++){
        cout<<time[m];
    }
    cout<<'.'<<"Too early to Dang.";
}
	//大于本身+1输出,等于本身输出
else{
    if(minute>0){
        for(int n = 0;n <= hour;n++) cout<<"Dang";
    }
    else{
        for(int n = 0;n < hour;n++) cout<<"Dang";
    }
}
```

```c++
//代码部分
#include<iostream>
using namespace std;
int main(){
    int h1,h2;
    int m1,m2;
    int hour,minute;
    //修正
    char time[5];
    for(int i = 0;i < 5;i++){
        cin>>time[i];
    }
    hour = (time[0]-'0')*10 + (time[1]-'0');
    minute = (time[3]-'0')*10 + (time[4]-'0');

    //判断条件设置
    //大于12敲,小于等于12不敲
    if(hour <= 12&&hour >= 0){
        cout<<"Only ";
        for(int m = 0;m < 5;m++){
            cout<<time[m];
        }
        cout<<".  "<<"Too early to Dang.";
    }
        //大于本身+1输出,等于本身输出
    else{
        if(minute>0){
            for(int n = 0;n <= hour%12;n++) cout<<"Dang";
        }
        else{
            for(int n = 0;n < hour%12;n++) cout<<"Dang";//自己看题目要求的条件
        }
    }
   return 0; 
}
```

![image-20211105084957204](C:\Users\lenovo\AppData\Roaming\Typora\typora-user-images\image-20211105084957204.png)

`scanf`和`cin`的效果一样

![image-20211105090908600](C:\Users\lenovo\AppData\Roaming\Typora\typora-user-images\image-20211105090908600.png)



## 第二道题

```c++
//谁先倒

//题目分析
//如果谁比划出的数字正好等于两人喊出的数字之和，谁就输了，输家罚一杯酒。
//两人同赢或两人同输则继续下一轮，直到唯一的赢家出现。
//酒量（最多能喝多少杯不倒）和划拳记录

//输入格式
	//数据类型
	int yell1,yell2;
	int finger1,finger2;
	int judge;
	int n;
	int volume1,volume2;
	int register1,register2;
//数据处理
//判断条件(这里只考虑输的情况)
	//一人输掉
for()
	judge = yell1+yell2;
	if(finger1 == judge||finger2 == judge){
        if(finger1 == judge) register1++;
        else register2++
    }
	//两人都输
	else if((finger1 == judge && finger2 == judge)||(finger1 != judge && finger2 != judge)){
        continue;
    }
	//到达其中一人酒量
	if(register1 == volume1 && register2 != volume2){
        cout<<"A"<<endl<<register2;
        break;
    }
	else if(register1 != volume1 && register2 == volume2){
        cout<<"B"<<endl<<register1;
        break;
    }
//数据不需要保存
//输出格式
	//先倒下的人

	//没有倒下的人喝的杯
	
	//题目保证有一个人倒下
        //这个是由测试数据决定的吧,自己应该不用考虑道程序里面
```

```c++
//代码部分
#include<iostream>
using namespace std;
int main(){
    int yell1,yell2;
	int finger1,finger2;
	int judge;
	int n;
	int volume1,volume2;
	int register1,register2;
    
    cin>>volume1>>volume2;
    cin>>n;
    
    judge = yell1+yell2;
    for(int i = 0;i < n;i++){
        cin>>yell1>>finger1>>yell2>>finger2;
        judge = yell1+yell2;
        
        if(finger1 == judge||finger2 == judge){
            if(finger1 == judge) register1++;
            else register2++
        }
	//两人都输/两人都赢
        else((finger1 == judge && finger2 == judge)||(finger1 != judge && finger2 != judge)){
            continue;
        }
        if(register1 == volume1 && register2 != volume2){
            cout<<"A"<<endl<<register2;
            break;
        }
        else if(register1 != volume1 && register2 == volume2){
            cout<<"B"<<endl<<register1;
            break;
        }
    }
    return 0;
}
//代码修改
//成果, 能正常输出结果, register2不能正常输出
//代码部分
#include<iostream>
using namespace std;
int main(){
    int yell1,yell2;
	int finger1,finger2;
	int judge;
	int n;
	int volume1,volume2;
	int register1,register2 = 0;
    
    cin>>volume1>>volume2;
    cin>>n;
    
    for(int i = 0;i < n;i++){
        cin>>yell1>>finger1>>yell2>>finger2;
        judge = yell1+yell2;
        
        if(finger1 == judge||finger2 == judge){
            if(finger1 == judge) register1++;
            else register2++;
        }
        else{//((finger1 == judge && finger2 == judge)||(finger1 != judge && finger2 != judge)){感觉是else if和下面的if没有搭配上 
        	if(finger1 == judge && finger2 == judge){
        		register1++;
        		register2++;
			} 
			else continue;
        }
        if(register1 > volume1 && register2 < volume2){
            cout<<"A"<<endl<<register2;
            break;
        }
        else if(register1 < volume1 && register2 > volume2){
            cout<<"B"<<endl<<register1;
            break;
        }
    }
    return 0;
}
//循环判断条件问题
#include<iostream>
using namespace std;
int main(){
    int yell1,yell2;
	int finger1,finger2;
	int judge;
	int n;
	int volume1,volume2;
	int register1,register2 = 0;
    
    cin>>volume1>>volume2;
    cin>>n;
    
    for(int i = 0;i < n;i++){
        cin>>yell1>>finger1>>yell2>>finger2;
        judge = yell1+yell2;
                
        if((finger1 == judge) && (finger2 == judge)){
        		register1++;
        		register2++;
			}
		if((finger1 == judge) && (finger2 != judge)) register1++;
        if((finger2 == judge) && (finger1 != judge)) register2++;
		if(finger1 != judge && finger2 != judge) continue;
        
        if(register1 > volume1 && register2 < volume2){
            cout<<"A"<<endl<<register2;
            break;
        }
        else if(register1 < volume1 && register2 > volume2){
            cout<<"B"<<endl<<register1;
            break;
        }
    }
    return 0;
}//感觉bug越改自己越迷

//修正
#include<iostream>
using namespace std;
int main(){
    int yell1,yell2;
	int finger1,finger2;
	int judge;
	int n;
	int volume1,volume2;
	int register1,register2 = 0;
    
    cin>>volume1>>volume2;
    cin>>n;
    
    for(int i = 0;i < n;i++){
        cin>>yell1>>finger1>>yell2>>finger2;
        judge = yell1+yell2;
                
        if((finger1 == judge) && (finger2 == judge)){
    		register1++;
    		register2++;
		}
		if((finger1 == judge) && (finger2 != judge)) register1++;
        if((finger2 == judge) && (finger1 != judge)) register2++;
        
		//这里如果continue的话后面的判断就不会执行了 
        
        if((register1 > volume1) && (register2 <= volume2)){
            cout<<"A"<<endl<<register2;
            break;
        }
        else if((register1 <= volume1) && (register2 > volume2)){
            cout<<"B"<<endl<<register1;
            break;
        }
    }
    return 0;
}//感觉bug越改自己越迷


```

![image-20211105104049998](C:\Users\lenovo\AppData\Roaming\Typora\typora-user-images\image-20211105104049998.png)

`B`的输出不正常

![image-20211105112236195](C:\Users\lenovo\AppData\Roaming\Typora\typora-user-images\image-20211105112236195.png)

```c++
//问题分析
没有做到等价,如果等价需要换用数据存储方式;???
某人一直喝;???
最大N随机数;???
```

## 第三道题

```c++
//题目分析
//整数的分类处理

//给定 N 个正整数，要求你从中得到下列三种计算结果：

//A1 = 能被 3 整除的最大整数
//A2 = 存在整数 K 使之可以表示为 3K+1 的整数的个数
//A3 = 存在整数 K 使之可以表示为 3K+2 的所有整数的平均值（精确到小数点后 1 位）


//输入
	//空格分隔
int number[];//统计个数不需要设置数组
int A[3] = {0,0,0,0};
int sum = 0;
double average = 0;
cin>>n;
while(n--){
    cin>>number;//number = getchar() - '0';
    if(number % 3 == 0){
        if(A[1] <= number) A[1] = number;
    }
    
    if(number % 3 == 1) A[2]++;
    
    if(number % 3 == 2){
        sum += number;
        A[3]++;
    }
}
average = sum / A[3];

//输出
	//空格分隔
if(A[1] == 0) cout<<"NONE";
else cout<<A[1]<<" ";

if(A[2] == 0) cout<<"NONE";
else cout<<A[2]<<" ";
    
if(A[3] == 0) cout<<"NONE";
else printf("%.1lf",average);
```

```c++
//代码部分
#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    int A[4] = {0,0,0,0};//在初始化的时候太多变量了
    int sum = 0;
    double average = 0;
    int n;
    int number;
    
    cin>>n;
    while(n--){
        cin>>number;//number = getchar() - '0';
        
        if(number % 3 == 0){
            if(A[1] <= number) A[1] = number;
        }

        if(number % 3 == 1) A[2]++;

        if(number % 3 == 2){
            sum += number;
            A[3]++;
        }
    }
    average = sum / A[3];

    //输出
    //空格分隔
    if(A[1] == 0) cout<<"NONE";
    else cout<<A[1]<<" ";

    if(A[2] == 0) cout<<"NONE";
    else cout<<A[2]<<" ";

    if(A[3] == 0) cout<<"NONE";
    else printf("%.1lf",average);
    
    return 0;
}
```

<img src="C:\Users\lenovo\AppData\Roaming\Typora\typora-user-images\image-20211106104034635.png" alt="image-20211106104034635" style="zoom:33%;" />

不能非常直观理解这个输入和输出过程

整个运算过程如何展示

```c++
//输出
8
5 8 7 6 9 1 3 10
9 3 6.0
```

```c++
//代码修正
//代码部分
#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    int A[4] = {0,0,0,0};//在初始化的时候太多变量了
    double sum = 0;
    double average = 0;
    int n;
    int number;
    
    cin>>n;
    while(n--){
        cin>>number;//number = getchar() - '0';
        
        if(number % 3 == 0){
            if(A[1] <= number) A[1] = number;
        }

        if(number % 3 == 1) A[2]++;

        if(number % 3 == 2){
            sum += number;
            A[3]++;
        }
    }
    average = sum / A[3];

    //输出
    //空格分隔
    if(A[1] == 0) cout<<"NONE";
    else cout<<A[1]<<" ";

    if(A[2] == 0) cout<<"NONE";
    else cout<<A[2]<<" ";

    if(A[3] == 0) cout<<"NONE";
    else printf("%.1lf",average);
    
    return 0;
}
```

![image-20211106104658084](C:\Users\lenovo\AppData\Roaming\Typora\typora-user-images\image-20211106104658084.png)



## 第四道题

```c++
//吃鱼还是吃肉
//题目分析
// 8 岁男宝宝的标准身高为 130 厘米、标准体重为 27 公斤
//8 岁女宝宝的标准身高为 129 厘米、标准体重为 25 公斤

//输入
int n;
struct{
    int gender;
    int height;
    int weight;
}member[10];

cin>>n;

//数据输入
for(int i = 0; i < n;i++){
    cin>>member[i].gender>>member[i].height>>member[i].weight;
}

//数据处理
if(gender == 1){
    //身高评价,体重评价
    if(height > 130) cout<<"ni li hai!";
    else if(height == 130) cout<<"wan mei!";
    else(height < 130) cout<<"duo chi yu!";
    
    if(weight > 27) cout<<"shao chi rou!";
    else if(weight == 27) cout<<"wan mei!";
    else(weight < 27) cout<<"duo chi rou!";
}

if(gender == 0){
    //身高评价,体重评价
    if(height > 129) cout<<"ni li hai!";
    else if(height == 129) cout<<"wan mei!";
    else(height < 129) cout<<"duo chi yu!";
    
    if(weight > 25) cout<<"shao chi rou!";
    else if(weight == 25) cout<<"wan mei!";
    else(weight < 25) cout<<"duo chi rou!";
}
```

```c++
//代码部分
#include<iostream>
using namespace std;

int main(){
    int n;
    struct{
        int gender;
        int height;
        int weight;
    }member[10];
    
    cin>>n;
    //数据输入
    for(int i = 0; i < n; i++){
        cin>>member[i].gender>>member[i].height>>member[i].weight;
    }
    
    for(int m = 0; m < n; m++{
        //数据处理
        if(member[m].gender == 1){
            //身高评价,体重评价
            if(member[m].height > 130) cout<<"ni li hai!";
            else if(member[m].height == 130) cout<<"wan mei!";
            else(member[m].height < 130) cout<<"duo chi yu!";

            if(member[m].weight > 27) cout<<"shao chi rou!";
            else if(member[m].weight == 27) cout<<"wan mei!";
            else(member[m].weight < 27) cout<<"duo chi rou!";
        }

        if(member[m].gender == 0){
            //身高评价,体重评价
            if(member[m].height > 129) cout<<"ni li hai!";
            else if(member[m].height == 129) cout<<"wan mei!";
            else(member[m].height < 129) cout<<"duo chi yu!";

            if(member[m].weight > 25) cout<<"shao chi rou!";
            else if(member[m].weight == 25) cout<<"wan mei!";
            else(member[m].weight < 25) cout<<"duo chi rou!";
        }
    }
    return 0;
}
```

![image-20211106110433108](C:\Users\lenovo\AppData\Roaming\Typora\typora-user-images\image-20211106110433108.png)

```c++
//代码修正
//代码部分
#include<iostream>
using namespace std;

int main(){
    int n;
    struct{
        int gender;
        int height;
        int weight;
    }member[10];
    
    cin>>n;
    //数据输入
    for(int i = 0; i < n; i++){
        cin>>member[i].gender>>member[i].height>>member[i].weight;
    }
    
    for(int m = 0; m < n; m++){
    	if(m == 0){
    		//数据处理
		    if(member[m].gender == 1){
		        //身高评价,体重评价
		        if(member[m].height > 130) cout<<"ni li hai! ";
		        else if(member[m].height == 130) cout<<"wan mei! ";
		        else if(member[m].height < 130) cout<<"duo chi yu! ";
		
		        if(member[m].weight > 27) cout<<"shao chi rou!";
		        else if(member[m].weight == 27) cout<<"wan mei!";
		        else if(member[m].weight < 27) cout<<"duo chi rou!";
		    }
		
		    if(member[m].gender == 0){
		        //身高评价,体重评价
		        if(member[m].height > 129) cout<<"ni li hai! ";
		        else if(member[m].height == 129) cout<<"wan mei! ";
		        else if(member[m].height < 129) cout<<"duo chi yu! ";
		
		        if(member[m].weight > 25) cout<<"shao chi rou!";
		        else if(member[m].weight == 25) cout<<"wan mei!";
		        else if(member[m].weight < 25) cout<<"duo chi rou!";
		    }
		}
        else{
        	cout<<"\n";
        	//数据处理
		    if(member[m].gender == 1){
		        //身高评价,体重评价
		        if(member[m].height > 130) cout<<"ni li hai! ";
		        else if(member[m].height == 130) cout<<"wan mei! ";
		        else if(member[m].height < 130) cout<<"duo chi yu! ";
		
		        if(member[m].weight > 27) cout<<"shao chi rou!";
		        else if(member[m].weight == 27) cout<<"wan mei!";
		        else if(member[m].weight < 27) cout<<"duo chi rou!";
		    }
		
		    if(member[m].gender == 0){
		        //身高评价,体重评价
		        if(member[m].height > 129) cout<<"ni li hai! ";
		        else if(member[m].height == 129) cout<<"wan mei! ";
		        else if(member[m].height < 129) cout<<"duo chi yu! ";
		
		        if(member[m].weight > 25) cout<<"shao chi rou!";
		        else if(member[m].weight == 25) cout<<"wan mei!";
		        else if(member[m].weight < 25) cout<<"duo chi rou!";
		    }
		}
	}
    return 0;
}
```

