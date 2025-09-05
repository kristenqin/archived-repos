# PTAB 锤子剪刀布

思路: 直接模拟解决

??? 这个是什么意思 前面的大数除法这个也是说的直接模拟解决

```c++
//题目分析
//交锋次数
//输入
int n;
first second;
B C J;
//输出 
first: win;ping;lose;
second:win;ping;lose;
//输出获胜次数最多首饰
//不唯一情况
	//按字母序BCJ最小输出
typedef struct member{
    char finger;
    int countfinger[3];
    int countwin[3];
    struct member* next;
} member,* figure;

figure first,second,temp1,temp2;
first = (figure)malloc(sizeof(member));
second = (figure)malloc(sizeof(member));
temp1 = first;
temp2 = second;
temp1->next = NULL;
temp2->next = NULL;

cin>>n;
for(int i = 0;i < n;i++){
    cin>>temp1->finger>>temp2->finger;
    if((temp1->finger = getchar()) == 'B' && (temp2->finger = getchar()) == 'B'){
        temp1->countwin[0]++;
        temp2->countwin[0]++;
    };
    if((temp1->finger = getchar()) == 'B' && (temp2->finger = getchar()) == 'C'){
        temp1->countwin[1]++;
        temp2->countwin[2]++;
        temp1->countfiger[0]++;
    };
    if((temp1->finger = getchar()) == 'B' && (temp2->finger = getchar()) == 'J'){
        temp1->countwin[2]++;
        temp2->countwin[1]++;
        temp2->countfinger[2]++;
    };    
    if((temp1->finger = getchar()) == 'C' && (temp2->finger = getchar()) == 'B'){
        temp1->countwin[2]++;
        temp2->countwin[1]++;
        temp2->countfinger[0]++;
    };
    if((temp1->finger = getchar()) == 'C' && (temp2->finger = getchar()) == 'C'){
        temp1->countwin[0]++;
        temp2->countfinger[0]++;
    };
    if((temp1->finger = getchar()) == 'C' && (temp2->finger = getchar()) == 'J'){
        temp1->countwin[1]++;
        temp2->countwin[3]++;
        temp1->countfinger[1]++;
    };
    if((temp1->finger = getchar()) == 'J' && (temp2->finger = getchar()) == 'B'){
        temp1->countwin[1]++;
        temp2->countwin[2]++;
        temp1->countfinger[2]++
    };
    if((temp1->finger = getchar()) == 'J' && (temp2->finger = getchar()) == 'C'){
        temp1->countwin[2]++;
        temp2->countwin[1]++;
        temp2->countfinger[1]++
    };
    if((temp1->finger = getchar()) == 'J' && (temp2->finger = getchar()) == 'J'){
        temp1->countwin[0]++;
        temp2->countwin[0]++;
    };
    //结构体构建忘了
    //结构体遍历感觉很困难
}
switch(finger){
    case 'B': tag = 1;
    case 'C': tag = 2;
    case 'J': tag = 3;
}
count[tag]++;
//如何使用双目运算符比较大小
count[1]>count[2]?count[1]:count[2];
count[1]>count[3]?count[1]:count[3];
```

