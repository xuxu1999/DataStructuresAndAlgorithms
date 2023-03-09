#ifndef LINK_LIST_H
#define LINK_LIST_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//node
typedef struct LinkNode{

	void* data;//��������������
	struct LinkNode* next;

} LinkNode;

//����������Ϣ
typedef struct LinkList {
	LinkNode* head;
	int size;//Ԫ�ظ���
}LinkList;

//��ʼ������
LinkList* Init_LinkList();

//��������ָ��λ�ã�������������
void Insert_LinkList(LinkList* list, int pos, void* data);

//ɾ��ָ��λ�ýڵ�
void RemoveByPos_LinkList(LinkList* list, int pos);

//����size
int Size_LinkList(LinkList* list);

//����ֵ����,��������
int Find_LinkList(LinkList* list, void* data);

//����ͷ���
void* Front_LinkList(LinkList* list);

typedef void(*PRINTLINKNODE)(void*);
//��ӡָ��������������,��һ������ָ��
void Print_LinkList(LinkList* list, PRINTLINKNODE print);

//�ͷ�����
void Free_LinkList(LinkList* list);




#endif // !LINK_LIST_H
