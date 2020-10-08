//https://www.runoob.com/data-structures/data-structures-tutorial.html
//
//
//常见的数据结构
//栈（Stack）：栈是一种特殊的线性表，它只能在一个表的一个固定端进行数据结点的插入和删除操作。
//队列（Queue）：队列和栈类似，也是一种特殊的线性表。和栈不同的是，队列只允许在表的一端进行插入操作，而在另一端进行删除操作。
//数组（Array）：数组是一种聚合数据类型，它是将具有相同类型的若干变量有序地组织在一起的集合。
//链表（Linked List）：链表是一种数据元素按照链式存储结构进行存储的数据结构，这种存储结构具有在物理上存在非连续的特点。
//树（Tree）：树是典型的非线性结构，它是包括，2 个结点的有穷集合 K。
//图（Graph）：图是另一种非线性数据结构。在图结构中，数据结点一般称为顶点，而边是顶点的有序偶对。
//堆（Heap）：堆是一种特殊的树形数据结构，一般讨论的堆都是二叉堆。
//散列表（Hash table）：散列表源自于散列函数(Hash function)，其思想是如果在结构中存在关键字和T相等的记录，那么必定在F(T)的存储位置可以找到该记录，这样就可以不用进行比较操作而直接取得所查记录。
//
//常用算法
//数据结构研究的内容：就是如何按一定的逻辑结构，把数据组织起来，并选择适当的存储表示方法把逻辑结构组织好的数据存储到计算机的存储器里。算法研究的目的是为了更有效的处理数据，提高数据运算效率。数据的运算是定义在数据的逻辑结构上，但运算的具体实现要在存储结构上进行。一般有以下几种常用运算：
//
//检索：检索就是在数据结构里查找满足一定条件的节点。一般是给定一个某字段的值，找具有该字段值的节点。
//插入：往数据结构中增加新的节点。
//删除：把指定的结点从数据结构中去掉。
//更新：改变指定节点的一个或多个字段的值。
//排序：把节点按某种指定的顺序重新排列。例如递增或递减。



#include<stdio.h>
#include<stdlib.h>
#include<cstring>
#define maxsize 10      //表示循环队列的最大容量
 
//循环队列的结构设计
typedef struct cir_queue{
    int data[maxsize];
    int rear;
    int front;
}cir_queue;
 
//初始化
cir_queue *init(){
    cir_queue *q = (cir_queue*)malloc(sizeof(cir_queue));
    if(q==NULL){
        exit(0);    //申请内存失败，退出程序
    }
    memset(q->data,0,sizeof(q->data));
    q->front=0;
    q->rear=0;
    return q;
}
 
//入队操作push
void push(cir_queue *q,int data){
    if((q->rear+1)%maxsize==q->front){
        printf("溢出，无法入队\n");
        return;
    }else{
        q->rear=(q->rear+1)%maxsize;
        q->data[q->rear]=data;
    }
}
 
//出队操作pop
void pop(cir_queue *q){
    if(q->rear==q->front){
        printf("队列为空，无法出队\n");
        return;
    }else{
        q->data[q->front]=0;
        q->front=(q->front+1)%maxsize;
    }
}
 
//遍历队列
void print(cir_queue *q){
    int i=q->front;
    while(i!=q->rear){
        i=(i+1)%maxsize;
        printf("%d\t",q->data[i]);   
    }
    printf("\n");       //记得换行
}
 
int main(){
    cir_queue *q = init();
    ////////////入队操作///////////////
    printf("入队操作\n");
    for(int i=1;i<=6;i++){
        push(q,i);
    }
    print(q);
    ////////////出队操作///////////////
    printf("出队操作\n");
    for(int i=1;i<=3;i++){
        pop(q);
        print(q);
    }
    return 0;
}