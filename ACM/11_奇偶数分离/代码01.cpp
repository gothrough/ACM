#include "stdio.h"
int main()
{
    int n;//��ʾ�û�Ҫ�������������
    scanf("%d",&n);
    int a;//�û�Ҫ�����ż��
    while(n)
    {
        scanf("%d",&a);
        for(int i=1;i<=a;i++)
            if(i%2==1)
                printf("%d ",i);//��С�����������
        printf("\n");

        for(int i=1;i<=a;i++)
            if(i%2==0)
                printf("%d ",i);//��С�������ż��

        printf("\n\n");
        n--;//��ʾ��Ҫ�����ż������
    }
    return 0;
}