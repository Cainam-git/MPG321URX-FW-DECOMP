/* pq_get_selected_window  (FUN_a00f6cf4)
 *
 * Return the picture window that is currently selected.
 * Returns: window index
 * Name basis: proven - cache byte at 0xA802B7B4, written by pq_select_window
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f6cf4 @ 0xa00f6cf4, flags -mcpu=v8 -O2.
 * Leaf routine, no register window.
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
extern unsigned char pq_selected_window;

/*
 * Return the picture window that is currently selected.
 * The value is stored in the global pq_selected_window.
 */
undefined1 pq_get_selected_window(void)
{
  return pq_selected_window;
}
