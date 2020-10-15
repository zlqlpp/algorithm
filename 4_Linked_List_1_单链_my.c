

#include <stdio.h>
#include <stdlib.h>

typedef struct LinkList{

	int value;

	struct LinkList *nextList;
}Node,*LinkList;

LinkList linklistinit(){
	Node *n;
	n= (Node *)malloc(sizeof(Node));

	return n;
}

// 头插
/*
 * 1,创建一个头，指向空
 * 2.每次新建元素A，都让头指向A,A指向头原来指向的元素
 * 3.返回头元素
 */
LinkList HeadInsert(){
	LinkList head;
	head = (LinkList)malloc(sizeof(Node));
	head->nextList=NULL;

	int x;
	while(scanf("%d",&x)!=EOF){ // eof ==  ctrl D
		LinkList new=(LinkList)malloc(sizeof(Node));
		new->value=x;
		new->nextList=head->nextList;
		head->nextList=new;
	}
	return head;
}
//尾插
/*
 * 1.新建一个头，一个尾，都指向空。
 * 2.每次新建元素，让新元素指向尾元素的指向。然后让尾元素=新元素。
 * 3.返回头元素
 */
LinkList TailInsert(){
	LinkList head ,tail;
	head =tail = (LinkList)malloc(sizeof(Node));
	head->nextList=NULL;

	int x;
	while(scanf("%d",&x)!=EOF){ // eof ==  ctrl D
		LinkList new=(LinkList)malloc(sizeof(Node));
		new->value=x;
		new->nextList=tail->nextList;
		tail->nextList=new;
		tail=new;
	}
	return head;
}
// 第I个位置插
// 删除值为 x的元素
// 遍历链表
/*
 * 1.接收链表，从头开始判断。
 * 2.如果指向不为NULL，刚打印，并将临时元素指向它的下一个元素
 */
void bianliList(LinkList l){
	LinkList tmp = l;
	while(tmp->nextList!=NULL){
		printf("%d",tmp->value);
		tmp=l->nextList;
	}
}
/**/

int main(void ){

	Node *n = linklistinit();
	n->value=2;
	n->nextList = NULL ;
	printf("%d",n->value);


	Node *n2 = HeadInsert();
	bianliList(n2);
	//printf("%d",n2->nextList->value);


	return 0;
}



