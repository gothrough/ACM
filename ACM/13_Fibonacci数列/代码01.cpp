#include "stdio.h"
int Fibonacci(int i)//递归完成斐波那契数列
{
    int sum;
    if(i>2)
        sum=Fibonacci(i-1)+Fibonacci(i-2);
    else
        return 1;
}
int main()
{
    int n,i;//输入组数,i为对应Fibonacci数列第几项
    scanf("%d",&n);
    while(n)
    {
        scanf("%d",&i);
        getchar();
        if(i==1&&i==2)
            printf("1\n");
        else
            printf("%d\n",Fibonacci(i));
        n--;
    }
    return 0;
}