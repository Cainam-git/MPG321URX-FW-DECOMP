/* pq_color_matrix_clear_option_bit  (FUN_a00f6ca4)
 *
 * Clear the second option bit of the colour matrix.
 * Name basis: descriptive - bit 7 of 0xCF00E984
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f6ca4 @ 0xa00f6ca4 (-mcpu=v8 -O2 -g)
 * Source form: the read-modify-write is expressed as an assignment with an explicit `&` mask.
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
#define COLOUR_MATRIX_OPTION_BIT_MASK 0xffffff7f  /* bit 7 (second option) cleared */

/*
 * Clear the second option bit (bit 7) of the colour matrix option register.
 * Called by pq_fga_handle_command and pq_color_matrix_set_option.
 */
void pq_color_matrix_clear_option_bit(void)

{
  reg_pq_color_matrix_option = reg_pq_color_matrix_option & COLOUR_MATRIX_OPTION_BIT_MASK;
  return;
}
