/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  /* (x & y) | (~x & ~y) */
  return ~(x & y) & ~ (~x & ~y);
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  /* 以二进制补码形式返回最小的integer值 */
  return 1 << 31;
}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
    /* x+1会溢出,为 10000.... , x 与 x+1 异或得到11111111, 取反后得到00000000*/
    /* 因为 -1 的机器码表示为 11111..... 所以 (x ^ (x+1)) 其结果也为 1111111, 所以要把 -1 排除掉, 也就是当x = -1时,使
      !(~(x ^ (x + 1))) 为 false 
    因此,要保证 x = -1 的时候, 要为全0,
    为什么要加 两个!! ?
    因为 如果 前面一个计算结果得到 0x01 后面那个如果是个非0的结果,那么做 & 运算会导致 0x01 可能变为0x00
    如果加上!! 那么就能保证 (~x)非0的时候, !!(~x) 为0x01,不会是的前面的运算结果改变.
    */
  return !(~(x ^ (x+1))) & !!(~x);
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
  int mask = 0xAA + (0xAA << 8) + (0xAA << 16) + (0xAA << 24);
  return !((x & mask) ^ mask);
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  /*
    A + ~A = -1
    A + neg A = 0
    neg A = ~A + 1
  */
  return ~x + 1;
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
	int mask1 = ~0x0F;
	int mask2 = 0x0000000F;
	int low = x & mask2;
  int mask4 = 0x8;

	return !(((x & mask1) ^ 0x30)) & (
    !((low & mask4) ^0x0) |
		!(low ^ 0x8) |
		!(low ^ 0x9)
	);
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  /*
    如何使用为运算来进行两个值取其一 t为全1
    0 | x = x
    ( t & z | !t & y)
  */
  int temp = !!x; // 取x的bool值， temp的结果只可能是0，或者1
  temp = ~temp + 1; // 取反 得到 0， 或者 -1，即全0，或者全1
  return (temp & y)|(~temp & z); //全1就返回 y 全0就返回 z
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
	int negx = ~x + 1;
	int res = y + negx;
	int sign = res >> 31 & 1; // 检查结果的符号位,符号位相同 如果为1 说明 y-x < 0,y < x , 如果为0， 说明 y>=x. 符号位不同正数大
	int leftBit = 1 << 31; // 最大为为1的32位有符号数 1000000...
	int xsign = x & leftBit; // 1000000或者00000..
	int ysign = y & leftBit; // 1000000或者00000..
	int bitxor = xsign ^ ysign; // 1000000或者00000..
	bitxor = (bitxor >> 31) & 1; // bitxor最后的值位 0或者1 0相同符号位，1不同符号位
	return ((!bitxor) & !sign)| ((bitxor) & !( y >> 31));
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
	/*
		为了得到x=0时 logicalneg 为1。 x=非0时 logicalneg  为0
		当x=0时，要返回1， 可以 t + 1 当 x = 0 时 t = 0，也就是 t = 0000000
		当x为非0时，要返回0， 可以 t + 1 当 x非0时， t = -1  t = 1111111
		所以 一个数 | 他的相反数 结果的符号为一定为1，所以可以进行右移31位，补充成全1
		考虑当 x=100000时，他与~x+1也满足。
	*/
	return ((x |(~x+1))>>31)+1;
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
  /*
  使用二进制补码进行表示x的值,最少使用多少位.
  思路: 如果是一个正数,要找到最高的第一个非0数,然后然后加上符号位.
  如果是一个负数,则需要知道最高位哪一位是0.
  */
  int b16,b8,b4,b2,b1,b0;
  int sign = x >> 31; // 全0或者全1
  /*
  如果x为正则不变，
  否则按位取反（这样好找最高位为1的，原来是最高位为0的，这样也将符号位去掉了

  位运算的二分查找
 
  */
  x = (sign & ~x) | (~sign & x); 
  b16 = !!(x >> 16) << 4; // 最高的16位是否有1,高16位有1,说明在高16位，向左走。没有1，说明1在低16位，向右走，找低16位。如下同理
  x = x >> b16; // 取高16位中的情况
  b8 = !!(x >> 8) << 3; // 再看看高25-32位中是否有1
  x = x >> b8; // x取25-32
  b4 = !!(x >> 4) << 2; // 再看看29-32 中是否有1
  x = x >> b4; // x取29-32
  b2 = !!(x >> 2) << 1; // 再看看31-32位中是否有1
  x = x >> b2; // x取31-32
  b1 = !!(x>>1); // 看看31-32位中是否有1, x表示的二进制数，左边为0  b1 = 0 ，左边为1， b1 = 1
  x = x >> b1; // x取32 当x最初位01111111时 b1=0
  b0 = x; // 看看32位是0是1, b0=01
  return b16 + b8 + b4 + b2 + b1 + b0 + 1;
}
//float
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
/*
    在规格化的数中
    在exp既不是全0,也不是全1的时候,称这个浮点数位规格化的值.在这种情况下,阶码字段也就是exp字段被解释为
    以偏置(biased)形式表示的有符号整数.也就是说, 阶码的值是 E = e-Bias,其中e是无符号数.
    其位表示为ek-1.....e1e0.而Bias是一个等于2^k-1 - 1的偏置值.

    对于float的所采用的单精度浮点型数来说.
    bias = 2^(8-1)-1= 127
    E = e - 127, e是exp的值, 也就是 -126<=E<=127
    
    尾码 frac 被解释为小数值f, 其中 0<=f<1,其二进制表示为0.fn-1fn-2...f1f0.
    也就是说二进制的小数点在最高有效位的左边.
    尾数 M定义为 M = 1 + f.
    这种方式也叫做隐含的以1开头的表示.
    我们可以把M看成一个二进制表达式为1.fn-1fn-2fn-3....f0的数字.

    在非规格化的数中
    M = f = 0.fn-1fn-2...f1f0
*/