```c++
//修正, 使用散装数据结构
#include<iostream>
using namespace std;
int main(){
    int CountResult1[4] = {0};
    int CountResult2[4] = {0};
    int CountFinger1[4] = {0};
    int CountFinger2[4] = {0};
    
    int N;
    char finger1,finger2 = '';
    int max1 = 0;
    int max2 = 0;
    char registerfinger = {'0','B','C','J'}
    char temp1;
    char temp2;
    
    cin>>N;
    while(N--){
        if((finger1 = getchar()) == 'B' && (finger2 = getchar()) == 'B'){//想把这些情况直接手动建立一个文档,一个一个写控制条件感觉好麻烦
        	CountResult1[2]++;
            CountResult2[2]++;
        }
        if((finger1 = getchar()) == 'B' && (finger2 = getchar()) == 'C'){//想把这些情况直接手动建立一个文档,一个一个写控制条件感觉好麻烦
        	CountResult1[1]++;
            CountResult2[3]++;
            CountFinger1[1]++;
        }
        if((finger1 = getchar()) == 'B' && (finger2 = getchar()) == 'J'){//想把这些情况直接手动建立一个文档,一个一个写控制条件感觉好麻烦
        	CountResult1[3]++;
            CountResult2[1]++;
            CountFinger2[3]++;
        }
        if((finger1 = getchar()) == 'C' && (finger2 = getchar()) == 'B'){//想把这些情况直接手动建立一个文档,一个一个写控制条件感觉好麻烦
        	CountResult1[3]++;
            CountResult2[1]++;
            CountFinger2[1]++;
        }
        if((finger1 = getchar()) == 'C' && (finger2 = getchar()) == 'C'){//想把这些情况直接手动建立一个文档,一个一个写控制条件感觉好麻烦
        	CountResult1[2]++;
            CountResult2[2]++;
        }
        if((finger1 = getchar()) == 'C' && (finger2 = getchar()) == 'J'){//想把这些情况直接手动建立一个文档,一个一个写控制条件感觉好麻烦
        	CountResult1[1]++;
            CountResult2[3]++;
            CountFinger1[2]++;
        }
        if((finger1 = getchar()) == 'J' && (finger2 = getchar()) == 'B'){//想把这些情况直接手动建立一个文档,一个一个写控制条件感觉好麻烦
        	CountResult1[1]++;
            CountResult2[3]++;
            CountFinger1[3]++;
        }
        if((finger1 = getchar()) == 'J' && (finger2 = getchar()) == 'C'){//想把这些情况直接手动建立一个文档,一个一个写控制条件感觉好麻烦
        	CountResult1[3]++;
            CountResult2[1]++;
            CountFinger2[2]++;
        }
        if((finger1 = getchar()) == 'J' && (finger2 = getchar()) == 'J'){//想把这些情况直接手动建立一个文档,一个一个写控制条件感觉好麻烦
        	CountResult1[2]++;
            CountResult2[2]++;
        }
    }
    for(int i = 1;i< 4;i++) cout<<CountResult1[i]<<" ";
    cout<<endl;
    for(int i = 1;i< 4;i++) cout<<CountResult2[i]<<" ";
    cout<<endl;
    
    for(int i = 1;i< 4;i++){
        if(max1 < CountFinger1[i]){
            max1 = CountFinger1[i];
            temp1 = registerfinger[i];
        }
    } 
    for(int i = 1;i< 4;i++){
        if(max2 < CountFinger2[i]){
            max2 = CountFinger2[i];
            temp2 = registerfinger[i];
        }
    }
    cout<<temp1<<" "<<temp2;
    
    return 0;
    
}
```

```c++
//修正, 使用散装数据结构
#include<iostream>
using namespace std;
int main(){
    int CountResult1[4] = {0};
    int CountResult2[4] = {0};
    int CountFinger1[4] = {0};
    int CountFinger2[4] = {0};
    
    int N;
    char finger1,finger2;
    int max1 = 0;
    int max2 = 0;
    char registerfinger[4] = {'0','B','C','J'};
    char temp1;
    char temp2;
    
    cin>>N;
    while(N--){
        cin>>finger1>>finger2;
        if(finger1 == 'B' && finger2 == 'B'){//想把这些情况直接手动建立一个文档,一个一个写控制条件感觉好麻烦
        	CountResult1[2]++;
            CountResult2[2]++;
        }
        if(finger1 == 'B' && finger2 == 'C'){//想把这些情况直接手动建立一个文档,一个一个写控制条件感觉好麻烦
        	CountResult1[1]++;
            CountResult2[3]++;
            CountFinger1[1]++;
        }
        if(finger1 == 'B' && finger2 == 'J'){//想把这些情况直接手动建立一个文档,一个一个写控制条件感觉好麻烦
        	CountResult1[3]++;
            CountResult2[1]++;
            CountFinger2[3]++;
        }
        if(finger1 == 'C' && finger2 == 'B'){//想把这些情况直接手动建立一个文档,一个一个写控制条件感觉好麻烦
        	CountResult1[3]++;
            CountResult2[1]++;
            CountFinger2[1]++;
        }
        if(finger1 == 'C' && finger2 == 'C'){//想把这些情况直接手动建立一个文档,一个一个写控制条件感觉好麻烦
        	CountResult1[2]++;
            CountResult2[2]++;
        }
        if(finger1 == 'C' && finger2 == 'J'){//想把这些情况直接手动建立一个文档,一个一个写控制条件感觉好麻烦
        	CountResult1[1]++;
            CountResult2[3]++;
            CountFinger1[2]++;
        }
        if(finger1 == 'J' && finger2 == 'B'){//想把这些情况直接手动建立一个文档,一个一个写控制条件感觉好麻烦
        	CountResult1[1]++;
            CountResult2[3]++;
            CountFinger1[3]++;
        }
        if(finger1 == 'J' && finger2 == 'C'){//想把这些情况直接手动建立一个文档,一个一个写控制条件感觉好麻烦
        	CountResult1[3]++;
            CountResult2[1]++;
            CountFinger2[2]++;
        }
        if(finger1 == 'J' && finger2 == 'J'){//想把这些情况直接手动建立一个文档,一个一个写控制条件感觉好麻烦
        	CountResult1[2]++;
            CountResult2[2]++;
        }
    }
    for(int i = 1;i< 4;i++) cout<<CountResult1[i]<<" ";
    cout<<endl;
    for(int i = 1;i< 4;i++) cout<<CountResult2[i]<<" ";
    cout<<endl;
    
    for(int i = 1;i< 4;i++){
        if(max1 < CountFinger1[i]){
            max1 = CountFinger1[i];
            temp1 = registerfinger[i];
        }
    } 
    for(int i = 1;i< 4;i++){
        if(max2 < CountFinger2[i]){
            max2 = CountFinger2[i];
            temp2 = registerfinger[i];
        }
    }
    cout<<temp1<<" "<<temp2;
    
    return 0;
    
}
```



