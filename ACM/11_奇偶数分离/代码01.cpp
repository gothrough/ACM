#include "stdio.h"
int main()
{
    int n;//表示用户要输入的数据组数
    scanf("%d",&n);
    int a;//用户要输入的偶数
    while(n)
    {
        scanf("%d",&a);
        for(int i=1;i<=a;i++)
            if(i%2==1)
                printf("%d ",i);//从小到大输出奇数
        printf("\n");

        for(int i=1;i<=a;i++)
            if(i%2==0)
                printf("%d ",i);//从小到大输出偶数

        printf("\n\n");
        n--;//表示还要输入的偶数个数
    }
    return 0;
}