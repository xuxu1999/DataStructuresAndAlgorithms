#include"LinkList.h"
//初始化链表
LinkList* Init_LinkList() {
	//分配list,只有head和size信息
	LinkList* list = (LinkList*)malloc(sizeof(LinkList));

	if (list) {
		list->size = 0;
		//分配头结点
		list->head = (LinkNode*)malloc(sizeof(LinkNode));
		if (list->head) {
			list->head->data = NULL;
			list->head->next = NULL;
			return list;
		}
		return NULL;
	}
	return NULL;

}

//插入链表指定位置，任意数据类型
void Insert_LinkList(LinkList* list, int pos, void* data) {
	if (list == NULL) {
		return;
	}
	if (data = NULL) {
		return;
	}
	if (pos<0 || pos>list->size) {
		pos = list->size;
	}
	//生成新节点
	LinkNode* newNode = (LinkNode*)malloc(sizeof(LinkNode));
	if (newNode) {
		newNode->data = data;
		newNode->next = NULL;

		LinkNode* pCurrent = list->head;
		for (int i = 0; i < pos; i++) {
			pCurrent = pCurrent->next;
		}
		newNode->next = pCurrent->next;
		pCurrent->next = newNode;

		list->size++;
	}

	
}

//删除指定位置节点
void RemoveByPos_LinkList(LinkList* list, int pos) {
	
	if (list && (pos > 0 && pos < list->size)) {
		LinkNode* pCurrent = list->head;
		for (int i = 0; i < pos; i++)
		{
			pCurrent = pCurrent->next;
		}
		LinkNode* pDel = pCurrent->next;
		pCurrent->next = pDel->next;
		free(pDel);
		list->size--;
	}
	return;

}

//链表size
int Size_LinkList(LinkList* list) {
	if (list) {
		return list->size;
	}
	return -1;
}

//根据值查找,返回索引
int Find_LinkList(LinkList* list, void* data) {
	if (list && data) {
		LinkNode* pCurrent = list->head->next;
		int i = 0;
		while (pCurrent) {
			if (pCurrent->data == data) {
				break;
			}
			i++;
			pCurrent = pCurrent->next;
		}
		return i;
	}
	return -1;
}

//返回头结点数据
void* Front_LinkList(LinkList* list) {
	if(list){
		return list->head->data;
	}
	return;
}

typedef void(*PRINTLINKNODE)(void*);
//打印指定数据类型链表,用户自定义打印print函数
void Print_LinkList(LinkList* list, PRINTLINKNODE print) {

	if (list) {
		LinkNode* pCurrent = list->head->next;
		while (pCurrent) {
			print(pCurrent->data);
			pCurrent = pCurrent->next;
		}
	}
	return;
}

//释放链表
void Free_LinkList(LinkList* list) {

	if (list) {
		LinkNode* pCurrent = list->head;
		while (pCurrent) {
			LinkNode* pNext = pCurrent->next;
			free(pCurrent);
			pCurrent = pNext;
		}
		free(list);
	}
}