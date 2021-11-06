#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
//initialize structure variable
struct threadArgs{
	int start;
	int finish;
};

//initialize golobal variable
int *p;
int num=0;
FILE  *fptr4;
pthread_mutex_t mutex;//defining the mutex lock algorithem

void* Calc_PrimrNum(void* args)
{   
    pthread_mutex_lock(&mutex);//lock the mutex lock algorithem
	int z;
	struct threadArgs* ptr=(struct threadArgs*)args;
	int st=ptr->start;
	int fi=ptr->finish;
	int i;
	for(i=st;i<=fi;i++){
		//creating Algorithem for calculating prime number.
		for(z=2; z<=p[i]-1; z++) {
			if(p[i]%z==0){
				break;
		}
			}
			if(z== p[i]) {
			fprintf(fptr4,"%d\n",p[i]);//Writing all the prime number on new file
		}		
}	
	pthread_mutex_unlock(&mutex);//unlock the mutex lock algorithem
		
}




//arg takes num of argument and argv takes position of argument in the form of array.
void main(int arg, char ** argv) { 
	//initialize file pointer and reading file.
	FILE *fptr1, *fptr2, *fptr3;
 	int i;
 	fptr1=fopen("PrimeData1.txt","r");
 	fptr2=fopen("PrimeData2.txt","r");
 	fptr3=fopen("PrimeData3.txt","r");
 	fptr4=fopen("CopyOnlyPrimeNum.txt","w");
 	if(fptr1==NULL||fptr2==NULL||fptr3==NULL) {
 		printf("Error occure at File.\n");
	 }
	//initialize dynomical 1 D array.
 	p=(int*)malloc(1200000*sizeof(int));
 	if(p==NULL) {
 		printf("Memory is not allocated.\n");
	 }
	 
	 //reading the data from file and storing that data on p[num] 1D array
 	while((fscanf(fptr1,"%d\n",&p[num]))!=EOF) {
   	num++;	
}

    while((fscanf(fptr2,"%d\n",&p[num]))!=EOF) {
   	num++;	
}

    while((fscanf(fptr3,"%d\n",&p[num]))!=EOF) {
   	num++;	
}
   printf("Total data in all file=%d\n",num);
   //initialize bydefault thread 1
	int threads = 1;
	if(arg> 1) {
		threads = atoi(argv[1]);
	}
	pthread_t id[threads];
	pthread_mutex_init(&mutex,NULL);//initialize the mutex lock algorithem
	struct threadArgs s[threads];
	int slicelist[threads];
	for(i=0;i<threads;i++)
	{
	  slicelist[i]=num/threads;
	}
	int remainder=num%threads;
	for(i=0;i<remainder;i++)
	{   //slicing all the num in equal slicelist
		slicelist[i]=slicelist[i]+1;
	}
	
	for(i=0;i<remainder;i++)
	{
		printf("slicelist=%d\n",slicelist[i]);
	}
	
	for(i=0;i<threads;i++){
       if(i==0)
         {
         s[i].start=1;
         }
       else{
                s[i].start=s[i-1].finish+1;
           }
s[i].finish=s[i].start+slicelist[i]-1;
}
for(i=0;i<threads;i++)
{   //Creating the living thread
	pthread_create(&id[i],NULL,Calc_PrimrNum,&s[i]);
}
for(i=0;i<threads;i++)
{   //joining the threads
	pthread_join(id[i],NULL);
}
 pthread_mutex_destroy(&mutex);//destroy the mutex lock algorithem
		
	//Closing the files
	fclose(fptr1);
	fclose(fptr2);
	fclose(fptr3);
	fclose(fptr4);
	free(p);//Free Dynomically alocated memory.
    
}
