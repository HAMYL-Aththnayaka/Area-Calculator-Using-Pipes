#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

double circle(double val){
	return 3.14*(val*val);
}
double square (double val){
	return val*val;
}
double triangle (double val,double height){
	return (val*height)/2;
}
double rectangle(double val,double val2){
	return val*val2;
}
void begin(){
printf("\nPlease Choose What You Want to Calculate :\n");
printf(":: Options :: \n");
printf(" 1 : Calculate a Circles Area \n");
printf(" 2 : Calculate a Trinagle Area \n");
printf(" 3 : Calculate a Square Area \n");
printf(" 4 : Calculate a Rectangle Area \n");
}
void printResults(double result){
printf("The Results Are : %lf",result);
}


int main(){
double val,val2,result;
int choice;
int f ;
int fd[2];
int fd2[2];
	if(pipe(fd)<0 || pipe(fd2)<0){
		perror("Pipe Failled");
		exit(1);
	}
	f = fork();
	if(f == 0){
		//child Process
		close(fd[1]);
		read(fd[0],&choice,sizeof(int));
		close(fd[0]);

		switch(choice){
			case 1:
			printf("Please Enter the Radius :\n");
			scanf("%lf",&val);
			result = circle(val);
			
			break;

			case 3:
			printf("Please Enter the Side Lenght :\n");
			scanf("%lf",&val);
			result = square(val);

			break;

			case 2:
			printf("Please Enter the Lenght :\n");
			scanf("%lf",&val);
			printf("Please Enter the Perpendicular height :\n");
			scanf("%lf",&val2);
			result = triangle(val,val2);

			break;

			case 4:
			printf("Please Enter The Lenght: \n");
			scanf("%lf",&val);
			printf("Please Enter The Width : \n");
			scanf("%lf",&val2);
			result = rectangle(val,val2);
			break;
			
			default:
			printf("Please Enter A Valid Option \n");
			break;
		}

		close(fd2[0]);
		write(fd2[1],&result,sizeof(double));
		close(fd2[1]);
	
	}else{
		//parent Process
		begin();
		scanf("%i",&choice);
		close(fd[0]);
		write(fd[1],&choice,sizeof(int));
		close(fd[1]);
		wait(NULL);

		close(fd2[1]);
		read(fd2[0],&result,sizeof(double));
		close(fd2[0]);

		printResults(result);
	}


return 0;
}
