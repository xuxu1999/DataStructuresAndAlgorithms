#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct DYNAMICARRAY {
	int* pAddr;//�����ַ
	int size;//Ԫ�ظ���
	int capcity;//����
} Dynamic_Array;

//��ʼ��
Dynamic_Array* Init_Array();

//����
void PushBack_Array(Dynamic_Array* arr, int value);

//ɾ��ָ��λ��Ԫ��
void RemoveByPos_Array(Dynamic_Array* arr, int pos);

//ɾ��ָ��ֵ��Ԫ��
void RemoveByValue_Array(Dynamic_Array* arr, int value);

//����ֵ����Ԫ�أ�����Ԫ������
int Find_Array(Dynamic_Array* arr, int value);

//��ӡ��̬����
void Print_Array(Dynamic_Array* arr);

//�ͷŶ�̬����ռ�
void FreeSpace_Array(Dynamic_Array* arr);

//����̬����
void Clean_Array(Dynamic_Array* arr);

//���ض�̬��������
int Capacity_Array(Dynamic_Array* arr);

//���ض�̬����Ԫ������
int Size_Array(Dynamic_Array* arr);

//����ָ������Ԫ��
int At_Array(Dynamic_Array* arr, int pos);
#endif // !DYNAMIC_ARRAY_H
