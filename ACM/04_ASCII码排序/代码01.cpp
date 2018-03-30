#include<stdio.h>
void sort(char a[][3],int n)//用于将字符数据每一行从小到大排序
{
	int i;
	char ch;
	for(i=0;i<n;i++)
	{
		if(a[i][0]>a[i][1])
		{
			ch=a[i][0];
			a[i][0]=a[i][1];
			a[i][1]=ch;
		}
		if(a[i][0]>a[i][2])
		{
			ch=a[i][0];
			a[i][0]=a[i][2];
			a[i][2]=ch;
		}
		if(a[i][1]>a[i][2])
		{
			ch=a[i][1];
			a[i][1]=a[i][2];
			a[i][2]=ch;
		}
	
	}
	
} 
int main()
{
	int i,n;
        scanf("%d",&n);
        getchar();
	char ch[n][3];//存储n组字符 
	for(i=0;i<n;i++)
	{
		scanf("%c%c%c",&ch[i][0],&ch[i][1],&ch[i][2]);//输入第i组字符
		getchar();
	}
	sort(ch,sizeof(ch)/sizeof(ch[0]));//sizeof(ch)/sizeof(ch[0])为二位数组的行数
	for(i=0;i<n;i++)
	printf("%c %c %c\n",ch[i][0],ch[i][1],ch[i][2]); 
	
	return 0;
} 
