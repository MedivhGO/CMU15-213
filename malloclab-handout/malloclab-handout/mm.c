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


static char* find_fit(int size);
static void place(char* bp, int asize);
/* 
 * mm_init - initialize the malloc package.
 */
int mm_init(void)
{
    // 进行所有的初始化操作,包括分配初始的堆区域.
    // 必须在这里重新初始化所有全局变量
    // 成功返回0,失败返回-1
    return 0;
}

/* 
 * mm_malloc - Allocate a block by incrementing the brk pointer.
 *     Always allocate a block whose size is a multiple of the alignment.
 */
void *mm_malloc(size_t size)
{
//    int newsize = ALIGN(size + SIZE_T_SIZE);
//    void *p = mem_sbrk(newsize);
//    if (p == (void *)-1)
//	return NULL;
//    else {
//        *(size_t *)p = size;
//        return (void *)((char *)p + SIZE_T_SIZE);
//    }
    // size_t asize;
    // size_t extendsize;
    // char *bp;

    // if (size == 0)
    //     return NULL;

    // if (size <= DSIZE) 
    //     asize = 2 * DSIZE;
    // else 
    //     asize = DSIZE * ((size + (DSIZE) + (DSIZE - 1)) / DSIZE);

    // if ((bp = find_fit(asize)) != NULL) {
    //     place(bp, asize);
    //     return bp;
    // }

    // extendsize = MAX(asize,CHUNKSIZE);

    // if ((bp = extend_heap(extendsize / WSIZE)) == NULL)
    //     return NULL;

    // place(bp, asize);
    // return bp;
}

/*
 * mm_free - Freeing a block does nothing.
 */
void mm_free(void *ptr)
{

}

/*
 * mm_realloc - Implemented simply in terms of mm_malloc and mm_free
 */
void *mm_realloc(void *ptr, size_t size)
{
    void *oldptr = ptr;
    void *newptr;
    size_t copySize;
    
    newptr = mm_malloc(size);
    if (newptr == NULL)
      return NULL;
    copySize = *(size_t *)((char *)oldptr - SIZE_T_SIZE);
    if (size < copySize)
      copySize = size;
    memcpy(newptr, oldptr, copySize);
    mm_free(oldptr);
    return newptr;
}