## 问题分析

![image-20211110074238714](D:\CPrograming\MyPic\image-20211110074238714.png)

不能直接将`getchar()`作为循环条件, 会导致在每一个分支都进行一次输入判断. 

```c++
//思路没有看懂
#include <iostream>
#include <vector>
using namespace std;
#include <string>
#include <stdio.h>
#include <map>
bool Awin(char a, char b ){
   bool win = false;
    if((a == 'C'&& b == 'J') ||(a== 'J' && b=='B')||(a == 'B' && b == 'C' ) )
    {
        win = true;
    }
    return win;
}

int main()
{
    map<char,int> jia;
    map<char,int> yi;
    int n;
    cin>>n;
    int a1[3] ={0};
    int b1[3] = {0};
    getchar();

    char a,b;
    jia['B'] = 0;
    jia['C'] = 0;
    jia['J'] =0;
    yi['B'] = 0;
    yi['C'] = 0;
    yi['J'] =0;
    for(int i = 0 ; i< n; i++){
        cin>>a>>b;
        if(a == b){
            a1[2]++;
            b1[2]++;

        }
        else{
            if(Awin(a,b)){
                a1[0]++;
                b1[1]++;
                jia[a]++;
            }
            else{
                b1[0]++;
                a1[1]++;
                yi[b]++;
            }
        }
    }
    int jtim =0;
    int yitim =0;
    char jiaW,yiW;
    for(auto it = jia.begin() ; it != jia.end(); it++){
        if(it->second >jtim){
            jtim = it->second;
        }
    }
     for(auto it = yi.begin() ; it != yi.end(); it++){
        if(it->second >yitim){
            yitim = it->second;
        }
    }
    printf("%d %d %d\n",a1[0],a1[2],a1[1]);
    printf("%d %d %d\n",b1[0],b1[2],b1[1]);
    for(auto it = jia.begin() ; it != jia.end(); it++){
        if(it->second == jtim){
            cout<<it->first<<" ";
            break;
        }
    }
    for(auto it = yi.begin() ; it != yi.end(); it++){
        if(it->second ==yitim){
            cout<<it->first;
            break;
        }
    }
    return 0;
}

```

```c++
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int cnt[2][3];				//B、C、J
const char alpha[3]={'B','C','J'};	

int main()
{
	int n;
	scanf("%d",&n);
	string jia,yi;
	int yin=0,pingju=0,shu=0,len=n;
	
	while(len--)
	{
		cin>>jia>>yi;
        //判断的嵌套实现排列组合
		if(jia[0]=='C')
		{
			if(yi[0]=='C')
			{
				pingju++;
			}
			if(yi[0]=='J')
			{
				yin++;
				cnt[0][1]++;		//甲用锤子赢了 
			}
			if(yi[0]=='B')
			{
				shu++;
				cnt[1][0]++;		//乙用布赢了 
			}
		}
		else if(jia[0]=='J')
		{
			if(yi[0]=='C')
			{ 
				shu++;		
				cnt[1][1]++;
			}
			if(yi[0]=='J'){
				pingju++;
			}
			if(yi[0]=='B')
			{ 
				yin++;
				cnt[0][2]++;
			}
		}
		else
		{
			if(yi[0]=='C')
			{ 
				yin++; 
				cnt[0][0]++;
			}
			if(yi[0]=='J'){
				shu++;
				cnt[1][2]++;
			}
			if(yi[0]=='B')
			{ 
				pingju++;
			}
		}
	}
	int index1=-1,maxs=-1;
	for(int i=0;i<3;i++)
	{
		if(cnt[0][i]>maxs)
		{
			maxs=cnt[0][i];
			index1=i;
		}
	}
    //maxs初始化为-1作为临时判断不理解
	maxs=-1;
	int index2;
	for(int i=0;i<3;i++)
	{
		if(cnt[1][i]>maxs)
		{
			maxs=cnt[0][i];
			index2=i;
		}
	}
	
	
	printf("%d %d %d\n%d %d %d\n%c %c",yin,pingju,shu,shu,pingju,yin,alpha[index1],alpha[index2]);
	
	return 0;
}

```

