#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
typedef struct Point{
    int score;	
    char id[50];
    struct Point *next;
} pnode;

void node(int score,char ID[],pnode *phead){
	pnode *p;
	p = (pnode *)malloc(sizeof(pnode));
	p->score = score;
	strcpy(p->id,ID);
	p->next = NULL;
	printf("ID = %s,Score  = %d\n",p->id,p->score);
	
	while(phead->next!=NULL){
		phead = phead->next;
	}
	phead->next = p;
}

void printnode(pnode *phead,int count){
	for(int i=0;i<count;i++){
		printf("[%d]:  ID = %s,Score  = %d\n",i,phead->id,phead->score);
		phead = phead->next;
	}
}

int main(){
    int score;
    int count = 1;
    char ID[50] = "hello";
    pnode *phead;
    phead = (pnode *)malloc(sizeof(pnode));
    strcpy(phead->id,ID);
    phead->score = 99;
    phead->next = NULL;
    printf("ID = %s,Score  = %d\n",phead->id,phead->score);
    while(1){
    	printf("Enter score ");
	    scanf("%d",&score);
	    if(score==-1) break;
	    printf("Enter the ID ");
	    scanf("%s",&ID);
	    node(score,ID,phead);
	    count++;
	} 		
	printnode(phead,count);
	return 0;
}
