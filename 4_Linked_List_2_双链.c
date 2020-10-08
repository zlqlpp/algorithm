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
typedef struct line{
    int data;           //data
    struct line *pre;   //pre node
    struct line *next;  //next node
}line;
//分别表示该结点的前驱(pre)，后继(next)，以及当前数据(data)
 
//遍历双链表,同时打印元素数据
void printLine(line *head){
    line *list = head;
    int pos=1;
    while(list){
        printf("第%d个数据是:%d\n",pos++,list->data);
        list=list->next;
    }
}
 
//创建双链表
line* initLine(line * head){
    int number,pos=1,input_data;
    printf("请输入创建结点的大小\n");
    scanf("%d",&number);
    if(number<1){return NULL;} //输入非法直接结束
    //////头结点创建///////
    head=(line*)malloc(sizeof(line));
    head->pre=NULL;
    head->next=NULL;
    printf("输入第%d个数据\n",pos++);
    scanf("%d",&input_data);
    head->data=input_data;
 
    line * list=head;
    while (pos<=number) {
        line * body=(line*)malloc(sizeof(line));
        body->pre=NULL;
        body->next=NULL;
        printf("输入第%d个数据\n",pos++);
        scanf("%d",&input_data);
        body->data=input_data;
        
        list->next=body;
        body->pre=list;
        list=list->next;
    }
    return head;
}
 
//插入数据
line * insertLine(line * head,int data,int add){
    //三个参数分别为：进行此操作的双链表，插入的数据，插入的位置
    //新建数据域为data的结点
    line * temp=(line*)malloc(sizeof(line));
    temp->data=data;
    temp->pre=NULL;
    temp->next=NULL;
    //插入到链表头，要特殊考虑
    if (add==1) {
        temp->next=head;
        head->pre=temp;
        head=temp;
    }else{
        line * body=head;
        //找到要插入位置的前一个结点
        for (int i=1; i<add-1; i++) {
            body=body->next;
        }
        //判断条件为真，说明插入位置为链表尾
        if (body->next==NULL) {
            body->next=temp;
            temp->pre=body;
        }else{
            body->next->pre=temp;
            temp->next=body->next;
            body->next=temp;
            temp->pre=body;
        }
    }
    return head;
}
 
//删除元素
line * deleteLine(line * head,int data){
    //输入的参数分别为进行此操作的双链表，需要删除的数据
    line * list=head;
    //遍历链表
    while (list) {
        //判断是否与此元素相等
        //删除该点方法为将该结点前一结点的next指向该节点后一结点
        //同时将该结点的后一结点的pre指向该节点的前一结点
        if (list->data==data) {
            list->pre->next=list->next;
            list->next->pre=list->pre;
            free(list);
            printf("--删除成功--\n");
            return head;
        }
        list=list->next;
    }
    printf("Error:没有找到该元素，没有产生删除\n");
    return head;
}
 
int main(){
    line *head=NULL;
    printf("创建双链表操作\n"); 
    head=initLine(head);
    printLine(head);
//////////create line////////////
    printf("插入操作\n"); 
    head=insertLine(head,40,2);     //为了简化直接写参数了
    printLine(head);
//////////insert Line////////////
    printf("删除操作\n"); 
    head=deleteLine(head,2);       //为了简化直接写参数了
    printLine(head);
//////////delete Line////////////  
    return 0;
}