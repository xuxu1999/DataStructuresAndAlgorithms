#include "LinkList.h"
typedef struct PERSON {
	char name[50];
	int age;
	int score;
}Person;

void MyPrint(void* date) {
	Person* p = (Person*)date;
	printf("Name:%s Age:%d Socre:%d", p->name, p->age, p->score);
}
int main() {
	LinkList* list = Init_LinkList();

	Person p1 = { "xuxu",23,100 };
	Person p2 = { "xuxu2",21,100 };
	Person p3 = { "xuxu3",18,100 };
	Person p4 = { "xuxu4",29,100 };
	Person p5 = { "xuxu5",23,100 };

	Insert_LinkList(list, 0, &p1);
	Insert_LinkList(list, 0, &p2);
	Insert_LinkList(list, 0, &p3);
	Insert_LinkList(list, 0, &p4);
	Insert_LinkList(list, 0, &p5);

	Print_LinkList(list, MyPrint);
	printf("\n");

	RemoveByPos_LinkList(list, 3);
	Print_LinkList(list, MyPrint);

	Person* ret = (Person*)Front_LinkList(list);
	printf("Name:%s Age:%d Score:%d\n", ret->name, ret->age, ret->score);

	Free_LinkList(list);

	return 0;
}