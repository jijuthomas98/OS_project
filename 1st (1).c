#include<stdio.h>
#include<pthread.h>
int z;
void *func1()
{
int x,i,j;
printf("enter the no.");
scanf("%d",&x);
printf("the prime numbers less than %d are :\t",x);
for(i=2;i<=x;i++)
{	z=-1;
	for(j=2;j<i;j++)
	{
		if(i%j==0)
			z++;
	}
	if(z==-1)
	{
		printf("%d\t",i);	
	}
}
}
main()
{
pthread_t t1,t2;
pthread_create(&t1,NULL,func1,NULL);
pthread_join(t1,NULL);

}
