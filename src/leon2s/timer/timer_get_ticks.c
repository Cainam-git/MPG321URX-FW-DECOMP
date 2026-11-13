/* timer_get_ticks  (FUN_a00b2064)
 *
 * Return the current tick count.
 * Returns: tick count
 * Name basis: proven - word at 0xA80793A8; read all over the input program
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00b2064 @ 0xa00b2064 (-mcpu=v8 -Os -g)
 * Source form: the decompiler's type name undefined4 is kept.
 */
typedef unsigned char undefined, undefined1, byte, uchar, bool;
typedef unsigned short undefined2, ushort, word;
typedef unsigned int undefined4, uint, ulong, dword, undefined3;
typedef unsigned long long undefined8, ulonglong;
typedef long long longlong;
typedef signed char sbyte;
typedef int code();
extern unsigned int timer_tick_count;

/* Return the tick count (word +4 of the timer record, which timer_tick_isr increments once per tick). */
undefined4 timer_get_ticks(void)

{
  return timer_tick_count;
}