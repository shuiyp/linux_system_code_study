#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//在结构体中套 1 级指针
typedef struct
{
	int length;
	int capacity;
	unsigned int *pNode;
}sSeqList;

typedef void sSeqListNode;

sSeqList* SeqList_Create (int capacity)
{
	sSeqList *tmp = NULL;
	int ret = 0;

	tmp = (sSeqList *)malloc(sizeof(sSeqList) );
	if (tmp == NULL)
	{
		ret = -1;
		printf("func SeqList_Create() err : %d\n", ret);
		return NULL;
	}
	memset(tmp, 0, sizeof(sSeqList) );
	//根据 capacity 的大小分配节点的空间
	tmp->pNode = (unsigned int *)malloc(sizeof(unsigned int *) * capacity);
	if (tmp->pNode == NULL)
	{
		ret = -2;
		printf("func SeqList_Create() err: malloc err %d\n", ret);
		return NULL;
	}

	tmp->capacity = capacity;
	tmp->length = 0;

	return tmp;
}

int SeqList_Destory (sSeqList* list)
{
	sSeqList *tmpList = NULL;

	if (list == NULL)
	{
		return -1;
	}
	tmpList = (sSeqList *)list;
	if (tmpList->pNode != NULL)
	{
		free(tmpList->pNode);
	}
	free(tmpList);
	return 0;
}

//清空链表，回到初始化状态
int SeqList_Clear (sSeqList* list)
{
	sSeqList *tmpList = NULL;

	if (list == NULL)
	{
		return -1;
	}
	tmpList = (sSeqList *)list;
	tmpList->length = 0;
	return 0;
}

int SeqList_Length (sSeqList* list)
{
	sSeqList *tmpList = NULL;

	if (list == NULL)
	{
		return -1;
	}
	tmpList = (sSeqList *)list;
	return tmpList->length;
}

int SeqList_Capacity (sSeqList* list)
{
	sSeqList *tmpList = NULL;

	if (list == NULL)
	{
		return -1;
	}
	tmpList = (sSeqList *)list;
	return tmpList->capacity;
}

int SeqList_Insert (sSeqList* list, sSeqListNode* node, int pos)
{
	sSeqList *tmpList = NULL;
	int i = 0, ret = 0;

	if (list == NULL || node == NULL || pos < 0)
	{
		ret = -1;
		printf("func SeqList_Insert() err: %d\n", ret);
		return ret;
	}
	tmpList = (sSeqList *)list;

	//判断是不是满了
	if (tmpList->length >= tmpList->capacity)
	{
		ret = -2;
		printf("func SeqList_Insert() mpList->length >= tmpList->capacity err: %d\n", ret);
		return ret;
	}

	//容错修正 6个长度 容量20；用户Pos10位置插入...
	if (pos >= tmpList->length)
	{
		pos = tmpList->length;
	}

	//1 元素后移
	for (i = tmpList->length; i > pos; i--)
	{
		tmpList->pNode[i] = tmpList->pNode[i - 1];
	}
	//2 插入元素
	tmpList->pNode[i] = (unsigned int)node;
	tmpList->length++;
	return 0;
}

sSeqListNode* SeqList_Get (sSeqList* list, int pos)
{
	sSeqList *tmpList = NULL;
	int i = 0;
	sSeqListNode *ret = 0;

	if (list == NULL || pos < 0)
	{
		printf("func SeqList_Get() err: %d\n", -1);
		return NULL;
	}
	tmpList = (sSeqList *)list;

	ret = (void *)tmpList->pNode[pos];
	return ret;
}

sSeqListNode* SeqList_Delete (sSeqList* list, int pos)
{
	sSeqList *tmpList = NULL;
	sSeqListNode *ret = 0;
	int i = 0;

	if (list == NULL || pos < 0)
	{
		printf("func SeqList_Delete() err: %d\n", -1);
		return NULL;
	}
	tmpList = (sSeqList *)list;

	ret = (sSeqListNode *)tmpList->pNode[pos];// 缓存pos位置
	for (i = pos + 1; i < tmpList->length; i++)//pos后面的元素前移
	{
		tmpList->pNode[i - 1] = tmpList->pNode[i];
	}
	tmpList->length--;
	return ret;
}


int main (int argc, char *argv[])
{


}






