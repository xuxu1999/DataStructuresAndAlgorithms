#include"LinkList.h"
//��ʼ������
LinkList* Init_LinkList() {
	//����list,ֻ��head��size��Ϣ
	LinkList* list = (LinkList*)malloc(sizeof(LinkList));

	if (list) {
		list->size = 0;
		//����ͷ���
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

//��������ָ��λ�ã�������������
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
	//�����½ڵ�
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

//ɾ��ָ��λ�ýڵ�
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

//����size
int Size_LinkList(LinkList* list) {
	if (list) {
		return list->size;
	}
	return -1;
}

//����ֵ����,��������
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

//����ͷ�������
void* Front_LinkList(LinkList* list) {
	if(list){
		return list->head->data;
	}
	return;
}

typedef void(*PRINTLINKNODE)(void*);
//��ӡָ��������������,�û��Զ����ӡprint����
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

//�ͷ�����
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