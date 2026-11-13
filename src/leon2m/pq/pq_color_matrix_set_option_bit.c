/* pq_color_matrix_set_option_bit  (FUN_a00f6cc0)
 *
 * Set the second option bit of the colour matrix.
 * Name basis: descriptive - bit 7 of 0xCF00E984
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f6cc0 @ 0xa00f6cc0 (-mcpu=v8 -O2 -g)
 * Source form: single assignment with bitwise OR; the bit mask is a #define constant.
 */
typedef unsigned char undefined, undefined1, byte, uchar, bool;
typedef unsigned short undefined2, ushort, word;
typedef unsigned int undefined4, uint, ulong, dword, undefined3;
typedef unsigned long long undefined8, ulonglong;
typedef long long longlong;
typedef signed char sbyte;
typedef int code();
#define true 1
#define false 0
#define CONCAT44(a, b) (((unsigned long long)(a) << 32) | (unsigned int)(b))
#define reg_pq_color_matrix_option (*(volatile unsigned int *)0xcf00e984)
#define COLOUR_MATRIX_OPTION_BIT_7 0x80   /* bit 7: the second option of the colour matrix */

/*
 * Set the second option bit of the colour matrix.
 * The bit is bit 7 of the colour matrix option register (reg_pq_color_matrix_option).
 * Used by pq_color_matrix_set_option to store the second option flag and switch its hardware bit.
 */
void pq_color_matrix_set_option_bit(void)

{
  reg_pq_color_matrix_option = reg_pq_color_matrix_option | COLOUR_MATRIX_OPTION_BIT_7;
  return;
}
