#include <stdio.h>
#include "math.h"
int main()
{
    int n,i,sum=0,judge=1;//用户输入的数据组数,i为每组数据的个数
    scanf("%d",&n);
    getchar();
    while(n)
    {
        scanf("%d",&i);
        getchar();
        int a[i];
        for(int j=0;j<i;j++)
        {
            scanf("%d",&a[j]);
            //getchar();
        }
        for(int k=0;k<i;k++)
        {
            for(int j=2;j<=(int)sqrt(a[k]);j++)
            {
                if(a[k]%j==0)
                    judge=0;
            }
            if(judge==1&&a[k]>1)
                sum+=a[k];
            judge=1;
        }
        printf("%d\n",sum);
        sum=0;
        n--;

    }




    return 0;
}