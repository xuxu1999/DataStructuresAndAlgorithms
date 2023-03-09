#include "DynamicArray.h"

//��ʼ����̬���飬����һ�����������ַ��Ԫ�ظ����������Ľṹ��
Dynamic_Array* Init_Array()
{
	Dynamic_Array* myArray = (Dynamic_Array*)malloc(sizeof(Dynamic_Array));
	if (myArray) {
		myArray->size = 0;
		myArray->capcity = 20;//��ʼ����20
		myArray->pAddr = (int*)malloc(sizeof(int) * myArray->capcity);//���������С
		return myArray;
	}
	return NULL;
}



//����
void PushBack_Array(Dynamic_Array* arr, int value) {

	if (arr) {
		//�жϵ�ǰ�����ܷ�װ����,װ���£������¿ռ�����
		if (arr->size == arr->capcity) {
			//�����µĿռ�����
			int* newSpace = (int*)malloc(sizeof(int) * arr->capcity * 2);//�ɿռ�����
			if (newSpace) {
				//�ɿռ����ݿ���
				memcpy(newSpace, arr->pAddr, arr->capcity * sizeof(int));//�ֽڿ���

				//�ͷžɿռ�
				free(arr->pAddr);
				arr->pAddr = newSpace;
			}

			
		}

		//���������꣬���Ԫ��,size++
		arr->pAddr[arr->size] = value;
		arr->size++;
	}




}

//ɾ��ָ��λ��Ԫ��
void RemoveByPos_Array(Dynamic_Array* arr, int pos) {

	if (arr && pos >= 0 && pos < arr->size) {
		//����
		for (; pos < arr->size; pos++) {
			arr->pAddr[pos] = arr->pAddr[pos + 1];
		}
		arr->size--;
	}
	return;

}

//ɾ��ָ��ֵ��Ԫ��
void RemoveByValue_Array(Dynamic_Array* arr, int value) {


	if (arr) {
		int pos = Find_Array(arr, value);
		RemoveByPos_Array(arr, pos);
	}

}

//����ֵ����Ԫ�أ�����Ԫ������
int Find_Array(Dynamic_Array* arr, int value) {
	int pos = -1;//��¼λ��
	if (arr) {
		for (int i = 0; i < arr->size; i++) {
			if (arr->pAddr[i] == value) {
				pos = i;
				return pos;
				break;
			}
		}
	}
	return -1;


}

//��ӡ��̬����
void Print_Array(Dynamic_Array* arr) {

	if (arr) {
		for (int i = 0; i < arr->size; i++)
		{	
			printf("%d ", arr->pAddr[i]);
		}
		printf("\n");
	}
	return;


}













//�ͷŶ�̬����ռ�
void FreeSpace_Array(Dynamic_Array* arr) {
	//��Ҫ�ͷ����������,���ͷŽṹ��
	if (arr) {
		free(arr->pAddr);
		free(arr);
	}
	return;
}









//����̬����
void Clean_Array(Dynamic_Array* arr) {
	if (arr) {
		arr->size = 0;
	}
	return;
}









//���ض�̬��������
int Capacity_Array(Dynamic_Array* arr) {
	if (arr == NULL) {
		return -1;
	}
	return arr->capcity;
}

//���ض�̬����Ԫ������
int Size_Array(Dynamic_Array* arr) {

	if (arr == NULL) {
		return -1;
	}
	return arr->size;
}







int At_Array(Dynamic_Array* arr, int pos) {
	if (arr == NULL || pos<0 || pos>arr->size) {
		return -1;
	}
	return arr->pAddr[pos];
}
