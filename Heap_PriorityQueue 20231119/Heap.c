#include"library.h"
void HeapInit(Heap*heap,size_t size)// 初始化堆
{
    assert(heap);
    heap->data=(DataType*)malloc(sizeof(DataType)*(size+1));
    if(heap->data==NULL)
    {
        perror("malloc failed");
        exit(-1);
    }
    heap->size=size;
    heap->tail=0;
}


void DestroyHeap(Heap*heap)// 摧毁堆
{
    assert(heap);
    free(heap->data);
    heap->data=NULL;
    heap->size=0;
    heap->tail=0;
}


bool IsHeapFull(Heap*heap)// 判断堆是否已满
{
    assert(heap);
    if(heap->tail==heap->size)
        return true;
    else
        return false;
}


void Up_UpData(Heap*heap)// 堆元素向上调整
{
    assert(heap);
    size_t current=heap->tail;

    while(current!=1)
    {
        size_t parent= PARENT(current);
        if(heap->data[current]<=heap->data[parent])
        {
            break;
        }
        DataType tmp=heap->data[current];
        heap->data[current]=heap->data[parent];
        heap->data[parent]=tmp;
        current=parent;

    }

}


void HeapPush(Heap*heap,DataType data)// 元素入堆
{
    assert(heap);
    assert(!IsHeapFull(heap));
    heap->tail++;
    heap->data[heap->tail]=data;
    Up_UpData(heap);
}


bool IsHeapEmpty(Heap*heap)// 判断堆是否为空
{
    assert(heap);
    if(heap->tail==0)
        return true;
    else
        return false;
}



void Dawn_UpData(Heap*heap)// 堆元素向下调整
{
    assert(heap);
    size_t current=1;
    while(current*2<=heap->tail)
    {
        size_t left=LEFT(current);
        size_t right=RIGHT(current);
        size_t lager_child;

        if(right>heap->tail)
        {
            lager_child=left;
        }
        else
        {
            lager_child = heap->data[left]>heap->data[right]
                    ?left:right;
        }


        if(heap->data[current]<heap->data[lager_child])
        {
            DataType tmp=heap->data[current];
            heap->data[current]=heap->data[lager_child];
            heap->data[lager_child]=tmp;
        }
        else
        {
            break;
        }
        current=lager_child;
    }
}



void HeapPop(Heap*heap)// 元素出堆
{
    assert(heap);
    assert(!IsHeapEmpty(heap));
    heap->data[1]=heap->data[heap->tail];
    heap->tail--;
    Dawn_UpData(heap);
}


void HeapPrint(Heap*heap)// 打印堆元素
{
    assert(heap);
    for(int current=1;current<=heap->tail;current++)
    {
        printf(PRINT_FORMAT,heap->data[current]);
    }
    if(heap->tail==0)
    {
        printf("heap is empty");
    }
    printf("\n");
}


