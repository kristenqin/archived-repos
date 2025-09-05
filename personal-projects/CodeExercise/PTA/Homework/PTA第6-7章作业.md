# PTA第6-7章作业

## 单选题

知识点:

1. 字符串初始化

2. 数组初始化

   ==<img src="C:\Users\lenovo\AppData\Roaming\Typora\typora-user-images\image-20211106112137263.png" alt="image-20211106112137263" style="zoom: 50%;" />==

3. 数组长度

4. 条件编译

   

## 函数题

```c++
//连接字符串
//编写函数fun，其功能是：把p2所指的字符串连接到p1所指的字符串的后面。//由范例可知是非指针指向
void fun(char p1[],char p2[]){
    char whole[10000];
    //字符串--->循环条件
	int i = 0;
    while(!('\n')){
        whole[i] = p1[i];
        i++;
    }
    int m = 0;
    while(!('\n')){
        whole[i+1] = p2[m] ;
        m++;
    }
    int n = 0;
   	while(!('\n')){
       cout<<whole[n];
       n++;
   }
}
```

```c++
//错误分析
//没有看主函数, 主函数要求一个数组的元素直接加到另一个数组末尾,而不是创建一个新数组  
void fun(char p1[],char p2[]){
    char whole[10000];
    //字符串--->循环条件
	int i = 0;
    while(p1[i] != '\n'){
        i++;
    }
    int m = 0;
    while(!('\n')){
        p1[i] = p2[m] ;
        m++;
    }
}
//修改
#include<iostream>
#include<cstdio>
using namespace std;

void fun(char p1[], char p2[]);
 int main(){    
     char s1[80], s2[40] ;
     scanf("%s%s", s1, s2) ;    
     fun(s1, s2) ;
     printf("%s", s1);
     return 0;
}
void fun(char p1[],char p2[]){
    //字符串--->循环条件
	int i = 0;
    while(p1[i] != '\0'){
        i++;
    }
    int m = 0;
    while(p2[m] != '\0'){
        p1[i] = p2[m] ;
        m++;
    }
    //是否需要在最后加上一个换行符
    p1[i+m] = '\0';
}
```

```c++
//输出
first
second
firstsecondfirst
//输出说明只并没有执行成功函数
//修改输出函数根本不执行了
first
second
firstsecond
//第三次修改
//直接将空格分个的内容看成了字符串
first --
first--
```

![image-20211106161400494](C:\Users\lenovo\AppData\Roaming\Typora\typora-user-images\image-20211106161400494.png)

题目给的测试用例有问题, 只要不是好学校给到的题目, 自己在调试的时候警惕一下

## 编程题

### 第一题

```c++
//题目分析
//找出最大值及其下标
//第一个最大值

//输入
int number[10] = {0};
int n = 0;
int i = 0;
int max = 0;
//数据处理
for(i = 0;i < n;i++){
    cin>>number[i];//看看和getchar有什么区别
    if(number[i] > max){
        max = number[i];
        register = i;
    }
}
//输出
cout<<max<<" "<<register;
```

```c++
//代码部分
#include<iostream>
using namespace std;
int main(){
    int number[10] = {0,0,0,0,0,0,0,0,0,0};
    int n,i,max = 0;
    //数据处理
    cin>>n;
    for(i = 0;i < n;i++){
        cin>>number[i];//看看和getchar有什么区别
        if(number[i] > max){
            max = number[i];
            register = i;
        }
    }
    //输出
    cout<<max<<" "<<register;
    return 0;
}
//代码修正
//代码部分
#include<iostream>
using namespace std;
int main(){
    int number[10] = {0,0,0,0,0,0,0,0,0,0};
    int n,i,max = 0;
    int registern = 0;
    //数据处理
    cin>>n;
    for(i = 0;i < n;i++){
        cin>>number[i];//看看和getchar有什么区别
        if(number[i] == 0){
            max = number[i];
            registern = 0;
        } 
        if(number[i] > max){
            max = number[i];
            registern = i;
        }
    }
    //输出
    cout<<max<<" "<<registern;
    return 0;
}
//问题出现在数组的初始化上,之前写的一道题数组在初始化的时候只初始化了第一个元素,自己以为是在程序过程中会自动进行初始化
//可能是自己设置的max的初始值在输出2,0,0的临界情况的时候,并没有进入循环判断,输出的最大值和下标都是各自的初始值,意义不一样吧
```

