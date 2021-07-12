#include<rtms_functions.h>
int main()
{
char s1[50]={"TMS"},un[50],pw[50],s2[60]={"tms123"};
int i,a,b,chr,ch,y,n=3;
char sou[20]={"Nagpur"},des[20]={"Gondia"};
char source[20],destination[20],ans[5];
int checks,checkd,sel;
printf("\n===========================================WELCOME===================================================\n ");
while(n>=1)
{
printf("\n\t\t\tEnter User Name: ");
scanf("%s",&un);
printf("\n\t\t\tEnter Password:");
scanf("%s",&pw);
a=strcmp(s1,un);
b=strcmp(s2,pw);
if (a==0 && b==0)
{
	printf("\n\n\t\t========================================");
printf("\n\n\t\t\tLOGIN SUCCESSFUL..!!!\n");
printf("\n\n\t\t========================================");
menu();
break;
}
else
{
n--;	
printf("\nUserName Or Password Is Incorrect\n\n");
printf("You Have %d Chances To Login\n",n);
}
}
if(n==0)
{
	exit(1);
}
getch();
}