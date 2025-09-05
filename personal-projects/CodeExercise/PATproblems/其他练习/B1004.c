#include<stdio.h>
int main(){
    int n,i,j;
    int count1,count2;
    struct info{
        char name[10];
        char id[10];
        int grade;
    };
    typedef struct info Student;
    scanf("%d",&n);
    Student student[n];//变长数组的定义（malloc用法）

    scanf("%d",&n);
    int maxgrade = -1, mingrade = 101;

    for(i = 1;i<=n;i++){
        scanf("%s %s %d",
		student[i].name,
		student[i].id,
		&student[i].grade);
    }
    for(i = 1;i<=n;i++){
        if(student[i].grade<student[i+1].grade) {
            maxgrade = student[i+1].grade;
            count1 = i+1;

        }
        if(student[i].grade<student[i+1].grade) 
            mingrade = student[i].grade;
            count2 = i;
    }
    printf("%s %s",
    student[count1].name,
    student[count1].id);
    printf("%s %s",
    student[count2].name,
    student[count2].id);
    return 0;
}
//结构体用得太少
//程序框不能输出内容