![image-20211106162142106](C:\Users\lenovo\AppData\Roaming\Typora\typora-user-images\image-20211106162142106.png)

![image-20211106162411817](C:\Users\lenovo\AppData\Roaming\Typora\typora-user-images\image-20211106162411817.png)

![image-20211106162525311](C:\Users\lenovo\AppData\Roaming\Typora\typora-user-images\image-20211106162525311.png)

不能理解16从哪里出来的

![image-20211106162820080](C:\Users\lenovo\AppData\Roaming\Typora\typora-user-images\image-20211106162820080.png)

![image-20211106163010980](C:\Users\lenovo\AppData\Roaming\Typora\typora-user-images\image-20211106163010980.png)

这个应该对应的是最后的边界条件

### 第二题

```c++
//题目分析
//本题就要求你写个程序，通过统计一个人点赞的纪录，分析这个人的特性。
//数据N1000循环次数;K10左右闭 特性个数循环;K特性标签1-1000;
int CountF[1001];

int n,k,f,registern;
int max = 0;
cin>>n;
while(n--){
    cin>>k;
    for(int i = 0;i<k;i++){
        cin>>f;
        CountF[f]++;
    }
}
//输出
//统计所有被点赞的博文中最常出现的那个特性标签，在一行中输出它的编号和出现次数
//数字间隔1个空格。如果有并列，则输出编号最大的那个。
	//判断
	//使用变量max的话应该就不需要使用判断语句了
for(int i = 0;i < 1001){
    if(max <= CountF[i]) max = CountF[i];
    registern = i;
}

cout<<registern<" "<<max;
```

```c++
//代码部分
#include<iostream>
using namespace std;
int CountF[1001];
int main(){
    int n,k,f,registern;
    int max = 0;
    cin>>n;
    while(n--){
        cin>>k;
        for(int i = 0;i<k;i++){
            cin>>f;
            CountF[f]++;
        }
    }
    for(int i = 0;i < 1001;i++){
        if(max <= CountF[i]) max = CountF[i];
        registern = i;//会一直输rigister是循环完整个数组得到的i,不是在这个条件下得到的i 
    }

    cout<<registern<<" "<<max;
}
```

```c++
//输出
4
3 889 233 2
5 100 3 233 2 73
4 3 73 889 2
2 233 133
1000 3
```

![image-20211106170750408](C:\Users\lenovo\AppData\Roaming\Typora\typora-user-images\image-20211106170750408.png)

```c++
//代码修正
//代码部分
#include<iostream>
using namespace std;
int CountF[1001];

int main(){
    int n,k,f,registern;
    int max = 0;
    cin>>n;
    while(n--){
        cin>>k;
        for(int i = 0;i<k;i++){
            cin>>f;
            CountF[f]++;
        }
    }
    for(int i = 0;i < 1001;i++){
        if(max <= CountF[i]) {
        	max = CountF[i];
        	registern = i;
		}
    }
    cout<<registern<<" "<<max;
    return 0;
}
```

### 第三题

```c++
//题目分析
//求矩阵元素之和
#include<iostream>
using namespace std;
int number [6][6];
int main(){
    int m,n = 0;
    cin>>m>>n;
    int sum[m];
    for(int x = 0;x < m; x++){
        sum[x] = 0;
        for(int y = 0;y < n; y++){
            cin>>number[x][y];
            sum[x] += number[x][y];
        }
    }
    for(int z = 0;z < m;z++) cout<<sum[z]<<endl;
    return 0;
}
```

```c++
//输出结果
3 2
0
0
0
```

### 第四题

