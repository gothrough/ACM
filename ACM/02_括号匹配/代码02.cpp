#include "stdio.h"
#include "stdlib.h"//使用malloc函数时需要的头文件
#include "string.h"//使用strlen函数需要的头文件
typedef struct StackNode//栈结点
{
    char data;
    struct StackNode *next;
}StackNode,*LinkStackPtr;
typedef struct LinkStack//链栈
{
    LinkStackPtr top;//栈顶指针
    int count;//链栈中结点总数
}LinkStack;
void Push(LinkStack *s,char e)//将字符e入栈s中
{
    LinkStackPtr ptr=(LinkStackPtr)malloc(sizeof(StackNode));//ptr指向一个链栈结点
    ptr->data=e;
    ptr->next=s->top;//***刚分配的结点与top指向同一结点
    s->top=ptr;//top指向与刚分配的结点指向同一内存空间
    s->count++;//结点数加一
}
void GetTop(LinkStack *s,char *e)//取栈顶元素值赋给变量e
{
    *e=s->top->data;
}
void Pop(LinkStack *s)//出栈
{
    s->top=s->top->next;//top指向下一个结点
    s->count--;//count值减一
}
int main()
{
    int n，int i;//用户输入的字符串
    scanf("%d",& n);
    char str[n][100],elem;//str存储n组字符串，elem存储GetTop操作后的字符
    LinkStack *s[n];//大小为n的链栈类型数组
    for(int i=0;i<n;i++)//每个链栈的初始化
    {
        s[i]=(LinkStack*)malloc(sizeof(LinkStack));
        s[i]->count=0;
		
		/*
		下面两个语句之所以存在是因为当top指向栈底时
		栈底的data并未被赋值，所以应该赋一个初值来判断
		是否达到栈底，data的值任意
		*/
        s[i]->top=(LinkStackPtr)malloc(sizeof(StackNode));
        s[i]->top->data='2';

        scanf("%s",str[i]);//输入第i个字符串
    }
    for(int j=0;j<n;j++)
    {
        int len=strlen(str[j]);//计算第j个字符串长度
        for(i=0;i<len;i++)
        {
            if(str[j][i]=='('||str[j][i]=='[')//判断如果为左括号则直接入栈
                Push(s[j],str[j][i]);
            else//是右括号时
            {
                GetTop(s[j],&elem);//取得栈顶元素存储在elem中
                if((str[j][i]-elem==1||str[j][i]-elem==2)&&elem!='2')//当前字符为右括号且不为'2'时出栈
                    Pop(s[j]);
                else//当栈顶元素与字符串中当前元素无法凑成括号时
                {
                    printf("No\n");//打印No表示括号匹配失败
                    break;
                }
            }

        }
		/*
		count为0表示栈中无括号字符，i==len是为了避免(([])))这种情况
		两个条件都满足才表示匹配成功
		*/
        if(s[j]->count==0&&i==len)
            printf("Yes\n");
    }
    return 0;
}
