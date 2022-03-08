#include<stdio.h>
#include<conio.h>
struct bed{
	long int b_id,pd_charg;
	char b_avail[5],w_id[15],Hbid[20],Hwid[20],Hbav[20],Hpdcharg[20];
};
void add_beds(int perdaych,char ar[15])
{
	FILE *b1,*col;
	int count=0;
	char ch;
	struct bed case1;
	clrscr();
	strcpy(case1.Hbid,"B_ID");
	strcpy(case1.Hwid,"W_ID");
	strcpy(case1.Hbav,"B_AVAIL");
	strcpy(case1.Hpdcharg,"PD_CHARGE");
	strcpy(case1.w_id,ar);
	fflush(stdin);
	strcpy(case1.b_avail,"Yes");
	case1.pd_charg=perdaych;
	b1=fopen("project//bed.txt","r");
	while(fscanf(b1,"%c",&ch)!=EOF)
	{
		if(ch=='\n')
		{
			count++;
		}
	}
	fclose(b1);
	count+=1000;
	case1.b_id=count;
	col=fopen("project//bed.txt","r");
	fseek(col,0,SEEK_END);
	if(ftell(col)<0)
	{
		fclose(col);
		b1=fopen("project//bed.txt","w");
		fprintf(b1,"%s\t%s\t%s\t\t%s\n",case1.Hbid,case1.Hwid,case1.Hbav,case1.Hpdcharg);
		fclose(b1);
	}
	else
	{
		fclose(col);
	}
	b1=fopen("project//bed.txt","a");
	fprintf(b1,"\n%ld\t%s\t%s\t\t%ld",case1.b_id,case1.w_id,case1.b_avail,case1.pd_charg);
	fclose(b1);
}
void show_beds()
{
	char sim;
	FILE *b3;
	clrscr();
	b3=fopen("project//bed.txt","r");
	while(fscanf(b3,"%c",&sim)!=EOF)
	{
		printf("%c",sim);
	}
	fclose(b3);
}
void show_bedsp()
{
	struct bed case3;
	char del[20],ch[500];
	FILE *b3;
	clrscr();
	strcpy(case3.Hbid,"B_ID");
	strcpy(case3.Hwid,"W_ID");
	strcpy(case3.Hbav,"B_AVAIL");
	strcpy(case3.Hpdcharg,"PD_CHARGE");
	printf("Enter B_ID to show that a record :");
	fflush(stdin);
	scanf("%s",del);
	printf("%s\t%s\t%s\t\t%s\n",case3.Hbid,case3.Hwid,case3.Hbav,case3.Hpdcharg);
	b3=fopen("project//bed.txt","r");
	while(fscanf(b3,"%s",ch)!=EOF)
	{
		if(strcmp(ch,del)==0)
		{
			fgets(ch,500,b3);
			printf("%s%s",del,ch);
			break;
		}
	}
	fclose(b3);
}

