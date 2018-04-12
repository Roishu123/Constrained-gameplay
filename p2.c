#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<semaphore.h>
#include<time.h>

void *log_in();
void *teacher();
void *student();
void *log_out();
void *computer_staff();

struct tm *t6;time_t t;
pthread_t thread_1,thread_2,thread_3,thread_4,thread_5,thread_6;
pthread_mutex_t l1,l2;
int x,pcnt=0,teach=0,stud=0,staff=0,h;
	
void main()
{	time(&t);
	printf("\nEnter number of login :: \n");
	int i;
	scanf("%d",&h);sleep(1);system("cls");
	for(i=0;i<h;i++)
		{	system("cls");
			pthread_create(&thread_1,NULL,log_in,NULL);
			pthread_join(thread_1,NULL);
			printf("Total number of GaMeRs %d",pcnt);sleep(1);
		}
	pthread_create(&thread_6,NULL,log_out,NULL);
	pthread_join(thread_6,NULL);
}
	
void *teacher()
	{
		pthread_mutex_lock(&l1);
		teach++;
		printf("\nTeacher number %d is rocking the Game\n",teach);
		pcnt++;
		pthread_mutex_unlock(&l1);
		sleep(10);// to look after 10 sec is time going to run out or not
    	if(t6->tm_hour>8&&t6->tm_hour<17)
			{
				pthread_mutex_lock(&l1);
				teach--;
				pcnt--;
				printf("\nTeacher number %d have been log out due to time out\n",teach);
				pthread_mutex_unlock(&l1);
			}
		pthread_exit(NULL);
	}
void *computer_staff()
	{
		pthread_mutex_lock(&l2);
		staff++;
		pcnt++;
		printf("\nComputer staff number %d is facing problem in battling others\n",staff);
		pthread_mutex_unlock(&l2);
		pthread_exit(NULL);
	}
void *student()
{
	pthread_mutex_lock(&l1);
	pcnt++;
	stud++;
	printf("\nStudent number %d is cheating in Game\n",stud);
	pthread_mutex_unlock(&l1);
	sleep(10);     // to look after 10 sec is time going to run out or not
    if(t6->tm_hour>6&&t6->tm_hour<22)
	{
		pthread_mutex_lock(&l2);
		stud--;
		pcnt--;
		printf("\nStudent number %d have been log out due to time out\n",studt);
	    pthread_mutex_unlock(&l2);
	}
	pthread_exit(NULL);
}
void *log_in()
{
	A:
	printf("\n1. For Staff\n2. Fosr Student\n3. For Teacher\n4.For Exit\nEnter Your choice :: ");
	scanf("%d",&x);

		switch(x){
			case 1:	
				printf("\nComputer Staff Loging In \n");sleep(1);
				printf("\nComputer staff logged In\n");
				pthread_create(&thread_3,NULL,computer_staff,NULL);
				pthread_join(thread_3,NULL);
				break;
		case 2:
	    		t6=localtime(&t);
	    		printf("\n%s\n",asctime(t6));
				if(t6->tm_hour>=22||t6->tm_hour<=6)
	    			{
						printf("\nStudent  Loging In \n");sleep(1);
						printf("\nStudent logged in\n");pthread_create(&thread_4,NULL,student,NULL);
						pthread_join(thread_4,NULL);
					}
				else 
					{printf("\nAccess denied due to time-constraint.\nPlease visit in alloted time-slot.\n");
					}		
				break;
	    case 3:
	    		t6=localtime(&t);
	    		printf("\n%s\n",asctime(t6));
	    		if(t6->tm_hour>=17||t6->tm_hour<=8)
	    			{
						printf("\nComputer Teacher Login \n");sleep(1);
						printf("\nTeacher logged in\n");
						pthread_create(&thread_5,NULL,teacher,NULL);
						pthread_join(thread_5,NULL);}
				else 
					{printf("\nAccess denied due to time-constraint.\nPlease visit in alloted time-slot.\n");
					}
				break;
	    case 4:
	    		pthread_exit(NULL);
	    default: 
				printf("\nWrong Entry.\nPlease try again\n");
	    		goto A;
	    }
	pthread_exit(NULL);
}
	
void *log_out()
	{	int j;
		if(teach>0){for(j=1;j<=teach;j++)printf("\nTeacher nunmber %d Logged Out\n",j);}
		if(stud>0){for(j=1;j<=staff;j++)printf("\nComputer staff number %d Logged Out\n",j);}
		if(staff>0){for(j=1;j<=stud;j++)printf("\nStudent number %d Logged Out\n",j);}
	}
