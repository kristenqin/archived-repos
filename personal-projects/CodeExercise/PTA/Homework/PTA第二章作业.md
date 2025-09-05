# PTA第二章作业

## 基础题目

1. 指针和数组相关

   ![image-20211104072145170](C:\Users\lenovo\AppData\Roaming\Typora\typora-user-images\image-20211104072145170.png)

## 编程题

### 第一道

```c++
//计算和差积
#include<iostream>
#include<cstdio>
int main(){
    int x,y;
    std::cin>>x>>y;
    printf("x + y = %d\n",x+y);
    printf("x - y = %d\n",x - y);
    printf("x * y = %d\n",x*y);
    printf("x / y = %d",x/y);
    return 0;
}
//C++中如何使用cout进行占位符输出呢

//修正
//计算和差积
#include<iostream>
#include<cstdio>
int main(){
    int x,y;
    std::cin>>x>>y;
    printf("%d + %d = %d\n",x,y,x+y);
    printf("%d - %d = %d\n",x,y,x - y);
    printf("%d * %d = %d\n",x,y,x*y);
    printf("%d / %d = %d",x,y,x/y);
    return 0;
}
```

==<img src="C:\Users\lenovo\AppData\Roaming\Typora\typora-user-images\image-20211104073644956.png" alt="image-20211104073644956" style="zoom:33%;" />==

### 第二道

```c++
//打妖怪
#include<iostream>
using namespace std;
int main(){
    int v,h;
    cin>>v>>h;
    if(v%h == 0) cout<<v/h;
    else cout<<v/h + 1;
    return 0;
}
```

### 第三道

```c++
//过几天是星期几
#include<iostream>
using namespace std;
int main(){
    int w,n,d; 
    cin>>w>>n;
    d = w + n%7;
    cout<<d;
    return 0;
}
//拼题中是部分正确
```



