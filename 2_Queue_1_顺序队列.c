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
//结点定义
typedef struct node{
    int data;
    struct node *next;
}node;
//队列定义，队首指针和队尾指针
typedef struct queue{
    node *front;
    node *rear;
}queue;
 
//初始化结点
node *init_node(){
    node *n=(node*)malloc(sizeof(node));
    if(n==NULL){    //建立失败，退出
        exit(0);
    }
    return n;
}
 
//初始化队列
queue *init_queue(){
    queue *q=(queue*)malloc(sizeof(queue));
    if(q==NULL){    //建立失败，退出
        exit(0);
    }
    //头尾结点均赋值NULL
    q->front=NULL;  
    q->rear=NULL;
    return q;
}
 
//队列判空
int empty(queue *q){
    if(q->front==NULL){
        return 1;   //1--表示真，说明队列非空
    }else{
        return 0;   //0--表示假，说明队列为空
    }
}
 
//入队操作
void push(queue *q,int data){
    node *n =init_node();
    n->data=data;
    n->next=NULL;   //采用尾插入法
    //if(q->rear==NULL){  
    if(empty(q)){
        q->front=n;
        q->rear=n;
    }else{
        q->rear->next=n;    //n成为当前尾结点的下一结点
        q->rear=n;  //让尾指针指向n
    }
}
 
//出队操作
void pop(queue *q){
    node *n=q->front;
    if(empty(q)){
        return ;    //此时队列为空，直接返回函数结束
    }
    if(q->front==q->rear){
        q->front=NULL;  //只有一个元素时直接将两端指向制空即可
        q->rear=NULL;
        free(n);        //记得归还内存空间
    }else{
        q->front=q->front->next;
        free(n);
    }
}
 
//打印队列元素
void print_queue(queue *q){
    node *n = init_node();
    n=q->front;
    if(empty(q)){
        return ;    //此时队列为空，直接返回函数结束
    }
    while (n!=NULL)
    {
        printf("%d\t",n->data);
        n=n->next;
    }
    printf("\n");   //记得换行
}
 
//主函数调用，这里只是简单介绍用法
int main(){
    queue *q=init_queue();
    ///////////////入队操作/////////////////
    printf("入队\n");
    for(int i=1;i<=5;i++){
        push(q,i);
        print_queue(q);
    }
    ///////////////出队操作/////////////////
    printf("出队\n");
    for(int i=1;i<=5;i++){
        pop(q);
        print_queue(q);
    }
    return 0;
}