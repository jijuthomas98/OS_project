#include<stdio.h>
#include<conio.h>
	
int main() {
	int process,resource,i,j,instance,total=0, k=0,c1=0,c2=0; 
	/*c1, c2 and k are used for counting purpose*/
	
	printf("\n*Enter No. of Process: ");
	scanf("%d",&process); //Entering No. of Processes
	printf("*Enter No. of Resources: ");
	scanf("%d",&resource); //Entering No. of Resources
	
	int instances[resource], avail[resource], max[process][resource],allot[process][resource],
	need[process][resource],completed[process]; //Declaring the necessary matrices
	
	for(i=0;i<process;i++)
		completed[i]=0; //Setting Flag for uncompleted Processes
	
	printf("\n*Enter No. of Instances per Resource type: \n");
		for(i=0;i<resource;i++) {
			printf("%c: ",(i+65));
		    scanf("%d",&instance);
		    instances[i]=instance; //Storing instancesable instancees
		} 
	
	printf("\n*Enter Maximum No. of Resource type Instances for each:\n");
		for(i=0;i<process;i++) {
			printf("\nFor P%d: \n",i);
			for(j=0;j<resource;j++) {
				printf("%c: ",(j+65));
		        scanf("%d",&instance);
		        max[i][j]=instance;               
		    } 
		}  
		   
	printf("\n*Enter No. of Resource type Instances allocated to each process:\n"); 
		for(i=0;i<process;i++) {
			printf("\nFor P%d: \n",i);
			for(j=0;j<resource;j++) {
				printf("%c: ",(j+65));
		    	scanf("%d",&instance);
		        allot[i][j]=instance;
				
		        need[i][j]=max[i][j]-allot[i][j]; //Calculating the Need of each process
		    }  
		} 
	
	//Calculating the Available Instances for each Resource type	
		for(j=0;j<resource;j++) {
		total=0;
			for(i=0;i<process;i++) {
				total+= allot[i][j];
		    }  
			avail[j]=instances[j]-total;
			printf("R%d : %d\n",j,avail[j]);
		}
	
	
	printf("The System is in a Safe State\n***** Safe Sequence is: < ");
	    while(c1!=process) {
	    	c2 = c1;
	    	for(i=0;i<process;i++) {
	       		for(j=0;j<resource;j++) {
	            	if(need[i][j]<=avail[j]) // Checking if Need can be fulfilled
	                	k++;  
	        	}     
	        	if(k==resource && completed[i]==0 ) {
	           		printf("P%d ",i);
	           		completed[i]=1; // Setting flag for completed Process
	
	           		for(j=0;j<resource;j++) {
	            		avail[j]=avail[j]+allot[i][j]; //Updating instancesable Resources
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
} 
