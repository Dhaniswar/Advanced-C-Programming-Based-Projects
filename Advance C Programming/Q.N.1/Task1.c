#include<stdio.h>
#include<stdlib.h>
void main() {
	/*Reading four file continuously using fopen() function file name are datasetLR1,datasetLR2, 
	datasetLR3 And datasetLR4. where x1,x2,x3,x4 are the X data of each file, y1,y2,y3,y4 are
	the Y data of each file, x1sq, x2sq, x3sq, x4sq X square data of each file, y1sq, y2sq, 
	y3sq, y4sq data are Y square data of each file and x1y1, x2y2, x3y3, x4y4 are the XY data
	of each file  */
	FILE *fptr1 = fopen("datasetLR1.txt","r");//Reading a first file.
	int a1, b1 , count1=0, x1=0, y1=0, x1sq=0, y1sq=0, x1y1=0;//initializing variable
	if(fptr1 == NULL) { //checking file is opened or not.
		printf("File cannot read.\n");
	}
	while(!feof(fptr1)) { /*Reading data from file using formated function fscanf
		and storing a data x data at a1 and y data at b1.*/
		fscanf(fptr1,"%d,%d\n",&a1,&b1);
		count1++;//Counting no of data 
		x1 += a1;//calculating the sum of x data  
		y1 += b1;//calculating the sum of y data
		x1sq += a1*a1;//calculating the sum of square of x data
		y1sq += b1*b1;//calculating the sum of square of y data
		x1y1 += a1*b1;//calculating the sum of product of x and y data
	}

	fclose(fptr1);
	
	
	
	//Idea is same as above
	FILE *fptr2 = fopen("datasetLR2.txt","r");
	int a2, b2, count2=0, x2=0, y2=0, x2sq=0, y2sq=0, x2y2=0;
	if(fptr2 == NULL) {
		printf("cannot read datasetLR2.\n");
	}
	while(!feof(fptr2)) {
		fscanf(fptr2,"%d,%d\n",&a2,&b2);
		count2++;
		x2 += a2;
		y2 += b2;
        x2sq += a2*a2;
		y2sq += b2*b2;
		x2y2 += a2*b2;
	}

	fclose(fptr2);
	
	
	//Idea is same as above	
	FILE *fptr3 = fopen("datasetLR3.txt","r");
	int a3, b3, count3=0, x3=0, y3=0, x3sq=0, y3sq=0, x3y3=0;
	if(fptr3 == NULL) {
		printf("cannot read datasetLR3.\n");
	}
	while(!feof(fptr3)) {
		fscanf(fptr3,"%d,%d\n",&a3,&b3);
		count3++;
		x3 += a3;
		y3 += b3;
        x3sq += a3*a3;
		y3sq += b3*b3;
		x3y3 += a3*b3;
		

	}

	fclose(fptr3);
	
	
	//Idea is same as above
	FILE *fptr4 = fopen("datasetLR4.txt","r");
	int a4, b4, count4=0, x4=0, y4=0, x4sq=0, y4sq=0, x4y4=0;
	if(fptr4 == NULL) {
		printf("cannot read datasetLR2.\n");
	}
	while(!feof(fptr4)) {
		fscanf(fptr4,"%d,%d\n",&a4,&b4);
		count4++;
		x4 += a4;
		y4 += b4;
        x4sq += a4*a4;
		y4sq += b4*b4;
		x4y4 += a4*b4;
	}
	fclose(fptr4);
	
	
    //Creating variable for combining data 
    long long int n,sumOfX,sumOfY,sumOfXY,sumOfXX,sumOfYY;
    n = count1 + count2 + count3 + count4;
    sumOfX = x1 + x2 + x3 + x4;
    sumOfY = y1 + y2 + y3 + y4;
    sumOfXY = x1y1 + x2y2 + x3y3 + x4y4;
    sumOfXX = x1sq + x2sq + x3sq + x4sq;
	sumOfYY = y1sq + y2sq + y3sq + y4sq;
	
	
	//creating variables to calculate linear regression formula separately
	double A1=0,A2=0,A=0,B1=0,B2=0,B=0,X,Y=0;	
	A1 = ((sumOfY)*(sumOfXX))- ((sumOfX)*(sumOfXY));
	A2 = (n*(sumOfXX)) - ((sumOfX)*(sumOfX));
	A  = A1/A2;
	
	B1 = (n*(sumOfXY))- ((sumOfX)*(sumOfY));
	B2 = (n*(sumOfXX)) - ((sumOfX)*(sumOfX));
	B  =B1/B2;
    

	printf("Enter the value of X.\n");
	scanf("%lf",&X);
	Y = ((B*X )+ A);
	printf("The Value of predicted Y is => %.3lf\n",Y);
		
	
}
