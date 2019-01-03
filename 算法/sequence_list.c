#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// 线性表定义：
// 线性表（List）是零个或多个数据元素的集合；
// 线性表中的数据元素之间是有顺序的；
// 线性表中的数据元素个数是有限的；
// 线性表中的数据元素的类型必须相同。

// 优点：
// 无需为线性表中的逻辑关系增加额外的空间
// 可以快速的获取表中合法位置的元素
// 缺点：
// 插入和删除操作需要移动大量元素；
// 当线性表长度变化较大时，难以确定存储空间的容量


//typedef void sSeqList;
//typedef void sSeqListNode;

//在结构体中套 1 级指针
typedef struct SeqList
{
    int length;
    int capacity;
    unsigned int **pNode;
}sSeqList;




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
    
    // 根据 capacity 的大小分配节点的空间
    tmp->pNode = (unsigned int **)malloc(sizeof(unsigned int *) * capacity);
    if (tmp->pNode == NULL)
    {
        ret = -2;
        printf("func SeqList_Create() err: malloc err %d\n", ret);
        return NULL;
    }
    
    tmp->capacity = capacity;
    tmp->length = 0;
    printf("SeqList_Create() sucess. sizeof(sSeqList) = %lu\n", sizeof(sSeqList) );
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

int SeqList_Insert (sSeqList* list, void* node, int pos)
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
    tmpList->pNode[i] = node;
    tmpList->length++;
    return 0;
}

void* SeqList_Get (sSeqList* list, int pos)
{
    sSeqList *tmpList = NULL;
    int i = 0;
    void* ret = NULL;
    
    if (list == NULL || pos < 0)
    {
        printf("func SeqList_Get() err: %d\n", -1);
        return NULL;
    }
    tmpList = (sSeqList *)list;
    
    ret = tmpList->pNode[pos];
    return ret;
}

void* SeqList_Delete (sSeqList* list, int pos)
{
    sSeqList *tmpList = NULL;
    int i = 0;
    void* ret = 0;
    
    
    if (list == NULL || pos < 0)
    {
        printf("func SeqList_Delete() err: %d\n", -1);
        return NULL;
    }
    tmpList = (sSeqList *)list;
    
    ret = &tmpList->pNode[pos];// 缓存pos位置
    for (i = pos + 1; i < tmpList->length; i++)//pos后面的元素前移
    {
        tmpList->pNode[i - 1] = tmpList->pNode[i];
    }
    tmpList->length--;
    return ret;
}

void SeqList_Printf (sSeqList* list)
{
    int i = 0;
    
    for (i = 0; i < list->length; i++)
    {
        // printf("%d\n", list->pNode[i]);
    }
}

typedef struct Teacher
{
    int age;
    char name[64];
}sTeacher;


int main (int argc, char *argv[])
{
    int ret = 0, i = 0;
    sSeqList* tmpList = NULL;
    sTeacher t1, t2, t3, t4, t5;
    sTeacher* tmpTeacher = NULL;
    
    t1.age = 3333333;
    printf("t1.age = %d\n", t1.age);
    // t1.name = "aaaa";
    t2.age = 32;
    // t2.name = "bbbb";
    t3.age = 33;
    // t3.name = "cccc";
    t4.age = 34;
    // t4.name = "dddd";
    t5.age = 35;
    // t5.name = "eeee";
    
    tmpList = SeqList_Create(10);
    if (tmpList == NULL)
    {
        printf("func SeqList_Create() ret : %d\n", ret);
    }
    
    ret = SeqList_Insert (tmpList, &t1, 0);
    printf("插入 1 个数据, 链表长度为 %d\n", SeqList_Length(tmpList) );
    
    tmpTeacher = (sTeacher *)SeqList_Get(tmpList, 0);
    printf("tmpTeacher->age:%d\n", tmpTeacher->age);
    printf("tmpTeacher->name:%s\n", tmpTeacher->name);
    
    ret = SeqList_Insert (tmpList, &t2, 1);
    printf("插入 1 个数据, 链表长度为 %d\n", SeqList_Length(tmpList) );
    ret = SeqList_Insert (tmpList, &t3, 2);
    printf("插入 1 个数据, 链表长度为 %d\n", SeqList_Length(tmpList) );
    ret = SeqList_Insert (tmpList, &t4, 3);
    printf("插入 1 个数据, 链表长度为 %d\n", SeqList_Length(tmpList) );
    ret = SeqList_Insert (tmpList, &t5, 4);
    printf("插入 1 个数据, 链表长度为 %d\n", SeqList_Length(tmpList) );
    
    for (i = 0; i < SeqList_Length(tmpList); i++)
    {
        tmpTeacher = (sTeacher *)SeqList_Get(tmpList, i);
        if (tmpTeacher == NULL)
        {
            return 0;
        }
        printf("tmpTeacher->age:%d\n", tmpTeacher->age);
    }
    
    while (SeqList_Length(tmpList) > 0)
    {
        SeqList_Delete(tmpList, 0);
        printf("删除头上的数据 1 个数据, 链表长度为 %d\n", SeqList_Length(tmpList) );
    }
    
    // system("pause");
    return 0;
}