```c++
//题目分析
//单词首字母大写
	//输入一行字符，将每个单词的首字母改为大写后输出
	//“单词”是指连续不含空格的字符串
	//各单词之间用空格分隔
	//空格数可以是多个

//输入
	//输入的类型
	//字符
	getchar()
	//循环条件
	while(getchar() != '\n'){
        
    }

//数据处理
	//一个单词后面的空格结束对下一个单词进行处理
	//下一个单词的首字母
int m = 0;
char sentence[maxsize];
while((sentence[m] = getchar()) != '\n'))
    m++;


int n = 0
while(sentence[n] != '\0')){
    int pos = 0;
    int z = 0;
    while(sentence[])
    if(n == 0) putchar(c-'a' + 'A');
    else if(n > 1 && c != ' ') putchar(c);
    n++;
}
???//应该将数据全部输入之后再处理输出的
//输出

//感觉比较像矩阵
```

```c++
//字符类型
	1. 空格;
	2. 标点符号;
	3. 大小写;
//字串存储
//字符处理
	//处理单位:单词+空格
#include<iostream>
#define maxsize 10000
using namespace std;
char character[maxsize];
int main(){
    int i = 0;
    int countblank[maxsize];
    while((character[i] = getchar()) != '\n') i++;
    for(int m = 1;m < i;m++){
        if(sentence[m]-'a'<0) countblank[m]++;
    }
    for(int n = 1;n < i;n++){
        if(countblank[n] != 0) sentence[n+countblank[n]] - 'a' + 'A';
    }
    for(int z = 0;z < i;z++){
        cout<<sentence[z];
    }
    return 0;
}
//代码修改
#include<iostream>
#define maxsize 10000
using namespace std;
char character[maxsize];
int main(){
    int i = 0;
    int countblank[maxsize];
    //char list[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    //int y = 0;
    while((character[i] = getchar()) != '\n') i++;
    for(int m = 1;m < i;m++){
        if(character[m]-'a'<0) countblank[m]++;
    }
    /*for(int y = 0;y < 26;y++){
    	if((character[0]-list[y])> 0) character[0] = character[0]-'a' + 'A';
    	else if((character[0]-list[y]) <= 0) continue;
	}*/
    for(int n = 1;n < i;n++){
        if(countblank[n] != 0) character[n+countblank[n]] = character[n+countblank[n]]- 'a' + 'A';
    }
    for(int z = 0;z < i;z++){
        putchar(character[z]);
    }
    return 0;
}
```

![image-20211106211215295](C:\Users\lenovo\AppData\Roaming\Typora\typora-user-images\image-20211106211215295.png)



### 第五题

```c++
//题目分析
//说反话
//在一行内给出总长度不超过 80 的字符串
//字符串由若干单词和若干空格组成，其中单词是由英文字母（大小写有区分）组成的字符串
//单词之间用 1 个空格分开，输入保证句子末尾没有多余的空格
//数据分析
	//整体输入类型:字符串;组成类型:字符串
	//逆序输出
//要注意的点
	//字符串的'\0',单词之间的空格,句子末尾开头无空格
#include<iostream>
using namespace std;
char string[80][80];
int main(){
    int x,y;
    for(x,y = 0;string[x][y] !='\0';x++,y++) cin>>string[x][y];
    for(int m = x,n = y;string[m][n] != '\0';m--,n--){
    return 0;
}
//修正
#include<iostream>
using namespace std;
char stringinput[80][80];
int main(){
    int x,y = 0;
	while((stringinput[x][y] = getchar()) != '\n'){
		for(;stringinput[x][y] != '\0';y++);
		x++;
	}	
	for(x,y = 0;(stringinput[x][y] = getchar()) != '\n';x++,y++);
    for(int m = x,n = 0;m > 0,n < y;m--,n++) cout<<stringinput[m][n];
    return 0;
}
//还是不能理解对字符串的操作
```

![image-20211106214923582](C:\Users\lenovo\AppData\Roaming\Typora\typora-user-images\image-20211106214923582.png)

