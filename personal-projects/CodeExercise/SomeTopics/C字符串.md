# C语言函数教程

参考：http://c.biancheng.net/c/ref/

## C语言strcpy()函数：字符串复制（拷贝）函数

```c++
#include<iostream>
#include<cstdio>
#include<cstring>
int main(){
    char dest[50] = {0};
    char src[50] = {"http://test.com"};
    strcpy(dest,src);
    puts(dest);
    return 0;
}
//在初始化的时候只初始化第一个元素
```

![image-20211107205647526](D:\CPrograming\MyPic\image-20211107205647526.png)

初始化结果

==不理解的点：==

`puts`

`dest[50]`的初始化



## C语言strlen()函数：求字符串的长度

最终统计的字符串长度不包括`\0`

`size_t strlen(const char* str);`

```c++
#include<cstdio>
#include<cstring>
int main(){
    char str[100] = {0};
    size_t len;
    gets(str);
    len = strlen(str);
    printf("%d",len);
    return 0;
}
```

==不理解的点：==

`gets`

`size_t`



## strlen函数与sizeof的区别

==不理解的点：==

`sizeof`在编译时计算缓冲区的长度, 不能用来返回动态分配的内容空间的大小

因为缓冲区已用已知字符串进行了初始化, 长度固定

`size_t`类型值是无符号值, 没有负数

```c++
size_t strlen(char const* str);
```

```c++
#include<cstring>
#include<iostream>
using namespace std;
int main(){
    char Array[50] = {0};
    cout<<strlen(gets(Array))<<endl;
    return 0;
}
```

```c++
//比较两个字符串大小
//建议直接比较, 而不是计算二者之差(关注一下比较时常用的一些表达式)
#include<cstring>
#include<iostream>
int main(){
    char Array1[50] = {0};
    char Array2[50] = {0};
    for(int i = 0;i < n;i++){
        get
    }
}
```

```c++
//字符串的嵌套
//  arrchar.c -- array of pointers, array of strings
#include <stdio.h>
#define SLEN 40
#define LIM 5
int main(void)
{
    const char *mytalents[LIM] = {
        "Adding numbers swiftly",
        "Multiplying accurately", "Stashing data",
        "Following instructions to the letter",
        "Understanding the C language"
    };
    char yourtalents[LIM][SLEN] = {
        "Walking in a straight line",
        "Sleeping", "Watching television",
        "Mailing letters", "Reading email"
    };
    int i;

    puts("Let's compare talents.");
    printf ("%-36s  %-25s\n", "My Talents", "Your Talents");
    for (i = 0; i < LIM; i++)
        printf("%-36s  %-25s\n", mytalents[i], yourtalents[i]);
    printf("\nsizeof mytalents: %zd, sizeof yourtalents: %zd\n",
           sizeof(mytalents), sizeof(yourtalents));

    return 0;
}
```

![image-20211107211705864](D:\CPrograming\MyPic\image-20211107211705864.png)

 