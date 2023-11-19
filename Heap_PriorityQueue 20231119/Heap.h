#pragma once
#define PRINT_FORMAT "%2d "
#define PARENT(child) ((child)/2)
#define LEFT(parent) (2*(parent))
#define RIGHT(parent) (2*(parent)+1)
typedef int DataType;
typedef struct Heap
{
    DataType*data;
    size_t size;// 堆的最大容量
    size_t tail;// 堆的末尾元素下标(从1开始)
}Heap;
void HeapInit(Heap*heap,size_t size);// 初始化堆
void DestroyHeap(Heap*heap);// 摧毁堆

bool IsHeapFull(Heap*heap);// 判断堆是否已满
void Up_UpData(Heap*heap);// 堆元素向上调整
void HeapPush(Heap*heap,DataType data);// 元素入堆

bool IsHeapEmpty(Heap*heap);// 判断堆是否为空
void Dawn_UpData(Heap*heap);// 堆元素向下调整
void HeapPop(Heap*heap);// 元素出堆
void HeapPrint(Heap*heap);// 打印堆元素

