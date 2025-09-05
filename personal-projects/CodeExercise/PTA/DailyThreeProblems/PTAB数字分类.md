# PTAB数字分类

```c++
//题目分析
//偶数和,交错和,个数,平均数,最大数
//空格间隔
//行末无多余空格
#include<iostream>
using namespace std;
int main(){
    int N;
    int A[6] = {0,0,0,0,0,0};
    int number;
    int count = 0;
    double average;
    cin>>N;
    while(N--){
        cin>>number;
        if(number%10==0) A[1] += number;
        else if(number%5 == 1){
            A[2] += number;
            number = (-1)*number;
        }
        else if(number%5 == 2) A[3]++;
        else if(number%5 == 3){
            count++;
            (double)A[4] += number;
        }
        else if(number%5 == 4){
            if(A[5] < number) A[5] = number;
        }
    }
    average = A[4] / count;
    cout<<A[1]<<" "<<A[2]<<" "<<A[3]<<" "<<average<<" "<<A[5];
    return 0;
}
```

```c++
//代码修正
//题目分析
//偶数和,交错和,个数,平均数,最大数
//空格间隔
//行末无多余空格
#include<iostream>
#include<iomanip>
using namespace std;
int main(){
    int N;
    int A[6] = {0,0,0,0,0,0};
    int number;
    int count,i = 0;
    double average;
    cin>>N;
    while(N--){
        cin>>number;
        if(number%10==0) A[1] += number;
        else if(number%5 == 1){
        	if(i % 2 == 0) number = 1 * number;
            else number = (-1)*number;
            A[2] += number;
            i++;
        }
        else if(number%5 == 2) A[3]++;
        else if(number%5 == 3){
            count++;
			A[4] += number;
        }
        else if(number%5 == 4){
            if(A[5] < number) A[5] = number;
        }
    }
    //其实在最初构建一个结构体的话,最后输出会方便很多
    average = (double)A[4] / count;
    if(A[1] == 0) (char)A[1] = 'N';
    if(A[2] == 0) (char)A[2] = 'N';
    if(A[3] == 0) (char)A[3] = 'N';
    if(A[5] == 0) (char)A[5] = 'N';
    if(average == 0) (char) average = 'N';
    //输出部分感觉没自己想得那么合理,不是很对劲
    //强制类型转换感觉太粗暴了, 一直觉得这种习惯不好,虽然之前看书说的都是对指针进行强制类型转换不好
    //printf("%d %d %d %.1lf %d",A[1],A[2],A[3],average,A[5]);
    cout<<A[1]<<" "<<A[2]<<" "<<A[3]<<" "<<setprecision(1)<<average<<" "<<A[5];
    return 0;
}
```

![image-20211107162529751](D:\CPrograming\MyPic\image-20211107162529751.png)



`setprecision` 输出结果

![image-20211107163118911](D:\CPrograming\MyPic\image-20211107163118911.png)

我不理解啊淦那

==struct这部分没有写完==


```c++
#include<iostream>
using namespace std;
typedef struct DataType{
    int A1,A2,A3,A5;
    double A4;
}A[6];
//比较疑惑的地方是这个数组在创建的时候是如何被初始化的呢
int main(){
    int N;
    cin>>N;
    while(N--){
        cin>>number;
        if(number%10==0) A[1].A1 += number;
        else if(number%5 == 1){
            if(i % 2 == 0) number = 1 * number;
            else number = (-1)*number;
            A[2].A2 += number;
            i++;
        }
        else if(number%5 == 2) A[3].A3++;
        else if(number%5 == 3){
            count++;
            A[4].A4 += number;
        }
        else if(number%5 == 4){
            if(A[5].A5 < number) A[5].A5 = number;
        }
    }
    A[4].A4 /= count;
    for(int i = 0;i < 5;i++){
        if(A[i] == 0) cout<<N;
        else cout<<A[i];
    }
    return 0;
}
```

![image-20211107161643422](D:\CPrograming\MyPic\image-20211107161643422.png)

使用`struct`作为数据结构时的报错

==对于没有此类型的输出补充==

```c++
//代码修正
//题目分析
//偶数和,交错和,个数,平均数,最大数
//空格间隔
//行末无多余空格
#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    int N;
    int A[6] = {0,0,0,0,0,0};
    int number;
    int count,i = 0;
    double average;
    cin>>N;
    while(N--){
        cin>>number;
        if(number%10==0) A[1] += number;
        else if(number%5 == 1){
        	if(i % 2 == 0) number = 1 * number;
            else number = (-1)*number;
            A[2] += number;
            i++;
        }
        else if(number%5 == 2) A[3]++;
        else if(number%5 == 3){
            count++;
			A[4] += number;
        }
        else if(number%5 == 4){
            if(A[5] < number) A[5] = number;
        }
    }
    average = (double)A[4] / count;
    //没有化简的最简
    if(A[1] == 0) cout<<"N ";
    else cout<<A[1]<<' ';
    
    if(A[2] == 0) cout<<"N ";
    else cout<<A[2]<<' ';
    
    if(A[3] == 0) cout<<"N ";
    else cout<<A[3]<<' ';
    
    if(count == 0) cout<<"N ";//注意和0比较的数字 想的时候还是要想深入一些
    else printf("%.1lf ",average);
    
    if(A[5] == 0) cout<<"N";
    else cout<<A[5];
        
    return 0;
}
```

![image-20211107164710568](D:\CPrograming\MyPic\image-20211107164710568.png)

为啥会输出nan呢, 好诡异啊

[答案](https://blog.csdn.net/qq_16334327/article/details/86526854) `nan not a number` 分母为0

