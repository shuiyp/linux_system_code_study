#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 循环列表链式存储设计与实现





// typedef void CircleList;

// typedef struct CircleListNode
// {
// 	struct CircleListNode* next;
// }sCircleListNode;

// struct Value
// {
// 	sCircleListNode circleNode;
// 	int v;
// };


sCircleLinkList* CircleLinkList_Init(void)
{
	sCircleLinkList *tmpList = NULL;
	sCircleListNode *headNode = NULL;

	tmpList = (sCircleLinkList *)malloc(sizeof(sCircleLinkList) );
	if (tmpList == NULL)
	{
		return NULL;
	}
	memset(tmpList, 0, sizeof(sCircleLinkList) );

	// 创建头结点，是为了空链表和非空链表处理一致
	headNode = (sCircleLinkNode *)malloc(sizeof(sCircleLinkNode) );
	if (headNode == NULL)
	{
		if (tmpList != NULL)
		{
			free(tmpList);
		}
		return NULL;
	}
	headNode->data = NULL;
	headNode->next = NULL;
	// 初始化链表
	tmpList->head = headNode;
	tmpList->rear = headNode;
	tmpList->length = 0;

	return tmpList;
}

// 销毁链表
void CircleLinkList_Destroy(sCircleLinkList* dlist)
{
	sCircleListNode* pCurrent = dlist->head;
	while (pCurrent != dlist->head)
	{
		// 缓存被删除结点的下一个结点
		sCircleListNode* pNext = pCurrent->next;
		free(pCurrent);
		pCurrent = pNext;
	}
	if (dlist != NULL)
	{
		free(dlist);
		dlist = NULL;
	}
}

void CircleList_Clear(CircleList* list)
{

}

int CircleList_Length(CircleList* list)
{
	return 0;
}

int CircleList_Insert(CircleList* list, sCircleListNode* node, int pos)
{

	return 0;
}

sCircleListNode* CircleList_Get(CircleList* list, int pos)
{
	return NULL;
}

sCircleListNode* CircleList_Delete(CircleList* list, int pos)
{
	return NULL;
}



sCircleListNode* CircleList_DeleteNode(CircleList* list, sCircleListNode* node)
{
	return NULL;
}

sCircleListNode* CircleList_Reset(CircleList* list)
{

	return NULL;
}

sCircleListNode* CircleList_Current(CircleList* list)
{
	return NULL;
}

sCircleListNode* CircleList_Next(CircleList* list)
{
	return NULL;
}
















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




int main (int argc, char *argv[])
{
	CircleList* list = CircleList_Create();

	struct Value v1;
	struct Value v2;
	struct Value v3;
	struct Value v4;
	struct Value v5;
	struct Value v6;
	struct Value v7;
	struct Value v8;

	int i = 0;

	v1.v = 1;
	v2.v = 2;
	v3.v = 3;
	v4.v = 4;
	v5.v = 5;
	v6.v = 6;
	v7.v = 7;
	v8.v = 8;

	CircleList_Insert(list, (sCircleListNode*)&v1, 0);
	CircleList_Insert(list, (sCircleListNode*)&v2, 0);
	CircleList_Insert(list, (sCircleListNode*)&v3, 0);
	CircleList_Insert(list, (sCircleListNode*)&v4, 0);

	for (i = 0; i < 2 * CircleList_Length(list); i++)// 怎么样证明是循环链表
	{
		struct Value* pv = (struct Value*)CircleList_Get(list, i);
		printf("%d\n", pv->v);
	}

	while (CircleList_Length(list) > 0)
	{
		CircleList_Delete(list, 0);
	}

	printf("\n");

	CircleList_Destroy(list);

	return 0;
}





