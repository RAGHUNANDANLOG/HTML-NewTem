#include<stdio.h>
#include<conio.h>
struct staff{
	long int s_id,s_con,up;
	char s_name[50],s_add[100],s_gen[10],s_post[50],s_qua[50],s_dept[50],s_spe[50];
	char Hsid[20],Hsname[20],Hscon[20],Hsadd[20],Hsgen[20],Hspost[20],Hsqua[20],Hsdept[20],Hsspe[20];
};
void show_staff();
void add_staff()
{
	FILE *s1,*col;
	char a[15]={"@"};
	long int check;
	struct staff case2;
	strcpy(case2.Hsid,"S_ID");
	strcpy(case2.Hsname,"S_Name");
	strcpy(case2.Hscon,"S_Contact");
	strcpy(case2.Hsadd,"S_Address");
	strcpy(case2.Hsgen,"S_Gender");
	strcpy(case2.Hspost,"S_Post");
	strcpy(case2.Hsqua,"S_Quali.");
	strcpy(case2.Hsdept,"S_Depart.");
	strcpy(case2.Hsspe,"S_Special.");
	show_staff();
	printf("Enter Details of Staff Record :\n");
	printf("Staff ID :");
	scanf("%ld",&case2.s_id);
	fflush(stdin);
	printf("\nStaff Name :");
	gets(case2.s_name);
	printf("\nStaff Contact :");
	scanf("%ld",&case2.s_con);
	fflush(stdin);
	printf("\nStaff Address :");
	gets(case2.s_add);
	printf("\nStaff Gender :");
	gets(case2.s_gen);
	up:
	printf("\nStaff Post that are available in hospital are :- \nPRESS 1 for>Doctor\nPRESS 2 for>Compounder\nPRESS 3 for>Ward Boy\nPRESS 4 for>Nurse\nEnter Your Choice :");
	scanf("%ld",&check);
	if(check>0)
	{
		if(check==1)
		{
			strcpy(case2.s_post,"Doctor");
			strcat(a,case2.s_post);
			strcpy(case2.s_post,a);
			printf("\nStaff Specialist :");
			fflush(stdin);
			gets(case2.s_spe);
		}
		else if(check==2)
		{
			strcpy(case2.s_post,"Compounder");
			goto down;
		}
		else if(check==3)
		{
			strcpy(case2.s_post,"Ward Boy");
			goto down;
		}
		else if(check==4)
		{
			strcpy(case2.s_post,"Nurse");
			goto down;
		}
		else
		{
			printf("Invalid Option");
			getch();
			goto up;
		}

	}
	else if(check<0 || strcmp(case2.s_post,"Compounder")!=0 && strcmp(case2.s_post,"Ward boy")!=0 && strcmp(case2.s_post,"Nurse")!=0)
	{
		printf("Invalid Option");
		getch();
		goto up;
	}
	else
	{
		down:
		strcpy(case2.s_spe,"-----");
	}
	fflush(stdin);
	printf("\nStaff Qualification :");
	gets(case2.s_qua);
	printf("\nStaff Department :");
	gets(case2.s_dept);
	col=fopen("project//staff.txt","r");
	fseek(col,0,SEEK_END);
	if(ftell(col)<0)
	{
		fclose(col);
		s1=fopen("project//staff.txt","w");
		fprintf(s1,"%s\t%s       \t%s\t%s\t%s   %s\t%s %s\t%s\n",case2.Hsid,case2.Hsname,case2.Hscon,case2.Hsadd,case2.Hsgen,case2.Hspost,case2.Hsqua,case2.Hsdept,case2.Hsspe);
		fclose(s1);
	}
	else
	{
		fclose(col);
	}
	s1=fopen("project//staff.txt","a");
	fprintf(s1,"%ld\t%s\t%ld\t%s\t%s\t   %s\t%s\t %s\t\t%s\n",case2.s_id,case2.s_name,case2.s_con,case2.s_add,case2.s_gen,case2.s_post,case2.s_qua,case2.s_dept,case2.s_spe);
	fclose(s1);
}
void show_staff()
{
	struct staff case2;
	char sim,ch[500];
	FILE *s2;
	clrscr();
	strcpy(case2.Hsid,"S_ID");
	strcpy(case2.Hsname,"S_Name");
	strcpy(case2.Hscon,"S_Contact");
	strcpy(case2.Hsadd,"S_Address");
	strcpy(case2.Hsgen,"S_Gender");
	strcpy(case2.Hspost,"S_Post");
	strcpy(case2.Hsqua,"S_Quali.");
	strcpy(case2.Hsdept,"S_Depart.");
	strcpy(case2.Hsspe,"S_Special.");
	printf("\n\tAll Record Is--->>\n\t___________________\n");
	s2=fopen("project//staff.txt","r");
	while(fscanf(s2,"%c",&sim)!=EOF)
	{
		printf("%c",sim);
	}
	fclose(s2);
}
void part_staff()
{
	struct staff case2;
	char poa,sim,del[20],ch[500];
	FILE *s3;
	clrscr();
	strcpy(case2.Hsid,"S_ID");
	strcpy(case2.Hsname,"S_Name");
	strcpy(case2.Hscon,"S_Contact");
	strcpy(case2.Hsadd,"S_Address");
	strcpy(case2.Hsgen,"S_Gender");
	strcpy(case2.Hspost,"S_Post");
	strcpy(case2.Hsqua,"S_Quali.");
	strcpy(case2.Hsdept,"S_Depart.");
	strcpy(case2.Hsspe,"S_Special.");
	printf("Enter S_ID to show that a record :");
	fflush(stdin);
	scanf("%s",del);
	printf("%s\t%s\t\t%s\t%s\t%s   %s\t%s %s\t%s\n",case2.Hsid,case2.Hsname,case2.Hscon,case2.Hsadd,case2.Hsgen,case2.Hspost,case2.Hsqua,case2.Hsdept,case2.Hsspe);
	s3=fopen("project//staff.txt","r");
	while(fscanf(s3,"%s",ch)!=EOF)
	{
		if(strcmp(ch,del)==0)
		{
			fgets(ch,500,s3);
			printf("%s%s",del,ch);
			break;
		}
	}
	fclose(s3);
}
void show_doc()
{
	struct staff case2;
	int pos,curp,re;
	char ch;
	FILE *s4;
	clrscr();
	strcpy(case2.Hsid,"S_ID");
	strcpy(case2.Hsname,"S_Name");
	strcpy(case2.Hscon,"S_Contact");
	strcpy(case2.Hsadd,"S_Address");
	strcpy(case2.Hsgen,"S_Gender");
	strcpy(case2.Hspost,"S_Post");
	strcpy(case2.Hsqua,"S_Quali.");
	strcpy(case2.Hsdept,"S_Depart.");
	strcpy(case2.Hsspe,"S_Special.");
	printf("%s\t%s\t\t%s\t%s\t%s   %s\t%s %s\t%s\n",case2.Hsid,case2.Hsname,case2.Hscon,case2.Hsadd,case2.Hsgen,case2.Hspost,case2.Hsqua,case2.Hsdept,case2.Hsspe);
	s4=fopen("project//staff.txt","r");
	while(fscanf(s4,"%c",&ch)!=EOF)
	{
		if(ch=='\n')
		{
			pos=ftell(s4);
		}
		if(ch=='@')
		{
			curp=ftell(s4);
			re=curp-pos;
			fseek(s4,-(re),SEEK_CUR);
			while((ch=fgetc(s4))!='\n')
			{
				if(ch!='@')
				{
					printf("%c",ch);
				}
			}
			printf("\n");
			pos=ftell(s4);
		}
	fclose(s4);
}







