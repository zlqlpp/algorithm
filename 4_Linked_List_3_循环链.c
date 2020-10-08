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
typedef struct list{
    int data;
    struct list *next;
}list;
//data为存储的数据，next指针为指向下一个结点
 
//初始结点
list *initlist(){
    list *head=(list*)malloc(sizeof(list));
    if(head==NULL){
        printf("创建失败，退出程序");
        exit(0);
    }else{
        head->next=NULL;
        return head;
    }
}
 
//创建--插入数据
int create_list(list *head){
    int data;   //插入的数据类型
    printf("请输入要插入的元素：");
    scanf("%d",&data);
 
    list *node=initlist();
    node->data=data;
    //初始化一个新的结点，准备进行链接
 
    if(head!=NULL){
        list *p=head;
        //找到最后一个数据
        while(p->next!=head){
            p=p->next;
        }
        p->next=node;
        node->next=head;
        return 1;
    }else{
        printf("头结点已无元素\n");
        return 0;
    }
 
}
 
//插入元素
list *insert_list(list *head,int pos,int data){
    //三个参数分别是链表，位置，参数
    list *node=initlist();  //新建结点
    list *p=head;       //p表示新的链表
    list *t;
    t=p;
    node->data=data;
    if(head!=NULL){
        for(int i=1;i<=pos;i++){
            t=t->next;
        }
        node->next=t->next;
        t->next=node;
        return p;
    }
    return p;
}
 
//删除元素
int delete_list(list *head) {
    if(head == NULL) {
        printf("链表为空！\n");
        return 0;
    }
    //建立零时结点存储头结点信息（目的为了找到退出点）
    //如果不这么建立的化需要使用一个数据进行计数标记，计数达到链表长度时自动退出
    //循环链表当找到最后一个元素的时候会自动指向头元素，这是我们不想让他发生的
    list *temp = head;          
    list *ptr = head->next;
 
    int del;
    printf("请输入你要删除的元素：");
    scanf("%d",&del);
 
    while(ptr != head) {
        if(ptr->data == del) {
            if(ptr->next == head) { //循环结束的条件换成ptr->next == head
                temp->next = head;
                free(ptr);
                return 1;
            }
            temp->next = ptr->next;
            free(ptr);
            //printf("元素删除成功！\n");
            return 1;
        }
        temp = temp->next;
        ptr = ptr->next;
    }
    printf("没有找到要删除的元素\n");
    return 0;
}
 
 
//遍历元素
int display(list *head) {
    if(head != NULL) {
        list *p  = head;
        //遍历头节点到，最后一个数据
        while(p->next != head ) {
            printf("%d   ",p->next->data);
            p = p->next;
        }
        printf("\n");   //习惯性换行 ( o=^•ェ•)o　┏━┓
        //把最后一个节点赋新的节点过去
        return 1;
    } else {
        printf("头结点为空!\n");
        return 0;
    }
}
 
int main(){
    //////////初始化头结点//////////////
    list *head=initlist();
    head->next=head;
    ////////通过插入元素完善链表/////////
    for(int i=0;i<5;i++){   //只是演示使用，不具体提供输入
        create_list(head);
    }
    display(head);
    ////////////插入元素////////////////
    head=insert_list(head,1,10);
    display(head);
    ////////////删除元素////////////////
    delete_list(head);
    display(head);
    return 0;
}