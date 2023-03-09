#include "DynamicArray.h"
int main() {

	Dynamic_Array* arr = Init_Array();
	for (int i = 0; i < 30; i++)
	{
		PushBack_Array(arr, i);
	}

	Print_Array(arr);

	RemoveByPos_Array(arr, 4);
	Print_Array(arr);

	PushBack_Array(arr, 100);
	Print_Array(arr);

	int pos = Find_Array(arr, 100);
	printf("%d\n", pos);
	return 0;
}