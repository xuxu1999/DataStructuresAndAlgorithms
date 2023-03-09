#ifndef LINK_LIST_H
#define LINK_LIST_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//node
typedef struct LinkNode{

	void* data;//存任意类型数据
	struct LinkNode* next;

} LinkNode;

//单项链表信息
typedef struct LinkList {
	LinkNode* head;
	int size;//元素个数
}LinkList;

//初始化链表
LinkList* Init_LinkList();

//插入链表指定位置，任意数据类型
void Insert_LinkList(LinkList* list, int pos, void* data);

//删除指定位置节点
void RemoveByPos_LinkList(LinkList* list, int pos);

//链表size
int Size_LinkList(LinkList* list);

//根据值查找,返回索引
int Find_LinkList(LinkList* list, void* data);

//返回头结点
void* Front_LinkList(LinkList* list);

typedef void(*PRINTLINKNODE)(void*);
//打印指定数据类型链表,传一个函数指针
void Print_LinkList(LinkList* list, PRINTLINKNODE print);

//释放链表
void Free_LinkList(LinkList* list);




#endif // !LINK_LIST_H
