#include<stdio.h>
void fun(){
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			printf("*");
		}
		printf("\n");
	}
}

void fun2(){
	for(int i=0;i<4;i++){
		for(int j=0;j<4-i;j++){
			printf("*");
		}
		printf("\n");
	}
}

void fun3(){
	for(int i=0;i<4;i++){
		for(int j=0;j<i+1;j++){
			printf("*");
		}
		printf("\n");
	}
}

void fun4(){
	for(int i=0;i<4;i++){
		for(int j=4;j>i+1;j--){
			printf(" ");
		}
		for(int j=0;j<i+1;j++){
			printf("*");
		}
		printf("\n");
	}
}
int main(){
	int choice;
	printf("1. Function1\n");
	printf("2. Function2\n");
	printf("3. Function3\n");
	printf("4. Function4\n");
	scanf("%d",&choice);
	switch(choice){
		case 1:{
			fun();
			printf("\n");
			break;
		}
		case 2:{
			fun2();
			printf("\n");
			break;
		}
		case 3:{
			fun3();
			printf("\n");
			break;
		}
		case 4:{
			fun4();
			printf("\n");
			break;
		}
	}
	return 0;
}
