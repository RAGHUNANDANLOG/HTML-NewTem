#include<stdio.h>
#include<conio.h>
#include<dos.h>
struct bill
{
	char bamo[20],add[10],adm[10],ady[10],pid[15],pnam[15],bdate[15],Hbid[50],Hpid[50],Hpnam[50],Hbdate[50],Hbamo[50],bid[15];
};
void add_Bill(char id[50], char name[50],char amt[50])
{
	struct bill case7;
	struct date d;
	char sim,a[15]={'B'},ch,z[20]={'0'};
	int count=1;
	FILE *b1,*col;
	clrscr();
	puts(name);
	strcpy(case7.Hbid,"B_ID");
	strcpy(case7.Hpid,"P_ID");
	strcpy(case7.Hpnam,"P_Name");
	strcpy(case7.Hbdate,"B_Date");
	strcpy(case7.Hbamo,"B_Amount");
	b1=fopen("project//bill.txt","r");
	while(fscanf(b1,"%c",&ch) != EOF)
	{
		if(ch=='\n')
		{
			count++;
		}
	}
	fclose(b1);
	count+=100;
	fflush(stdin);
	itoa(count,case7.bid,10);
	strcat(a,case7.bid);
	printf("Enter Details for making (BILL'S):\n");
	printf("\nPatient ID:");
	printf("%s",id);
	itoa(id,case7.pid,10);
	fflush(stdin);
	printf("\nPatient Name:");
	printf("%s",name);
	strcpy(case7.pnam,name);
	fflush(stdin);
	getdate(&d);
	itoa(d.da_day,case7.add,10);
	strcat(case7.add,"/");
	itoa(d.da_mon,case7.adm,10);
	strcat(z,case7.adm);
	strcat(z,"/");
	itoa(d.da_year,case7.ady,10);
	strcpy(case7.bdate,case7.add);
	strcat(case7.bdate,z);
	strcat(case7.bdate,case7.ady);
	strcpy(case7.bamo,amt);
	if(strcmp(case7.bamo,"Outdoor")==0)
	{
		printf("\nEnter Bill Amount:");
		gets(case7.bamo);

	}
	col=fopen("project//bill.txt","r");
	fseek(col,0,SEEK_END);
	if(ftell(col)<0)
	{
		fclose(col);
		b1=fopen("project//bill.txt","w");
		fprintf(b1,"%s\t%s\t%s\t\t%s\t\t%s",case7.Hbid,case7.Hpid,case7.Hpnam,case7.Hbdate,case7.Hbamo);
		fclose(b1);
	}
	else
	{
		fclose(col);
	}
	b1=fopen("project//bill.txt","a");
	fprintf(b1,"\n%s\t%s%s\t%s\t%s",a,id,name,case7.bdate,case7.bamo);
	fclose(b1);
}
void show_Billa()
{
	char sim;
	FILE *b2;
	clrscr();
	printf("\n\t\t\tThe Record Is--->>\n\t\t\t___________________\n");
	b2=fopen("project//bill.txt","r");
	while(fscanf(b2,"%c",&sim)!=EOF)
	{
		printf("%c",sim);
	}
	fclose(b2);
}
void show_Billp()
{
	struct bill case7;
	char del[20],ch[500];
	FILE *b2;
	clrscr();
	strcpy(case7.Hbid,"B_ID");
	strcpy(case7.Hpid,"P_ID");
	strcpy(case7.Hpnam,"P_Name");
	strcpy(case7.Hbdate,"B_Date");
	strcpy(case7.Hbamo,"B_Amount");
	printf("\nEnter B_ID to show that record.\n");
	fflush(stdin);
	scanf("%s",del);
	printf("\n\t\t\tThe Record Is--->>\n\t\t\t___________________\n");
	printf("%s\t%s\t%s\t\t%s\t\t%s\n",case7.Hbid,case7.Hpid,case7.Hpnam,case7.Hbdate,case7.Hbamo);
	b2=fopen("project//bill.txt","r");
	while(fscanf(b2,"%s",ch)!=EOF)
	{
		if(strcmp(ch,del)==0)
		{
			fgets(ch,500,b2);
			printf("%s %s",del,ch);
			break;
		}
	}
	fclose(b2);
}



