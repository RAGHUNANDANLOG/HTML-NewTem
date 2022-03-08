#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include"STAFF.c"
#include"MADATE.c"
#include"BILL.c"
struct admit
{
	long int docid;
	char wid[12],wana[50],add[10],adm[10],ady[10],pid[15],pna[20],adid[15],admdat[15],admdatd[15],Hbed[10],disda[15],Hadid[25],Hpid[25],Hdocid[25],Hadmdat[25],Hdisdat[25];
};
void admit_person()
{
	int count=1,flag=0,pos,dup;
	char a[15]={'A'},ch,bh[500],del[20],b[10],z[20]={'0'},z2[20]={'0'};
	struct date d;
	struct admit case6;
	FILE *ad1,*col;
	clrscr();
	strcpy(case6.Hadid,"A_ID");
	show_patient();
	strcpy(case6.Hpid,"P_ID");
	strcpy(case6.Hdocid,"Do_ID");
	strcpy(case6.Hbed,"B_ID");
	strcpy(case6.Hadmdat,"Admission_Date");
	strcpy(case6.Hdisdat,"Discharge_Date");
	ad1=fopen("project//admit.txt","r");
	while(fscanf(ad1,"%c",&ch)!=EOF)
	{
		if(ch=='\n')
		{
			count++;
		}
	}
	fclose(ad1);
	count+=100;
	fflush(stdin);
	printf("\nEnter Details for Admit record:\n");
	itoa(count,case6.adid,10);
	strcat(a,case6.adid);
	show_patient();
	printf("\nPatient ID:");
	scanf("%s",case6.pid);
	show_doc();
	printf("\nDoctor ID:");
	scanf("%ld",&case6.docid);
	fflush(stdin);
	getdate(&d);
	itoa(d.da_day,case6.add,10);
	strcat(case6.add,"/");
	itoa(d.da_mon,case6.adm,10);
	strcat(z,case6.adm);
	strcat(z,"/");
	itoa(d.da_year,case6.ady,10);
	strcpy(case6.admdat,case6.add);
	strcat(case6.admdat,z);
	strcat(case6.admdat,case6.ady);
	itoa(d.da_day,case6.add,10);
	strcat(case6.add," ");
	itoa(d.da_mon,case6.adm,10);
	strcat(z2,case6.adm);
	strcat(z2," ");
	itoa(d.da_year,case6.ady,10);
	strcpy(case6.admdatd,case6.add);
	strcat(case6.admdatd,z2);
	strcat(case6.admdatd,case6.ady);
	strcpy(case6.disda,"----------");
	ltoa(case6.docid,del,10);
	ad1=fopen("project//staff.txt","r");
	while(fscanf(ad1,"%s",bh)!=EOF)
	{
		if(strcmp(del,bh)==0)
		{
			fscanf(ad1,"%s",bh);
			fscanf(ad1,"%s",bh);
			fscanf(ad1,"%s",bh);
			fscanf(ad1,"%s",bh);
			fscanf(ad1,"%s",bh);
			fscanf(ad1,"%s",bh);
			fscanf(ad1,"%s",bh);
			fscanf(ad1,"%s",bh);
			fscanf(ad1,"%s",bh);
			strcpy(case6.wana,bh);
			break;
		}
	}
	fclose(ad1);
	printf("\n2Wname==== %s\n",case6.wana);
	ad1=fopen("project//ward.txt","r");
	while(fscanf(ad1,"%s",bh)!=EOF)
	{
		if(strcmp(case6.wana,bh)==0)
		{
			dup=ftell(ad1);
			fseek(ad1,-(dup-pos)-6,SEEK_CUR);
			fscanf(ad1,"%s",bh);
			strcpy(case6.wid,bh);
			break;
		}
		pos=ftell(ad1);
	}
	fclose(ad1);
	clrscr();
	printf("B_ID\tW_ID\tB_AVAIL\t  PD_CHARGE\n");
	ad1=fopen("project//bed.txt","r");
	while(fscanf(ad1,"%s",bh)!=EOF)
	{
		if(strcmp(case6.wid,bh)==0)
		{
			dup=ftell(ad1);
			fseek(ad1,-(dup-pos)-6,SEEK_CUR);
			fscanf(ad1,"%s",bh);
			printf("%s\t",bh);
			fscanf(ad1,"%s",bh);
			printf("%s\t",bh);
			fscanf(ad1,"%s",bh);
			printf("%s\t",bh);
			fscanf(ad1,"%s",bh);
			printf("  %s\t\n",bh);
		}
		pos=ftell(ad1);
	}
	fclose(ad1);
	getch();
	fflush(stdin);
	printf("\nEnter Bed_ID you to avail that bed\n");
	gets(del);
	ad1=fopen("project//bed.txt","rb+");
	strcpy(b,"Yes");
	while(fscanf(ad1,"%s",bh)!=EOF)
	{
		if(strcmp(del,bh)==0)
		{
			flag=1;
		}
		if(strcmp(bh,b)==0 && flag==1)
		{
			fseek(ad1,-3,SEEK_CUR);
			fprintf(ad1,"%s"," No");
			fseek(ad1,0,SEEK_CUR);
			break;
		}
	}
	fclose(ad1);
	col = fopen("project//admit.txt","r");
	fseek(col,0,SEEK_END);
	if(ftell(col)<0)
	{
		fclose(col);
		ad1=fopen("project//admit.txt","w");
		fprintf(ad1,"%s\t%s\t%s\t%s\t\t%s\t\t%s",case6.Hadid,case6.Hpid,case6.Hdocid,case6.Hbed,case6.Hadmdat,case6.Hdisdat);
		fclose(ad1);
	}
	else
	{
		fclose(col);
	}
	ad1=fopen("project//admit.txt","a");
	fprintf(ad1,"\n%s\t%s\t%ld\t%s\t\t%s\t\t%s",a,case6.pid,case6.docid,del,case6.admdat,case6.disda);
	fclose(ad1);
	col = fopen("project//admitd.txt","r");
	fseek(col,0,SEEK_END);
	if(ftell(col)<0)
	{
		fclose(col);
		ad1=fopen("project//admitd.txt","w");
		fprintf(ad1,"%s\t%s\t%s\t\t%s\t\t%s",case6.Hadid,case6.Hpid,case6.Hdocid,case6.Hadmdat,case6.Hdisdat);
		fclose(ad1);
	}
	else
	{
		fclose(col);
	}
	ad1=fopen("project//admitd.txt","a");
	fprintf(ad1,"\n%s\t%s\t%ld\t\t%s\t\t%s",a,case6.pid,case6.docid,case6.admdatd,case6.disda);
	fclose(ad1);
}
void show_admitrecA();
void disc_person()
{
	struct admit case6;
	struct date d;
	char sim[100],beid[15],ch[500],del[20],b[20],bh[500],Date[20],de[20],z[20]={'0'},z2[20]={'0'},lt[20];
	long int amt,flag=0,fla=0,d1,m1,y1,d2,m2,y2,madate;
	FILE *ad2,*col;
	clrscr();
	show_admitrecA();
	printf("\nEnter Admit ID to discharge the patient :\n");
	scanf("%s",del);
	show_beds();
	fflush(stdin);
	printf("\nEnter Bed_ID that we alotted .When you admited.\n");
	gets(de);
	ad2=fopen("project//bed.txt","rb+");
	strcpy(b,"No");
	while(fscanf(ad2,"%s",bh)!=EOF)
	{
		if(strcmp(de,bh)==0)
		{
			fla=1;
		}
		if(strcmp(bh,b)==0 && fla==1)
		{
			fseek(ad2,-3,SEEK_CUR);
			fprintf(ad2,"%s","Yes");
			fseek(ad2,0,SEEK_CUR);
			break;
		}
	}
	fclose(ad2);
	col=fopen("project//admit.txt","rb+");
	strcpy(b,"----------");
	getdate(&d);
	itoa(d.da_day,case6.add,10);
	strcat(case6.add,"/");
	itoa(d.da_mon,case6.adm,10);
	strcat(z,case6.adm);
	strcat(z,"/");
	itoa(d.da_year,case6.ady,10);
	strcpy(Date,case6.add);
	strcat(Date,z);
	strcat(Date,case6.ady);
	while(fscanf(col,"%s",ch)!=EOF)
	{
		if(strcmp(del,ch)==0)
		{
			flag=1;
		}
		if(strcmp(ch,b)==0 && flag==1)
		{
			fseek(col,-10,SEEK_CUR);
			fprintf(col,"%s",Date);
			fseek(col,0,SEEK_CUR);
			break;
		}
	}
	fclose(col);
	col=fopen("project//admitd.txt","rb+");
	strcpy(b,"----------");
	getdate(&d);
	itoa(d.da_day,case6.add,10);
	strcat(case6.add," ");
	itoa(d.da_mon,case6.adm,10);
	strcat(z2,case6.adm);
	strcat(z2," ");
	itoa(d.da_year,case6.ady,10);
	strcpy(Date,case6.add);
	strcat(Date,z2);
	strcat(Date,case6.ady);
	while(fscanf(col,"%s",ch)!=EOF)
	{
		if(strcmp(del,ch)==0)
		{
			flag=1;
		}
		if(strcmp(ch,b)==0 && flag==1)
		{
			fseek(col,-10,SEEK_CUR);
			fprintf(col,"%s",Date);
			fseek(col,0,SEEK_CUR);
			break;
		}
	}
	fclose(col);
	printf("\nPatient %s has been successfully DISCHARGED\n",del);
	getch();
	ad2=fopen("project//admit.txt","r");
	while(fscanf(ad2,"%s",ch)!=EOF)
	{
		if(strcmp(del,ch)==0)
		{
			fscanf(ad2,"%s",ch);
			break;
		}
	}
	fclose(ad2);
	strcpy(case6.pid,ch);
	ad2=fopen("project//patient.txt","r");
	while(fscanf(ad2,"%s",ch)!=EOF)
	{
		if(strcmp(case6.pid,ch)==0)
		{
			fscanf(ad2,"%s",ch);
			fscanf(ad2,"%s",ch);
			fgets(ch,13,ad2);
			break;
		}
	}
	fclose(ad2);
	strcpy(case6.pna,ch);
	ad2 = fopen("project//admitd.txt","r");
	while(fscanf(ad2,"%s",ch) != EOF)
	{
		if(strcmp(ch,del)==0)
		{
			fscanf(ad2,"%s",ch);
			fscanf(ad2,"%s",ch);
			fgets(ch,14,ad2);
			sscanf(ch,"%ld%ld%ld",&d1,&m1,&y1);
			fgets(ch,14,ad2);
			sscanf(ch,"%ld%ld%ld",&d2,&m2,&y2);
			getch();
			break;
		}
	}
	fclose(ad2);
	madate=dmain(d1,m1,y1,d2,m2,y2);
	ad2 = fopen("project//admit.txt","r");
	while(fscanf(ad2,"%s",ch) != EOF)
	{
		if(strcmp(ch,del)==0)
		{
			fscanf(ad2,"%s",ch);
			fscanf(ad2,"%s",ch);
			fscanf(ad2,"%s",ch);
			strcpy(beid,ch);
			break;
		}
	}
	fclose(ad2);
	ad2 = fopen("project//bed.txt","r");
	while(fscanf(ad2,"%s",ch) != EOF)
	{
		if(strcmp(ch,beid)==0)
		{
			fscanf(ad2,"%s",ch);
			fscanf(ad2,"%s",ch);
			fscanf(ad2,"%s",ch);
			sscanf(ch,"%ld",&amt);
			break;
		}
	}
	fclose(ad2);
	clrscr();
	amt=amt*madate;
	getch();
	ltoa(amt,lt,10);
	printf("bill amount is %s",lt);
	getch();
	add_Bill(case6.pid,case6.pna,lt);
	show_Billa();
	getch();
}
void show_admitrecA()
{
	char sim;
	FILE *ad3;
	clrscr();
	ad3=fopen("project//admit.txt","r");
	while(fscanf(ad3,"%c",&sim)!=EOF)
	{
		printf("%c",sim);
	}
	fclose(ad3);
}
void show_admitrecP()
{
	struct admit case6;
	char ch[500],del[20];
	FILE *ad3;
	clrscr();
	strcpy(case6.Hadid,"A_ID");
	strcpy(case6.Hpid,"P_ID");
	strcpy(case6.Hdocid,"Do_ID");
	strcpy(case6.Hadmdat,"Admission_Date");
	strcpy(case6.Hdisdat,"Discharge_Date");
	printf("\nEnter A_id to SHOW that record.\n");
	fflush(stdin);
	scanf("%s",del);
	printf("\n\t\t\tThe Record Is--->>\n\t\t\t___________________\n");
	printf("%s    %s    %s    \t%s       \t%s\n",case6.Hadid,case6.Hpid,case6.Hdocid,case6.Hadmdat,case6.Hdisdat);
	ad3=fopen("project//admit.txt","r");
	while(fscanf(ad3,"%s",ch)!=EOF)
	{

		if(strcmp(ch,del)==0)
		{
			fgets(ch,500,ad3);
			printf("%s %s",del,ch);
			break;
		}
	}
	fclose(ad3);
}