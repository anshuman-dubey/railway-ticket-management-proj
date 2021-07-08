#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
int seats=50;
struct passenger
{
	char name1[50],sex1[10],email1[50];
	int age1;
	long long int number1;
	int train_number1;
	int alloted_seat;
	struct passenger *next;
}*top=NULL;
void book()
{
	struct passenger *temp;
	char name[50],sex[10],email[50];
	int age;
	long int train_number; 
	long long int number;
	temp=(struct passenger*)malloc(sizeof(struct passenger));
	FILE *fw;
	fw=fopen("Information.txt","a");
	printf("\nPassenger Name:");
	scanf("%s",&name);
	printf("\nSex:");
	scanf("%s",&sex);
	printf("\nAge:");
	scanf("%d",&age);
	printf("\nEmail Id:");
	scanf("%s",&email);
	printf("\nContact Number:");
	scanf("%lld",&number);
	printf("\nTrain Number:");
	scanf("%ld",&train_number);
	strcpy(temp->name1,name);
	strcpy(temp->sex1,sex);
	temp->age1=age;
	strcpy(temp->email1,email);
	temp->number1=number;
	temp->train_number1=train_number;
	temp->alloted_seat=seats;
	/*temp->next=NULL;
	if(start==NULL)
	{
		start=temp;
	}
	else
	{
		struct passenger *q;
		q=start;
		while(q->next!=NULL)
		{
			q=q->next;
		}
		q->next=temp;
	}*/
	if(top==NULL)
	{
		temp->next=NULL;
	}
	else
	{
		temp->next=top;
	}
	top=temp;
	fprintf(fw,"Alloted Seat:%d\n",seats);
	fprintf(fw,"Name:%s\n",temp->name1);
	fprintf(fw,"Sex:%s\n",temp->sex1);
	fprintf(fw,"Age:%d\n",temp->age1);
	fprintf(fw,"Email:%s\n",temp->email1);
	fprintf(fw,"Contact Number:%lld\n",temp->number1);
	fprintf(fw,"Train Number:%ld\n",temp->train_number1);
	fclose(fw);
	printf("\n\n\t\t========================================");
	printf("\n\t\t\tTicket Booked Successfully");
	printf("\n\n\t\tAlloted Seat:%d",seats);
	printf("\n\n\t\t========================================");
	seats--;
	menu();
}
void display()
{
	struct passenger *q;
	if(top==NULL)
	{
		printf("\n\nNo Details To Show");
	}
	else
	{
		q=top;
		printf("\n\n\t\t========================================");
		printf("\nDetails:");
		while(q!=NULL)
		{
			printf("\n\nAlloted Seat:%d\nPassenger Name:%s\nSex:%s\nAge:%d\nEmail:%s\nContact Number:%lld\nTrain Number%ld",q->alloted_seat,q->name1,q->sex1,q->age1,q->email1,q->number1,q->train_number1);
			printf("\n\n\t\t========================================");
			q=q->next;
		}
	}
}
void info()
{
	FILE *fr;
	char c;
	fr=fopen("Information.txt","r");
	if(fr==NULL)
	{
		printf("Error In Opening File");
		menu();
	}
	else
	{
		c=fgetc(fr);
		printf("\n\n\n");
		printf("\n\n\t\t========================================");
		while(c!=EOF)
		{
			printf("%c",c);
			c=fgetc(fr);
		}
		
		fclose(fr);
	}
}
void cancel()
{
	struct passenger *q;
	q=top;
	printf("\n\n\t\t========================================");
	printf("\n\n\t\tCancelled Ticket:");
	printf("\n\nCancelled Seat:%d\nPassenger Name:%s\nSex:%s\nAge:%d\nEmail:%s\nContact Number:%lld\nTrain Number%ld\n\n",q->alloted_seat,q->name1,q->sex1,q->age1,q->email1,q->number1,q->train_number1);
	printf("\n\n\t\t========================================");
	top=top->next;
	free(q);
	FILE *fd;
	fd=fopen("CancelledTickets.txt","a");
	fprintf(fd,"Cancelled Seat:%d\n",seats);
	fprintf(fd,"Name:%s\n",q->name1);
	fprintf(fd,"Sex:%s\n",q->sex1);
	fprintf(fd,"Age:%d\n",q->age1);
	fprintf(fd,"Email:%s\n",q->email1);
	fprintf(fd,"Contact Number:%lld\n",q->number1);
	fprintf(fd,"Train Number:%ld\n",q->train_number1);
	fclose(fd);
	seats++;
	menu();
}
void cancelinfo()
{
	FILE *frc;
	char c;
	printf("\n\n\t\t========================================");
	frc=fopen("CancelledTickets.txt","r");
	if(frc==NULL)
	{
		printf("Error In Opening File");
		menu();
	}
	else
	{
		c=fgetc(frc);
		while(c!=EOF)
		{
			printf("%c",c);
			c=fgetc(frc);
		}
		fclose(frc);
	}
}
void search()
{
	int ticketno,c=0;
	struct passenger *q;
	printf("\n\n\t\t========================================");
	printf("\n\n\t\tEnter the ticket number to search");
	scanf("%d",&ticketno);
	q=top;
	while(q!=NULL)
	{
		if(q->alloted_seat==ticketno)
		{
			printf("\n\nTicket with ticket number %d is reserved",ticketno);
			printf("\n\n\n\nAlloted Seat:%d\nPassenger Name:%s\nSex:%s\nAge:%d\nEmail:%s\nContact Number:%lld\nTrain Number%ld",q->alloted_seat,q->name1,q->sex1,q->age1,q->email1,q->number1,q->train_number1);
			c=1;
			printf("\n\n\t\t========================================");
			menu();	
		}
		q=q->next;
	}
	if(c==0)
	{
		printf("\n\nThere is no reserved ticket with ticket number %d",ticketno);
		printf("\n\n\t\t========================================");
		menu();
	}
}
int menu()
{
char s1[50]={"TMS"},un[50],pw[50],s2[60]={"tms123"};
int i,a,b,chr,ch,y,n=3;
char sou[20]={"Nagpur"},des[20]={"Gondia"};
char source[20],destination[20],ans[5];
int checks,checkd,sel;	
while(1)
{		
printf("\n\n");
printf("\n\n\t\t========================================");
printf("\n\n1.Reserve Ticket\n ");
printf("2.Display\n ");
printf("3.Booked Tickets Information\n ");
printf("4.Cancel Ticket\n ");
printf("5.Cancelled Tickets Informatiom\n ");
printf("6.Search \n ");
printf("7.Exit\n ");
printf("Enter the Choice:");
scanf("%d",&ch);
switch(ch)
{
case 1:
	if(seats>0)
	{
	printf("\nEnter the Source:");
	scanf("%s",&source);
	printf("\nEnter the Destination:");
	scanf("%s",&destination);
	checks=strcmp(sou,source);
	checkd=strcmp(des,destination);
	if(checks==0 && checkd==0)
	{
		while(1)
		{
		printf("\n\nAvailable Trains between %s and %s are:\n",source,destination);
		printf("\n1.CSMT-HWH Express\n2.Karmabhoomi Express\n3.Samta Express\n4.Intercity Express\n5.Vidarbha Express");
		printf("\n6.Gondwana Express\n7.PBR Howrah Express\n8.Jnaneswari Express\n9.Samarsata Express\n10.Kaviguru Express");
		printf("\n11.ADI-Howrah Express\n12.HWH CSMT Express");
		printf("\n\nEnter The Prefered Choice");
		scanf("%d",&sel);
		int y;
		char an[10]={"YES"};
		switch(sel)
		{
			case 1:
				printf("\n\n\t\t========================================");
				printf("\n\nTrain Number: 12869\nTrain Type:Express\nDeparture Time: 01:40\nArrival Time: 03:21\nTravel Time:01:41");
				printf("\n\n\t\t========================================");
				printf("\n\nWant To Book Ticket?\nYES OR NO\n");
				scanf("%s",&ans);
				y=strcmp(ans,an);
				if(y==0)
				{
					book();
				}
				else
				{
					menu();
				}
				break;
			case 2:
				printf("\n\n\t\t========================================");
				printf("\n\nTrain Number: 22511\nTrain Type:Express\nDeparture Time: 01:40\nArrival Time: 03:25\nTravel Time:01:45");
				printf("\n\n\t\t========================================");
				printf("\n\nWant To Book Ticket?\nYES OR NO\n");
				scanf("%s",&ans);
				
				y=strcmp(ans,an);
				if(y==0)
				{
					book();
				}
				else
				{
					menu();
				}
				break;
			case 3:
				printf("\n\n\t\t========================================");
				printf("\n\nTrain Number: 12808\nTrain Type:Express\nDeparture Time: 02:00\nArrival Time: 03:55\nTravel Time:01:55");
				printf("\n\n\t\t========================================");
				printf("\n\nWant To Book Ticket?\nYES OR NO\n");
				scanf("%s",&ans);
				
				y=strcmp(ans,an);
				if(y==0)
				{
					book();
				}
				else
				{
					menu();
				}
				break;
			case 4:
				printf("\n\n\t\t========================================");
				printf("\n\nTrain Number: 12856\nTrain Type:Express\nDeparture Time: 06:30\nArrival Time: 08:28\nTravel Time:01:58");
				printf("\n\n\t\t========================================");
				printf("\n\nWant To Book Ticket?\nYES OR NO\n");
				scanf("%s",&ans);
				
				y=strcmp(ans,an);
				if(y==0)
				{
					book();
				}
				else
				{
					menu();
				}
				break;
			case 5:
				printf("\n\n\t\t========================================");
				printf("\n\nTrain Number: 12105\nTrain Type:Express\nDeparture Time: 09:10\nArrival Time: 11:15\nTravel Time:02:05");
				printf("\n\n\t\t========================================");
				printf("\n\nWant To Book Ticket?\nYES OR NO\n");
				scanf("%s",&ans);
				y=strcmp(ans,an);
				if(y==0)
				{
					book();
				}
				else
				{
					menu();
				}
				break;
			case 6:
				printf("\n\n\t\t========================================");
				printf("\n\nTrain Number: 12410\nTrain Type:Express\nDeparture Time: 09:35\nArrival Time: 11:27\nTravel Time:01:52");
				printf("\n\n\t\t========================================");
				printf("\n\nWant To Book Ticket?\nYES OR NO\n");
				scanf("%s",&ans);
				
				y=strcmp(ans,an);
				if(y==0)
				{
					book();
				}
				else
				{
					menu();
				}
				break;
			case 7:
				printf("\n\n\t\t========================================");
				printf("\n\nTrain Number: 12905\nTrain Type:Express\nDeparture Time: 09:50\nArrival Time: 11:40\nTravel Time:01:50");
				printf("\n\n\t\t========================================");
				printf("\n\nWant To Book Ticket?\nYES OR NO\n");
				scanf("%s",&ans);
				
				y=strcmp(ans,an);
				if(y==0)
				{
					book();
				}
				else
				{
					menu();
				}
				break;
			case 8:
				printf("\n\n\t\t========================================");
				printf("\n\nTrain Number: 12101\nTrain Type:Express\nDeparture Time: 10:00\nArrival Time: 11:36\nTravel Time:01:36");
				printf("\n\n\t\t========================================");
				printf("\n\nWant To Book Ticket?\nYES OR NO\n");
				scanf("%s",&ans);
				
				y=strcmp(ans,an);
				if(y==0)
				{
					book();
				}
				else
				{
					menu();
				}
				break;
			case 9:
				printf("\n\n\t\t========================================");
				printf("\n\nTrain Number: 12151\nTrain Type:Express\nDeparture Time: 10:55\nArrival Time: 12:45\nTravel Time:01:50");
				printf("\n\n\t\t========================================");
				printf("\n\nWant To Book Ticket?\nYES OR NO\n");
				scanf("%s",&ans);
				
				y=strcmp(ans,an);
				if(y==0)
				{
					book();
				}
				else
				{
					menu();
				}
				break;
			case 10:
				printf("\n\n\t\t========================================");
				printf("\n\nTrain Number: 12949\nTrain Type:Express\nDeparture Time: 10:55\nArrival Time: 12:45\nTravel Time:01:50");
				printf("\n\n\t\t========================================");
				printf("\n\nWant To Book Ticket?\nYES OR NO\n");
				scanf("%s",&ans);
				
				y=strcmp(ans,an);
				if(y==0)
				{
					book();
				}
				else
				{
					menu();
				}
				break;
			case 11:
				printf("\n\n\t\t========================================");
				printf("\n\nTrain Number: 12833\nTrain Type:Express\nDeparture Time: 17:55\nArrival Time: 19:56\nTravel Time:02:01");
				printf("\n\n\t\t========================================");
				printf("\n\nWant To Book Ticket?\nYES OR NO\n");
				scanf("%s",&ans);
				
				y=strcmp(ans,an);
				if(y==0)
				{
					book();
				}
				else
				{
					menu();
				}
				break;
			case 12:
				printf("\n\n\t\t========================================");
				printf("\n\nTrain Number: 12859\nTrain Type:Express\nDeparture Time: 19:00\nArrival Time: 20:46\nTravel Time:01:46");
				printf("\n\n\t\t========================================");
				printf("\n\nWant To Book Ticket?\nYES OR NO\n");
				scanf("%s",&ans);
				
				y=strcmp(ans,an);
				if(y==0)
				{
					book();
				}
				else
				{
					menu();
				}
				break;
			default:
				printf("\n\n\t\t========================================");
				printf("\n\nEnter Valid Choice");
				printf("\n\n\t\t========================================");
				break;
			}
		}
	}
	else
	{
		printf("\n\n\t\t========================================");
		printf("\n\nThere are no trains available between %s and %s",source,destination);
		printf("\n\n\t\t========================================");
	}
	}
	else
	{
		printf("\n\n\t\t========================================");
		printf("\n\nSorry..!! All tickets are reserverd");
		printf("\n\n\t\t========================================");
	}
	break;
case 2:
		display();
		break;
case 3:
		info();
		break;
case 4:
		cancel();
		break;
case 5:
		cancelinfo();
		break;
case 6:
		search();
		break;
case 7:
		exit(1);
		break;		
/*default:printf("Sorry");
}*/
}
}
}
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