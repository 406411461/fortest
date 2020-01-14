#include<stdio.h>
#include<stdlib.h>

typedef struct NodeMana{
	struct pNode *head;
	struct pNode *tail;
	int count;
}pmana;

typedef struct pNode{
	int score;
	int ID;
	struct pNode *next;
	struct pNode *prep;
}pnode;

void createN(pmana *phead){
	pnode *p;
	p = (pNode *)malloc(sizeof(pNode));
	if(phead->count==0){
		printf("��J ID �M Score ");
		scanf("%d %d",&(p->ID),&(p->score));
		p->next = NULL;
		p->prep = NULL;
		
		phead->head = p;
		phead->tail = p;
	}
	else{
		int dest;
		int repl;
		pnode *q;
	    q = (pNode *)malloc(sizeof(pNode));
		printf("��J�s�W����m: ");	
		scanf("%d",&dest);
		printf("�e���٬O�᭱: ");
		scanf("%d",&repl);
		p = phead->head;
        for(int i=0;i<dest-1;i++){
			p = p->next;
		}
		printf("��J ID �M Score ");
		scanf("%d %d",&(q->ID),&(q->score));
		q->next = NULL;
		q->prep = NULL;
		if(repl==0){
            if(dest==1){
            	p->prep = q;
            	q->next = p;
            	phead->head = q;
			}
			else{
			    p->prep->next = q;
			    q->next = p;
			    q->prep = p->prep;
			    p->prep = q;
			}
		}
		else if(repl==1){
			if(dest==phead->count){
				p->next = q;
				q->prep = p;
				phead->tail = q;
			}
			else{
				p->next->prep = q;
				q->prep = p;
				q->next = p->next;
				p->next = q;
			}
		}
	}
	(phead->count)++;
}

void deleteN(pmana *phead){
	int dest;
	pNode *p;
	p = phead->head; 
    printf("��J�R������m: ");	
	scanf("%d",&dest);
    dest = dest-1;
    if(phead->count==1&&dest==0){
    	phead->head = NULL;
    	phead->tail = NULL;
	}
	else if(dest==0){
		p->prep = NULL;
		phead->head = p->next; 
	}
	else if((dest+1)==phead->count){
		p = phead->tail;
		phead->tail = p->prep;
		p->prep->next = NULL;
	}
	else{
		for(int i=0;i<dest;i++){
		    p = p->next;
	    }
		p->prep->next = p->next;
		p->next->prep = p->prep;
	}
    (phead->count)--;
}

void reverseN(pmana *phead){
	pnode *newnode;
	pnode *nnode;
	nnode = phead->head;
	newnode = (pnode *)malloc(sizeof(pnode));
	newnode = phead->tail;
	for(int i=0;i<phead->count;i++){
		if(i==0){
			newnode->next = newnode->prep;
			newnode->prep = NULL;
			phead->head = newnode;
			newnode = newnode->next;
		}
		else if((i+1)==phead->count){
		    newnode->next = NULL;
			phead->tail = newnode;	
		}
		else{
			newnode->next = newnode->prep;
			newnode->prep = nnode;
		    newnode = newnode->next;
		    nnode = nnode->next;
		}		
	}
}

void printN(pmana *phead){
	pnode *p;
	p = phead->head;
	printf("\n");
	for(int i=1;i<=phead->count;i++){
		printf("[%d]: ID = %d, Score = %d\n",i,p->ID,p->score);
	    p = p->next;
	}
	printf("count is %d",phead->count);
	printf("\n");
}

int main(){
	int choice = 0;
	pmana *phead;
	phead = (pmana *)malloc(sizeof(pmana));
	phead->head = NULL;
	phead->tail = NULL;
	phead->count = 0;

	while(1){
		printf("1. �s�W�`�I\n");
		printf("2. �R���`�I\n");
		printf("3. ����\n");
		printf("-1 ����\n");
		scanf("%d",&choice);
		if(choice==-1) break;
		switch(choice){
			case 1:{
				createN(phead);
				break;
			}
			case 2:{
				deleteN(phead);
				break;
			}
			case 3:{
				reverseN(phead);
				break;
			}
	    }
	    printN(phead);	
	}
	return 0;
}
