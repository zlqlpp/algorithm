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


#include <stdio.h>
#include <stdlib.h>
 
//定义结点类型
typedef struct Node {
    int data;           //数据类型，你可以把int型的data换成任意数据类型，包括结构体struct等复合类型
    struct Node *next;          //单链表的指针域
} Node,*LinkedList;
 
//单链表的初始化
LinkedList LinkedListInit() {
    Node *L;
    L = (Node *)malloc(sizeof(Node));   //申请结点空间
    if(L==NULL){    //判断申请空间是否失败
        exit(0);    //如果失败则退出程序
    }
    L->next = NULL;          //将next设置为NULL,初始长度为0的单链表
    return L;
}
 
 
//单链表的建立1，头插法建立单链表
LinkedList LinkedListCreatH() {
    Node *L;
    L = (Node *)malloc(sizeof(Node));   //申请头结点空间
    L->next = NULL;                      //初始化一个空链表
 
    int x;                         //x为链表数据域中的数据
    while(scanf("%d",&x) != EOF) {
        Node *p;
        p = (Node *)malloc(sizeof(Node));   //申请新的结点
        p->data = x;                     //结点数据域赋值
        p->next = L->next;                    //将结点插入到表头L-->|2|-->|1|-->NULL
        L->next = p;
    }
    return L;
}
 
 
//单链表的建立2，尾插法建立单链表
 
LinkedList LinkedListCreatT() {
    Node *L;
    L = (Node *)malloc(sizeof(Node));   //申请头结点空间
    L->next = NULL;                  //初始化一个空链表
    Node *r;
    r = L;                          //r始终指向终端结点，开始时指向头结点
    int x;                         //x为链表数据域中的数据
    while(scanf("%d",&x) != EOF) {
        Node *p;
        p = (Node *)malloc(sizeof(Node));   //申请新的结点
        p->data = x;                     //结点数据域赋值
        r->next = p;                 //将结点插入到表头L-->|1|-->|2|-->NULL
        r = p;
    }
    r->next = NULL;
 
    return L;
}
 
 
//单链表的插入，在链表的第i个位置插入x的元素
 
LinkedList LinkedListInsert(LinkedList L,int i,int x) {
    Node *pre;                      //pre为前驱结点
    pre = L;
    int tempi = 0;
    for (tempi = 1; tempi < i; tempi++) {
        pre = pre->next;                 //查找第i个位置的前驱结点
    }
    Node *p;                                //插入的结点为p
    p = (Node *)malloc(sizeof(Node));
    p->data = x;
    p->next = pre->next;
    pre->next = p;
 
    return L;
}
 
 
//单链表的删除，在链表中删除值为x的元素
 
LinkedList LinkedListDelete(LinkedList L,int x) {
    Node *p,*pre;                   //pre为前驱结点，p为查找的结点。
    p = L->next;
     
    while(p->data != x) {              //查找值为x的元素
        pre = p;
        p = p->next;
    }
    pre->next = p->next;          //删除操作，将其前驱next指向其后继。
    free(p);
     
    return L;
}
 
//链表内容的修改，再链表中修改值为x的元素变为为k。
LinkedList LinkedListReplace(LinkedList L,int x,int k) {
    Node *p=L->next;
    int i=0;
    while(p){
        if(p->data==x){
            p->data=k;
        }
        p=p->next;
    }
    return L;
}
 
 
//便利输出单链表
void printList(LinkedList L){
    Node *p=L->next;
    int i=0;
    while(p){
        printf("第%d个元素的值为:%d\n",++i,p->data);
        p=p->next;
    }
} 
 
int main() {
    //创建 
    LinkedList list;
    printf("请输入单链表的数据：以EOF结尾\n");
    list = LinkedListCreatT();
    //list=LinkedListCreatT();
    printList(list);
     
    //插入 
    int i;
    int x;
    printf("请输入插入数据的位置：");
    scanf("%d",&i);
    printf("请输入插入数据的值：");
    scanf("%d",&x);
    LinkedListInsert(list,i,x);
    printList(list);
     
    //修改
    printf("请输入修改的数据：");
    scanf("%d",&i);
    printf("请输入修改后的值：");
    scanf("%d",&x);
    LinkedListReplace(list,i,x);
    printList(list);
     
    //删除 
    printf("请输入要删除的元素的值：");
    scanf("%d",&x);
    LinkedListDelete(list,x);
    printList(list);
 
    return 0;
}