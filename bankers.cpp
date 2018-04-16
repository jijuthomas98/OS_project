#include<stdio.h>
#include<conio.h>
int main() {
	int p;//for taking the number of process
	int r;//for taking the number of resources
	int i,j;//iteration variables
	int in;//variable to take input from user
	int ch;//switch case variable
	int t=0;//for resources adding purpose
	int k=0;//for checking the number of resources
	int c1=0,c2=0;//while loop variable
	int c;//to start the again the program
	printf("ENTER THE NUMBER OF PROCESS :");
	scanf("%d",&p); //Entering No. of Processes
	printf("\nPROCESS CREATED \n");
	for(i=0;i<p;i++)
	{
		printf("%d) P%d\n",i+1,i);
	}
	printf("\nENTER NUMBER OF RESOURCES :");
	scanf("%d",&r); //Entering No. of Resources
	for(i=0;i<r;i++)
	{
		printf("%d) R%d\n",i+1,i);
	}
	int i_r[r];//1D array containing instance of all variable
	int av_r[r];//1D array containing available number of instance of all the resources
	int m_n_r[p][r];//2D array containing maximum need of resources by all the process
	int al_r[p][r];//2D array containing allocated number of resources by all the process
	int n_r[p][r];//2D array containing need of resources by all the process
	int comp[p]; //containing the status of all the process
	//int copy_available_resource[resource];//containing the out put of the available_resource
	for(i=0;i<p;i++)
		{comp[i]=0;} //Setting Flag for uncompleted Processes
	printf("\nENTER NUMBER OF INSTANCE PER RESOURCE\n");//entering the instance allocated with every resource
		for(i=0;i<r;i++) {
			printf("R%d : ",i);
		    scanf("%d",&in);
		    i_r[i]=in; //storing the instance value in the instance_resource array
		}
	printf("\nINSTANCE ARE\n");//display the instance of resources
	for(i=0;i<r;i++)
	{
		printf("R%d : %d\n",i,i_r[i]);
	}
	printf("\nENTER MAX RESOURCES REQUIRED BY EVERY PROCESS \n");//entering maximum how much resources required to execute completely every porcess
		for(i=0;i<p;i++) {
			printf("\nFor P%d: \n",i);
			for(j=0;j<r;j++) {
				printf("R%d: ",j);
		        scanf("%d",&in);
		        m_n_r[i][j]=in;
		    }
		}
	printf("\nTHE MAX RESOURCES REQUIRED ARE\n");
	for(i=0;i<p;i++)
	{
		printf("FOR P%d :\n",i);
		for(j=0;j<r;j++)
		{
			printf("R%d : %d\n",j,m_n_r[i][j]);
		}
		printf("\n");
	}
	printf("\nENTER THE NUMBER OF RESOURCES ALLOCATED TO THE PROCESS\n"); //entering the initially allocated resources for the every process
			for(i=0;i<p;i++) {
			printf("\nFor P%d: \n",i);
			for(j=0;j<r;j++) {
				printf("R%d: ",j);
		    	scanf("%d",&in);
		        a:
		    	if(in<=m_n_r[i][j])//checking condition as the resource we input is always lesser then the maximum resource needed
		    	{
		        	al_r[i][j]=in;
		        }
		        else
		        {
		        	printf("RE-ENTER THE VALUE\n");
		        	printf("R%d: ",j);
		    		scanf("%d",&in);
		        	goto a;
				}
		        n_r[i][j]=m_n_r[i][j]-al_r[i][j]; //Calculating the need of each process
		    }
		}
	printf("\nTHE ALLOCATED RESOURCES ARE\n");
	for(i=0;i<p;i++)
	{
		printf("FOR P%d :\n",i);
		for(j=0;j<r;j++)
		{
			printf("R%d : %d\n",j,al_r[i][j]);
		}
		printf("\n");
	}
	printf("\nAVAILABLE RESOURCE ARE\n");//cheking the available resources
		for(j=0;j<r;j++) {
		t=0;
			for(i=0;i<p;i++) {
				t+= al_r[i][j];
		    }
			av_r[j]=i_r[j]-t;
			printf("R%d : %d\n",j,av_r[j]);
		}
	printf("\nCHECKING THE SYSTEM IS IN SAFE OR UNSAFE STATE\n\n< ");//checking the system is in safe or in unsafe state
            while(c1!=p) {
	    	c2 = c1;
	    	for(i=0;i<p;i++) {
	       		for(j=0;j<r;j++) {
	            	if(n_r[i][j]<=av_r[j]) // Checking if Need can be fulfilled
	                	k++;
	        	}
	        	if(k==r && comp[i]==0 ) {
	           		printf("P%d ",i);
	           		comp[i]=1; // Setting flag for completed Process

	           		for(j=0;j<r;j++) {
	            		av_r[j]=av_r[j]+al_r[i][j]; //Updating instancesable Resources
	            	}
	            	c1++;
	         	}
	        	k=0;
	       	}
	        if(c1==c2) {
	        	printf("STOP ... Deadlock likely to happen!\n");
	        	break;
	       	}
	 	}
	 	printf(" >\n");
getch();
return 0;
}
