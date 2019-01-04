#ifndef CIRCLE_LINK_LIST_H
#define CIRCLE_LINK_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef void(*CIRCLEPRINT)(void*);
#define CIRCLE_TRUE   1
#define CIRCLE_FALSE  0

// 循环链表结点
typedef struct _CircleLinkNode
{
	void* data;
	struct _CircleLinkNode* next;
}sCircleLinkNode;

// 链表
typedef struct _DoubleLinkList
{
	sCircleLinkNode* head;// 头结点
	sCircleLinkNode* rear;// 尾结点
	int length;
}sCircleLinkList;


// 循环链表初始化
sCircleLinkList* CircleLinkList_Init(void);
// 循环链表插入数据
void CricleLinkList_Insert(sCircleLinkList* dlist, int pos, void* data);
// 循环链表删除数据
void CircleLinkList_Delete(sCircleLinkList* dlist, int pos);
// 销毁链表
void CircleLinkList_Destroy(sCircleLinkList* dlist);
// 打印链表
void CircleLinkList_Print(sCircleLinkList* dlist, CIRCLEPRINT print);
// 获得链表长度
int CircleLinkList_Length(sCircleLinkList* dlist);
// 清空链表
void CircleLinkList_Clear(sCircleLinkList* dlist);


#endif