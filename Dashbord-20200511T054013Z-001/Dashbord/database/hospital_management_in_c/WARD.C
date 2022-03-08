#include<stdio.h>
#include<conio.h>
#include"BED.c"
struct ward
{
	long int nobeds;
	char wnam[25],Hwid[25],wid[15],Hwnam[25],Hnobeds[25];
};
void show_ward1();
void add_ward()
{
	struct ward case4;
	FILE *w1,*col;
	long int perdaych,i;
	strcpy(case4.Hwid,"W_ID");
	strcpy(case4.Hwnam,"W_Name");
	strcpy(case4.Hnobeds,"No.of_Beds");
	fflush(stdin);
	show_ward1();
	printf("\nEnter Details for Ward record:\nWard ID:");
	gets(case4.wid);
	fflush(stdin);
	printf("\nW_Name:");
	gets(case4.wnam);
	printf("\nNo.of_Beds:");
	scanf("%ld",&case4.nobeds);
	printf("\nPer Day Charges of one bed\n");
	scanf("%ld",&perdaych);
	col=fopen("project//ward.txt","r");
	fseek (col,0,SEEK_END);
	if(ftell(col)<0)
	{
		fclose(col);
		w1=fopen("project//ward.txt","w");
		fprintf(w1,"%s\t%s\t\t%s",case4.Hwid,case4.Hwnam,case4.Hnobeds);
		fclose(w1);
	}
	else
	{
		fclose(col);
	}
	w1=fopen("project//ward.txt","a");
	fprintf(w1,"\n%s\t%s\t\t%ld",case4.wid,case4.wnam,case4.nobeds);
	fclose(w1);
	for(i=1;i<=case4.nobeds;i++)
	{
		add_beds(perdaych,case4.wid);
	}
}
void show_ward1()
{
	struct ward case4;
	char poa,sim,del[20],ch[500];
	FILE *w2;
	clrscr();
	strcpy(case4.Hwid,"W_ID");
	strcpy(case4.Hwnam,"W_Name");
	strcpy(case4.Hnobeds,"No.of_Beds");
	printf("\n\tAll Record Is--->>\n\t___________________\n");
	w2=fopen("project//ward.txt","r");
	while(fscanf(w2,"%c",&sim)!=EOF)
	{
		printf("%c",sim);
	}
	fclose(w2);
}
void show_wardp()
{
	struct ward case4;
	char sim,del[20],ch[500];
	FILE *w3;
	clrscr();
	strcpy(case4.Hwid,"W_ID");
	strcpy(case4.Hwnam,"W_Name");
	strcpy(case4.Hnobeds,"No.of_Beds");
	printf("\nEnter W_ID to show that record.\n");
	fflush(stdin);
	scanf("%s",del);
	printf("\n\tThe Record Is--->>\n\t___________________\n");
	printf("%s\t%s\t\t%s\n",case4.Hwid,case4.Hwnam,case4.Hnobeds);
	w3=fopen("project//ward.txt","r");
	while(fscanf(w3,"%s",ch)!=EOF)
	{
		if(strcmp(ch,del)==0)
		{
			fgets(ch,500,w3);
			printf("%s %s",del,ch);
			break;
		}
	}
	fclose(w3);
}