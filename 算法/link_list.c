#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 线性表链式存储设计与实现


// 优点：
// 无需一次性定制链表的容量
// 插入和删除操作无需移动数据元素
// 缺点：
// 数据元素必须保存后继元素的位置信息
// 获取指定数据的元素操作需要顺序访问之前的元素
// 


typedef void LinkList;

typedef struct LinkListNode
{
	struct LinkListNode* next;
}sLinkListNode;

typedef struct
{
	sLinkListNode header;
	int length;
}sLinkList;

LinkList* LinkList_Create()
{
	sLinkList *tmpList = NULL;

	tmpList = (sLinkList *)malloc(sizeof(sLinkList) );
	if (tmpList == NULL)
	{
		return NULL;
	}
	memset(tmpList, 0, sizeof(sLinkList) );
	tmpList->header.next = NULL;
	tmpList->length = 0;

	return tmpList;
}

void LinkList_Destroy(LinkList* list)
{
	if (list != NULL)
	{
		free(list);
		list = NULL;
	}
}

// 让链表恢复到初始化状态
void LinkList_Clear(LinkList* list)
{
	sLinkList * tmpList = NULL;

	if (list == NULL)
	{
		return ;
	}
	tmpList = (sLinkList *)list;
	tmpList->length = 0;
	tmpList->header.next = NULL;
}

int LinkList_Length(LinkList* list)
{
	sLinkList *tmpList = NULL;

	if (list == NULL)
	{
		return 0;
	}
	tmpList = (sLinkList *)list;

	return tmpList->length;
}

int LinkList_Insert(LinkList* list, sLinkListNode* node, int pos)
{
	int ret = 0, i = 0;
	sLinkList *tmpList = NULL;
	sLinkListNode *current = NULL;

	if (list == NULL || node == NULL || pos < 0)
	{
		ret = -1;
		printf("func LinkList_Insert() err: %d\n", ret);
		return ret;
	}
	tmpList = (sLinkList *)list;
	current = &(tmpList->header);

	// 防止 pos的位置超过链表的长度
	for (i = 0; i < pos && (current->next != NULL); i++)
	{
		current = current->next;
	}
	// 1 让 node 连接后续链表
	node->next = current->next;
	// 2 让前面的链表 连接新的 Node 节点
	current->next = node;

	tmpList->length++;

	return 0;
}

sLinkListNode* LinkList_Get(LinkList* list, int pos)
{
	int ret = 0, i = 0;
	sLinkList *tmpList = NULL;
	sLinkListNode *current = NULL;

	if (list == NULL || pos < 0)
	{
		ret = -1;
		printf("func LinkList_Insert() err: %d\n", ret);
		return NULL;
	}
	tmpList = (sLinkList *)list;
	current = &(tmpList->header);// 让辅助指针变量指向链表的头部

	// 防止 pos的位置超过链表的长度
	for (i = 0; i < pos && (current->next != NULL); i++)
	{
		current = current->next;
	}
	return current->next;
}

sLinkListNode* LinkList_Delete(LinkList* list, int pos)
{
	int i = 0;
	sLinkList *tmpList = NULL;
	sLinkListNode *current = NULL;
	sLinkListNode *ret = NULL;

	if (list == NULL || pos < 0)
	{
		return NULL;
	}
	tmpList = (sLinkList *)list;
	current = &(tmpList->header);// 让辅助指针变量指向链表的头部

	// 防止 pos的位置超过链表的长度
	for (i = 0; i < pos && (current->next != NULL); i++)
	{
		current = current->next;
	}
	// 缓存被删除的节点位置
	ret = current->next;
	// 连线
	current->next = ret->next;

	tmpList->length--;

	return ret;
}


typedef struct Teacher
{
	sLinkListNode node;
    int age;
    char name[64];
}sTeacher;

int main (int argc, char *argv[])
{
	LinkList* tmpList = NULL;
	int len = 0, ret = 0, i = 0;
	sTeacher t1, t2, t3, t4, t5;
	sTeacher* tmpTeacher = NULL;
    
    t1.age = 31;
    t2.age = 32;
    t3.age = 33;
    t4.age = 34;
    t5.age = 35;

	tmpList = LinkList_Create();
	if (tmpList == NULL)
	{
		return 0;
	}

	len = LinkList_Length(tmpList);

	// 链表的算法和具体业务节点的分离
	LinkList_Insert(tmpList, (sLinkListNode *)&t1, 0);
	LinkList_Insert(tmpList, (sLinkListNode *)&t2, 0);
	LinkList_Insert(tmpList, (sLinkListNode *)&t3, 0);
	LinkList_Insert(tmpList, (sLinkListNode *)&t4, 0);
	LinkList_Insert(tmpList, (sLinkListNode *)&t5, 0);

	// 遍历
	for (i = 0; i < LinkList_Length(tmpList); i++)
	{
		tmpTeacher = (sTeacher *)LinkList_Get(tmpList, i);
		if (tmpTeacher == NULL)
		{
			return -1;
		}
		printf("tmpTeacher->age = %d\n", tmpTeacher->age);
	}

	// 删除链表
	while (LinkList_Length(tmpList) > 0)
	{
		tmpTeacher = (sTeacher *)LinkList_Delete(tmpList, 0);
		if (tmpTeacher == NULL)
		{
			return -1;
		}
	}

	LinkList_Destroy(tmpList);

	return 0;
}





