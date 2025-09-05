# PTAB德才论

##  题目分析和代码

- [ ] 题目状态: 没有过

```c++
//题目分析
//输入
//考生数, 及格线,优秀线
#include<iostream>
#define maxsize = 100000
int N,L,H;
int *T1[maxsize],*T2[maxsize],*T3[maxsize],*T4[maxsize];
int count1,count2,count3,count3;
typedef struct student{
    int D;
    int C;
    char id;
}student[maxsize];

int main(){
    cin>>N>>L>>H;

    for(int i = 0;i < N;i++){
        cin>>student[i].id>>student[i].D>>student[i].C;
        if(student[i].D >= H && student[i].C >= H){
            T1[count1] = &student[i];
            count1++;
        }
        else if(student[i].D >= H && student[i].C < H){
            T2[count2] = &student[i];
            count2++;
        }
        else if(student[i].D < H && student[i].C < H && D >= C){
            T3[count3] = &student[i];
            count3++;
        }
        else{
            T4[count4] = &student[i];
            count4++;
        }
    }

    //输出
    //输出T1
    Sort(T1[],count1);
    show(T1[],count1);
    //输出T2
    Sort(T2[],count2);
    show(T2[],count2);
    //输出T3
    Sort(T3[],count3);
    show(T3[],count3);
    //输出T4
    Sort(T4[],count4);
    show(T4[],count4);

    //设计排序函数输出
    //总分相同德分降序 两项完全相同 学号升序
    //冒泡排序, 但是忘了指针之间应该怎么嵌套的了
    void Sort(int*T[],int count){
        int *temp;
        temp = T[0];
        for(int i = 1;i < N;i++){//>0是为了指针数组中的0地址
            if(T[i]->D+T[i]->C > temp->D + temp->C){
                T[i] = temp;
                temp = T[i];
            }
            if(T[i]->D+T[i]->C == temp->D + temp->C && T[i]->D > temp->D){
                T[i] = temp;
                temp = T[i];
            }
            else if(T[i]->D+T[i]->C == temp->D + temp->C && T[i]->D == temp->D){
                if(T[i]->id < temp.id){
                    T[i] = temp;
                    temp = T[i];
                }
            }
        }
    }

    //输出函数
    void Show(int*T[],int count){
        for(int i = 0;i < count;i++) cout<<T[i].id<<" "<<T[i].D<<" "<<T[i].C;
    }
}
```

```c++
//代码修正
//题目分析
//输入
//考生数, 及格线,优秀线
#include<iostream>
#define maxsize 100000
using namespace std;
int N,L,H;
int count1,count2,count3,count4;
struct student{
    int D;
    int C;
    char id;
};
struct student student[maxsize],*T1[maxsize],*T2[maxsize],*T3[maxsize],*T4[maxsize];

void Sort(struct student*T[],int count){
    struct student *temp;
    temp = T[0];
    for(int i = 1;i < N;i++){//>0是为了指针数组中的0地址
        if(T[i]->D+T[i]->C > temp->D + temp->C){
            T[i] = temp;
            temp = T[i];
        }
        if(T[i]->D+T[i]->C == temp->D + temp->C && T[i]->D > temp->D){
            T[i] = temp;
            temp = T[i];
        }
        else if(T[i]->D+T[i]->C == temp->D + temp->C && T[i]->D == temp->D){
            if(T[i]->id < temp->id){
                T[i] = temp;
                temp = T[i];
            }
        }
    }
}

//输出函数
void Show(struct student *T[],int count){
    for(int i = 0;i < count;i++) cout<<T[i]->id<<" "<<T[i]->D<<" "<<T[i]->C;
}

int main(){
    cin>>N>>L>>H;

    for(int i = 0;i < N;i++){
        cin>>student[i].id>>student[i].D>>student[i].C;
        if(student[i].D >= H && student[i].C >= H){
            T1[count1] = &student[i];
            count1++;
        }
        else if(student[i].D >= H && student[i].C < H){
            T2[count2] = &student[i];
            count2++;
        }
        else if(student[i].D < H && student[i].C < H && student[i].D >= student[i].C){
            T3[count3] = &student[i];
            count3++;
        }
        else{
            T4[count4] = &student[i];
            count4++;
        }
    }

    //输出
    //输出T1
    Sort(T1,count1);
    Show(T1,count1);
    //输出T2
    Sort(T2,count2);
    Show(T2,count2);
    //输出T3
    Sort(T3,count3);
    Show(T3,count3);
    //输出T4
    Sort(T4,count4);
    Show(T4,count4);

    //设计排序函数输出
    //总分相同德分降序 两项完全相同 学号升序
    //冒泡排序, 但是忘了指针之间应该怎么嵌套的了
	return 0;
}
```



## 答案

```c++
链接：https://www.nowcoder.com/questionTerminal/97b6a49a85944650b2e3d0660b91c324
来源：牛客网

#include <cstdio>
#include <algorithm>
using namespace std;
struct student{
    int id;
    int de,cai,sum;
    int rank;
}s[100010];
//这里直接弄到结构体里面, 省去了变量初始化
 
bool cmp(student a,student b){
    if(a.rank!=b.rank) return a.rank<b.rank;
    else if(a.sum!=b.sum) return a.sum>b.sum;
    else if(a.de!=b.de) return a.de>b.de;
    else return a.id<b.id;
}
int main(int argc, char *argv[]){
    int n,l,h,num;
    scanf("%d%d%d",&n,&l,&h);
    num=n;
    for(int i=0;i<n;i++){
        scanf("%d%d%d",&s[i].id,&s[i].de,&s[i].cai);
        s[i].sum=s[i].de+s[i].cai;
        if(s[i].de<l ||s[i].cai<l){
            num--;
            s[i].rank=5;
        }//这个决定的是第一行的输出, 比我的代码中的count1-cout4少了多个变量
        else{
            if(s[i].de>=h && s[i].cai>=h) s[i].rank=1;
            else if(s[i].de>=h && s[i].cai<h) s[i].rank=2;
            else if(s[i].de>=s[i].cai) s[i].rank=3;
            else s[i].rank=4;
        }
    }
    sort(s,s+n,cmp);//cmp在这里作用是输出标准(设置bool变量很神奇)
    printf("%d\n",num);
    for(int i=0;i<num;i++)
        printf("%d %d %d\n",s[i].id,s[i].de,s[i].cai);
 
    return 0;
}
```

问题: 输出的时候不需要输出第五类等级人数啊, 这里为什么设置第五类等级呢

自己的问题:

忘记考虑对达到线的人数的计数输出

语法上的问题:

- 指针数组作为函数参数,不需要加[]
- 指针数组类型生命
- 结构体使用
- 变量初始化, 遇到需要将多个变量同时初始化为0的情况
- 需要了解C++的一些函数库就是一些排序算法
  - `sort` 