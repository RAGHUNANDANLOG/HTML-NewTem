#include<stdio.h>
#include<conio.h>
struct patient{
	long int age,pho;
	char paid[15],nam[50],dis[50],addr[150],gen,type[10],Hid[10],Hage[10],Hpho[21],Hnam[10],Hdis[15],Haddr[15],Hgen[10],Htype[10];
};
void add_Bill();
void add_Patient()
{
	struct patient case1;
	char a[15]={'P'},ch;
	int count=0,i;
	FILE *p1,*col;
	clrscr();
	strcpy(case1.Hid,"P_ID");
	strcpy(case1.Hage,"P_Age");
	strcpy(case1.Hpho,"P_Phone.No.");
	strcpy(case1.Hnam,"P_Name");
	strcpy(case1.Hdis,"P_Dissease");
	strcpy(case1.Haddr,"P_Address");
	strcpy(case1.Hgen,"P_Gender");
	strcpy(case1.Htype,"P_Type");
	up:
	fflush(stdin);
	printf("Enter Details Of Patient record:\nChoose Patient TYPE\n>1 for Outdoor\n>2 for Indoor\nEnter your choice:");
	scanf("%d",&i);
		if(i==1)
		{
			strcpy(case1.type,"Outdoor");
		}
		else if(i==2)
		{
			strcpy(case1.type,"Indoor");
		}
		else
		{
			printf("\nInvalid 'INPUT'\n");
			getch();
			goto up;
		}
	p1=fopen("project//patient.txt","r");
	while(fscanf(p1,"%c",&ch) != EOF)
	{
		if(ch=='\n')
		{
			count++;
		}
	}
	fclose(p1);
	count+=100;
	fflush(stdin);
	itoa(count,case1.paid,10);
	strcat(a,case1.paid);
	printf("\nPatient AGE:");
	scanf("%ld",&case1.age);
	fflush(stdin);
	printf("\nPatient Gender (M or F):");
	scanf("%c",&case1.gen);
	fflush(stdin);
	printf("\nPatient NAME:");
	gets(case1.nam);
	printf("\nPatient DISEASES:");
	gets(case1.dis);
	printf("\nPatient PHONE NUMBER:");
	scanf("%ld",&case1.pho);
	fflush(stdin);
	printf("\nPatient ADDRESS:");
	gets(case1.addr);
	if(strcmp(case1.type,"Outdoor")==0)
	{

		add_Bill(a,case1.nam,case1.type);
	}
	getch();
	col = fopen("project//patient.txt","r");
	fseek(col,0,SEEK_END);
	if(ftell(col)<0)
	{
		fclose(col);
		p1=fopen("project//patient.txt","w");
		fprintf(p1,"%s\t%s\t%s\t%s\t\t%s\t%s\t%s\t%s",case1.Hid,case1.Htype,case1.Hage,case1.Hnam,case1.Hgen,case1.Hdis,case1.Hpho,case1.Haddr);
		fclose(p1);
	}
	else
	{
		fclose(col);
	}
	p1=fopen("project//patient.txt","a");
	fprintf(p1,"\n%s\t%s\t%ld\t%s\t%c\t\t%s\t%ld\t%s",a,case1.type,case1.age,case1.nam,case1.gen,case1.dis,case1.pho,case1.addr);
	fclose(p1);
}
void show_patient()
{
	struct patient case1;
	char ch[500],del[20],sim;
	FILE *p3;
	clrscr();
	printf("\t\tAll Record --->>>\n");
	p3=fopen("project//patient.txt","r");
	while(fscanf(p3,"%c",&sim)!=EOF)
	{
		printf("%c",sim);
	}
	fclose(p3);
}
void show_patientp()
{
	struct patient case1;
	char ch[500],del[20];
	FILE *p2;
	clrscr();
	strcpy(case1.Hid,"P_ID");
	strcpy(case1.Hage,"P_Age");
	strcpy(case1.Hpho,"P_Phone.No.");
	strcpy(case1.Hnam,"P_Name");
	strcpy(case1.Hdis,"P_Dissease");
	strcpy(case1.Haddr,"P_Address");
	strcpy(case1.Hgen,"P_Gender");
	strcpy(case1.Htype,"P_type");
	printf("\nEnter P_id to SHOW that Record :\n");
	fflush(stdin);
	scanf("%s",del);
	printf("\n\t\t\tThe Record Is--->>\n\t\t\t___________________\n");
	printf("%s    %s  %s   %s     \t%s	%s    \t%s\t%s\n",case1.Hid,case1.Htype,case1.Hage,case1.Hnam,case1.Hgen,case1.Hdis,case1.Hpho,case1.Haddr);
	p2=fopen("project//patient.txt","r");
	while(fscanf(p2,"%s",ch)!=EOF)
	{ 
		if(strcmp(ch,del)==0)
		{
			fgets(ch,500,p2);
			printf("%s %s",del,ch);
			break;
		}
	}
	fclose(p2);
}
void delete_pati()
{
	char ch[500],del[20],poa;
	FILE *p4,*temp;
	clrscr();
	printf("\nEnter capital 'P' to delete partticular record or \n Enter capital 'A' to delete entire record\n");
	fflush(stdin);
	scanf("%c",&poa);
	if(poa=='P')
	{
		printf("\nEnter P_id to delete that record.\n");
		fflush(stdin);
		scanf("%s",del);
		p4=fopen("project//patient.txt","r");
		temp=tmpfile();
		while(fscanf(p4,"%s",ch)!=EOF)
		{
			if(strcmp(ch,del)!=0)
			{
				fputs(ch,temp);
				fgets(ch,500,p4);
				fputs(ch,temp);
			}
			else
			{
				fgets(ch,500,p4);
			}
		}
		rewind(temp);
		fclose(p4);
		remove("project//patient.txt");
		p4=fopen("project//patient.txt","w");
		while(!feof(temp))
		{
			fgets(ch,500,temp);
			fputs(ch,p4);
		}
		fclose(p4);
	}
	if(poa=='A')
	{
		remove("project//patient.txt");
	}

}