#include<stdio.h>
#include<conio.h>
long int days(long int,long int,long int,long int,long int,long int);
long int month(long int,long int);
long int mon[12]={31,28,31,30,31,30,31,31,30,31,30,31};
dmain(long int a1,long int b1,long int c1,long int a2,long int b2,long int c2)
{
	long int count1=0;
	clrscr();
	if(c2>=c1)
	{
		count1 = days(c1,c2,b1,b2,a1,a2);
	}
	else
	{
		count1 = days(c2,c1,b2,b1,a2,a1);
	}
	getch();
	return count1;
}
long int days(long int y1,long int y2,long int m1,long int m2,long int d1,long int d2)
{
	long int count=0,i;
	for(i=y1;i<y2;i++)
	{
		if(i%4==0)
		{
			count+=366;
		}
		else
		{
			count+=365;
		}
	}
	count-=month(m1,y1);
	count-=d1;
	count+=month(m2,y2);
	count+=d2;
	if(count<0)
	{
		count=count*-1;
	}
	if(count==0)
	{
		count=1;
	}
	printf("The no. of days b/w the 2 dates = %d days",count);
	return count;
}
long int month(long int a,long int yy)
{
	long int x=0,c;
	for(c=0;c<a-1;c++)
	{
		if(c==1)
		{
			if(yy%4==0)
			{
				x+=29;
			}
			else
			{
				x+=28;
			}
		}
		else
		{
			x+=mon[c];
		}
	}
	return(x);
}