#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<semaphore.h>
#include<time.h>

pthread_t t1,t2,t3,t4,t5,t6;
pthread_mutex_t l1,l2;
int x,pcnt=0,teach=0,stud=0,staff=0,h;

void *tch()
{   
	pthread_mutex_lock(&l1);
	teach++;
	printf("\nTEACHER %d IS PLAYING\n",teach);
	pcnt++;
	pthread_mutex_unlock(&l1);
	pthread_exit(NULL);
}
void *stf()
{
	pthread_mutex_lock(&l2);
	staff++;
	pcnt++;
	printf("\nSTAFF %d is PLAYING\n",staff);
	pthread_mutex_unlock(&l2);
	pthread_exit(NULL);
}
void *stu()
{
	pthread_mutex_lock(&l1);
	pcnt++;
	stud++;
	printf("\nSTUDENT %d is PLAYING\n",stud);
	pthread_mutex_unlock(&l1);
    pthread_exit(NULL);
}
void *lgin()
{
	A:
	printf("\n1. For Staff\n2. Fosr Student\n3. For Teacher\n4.For Exit\nEnter Your choice :: ");
	scanf("%d",&x);
	switch(x){
	case 1:	
		printf("\nComputer Staff Login \n");
		printf("\nStaff logged in\n");
		pthread_create(&t3,NULL,stf,NULL);
		pthread_join(t3,NULL);
		break;
	case 2:
		printf("\nStudent  Login \n");
		printf("\nStudent logged in\n");pthread_create(&t4,NULL,stu,NULL);
		pthread_join(t4,NULL);
		break;
	case 3:
	    
		printf("\nComputer Teacher Login \n");
		printf("\nTecher logged in\n");
		pthread_create(&t5,NULL,tch,NULL);
		pthread_join(t5,NULL);
		break;
	case 4:
	       pthread_exit(NULL);
	default: printf("\nWrong Entry.\nTry again\n");
	         goto A;
	         }
	pthread_exit(NULL);}
void *lgout(){int j;
	if(teach>0){for(j=1;j<=teach;j++)printf("\n%d Teacher Logged Out\n",j);}
	if(stud>0){for(j=1;j<=staff;j++)printf("\n%d Staff Logged Out\n",j);}
	if(staff>0){for(j=1;j<=stud;j++)printf("\n%d Student Logged Out\n",j);}
}
void main()
{
	printf("\nEnter number of login :: \n");
	int i;
	scanf("%d",&h);system("cls");
	for(i=0;i<h;i++)
	{system("cls");
		pthread_create(&t1,NULL,lgin,NULL);
		pthread_join(t1,NULL);
		printf("TOTAL NO. OF USERS %d",pcnt);sleep(1);
	}
	pthread_create(&t6,NULL,lgout,NULL);
	pthread_join(t6,NULL);
	}
