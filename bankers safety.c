#include<stdio.h>
#include<conio.h>
	
int main() {
	int p,r,i,j,ins,t=0, k=0,c1=0,c2=0; 
	/*c1, c2 and k are used for counting purpose*/
	
	printf("\nNo. of Process: ");
	scanf("%d",&p); //Entering No. of Processes
	printf("*No. of Resources: ");
	scanf("%d",&r); //Entering No. of Resources
	
	int instances[r], avail[r], max[p][r],allot[p][r],need[p][r],comp[p]; //Declaring the necessary matrices
	
	for(i=0;i<p;i++)
		comp[i]=0; //Setting Flag for uncompleted Processes
	
	printf("\n*Enter Instances : \n");
		for(i=0;i<r;i++) {
			printf("%c: ",(i+65));
		    scanf("%d",&ins);
		    instances[i]=ins; //Storing instancesable instancees
		} 
	
	printf("\n*Enter Maximum Resource :\n");
		for(i=0;i<p;i++) {
			printf("\nFor P%d: \n",i);
			for(j=0;j<r;j++) {
				printf("%c: ",(j+65));
		        scanf("%d",&ins);
		        max[i][j]=ins;               
		    } 
		}  
		   
	printf("\n*Enter  resource for every process:\n"); 
		for(i=0;i<p;i++) {
			printf("\nFor P%d: \n",i);
			for(j=0;j<r;j++) {
				printf("%c: ",(j+65));
		    	scanf("%d",&ins);
		        allot[i][j]=ins;
				
		        need[i][j]=max[i][j]-allot[i][j]; //Calculating the Need of each process
		    }  
		} 
	
	//Calculating the Available Instances for each r type	
		for(j=0;j<r;j++) {
		t=0;
			for(i=0;i<p;i++) {
				t+= allot[i][j];
		    }  
			avail[j]=instances[j]-t;
			printf("R%d : %d\n",j,avail[j]);
		}
	
	
	printf("The System is in a Safe State\n***** Safe Sequence is: < ");
	    while(c1!=p) {
	    	c2 = c1;
	    	for(i=0;i<p;i++) {
	       		for(j=0;j<r;j++) {
	            	if(need[i][j]<=avail[j]) // Checking if Need can be fulfilled
	                	k++;  
	        	}     
	        	if(k==r && comp[i]==0 ) {
	           		printf("P%d ",i);
	           		comp[i]=1; // Setting flag for completed Process
	
	           		for(j=0;j<r;j++) {
	            		avail[j]=avail[j]+allot[i][j]; //Updating instancesable rs
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
