#include "stdio.h"
#include "stdlib.h"//ʹ��malloc����ʱ��Ҫ��ͷ�ļ�
#include "string.h"//ʹ��strlen������Ҫ��ͷ�ļ�
typedef struct StackNode//ջ���
{
    char data;
    struct StackNode *next;
}StackNode,*LinkStackPtr;
typedef struct LinkStack//��ջ
{
    LinkStackPtr top;//ջ��ָ��
    int count;//��ջ�н������
}LinkStack;
void Push(LinkStack *s,char e)//���ַ�e��ջs��
{
    LinkStackPtr ptr=(LinkStackPtr)malloc(sizeof(StackNode));//ptrָ��һ����ջ���
    ptr->data=e;
    ptr->next=s->top;//***�շ���Ľ����topָ��ͬһ���
    s->top=ptr;//topָ����շ���Ľ��ָ��ͬһ�ڴ�ռ�
    s->count++;//�������һ
}
void GetTop(LinkStack *s,char *e)//ȡջ��Ԫ��ֵ��������e
{
    *e=s->top->data;
}
void Pop(LinkStack *s)//��ջ
{
    s->top=s->top->next;//topָ����һ�����
    s->count--;//countֵ��һ
}
int main()
{
    int n��int i;//�û�������ַ���
    scanf("%d",& n);
    char str[n][100],elem;//str�洢n���ַ�����elem�洢GetTop��������ַ�
    LinkStack *s[n];//��СΪn����ջ��������
    for(int i=0;i<n;i++)//ÿ����ջ�ĳ�ʼ��
    {
        s[i]=(LinkStack*)malloc(sizeof(LinkStack));
        s[i]->count=0;
		
		/*
		�����������֮���Դ�������Ϊ��topָ��ջ��ʱ
		ջ�׵�data��δ����ֵ������Ӧ�ø�һ����ֵ���ж�
		�Ƿ�ﵽջ�ף�data��ֵ����
		*/
        s[i]->top=(LinkStackPtr)malloc(sizeof(StackNode));
        s[i]->top->data='2';

        scanf("%s",str[i]);//�����i���ַ���
    }
    for(int j=0;j<n;j++)
    {
        int len=strlen(str[j]);//�����j���ַ�������
        for(i=0;i<len;i++)
        {
            if(str[j][i]=='('||str[j][i]=='[')//�ж����Ϊ��������ֱ����ջ
                Push(s[j],str[j][i]);
            else//��������ʱ
            {
                GetTop(s[j],&elem);//ȡ��ջ��Ԫ�ش洢��elem��
                if((str[j][i]-elem==1||str[j][i]-elem==2)&&elem!='2')//��ǰ�ַ�Ϊ�������Ҳ�Ϊ'2'ʱ��ջ
                    Pop(s[j]);
                else//��ջ��Ԫ�����ַ����е�ǰԪ���޷��ճ�����ʱ
                {
                    printf("No\n");//��ӡNo��ʾ����ƥ��ʧ��
                    break;
                }
            }

        }
		/*
		countΪ0��ʾջ���������ַ���i==len��Ϊ�˱���(([])))�������
		��������������ű�ʾƥ��ɹ�
		*/
        if(s[j]->count==0&&i==len)
            printf("Yes\n");
    }
    return 0;
}
