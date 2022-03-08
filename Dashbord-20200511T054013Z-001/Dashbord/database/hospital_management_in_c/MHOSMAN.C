#include<stdio.h>
#include<conio.h>
#include"PATIENT1.c"
#include"APPOINMENT.c"
#include"WARD.c"
#include"ADMIT.c"
#include"CG.c"
void main()
{
	int a,com;
	printMsg();
	system("cls");
	ma:
	textbackground(WHITE);
	textcolor(MAGENTA);
	clrscr();
	printf("\n\t\t-+=====iBirds Hospital Management System=====+-");
	printf("\n\t\t\t-------------------------- \n");
	printf("\n\t\t //!/ Enter 1 for detail of patient:");
	printf("\n\t\t____________________________________________\n");
	printf("\n\t\t //!/ Enter 2 for staff details:");
	printf("\n\t\t____________________________________________\n");
	printf("\n\t\t //!/ Enter 3 for Ward details:");
	printf("\n\t\t____________________________________________\n");
	printf("\n\t\t //!/ Enter 4 for details [No. of beds]:");
	printf("\n\t\t____________________________________________\n");
	printf("\n\t\t //!/ Enter 5 for Admit details:");
	printf("\n\t\t____________________________________________\n");
	printf("\n\t\t //!/ Enter 6 for Billing:");
	printf("\n\t\t____________________________________________\n");
	printf("\n\t\t //!/ Enter 7 for EXIT:");
	printf("\n\t\t____________________________________________\n");
	scanf("%d",&a);
	clrscr();
	switch(a)
	{
		case 1:p:
			textbackground(BLUE);
			textcolor(7);
			clrscr();
		       printf("\n\t\t\t|||! Patient Menu !|||");
		       printf("\n\t\t\t----------------------- \n");
		       printf("\n\n\n\t\tPress 1 for add Patient record\n");
		       printf("\n\t\tPress 2 for delete Patient record\n");
		       printf("\n\t\tPress 3 to show all record of Patient\n");
		       printf("\n\t\tPress 4 to show Particular record of Patient\n");
		       printf("\n\t\tPress 5 for go to MAIN MENU\n");
		       textcolor(RED+BLINK);
		       printf("\n\n\n\n\n\n\n\n\t\t");
		       cprintf("6 Exit.\n");
		       scanf("%d",&com);
		       if(com==1)
		       {
			      textbackground(MAGENTA);
			      textcolor(WHITE);
			      add_Patient();
			      clrscr();
			      goto p;
		       }
		       if(com==2)
		       {
			      textbackground(MAGENTA);
			      textcolor(WHITE);
			      delete_pati();
			      getch();
			      goto p;
		       }
		       if(com==3)
		       {
			      textbackground(MAGENTA);
			      textcolor(WHITE);
			      show_patient();
			      getch();
			      goto p;
		       }
		       if(com==4)
		       {
			      textbackground(MAGENTA);
			      textcolor(WHITE);
			      show_patientp();
			      getch();
			      goto p;
		       }
		       if(com==5)
		       {
			goto ma;
		       }
		       if(com==6)
		       {
				exit(0);
		       }
		       else
		       {
			      printf("\nInvalid 'INPUT'\n");
			      getch();
			      goto p;
		       }
		       break;
		case 2:staff:
		       textbackground(CYAN);
		       textcolor(BLUE);
		       clrscr();
		       printf("\n\t\t\t|||! Staff Menu !|||");
		       printf("\n\t\t\t-------------------- \n");
		       printf("\n\n\n\t\tPress 1 to show all record of staff\n");
		       printf("\n\t\tPress 2 for add staff record\n");
		       printf("\n\t\tPress 3 to show a particular record.\n");
		       printf("\n\t\tPress 4 for go to MAIN MENU\n");
		       textcolor(RED+BLINK);
		       printf("\n\n\n\n\n\n\n\n\n\t\t");
		       cprintf("\n 5 Exit.\n");
		       scanf("%d",&com);
		       if(com==1)
		       {
				textbackground(MAGENTA);
				textcolor(WHITE);
				show_staff();
				getch();
				goto staff;
		       }
		       if(com==2)
		       {
				textbackground(MAGENTA);
				textcolor(WHITE);
				add_staff();
				goto staff;
		       }
		       if(com==3)
		       {
				textbackground(MAGENTA);
				textcolor(WHITE);
				part_staff();
				getch();
				goto staff;
		       }
		       if(com == 4)
		       {
				goto ma;
		       }
		       if(com == 5)
		       {
				exit(0);
		       }
		       else
		       {
				printf("\nInvalid 'INPUT'\n");
				getch();
				goto staff;
		       }
		       break;
		case 3:wa:
		       textbackground(YELLOW);
		       textcolor(GREEN);
		       clrscr();
		       printf("\n\t\t\t|||! Ward Menu !|||");
		       printf("\n\t\t\t-------------------- \n");
		       printf("\n\n\n\t\tPress 1 to show all record of Ward\n");
		       printf("\n\t\tPress 2 for add Ward record\n");
		       printf("\n\t\tPress 3 to show a particular record.\n");
		       printf("\n\t\tPress 4 for go to MAIN MENU\n");
		       textcolor(RED+BLINK);
		       printf("\n\n\n\n\n\n\n\n\n\t\t");
		       cprintf("\n 5 Exit.\n");
		       scanf("%d",&com);
		       if(com==2)
		       {
				textbackground(MAGENTA);
				textcolor(WHITE);
				add_ward();
				goto wa;
		       }
		       if(com==1)
		       {
				textbackground(MAGENTA);
				textcolor(WHITE);
				show_ward1();
				getch();
				goto wa;
		       }
		       if(com==3)
		       {
				textbackground(MAGENTA);
				textcolor(WHITE);
				show_wardp();
				getch();
				goto wa;
		       }
		       if(com == 4)
		       {
				goto ma;
		       }
		       if(com == 5)
		       {
				exit(0);
		       }
		       else
		       {
				printf("\nInvalid 'INPUT'\n");
				getch();
				goto wa;
		       }
		       break;
		 case 4:bed:
		       textbackground(BLACK);
		       textcolor(3);
		       clrscr();
		       printf("\n\t\t\t|||!  Bed Menu !|||");
		       printf("\n\t\t\t-------------------- \n");
		       printf("\n\n\n\t\tPress 1 to show all record of Beds\n");
		       printf("\n\n\t\tPress 2 to show particular record of Beds\n");
		       printf("\n\n\t\tPress 3 for go to MAIN MENU\n");
		       textcolor(RED+BLINK);
		       printf("\n\n\n\n\n\n\n\n\n\n\t\t");
		       cprintf("\n 4 Exit.\n");
		       scanf("%d",&com);
		       if(com==1)
		       {
				textbackground(MAGENTA);
				textcolor(WHITE);
				show_beds();
				getch();
				goto bed;
		       }
		       if(com == 2)
		       {
				textbackground(MAGENTA);
				textcolor(WHITE);
				show_bedsp();
				getch();
				goto bed;
		       }
		       if(com == 3)
		       {
				goto ma;
		       }
		       if(com==4)
		       {
				exit(0);
		       }
		       else
		       {
				printf("\nInvalid 'INPUT'\n");
				getch();
				goto bed;
		       }
		case 5:adm:
		       textbackground(2);
		       textcolor(5);
		       clrscr();
		       printf("\n\t\t\t|||!  Admission Menu !|||");
		       printf("\n\t\t\t--------------------------- \n");
		       printf("\n\n\t\tPress 1 to show all record of Admission\n");
		       printf("\n\t\tPress 2 for Admit person\n");
		       printf("\n\t\tPress 3 for Discharge person \n");
		       printf("\n\t\tPress 4 to show a particular record of Admission\n");
		       printf("\n\t\tPress 5 for go to MAIN MENU\n");
		       textcolor(RED+BLINK);
		       printf("\n\n\n\n\n\n\n\n\t\t");
		       cprintf("\n 6 Exit.\n");
		       scanf("%d",&com);
		       if(com==1)
		       {
				textbackground(MAGENTA);
				textcolor(WHITE);
				show_admitrecA();
				getch();
				goto adm;
		       }
		       else if(com==2)
		       {
				textbackground(MAGENTA);
				textcolor(WHITE);
				admit_person();
				goto adm;
		       }
		       else if(com==3)
		       {
				textbackground(MAGENTA);
				textcolor(WHITE);
				disc_person();
				goto adm;
		       }
		       else if(com==4)
		       {
				textbackground(MAGENTA);
				textcolor(WHITE);
				show_admitrecP();
				getch();
				goto adm;
		       }
		       if(com == 5)
		       {
				goto ma;
		       }
		       else if(com==6)
		       {
				exit(0);
		       }
		       else
		       {
				printf("\nInvalid 'INPUT'\n");
				getch();
				goto adm;
		       }
		       break;
		case 6:bill:
		       textbackground(MAGENTA);
		       textcolor(WHITE);
		       clrscr();
		       printf("\n\t\t\t|||!  Billing Menu !|||");
		       printf("\n\t\t\t-------------------- \n");
		       printf("\n\n\t\tPress 1 to show all record of Billing\n");
		       printf("\n\t\tPress 2 to show a particular record of Billing\n");
		       printf("\n\t\tPress 3 for go to MAIN MENU\n");
		       textcolor(RED+BLINK);
		       printf("\n\n\n\n\n\n\n\n\t\t");
		       cprintf("\n 4 Exit.\n");
		       scanf("%d",&com);
		       if(com==1)
		       {
			       textbackground(MAGENTA);
			       textcolor(WHITE);
			       show_Billa();
			       getch();
			       goto bill;
		       }
		       if(com==2)
		       {
			       textbackground(MAGENTA);
			       textcolor(WHITE);
			       show_Billp();
			       getch();
			       goto bill;
		       }
		       if(com == 3)
		       {
				goto ma;
		       }
		       if(com==4)
		       {
				exit(0);
		       }
		       else
		       {
			       printf("Invalid Input");
			       getch();
			       goto bill;
		       }
		       break;
		       case 7:goto k;
	}
	k:
	printf("\nEXIT\n");
	getch();
}
