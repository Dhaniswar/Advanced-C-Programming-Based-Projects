#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
#include<math.h>


struct thareadargument{
	int start;
	int finish;

};
//Declaring mutex log algorithem
pthread_mutex_t mutex;
double pi=0.0;

void* calcPI(void* args) {
	//lock mutex log algorithem
	pthread_mutex_lock(&mutex);
	struct thareadargument* p=(struct thareadargument*) args;
	int st=p->start;
	int fi=p->finish;
	int i;
	printf("%d\n",st );
	printf("%d\n",fi );
	for(i=st; i<=fi; i++){
    pi =pi + ((pow(-1,(i))/(2 * i + 1))*4);
   

	}
	
	pthread_mutex_unlock(&mutex);
	//unlock mutex log algorithem
}

void main(int ark, char ** arm) {
	long long int iteration;
	printf("Enter the iteration=>\n");
    scanf("%lld",&iteration);
	int numofthreads = 1;
	if(ark > 1) {
		numofthreads = atoi(arm[1]);
	}
	//initialize mutex log algorithem
	pthread_mutex_init(&mutex,NULL);
	pthread_t threadId[numofthreads];
	struct thareadargument s[numofthreads];

	int slicelist[numofthreads];
	int i;
	for(i=0; i<numofthreads; i++) {
		slicelist[i]=iteration/numofthreads;
	}
	for(i=0; i<numofthreads; i++) {
		printf("slicelist=%d\n",slicelist[i]);
	}

	int remainder = iteration % numofthreads;
	printf("remainder=%d\n",remainder );

	for (int i = 0; i < remainder; i++){

         slicelist[i]=slicelist[i]+1;
	}
	printf("remainder =%d\n",remainder );
	for(i=0; i<numofthreads; i++) {
		printf("slicelist=%d\n",slicelist[i]);
	}

	for (int i = 0; i < numofthreads; i++){
		if(i==0){
			s[i].start=0;
		}
		else{
			s[i].start=s[i - 1].finish + 1;
		}
		s[i].finish=s[i].start + slicelist[i] -1;
	}


     for (int i = 0; i <numofthreads; i++){
		pthread_create(&threadId[i],NULL,calcPI,&s[i]);
	}
     
     for (int i = 0; i <numofthreads; i++){

     	pthread_join(threadId[i],NULL);
     }
     //destroy the mutex lock algorithem
	pthread_mutex_destroy(&mutex);
     
     //Calculating the final value of the pi
     printf("The value of pi is =>%lf\n",pi);


	

}
