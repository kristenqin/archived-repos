# PTAB A+B和C

```c++
//题目分析
//输入
//T个测试用例, 空格分隔,数字是大数
cin>>T;
long int A[10],B[10],C[10];
int temp = T;
int i = 0;
while(T--){
    cin>>A[i]>>B[i]>>C[i];
    i++;
}
//数据处理
	//判断A+B>C
for(int m = 0;m < temp;m++){
    if(A[m]+B[m] > C[m]){
        cout<<"Case"<<" #"<<m<<": "<<"false";
    }
    else cout<<"Case"<<" #"<<m<<": "<<"true";
}
//输出
	//Case #标号: false/true


```

```c++
//代码部分
#include<iostream>
using namespace std;
int main(){
    int T,i = 0;
    long int A[10],B[10],C[10];
    cin>>T;
    int temp = T;
    while(T--){
        cin>>A[i]>>B[i]>>C[i];
        i++;
    }
    //数据处理
    //判断A+B>C
    for(int m = 0;m < temp;m++){
        if(A[m]+B[m] > C[m]){
            cout<<"Case"<<" #"<<m+1<<": "<<"true"<<endl;
        }
        else cout<<"Case"<<" #"<<m+1<<": "<<"false"<<endl;
    }
    return 0;
}
```



