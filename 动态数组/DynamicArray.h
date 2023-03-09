#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct DYNAMICARRAY {
	int* pAddr;//数组地址
	int size;//元素个数
	int capcity;//容量
} Dynamic_Array;

//初始化
Dynamic_Array* Init_Array();

//插入
void PushBack_Array(Dynamic_Array* arr, int value);

//删除指定位置元素
void RemoveByPos_Array(Dynamic_Array* arr, int pos);

//删除指定值得元素
void RemoveByValue_Array(Dynamic_Array* arr, int value);

//根据值查找元素，返回元素索引
int Find_Array(Dynamic_Array* arr, int value);

//打印动态数组
void Print_Array(Dynamic_Array* arr);

//释放动态数组空间
void FreeSpace_Array(Dynamic_Array* arr);

//清理动态数组
void Clean_Array(Dynamic_Array* arr);

//返回动态数组容量
int Capacity_Array(Dynamic_Array* arr);

//返回动态数组元素数量
int Size_Array(Dynamic_Array* arr);

//返回指定索引元素
int At_Array(Dynamic_Array* arr, int pos);
#endif // !DYNAMIC_ARRAY_H
