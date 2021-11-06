#include<stdio.h>
#include "lodepng.h"
#include<stdlib.h>
#include<pthread.h>

pthread_mutex_t mut;
//Creating structure variable
struct Threads_arguments{
long long  start;
long long  finish;
};

//Creating golobal variable
unsigned err;
unsigned char *img;
unsigned w, h, r, g, b, alpha;


void* cal_Gaussian_Blur(void* args)
{   
    struct Threads_arguments* ptr = (struct Threads_arguments*)args;
    long long st = ptr->start;
    long long fn = ptr->finish;
    for (int i = st; i <= fn; i++)
    {
        for(int j = 0; j < w; j++){
            
            if(i == 0 && j == 0){
                pthread_mutex_lock(&mut);
                r = (img[4 * w * i + 4 * j + 0] + img[4 * w * i + 4 * (j+1) + 0] + img[4 * w * (i+1) + 4 * j + 0] + img[4 * w * (i+1) + 4 * (j+1) + 0]) / 4;
                g = (img[4 * w * i + 4 * j + 1] + img[4 * w * i + 4 * (j+1) + 1] + img[4 * w * (i+1) + 4 * j + 1] + img[4 * w * (i+1) + 4 * (j+1) + 1]) / 4;
                b = (img[4 * w * i + 4 * j + 2] + img[4 * w * i + 4 * (j+1) + 2] + img[4 * w * (i+1) + 4 * j + 2] + img[4 * w * (i+1) + 4 * (j+1) + 2]) / 4;
                
                img[4 * w * i + 4 * j + 2] = b;
                img[4 * w * i + 4 * j + 1] = g;
                img[4 * w * i + 4 * j + 0] = r;
                pthread_mutex_unlock(&mut);
            }
            

            
            else if(i == 0 && j == w-1){
                pthread_mutex_lock(&mut);
                r = (img[4 * w * i + 4 * j + 0] + img[4 * w * i + 4 * (j-1) + 0] + img[4 * w * (i+1) + 4 * j + 0] + img[4 * w * (i+1) + 4 * (j-1) + 0]) / 4;
                g = (img[4 * w * i + 4 * j + 1] + img[4 * w * i + 4 * (j-1) + 1] + img[4 * w * (i+1) + 4 * j + 1] + img[4 * w * (i+1) + 4 * (j-1) + 1]) / 4;
                b = (img[4 * w * i + 4 * j + 2] + img[4 * w * i + 4 * (j-1) + 2] + img[4 * w * (i+1) + 4 * j + 2] + img[4 * w * (i+1) + 4 * (j-1) + 2]) / 4;
        
                img[4 * w * i + 4 * j + 2] = b;
                img[4 * w * i + 4 * j + 1] = g;
                img[4 * w * i + 4 * j + 0] = r;
                pthread_mutex_unlock(&mut);
            }
            
            else if(i == h-1 && j == 0){
                pthread_mutex_lock(&mut);
                r = (img[4 * w * i + 4 * j + 0] + img[4 * w * i + 4 * (j+1) + 0] + img[4 * w * (i-1) + 4 * j + 0] + img[4 * w * (i-1) + 4 * (j+1) + 0]) / 4;
                g = (img[4 * w * i + 4 * j + 1] + img[4 * w * i + 4 * (j+1) + 1] + img[4 * w * (i-1) + 4 * j + 1] + img[4 * w * (i-1) + 4 * (j+1) + 1]) / 4;
                b = (img[4 * w * i + 4 * j + 2] + img[4 * w * i + 4 * (j+1) + 2] + img[4 * w * (i-1) + 4 * j + 2] + img[4 * w * (i-1) + 4 * (j+1) + 2]) / 4;
                
                img[4 * w * i + 4 * j + 2] = b;
                img[4 * w * i + 4 * j + 1] = g;
                img[4 * w * i + 4 * j + 0] = r;
                pthread_mutex_unlock(&mut);
            }
            
            else if(i == h-1 && j == w-1){
                pthread_mutex_lock(&mut);
                r = (img[4 * w * i + 4 * j + 0] + img[4 * w * i + 4 * (j-1) + 0] + img[4 * w * (i-1) + 4 * j + 0] + img[4 * w * (i-1) + 4 * (j-1) + 0]) / 4;
                g = (img[4 * w * i + 4 * j + 1] + img[4 * w * i + 4 * (j-1) + 1] + img[4 * w * (i-1) + 4 * j + 1] + img[4 * w * (i-1) + 4 * (j-1) + 1]) / 4;
                b = (img[4 * w * i + 4 * j + 2] + img[4 * w * i + 4 * (j-1) + 2] + img[4 * w * (i-1) + 4 * j + 2] + img[4 * w * (i-1) + 4 * (j-1) + 2]) / 4;
                
                img[4 * w * i + 4 * j + 2] = b;
                img[4 * w * i + 4 * j + 1] = g;
                img[4 * w * i + 4 * j + 0] = r;
                pthread_mutex_unlock(&mut);
            }
            else if(i == 0 && j < w-1){
                pthread_mutex_lock(&mut);
                r = (img[4 * w * i + 4 * j + 0] + img[4 * w * i + 4 * (j-1) + 0] + img[4 * w * i + 4 * (j+1) + 0] + img[4 * w * (i+1) + 4 * (j-1) + 0] + img[4 * w * (i+1) + 4 * j + 0] + img[4 * w * (i+1) + 4 * (j+1) + 0]) / 6;
                g = (img[4 * w * i + 4 * j + 1] + img[4 * w * i + 4 * (j-1) + 1] + img[4 * w * i + 4 * (j+1) + 1] + img[4 * w * (i+1) + 4 * (j-1) + 1] + img[4 * w * (i+1) + 4 * j + 1] + img[4 * w * (i+1) + 4 * (j+1) + 1]) / 6;
                b = (img[4 * w * i + 4 * j + 2] + img[4 * w * i + 4 * (j-1) + 2] + img[4 * w * i + 4 * (j+1) + 2] + img[4 * w * (i+1) + 4 * (j-1) + 2] + img[4 * w * (i+1) + 4 * j + 2] + img[4 * w * (i+1) + 4 * (j+1) + 2]) / 6;
                
                img[4 * w * i + 4 * j + 2] = b;
                img[4 * w * i + 4 * j + 1] = g;
                img[4 * w * i + 4 * j + 0] = r;
                pthread_mutex_unlock(&mut);
            }

            else if(i < h-1 && j == 0){
                pthread_mutex_lock(&mut);
                r = (img[4 * w * i + 4 * j + 0] + img[4 * w * (i-1) + 4 * j + 0] + img[4 * w * i + 4 * (j+1) + 0] + img[4 * w * (i-1) + 4 * (j+1) + 0] + img[4 * w * (i+1) + 4 * j + 0] + img[4 * w * (i+1) + 4 * (j+1) + 0]) / 6;
                g = (img[4 * w * i + 4 * j + 1] + img[4 * w * (i-1) + 4 * j + 1] + img[4 * w * i + 4 * (j+1) + 1] + img[4 * w * (i-1) + 4 * (j+1) + 1] + img[4 * w * (i+1) + 4 * j + 1] + img[4 * w * (i+1) + 4 * (j+1) + 1]) / 6;
                b = (img[4 * w * i + 4 * j + 2] + img[4 * w * (i-1) + 4 * j + 2] + img[4 * w * i + 4 * (j+1) + 2] + img[4 * w * (i-1) + 4 * (j+1) + 2] + img[4 * w * (i+1) + 4 * j + 2] + img[4 * w * (i+1) + 4 * (j+1) + 2]) / 6;
                
                img[4 * w * i + 4 * j + 2] = b;
                img[4 * w * i + 4 * j + 1] = g;
                img[4 * w * i + 4 * j + 0] = r;
                pthread_mutex_unlock(&mut);
            }
            
            else if(i == h-1 && j < w-1){
                pthread_mutex_lock(&mut);
                r = (img[4 * w * i + 4 * j + 0] + img[4 * w * (i-1) + 4 * j + 0] + img[4 * w * i + 4 * (j+1) + 0] + img[4 * w * (i-1) + 4 * (j+1) + 0] + img[4 * w * i + 4 * (j-1) + 0] + img[4 * w * (i-1) + 4 * (j-1) + 0]) / 6;
                g = (img[4 * w * i + 4 * j + 1] + img[4 * w * (i-1) + 4 * j + 1] + img[4 * w * i + 4 * (j+1) + 1] + img[4 * w * (i-1) + 4 * (j+1) + 1] + img[4 * w * i + 4 * (j-1) + 1] + img[4 * w * (i-1) + 4 * (j-1) + 1]) / 6;
                b = (img[4 * w * i + 4 * j + 2] + img[4 * w * (i-1) + 4 * j + 2] + img[4 * w * i + 4 * (j+1) + 2] + img[4 * w * (i-1) + 4 * (j+1) + 2] + img[4 * w * i + 4 * (j-1) + 2] + img[4 * w * (i-1) + 4 * (j-1) + 2]) / 6;
                
                img[4 * w * i + 4 * j + 2] = b;
                img[4 * w * i + 4 * j + 1] = g;
                img[4 * w * i + 4 * j + 0] = r;
                pthread_mutex_unlock(&mut);
            }
            
            else if(i < h-1 && j == w-1){
                pthread_mutex_lock(&mut);
                r = (img[4 * w * i + 4 * j + 0] + img[4 * w * i + 4 * (j-1) + 0] + img[4 * w * (i-1) + 4 * j + 0] + img[4 * w * (i-1) + 4 * (j-1) + 0] + img[4 * w * (i+1) + 4 * j + 0] + img[4 * w * (i+1) + 4 * (j-1) + 0]) / 6;
                g = (img[4 * w * i + 4 * j + 1] + img[4 * w * i + 4 * (j-1) + 1] + img[4 * w * (i-1) + 4 * j + 1] + img[4 * w * (i-1) + 4 * (j-1) + 1] + img[4 * w * (i+1) + 4 * j + 1] + img[4 * w * (i+1) + 4 * (j-1) + 1]) / 6;
                b = (img[4 * w * i + 4 * j + 2] + img[4 * w * i + 4 * (j-1) + 2] + img[4 * w * (i-1) + 4 * j + 2] + img[4 * w * (i-1) + 4 * (j-1) + 2] + img[4 * w * (i+1) + 4 * j + 2] + img[4 * w * (i+1) + 4 * (j-1) + 2]) / 6;
                
                img[4 * w * i + 4 * j + 2] = b;
                img[4 * w * i + 4 * j + 1] = g;
                img[4 * w * i + 4 * j + 0] = r;
                pthread_mutex_unlock(&mut);
            }
            
            else{
                pthread_mutex_lock(&mut);
                r = (img[4 * w * i + 4 * j + 0] + img[4 * w * i + 4 * (j+1) + 0] + img[4 * w * i + 4 * (j-1) + 0] + img[4 * w * (i+1) + 4 * j + 0] + img[4 * w * (i-1) + 4 * j + 0] + img[4 * w * (i+1) + 4 * (j+1) + 0] + img[4 * w * (i+1) + 4 * (j-1) + 0] + img[4 * w * (i-1) + 4 * (j+1) + 0] + img[4 * w * (i-1) + 4 * (j-1) + 0]) / 9;
                g = (img[4 * w * i + 4 * j + 1] + img[4 * w * i + 4 * (j+1) + 1] + img[4 * w * i + 4 * (j-1) + 1] + img[4 * w * (i+1) + 4 * j + 1] + img[4 * w * (i-1) + 4 * j + 1] + img[4 * w * (i+1) + 4 * (j+1) + 1] + img[4 * w * (i+1) + 4 * (j-1) + 1] + img[4 * w * (i-1) + 4 * (j+1) + 1] + img[4 * w * (i-1) + 4 * (j-1) + 1]) / 9;
                b = (img[4 * w * i + 4 * j + 2] + img[4 * w * i + 4 * (j+1) + 2] + img[4 * w * i + 4 * (j-1) + 2] + img[4 * w * (i+1) + 4 * j + 2] + img[4 * w * (i-1) + 4 * j + 2] + img[4 * w * (i+1) + 4 * (j+1) + 2] + img[4 * w * (i+1) + 4 * (j-1) + 2] + img[4 * w * (i-1) + 4 * (j+1) + 2] + img[4 * w * (i-1) + 4 * (j-1) + 2]) / 9;
                
                img[4 * w * i + 4 * j + 2] = b;
                img[4 * w * i + 4 * j + 1] = g;
                img[4 * w * i + 4 * j + 0] = r;
                pthread_mutex_unlock(&mut); 
            }
            
        }
    }
    
    pthread_exit(0);
	

	
}