unsigned floatScale2(unsigned uf) {
  /*
	返回位级别的2*f的结果
	输入参数和返回结果都使用无符号整形,但是他们是用来表示一个
	单精度的浮点数。
	当输入参数时NaN时，返回该参数。
  当计算 根号-1,无穷减去无穷.或者表示未初始化的数据时,他们NaN是很有用处的.
  */
  unsigned exp = (uf & 0x7f800000)>>23; // 取23-30共8位 阶码 8位
  unsigned sign = (uf >> 31) & 0x01; // 得到符号位
  unsigned frac = uf & 0x7FFFFF; // 尾数 23位
  unsigned res;
  if (exp == 0xFF) return uf; // 如果 exp=255,也就是阶码所有位都为1. 
  //frac为全0,表示无穷大(正无穷和负无穷,能够表示溢出的结果)，非0表示NaN(not a number,一些运算的结果不能是实数或无穷就可以返回NaN)。都可以直接return uf
  else if (exp == 0) { // 非规格化的数,也就是阶码为0, 这样就可以表示0了, 值+0.0和值-0.0在某些方面被认为是不同的,而在其他方面是相同的.
  	frac <<= 1; // frac右移一位，相当与乘以2
  	res = (sign << 31) | (exp << 23) | frac; // 重新设置浮点数各个位置的0，1情况
  } else { // 规范化数,阶码既不全是0,也不全是1.
  	exp++; // exp 指数位置+1就相当于 *2 
  	res = (sign << 31) | (exp << 23) | frac; // 重新设置浮点数各个位置的0，1情况
  }
  return res; // 返回结果
}
/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {
  /*
  	返回由无符号变量uf所给定的二进制数，所代表的单精度浮点型变量转换成有符号
  	整形值。任意超过范围的数返回0x80000000u.

    先计算出 E = exp - bias
    1. 如果是小数 E < 0 的情况,我们直接返回0.
    2. 如果是exp = 255 的情况直接返回0x80000000u 这里注意如果超出范围了,也会直接返回0x80000000u
    因此可以直接使用E >= 31 来判断.
    3. 如果是规格化数则我们进行正常的处理 V = (-1)^s * M * 2^E
       1. 先给尾数补充上省略的1
       2. 判断 E < 23 则尾数需要舍去 23 - E 位
       3. 根据符号位返回结果
  */
  unsigned exp = (uf & 0x7f800000) >> 23; // 8位的阶码
  int sign = uf >> 31 & 0x1;
  unsigned frac = uf & 0x7FFFFF; // 23位的尾数
  int E = exp - 127; // bias为127, 得到通过exp和bias计算得到的E
  if (E < 0) return 0; // 所表示的是一个小于1的数,所以转换成int型,直接返回0.
  else if (E >= 31) { // 超过了32bit所能表示的int值
    return 0x80000000u;
  } else { //  0<=E<31
    frac = frac | 1 << 23; // 给尾数补上省略的1
    if (E < 23) { // 要把frac变成一个整形的数,需要23位
      frac >>= (23 - E); // 不够23位,那么只能保留 E 个整数位,因此需要将整个frac向右移动23 - E个位置
    } else {
      frac <<= (E - 23); // E的剩余的位数用来给frac的整数部分进行*2的运算
    }
  }
  if (sign) { // 加上符号
    return -frac;
  } else {
    return frac;
  }
}
/* 
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */
unsigned floatPower2(int x) {
	/*
	    计算2.0^x， x为任意的int变量
		返回值的单精度浮点型的二进制保存在unsigned类型变量中。
		如果结果太小不能用denorm表达，就返回0。
		如果结果太大，就返回+INF
	*/
    return 2;
}