```c++
//使用二维数组求解 没有看明白
#include <stdio.h>
#include <vector>
#include <map>
using namespace std;

int main()
{
    int n;
    char a, b;

    vector<vector<int> > rec(2, vector<int>(3, 0)); //初始化二维数组rec(2)(3)
    vector<map<char, int> > win(2);
    for (int i=0; i<2; i++){
        win[i]['C'] = 0;
        win[i]['B'] = 0;
        win[i]['J'] = 0;
    }

    scanf("%d", &n);
    getchar();
    for (int i=0; i<n; i++){
        scanf("%c %c", &a, &b);
        getchar();
        if (a==b){
            rec[0][1]++;
            rec[1][1]++;
        }
        else if ((a=='C'&&b=='B') || (a=='J'&&b=='C') || (a=='B'&&b=='J')){ //b胜a
            rec[0][2]++;
            rec[1][0]++;
            win[1][b]++;
        }
        else if ((b=='C'&&a=='B') || (b=='J'&&a=='C') || (b=='B'&&a=='J')){ //a胜b
            rec[0][0]++;
            rec[1][2]++;
            win[0][a]++;
        }
    }

    for (int i=0; i<2; i++){
        printf("%d", rec[i][0]);
        for (int j=1; j<3; j++){
            printf(" %d", rec[i][j]);
        }
        printf("\n");
    }

    char maxWin;
    for (int i=0; i<2; i++){
        int temp = win[i]['B'];
        maxWin = 'B';
        if (win[i]['C'] > temp){
            temp = win[i]['C'];
            maxWin = 'C';
        }
        if (win[i]['J'] > temp){
            maxWin = 'J';
        }
        printf("%c", maxWin);
        if (i==0) {
            printf(" ");
        }
    }

    printf("\n");
    return 0;
}
```

减少代码行数的初始化方法:

![image-20211110075919567](D:\CPrograming\MyPic\image-20211110075919567.png)

知识点:

二维数组

结构体

表

`scanf("%c %c", &jia[i], &yi[i]);` `%c`会将回车也当作输入内容, 如果待输入数据有`N`行, 循环到`N/2`行程序就会解释

```c++
//看不懂的代码
#include <iostream>
#include <algorithm>

int comp(char a, char b) {
    if(a == b) return 0;
    if( ('C' == a && 'J' == b) ||
        ('J' == a && 'B' == b) ||
        ('B' == a && 'C' == b)
        )
        return 1;
    return -1;
}

int mapping(char c) {
    if('B' == c) return 0;
    if('C' == c) return 1;
    return 2; // 'J'
}

char maxChar(int chArray[3]) {
    int maxV = *std::max_element(chArray, chArray + 3);
    if(chArray[0] == maxV)
        return 'B';
    if(chArray[1] == maxV)
        return 'C';
    return 'J';
}

int main() {
    int n;
    std::cin >> n;
    char a, b;
    int iCountWin = 0;
    int iCoundEven = 0;
    int cnt1[3] = {0, 0, 0};
    int cnt2[3] = {0, 0, 0};

    for(int i = 0; i < n; ++i) {
        std::cin >> a >> b;
        int ret = comp(a, b);
        if(1 == ret) {
            ++iCountWin;
            ++cnt1[mapping(a)];
        }
        else if(0 == ret)
            ++iCoundEven;
        else {
            ++cnt2[mapping(b)];
        }
    }
    std::cout << iCountWin << ' ' << iCoundEven << ' ' << n - iCoundEven - iCountWin << std::endl;
    std::cout << n - iCoundEven - iCountWin << ' ' << iCoundEven << ' ' << iCountWin << std::endl;
    std::cout << maxChar(cnt1) << ' ' << maxChar(cnt2) << std::endl;
    return 0;
}

```

```c++
//最简洁的代码
#include <iostream>
using namespace std;
int win[3] = {0};
//不同类型之间的数据是怎么对应起来的???    
char max3(int *a) {
    char r = 'B';
    if(a[1] > a[0]) {
        a[0] = a[1];
        r = 'C';
    }
    if(a[2] > a[0]) r = 'J';
    return r;
}
int main() {
    int n;
    char a[105],b[105];
    int awin[3] = {0};
    int bwin[3] = {0};
    cin >> n;    
    for(int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        //使用了中间自己想到的字符之间的顺序进行比较
        //双目运算符的使用
        int k = (a[i] - b[i]) * (a[i] - b[i]);
        if(k == 1)
            a[i] == 66 ? win[0]++,awin[0]++ : (win[1]++,bwin[0]++);
        else if(k == 49)
            a[i] == 67 ? win[0]++,awin[1]++ : (win[1]++,bwin[1]++);
        else if(k == 64)
            a[i] == 74 ? win[0]++,awin[2]++ : (win[1]++,bwin[2]++);
        else
            win[2]++;
    }
    cout << win[0] << " " << win[2] << " " << win[1] << endl;
    cout << win[1] << " " << win[2] << " " << win[0] << endl;
    cout << max3(awin) << " " << max3(bwin);
    return 0;
}
```

