/*
 * mm-naive.c - The fastest, least memory-efficient malloc package.
 * 
 * In this naive approach, a block is allocated by simply incrementing
 * the brk pointer.  A block is pure payload. There are no headers or
 * footers.  Blocks are never coalesced or reused. Realloc is
 * implemented directly using mm_malloc and mm_free.
 *
 * NOTE TO STUDENTS: Replace this header comment with your own header
 * comment that gives a high level description of your solution.
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#include "mm.h"
#include "memlib.h"

/*********************************************************
 * NOTE TO STUDENTS: Before you do anything else, please
 * provide your team information in the following struct.
 ********************************************************/
team_t team = {
    /* Team name */
    "lijingqi",
    /* First member's full name */
    "lijingqi",
    /* First member's email address */
    "lijingqi93@gmail.com",
    /* Second member's full name (leave blank if none) */
    "lijingqi",
    /* Second member's email address (leave blank if none) */
    "lijingqi93@gmail.com"
};

/* single word (4) or double word (8) alignment */
#define ALIGNMENT 8

/* rounds up to the nearest multiple of ALIGNMENT */
#define ALIGN(size) (((size) + (ALIGNMENT-1)) & ~0x7)


#define SIZE_T_SIZE (ALIGN(sizeof(size_t)))

#define MAX(x, y) ((x) > (y) ? (x) : (y))

typedef struct block_meta* blockptr;

#pragma pack(push, 8)
typedef struct block_meta {
  size_t size;
  int free; // 可用空间
  blockptr next_block;
} block_meta;
#pragma pack(8)

blockptr base = NULL;

#define META_SIZE (sizeof(block_meta));


static char* find_fit(blockptr* last, int size);
static void place(char* bp, int asize);

static char* find_fit(blockptr* last, int size) {
  return NULL;
}

blockptr extend_heap(blockptr last, size_t s);

static void place(char* bp, int asize) {
    return;
}

/* 
 * mm_init - initialize the malloc package.
 */
int mm_init(void)
{
    // 进行所有的初始化操作,包括分配初始的堆区域.
    // 必须在这里重新初始化所有全局变量
    // 成功返回0,失败返回-1
    mem_init();
    int heap_size = mem_heapsize();
    printf("\ninit heap size is: %d\n", heap_size);
    // perror(strerror(errno));
    if (errno == 0) {
      return 0;
    } else {
      return -1;
    }
}

/* 
 * mm_malloc - Allocate a block by incrementing the brk pointer.
 *     Always allocate a block whose size is a multiple of the alignment.
 */
void *mm_malloc(size_t size)
{
  char* ret = find_fit(NULL, size); // 在数据结构中找合适的内存空间
  place(NULL, 10);
  if (ret != NULL) {
    return ret;
  }

  // 没找到, 就在堆上分配新的
  void *p = mem_sbrk(0); // current break position
  int total_size = size + META_SIZE;
  void *request = mem_sbrk(ALIGN(total_size)); // 保证8字节对齐
  int len = mem_heapsize();
  printf("now heap size is : %d\n", len);
  if (request == (void*)-1) {
    return NULL;
  }
  assert(p == request); // Not thread safe

  // 更新数据结构
  // code
  return p;
}

/*
 * mm_free - Freeing a block does nothing.
 */
void mm_free(void *ptr)
{
  return;
}

/*
 * mm_realloc - Implemented simply in terms of mm_malloc and mm_free
 */
void *mm_realloc(void *ptr, size_t size)
{
  return NULL;
}