void main() {
	char fileName[50];
    printf("Please Enter inplace of choose a png file => Leo.png or chooose any png file\n");
    printf("choose a png file : \n");
    scanf("%s",fileName);
    err = lodepng_decode32_file(&img, &w, &h, fileName);
    if(err){
        printf("error in decoading img");
    }
    int numofthreads;
    long long iteration;
    iteration = h;
    //initialize threads and slicing dynomically
	printf("Enter the number of threads =>\n");
	scanf("%d",&numofthreads);
	int i;
	pthread_t id[numofthreads];
	pthread_mutex_init(&mut,NULL);
	struct Threads_arguments s[numofthreads];
	int slicelist[numofthreads];
	for(i=0;i<numofthreads;i++)
	{
	  slicelist[i]=iteration/numofthreads;
	}
	int remainder=iteration%numofthreads;
	for(i=0;i<remainder;i++)
	{
		slicelist[i]=slicelist[i]+1;
	}
	
	for(i=0;i<numofthreads;i++){
       if(i==0)
         {
         s[i].start=1;
         }
       else{
                s[i].start=s[i-1].finish+1;
           }
s[i].finish=s[i].start+slicelist[i]-1;
}
for(i=0;i<numofthreads;i++)
{
	pthread_create(&id[i],NULL,cal_Gaussian_Blur,&s[i]);
}
for(i=0;i<numofthreads;i++)
{
	pthread_join(id[i],NULL);
}
unsigned char *pngformat;
    size_t pngsize;
    err = lodepng_encode32(&pngformat, &pngsize, img, w, h);
    if(!err){
        lodepng_save_file(pngformat,pngsize, "encodingNewImg.png");
    }
    free(img);
    free(pngformat);
 pthread_mutex_destroy(&mut);
		
    
}
