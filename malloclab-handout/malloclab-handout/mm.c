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


#define WSIZE 4
#define DSIZE 8
#define CHUNKSIZE (1<<12) // 4KB

#define GET(p) (*(unsigned int*)(p))
#define PUG(p, val) ((*(unsigned int*)(p)) = (val))

#define GET_SIZE(p) (GET(p) & ~0x7)
#define GET_ALLOC(p) (GET(p) & 0x1)

/* rounds up to the nearest multiple of ALIGNMENT */

/* 8 字节对齐， + 7 是为了保证向上舍入 */
#define ALIGN(size) (((size) + (ALIGNMENT-1)) & ~0x7)

#define SIZE_T_SIZE (ALIGN(sizeof(size_t)))

#define MAX(x, y) ((x) > (y) ? (x) : (y))

/**
  memlib.c 包中提供了一些辅助函数
  初始化这个内存模型
  void mem_init(void);
  释放这个存储模型
  void mem_deinit(void);
  将堆扩展 incr 个字节，返回一个指向新分配的堆区的首字节 void* 指针，incr 只能是正数
  void *mem_sbrk(int incr);
  void mem_reset_brk(void);
  返回指向堆的第一个字节的指针
  void *mem_heap_lo(void);
  返回指向堆的最后一个字节的指针
  void *mem_heap_hi(void);
  返回堆当前的大小（字节）
  size_t mem_heapsize(void);
  返回系统的页大小
  size_t mem_pagesize(void);
*/

static char* heap_listp;

// 定义一些辅助函数
static void* extend_heap(size_t words);
static void* coalesce(void *bp);
static void place(char* bp, int asize);
static void* find_fit(int size);

static void check_free_blocks_marked_free()
{
  printf("check_free_blocks_marked_free passed.\n");
}

static void check_contiguous_free_block_coalesced()
{
  printf("check_contiguous_free_block_coalesced passed.\n");
}

static void check_all_free_blocks_in_free_list()
{
  printf("check_all_free_blocks_in_free_list passed.\n");
}

static void check_all_free_blocks_in_valid_ftr_hdr()
{
  printf("check_all_free_blocks_in_valid_ftr_hdr passed.\n");
}

static void check_ptrs_valid_heap_address()
{
  printf("check_ptrs_valid_heap_address passed.\n");
}

// 用于检测堆是否有问题，如果没有问题就返回 0
int mm_check(void)
{
  printf("BEGIN CHECK\n");
  check_free_blocks_marked_free();
  check_contiguous_free_block_coalesced();
  check_all_free_blocks_in_free_list();
  check_all_free_blocks_in_valid_ftr_hdr();
  check_ptrs_valid_heap_address();
  printf("END CHECK\n");
  return 0;
}

/* 
 * mm_init - initialize the malloc package.
 */
int mm_init(void)
{
  // 进行所有的初始化操作, 包括分配初始的堆区域
  // 必须在这里重新初始化所有全局变量
  // 成功返回 0, 失败返回 -1
  mem_init();
  int heap_size = mem_heapsize();
  printf("\ninit heap size is: %d\n", heap_size);
  perror(strerror(errno));
  return errno == 0 ? 0 : -1;
}

/* 
 * mm_malloc - Allocate a block by incrementing the brk pointer.
 *     Always allocate a block whose size is a multiple of the alignment.
 */
void *mm_malloc(size_t size)
{
  // 没找到, 就在堆上分配新的
  void *p = mem_sbrk(0); // current break position
  int total_size = size;
  void *request = mem_sbrk(ALIGN(total_size)); // 保证 8 字节对齐
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