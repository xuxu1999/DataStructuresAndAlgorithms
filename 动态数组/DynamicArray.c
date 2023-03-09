#include "DynamicArray.h"

//初始化动态数组，返回一个保存数组地址，元素个数，容量的结构体
Dynamic_Array* Init_Array()
{
	Dynamic_Array* myArray = (Dynamic_Array*)malloc(sizeof(Dynamic_Array));
	if (myArray) {
		myArray->size = 0;
		myArray->capcity = 20;//初始容量20
		myArray->pAddr = (int*)malloc(sizeof(int) * myArray->capcity);//分配数组大小
		return myArray;
	}
	return NULL;
}



//插入
void PushBack_Array(Dynamic_Array* arr, int value) {

	if (arr) {
		//判断当前数组能否装得下,装不下，开辟新空间扩容
		if (arr->size == arr->capcity) {
			//开辟新的空间数组
			int* newSpace = (int*)malloc(sizeof(int) * arr->capcity * 2);//旧空间两倍
			if (newSpace) {
				//旧空间数据拷贝
				memcpy(newSpace, arr->pAddr, arr->capcity * sizeof(int));//字节拷贝

				//释放旧空间
				free(arr->pAddr);
				arr->pAddr = newSpace;
			}

			
		}

		//上面扩容完，添加元素,size++
		arr->pAddr[arr->size] = value;
		arr->size++;
	}




}

//删除指定位置元素
void RemoveByPos_Array(Dynamic_Array* arr, int pos) {

	if (arr && pos >= 0 && pos < arr->size) {
		//覆盖
		for (; pos < arr->size; pos++) {
			arr->pAddr[pos] = arr->pAddr[pos + 1];
		}
		arr->size--;
	}
	return;

}

//删除指定值得元素
void RemoveByValue_Array(Dynamic_Array* arr, int value) {


	if (arr) {
		int pos = Find_Array(arr, value);
		RemoveByPos_Array(arr, pos);
	}

}

//根据值查找元素，返回元素索引
int Find_Array(Dynamic_Array* arr, int value) {
	int pos = -1;//记录位置
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

//打印动态数组
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













//释放动态数组空间
void FreeSpace_Array(Dynamic_Array* arr) {
	//先要释放里面的数组,再释放结构体
	if (arr) {
		free(arr->pAddr);
		free(arr);
	}
	return;
}









//清理动态数组
void Clean_Array(Dynamic_Array* arr) {
	if (arr) {
		arr->size = 0;
	}
	return;
}









//返回动态数组容量
int Capacity_Array(Dynamic_Array* arr) {
	if (arr == NULL) {
		return -1;
	}
	return arr->capcity;
}

//返回动态数组元素数量
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
