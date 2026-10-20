/* leon2s FUN_a00a2080 @ 0xa00a2080  MATCH (-mcpu=v8 -Os -g)
 * Returns 1 when the word at offset 0x50 of the 400-byte record (param_1 & 0xFF) of the table at 0xa807d7e0 equals
 * 3, else 0.
 */
extern unsigned char ARR_a807d7e0[];

int FUN_a00a2080(unsigned int param_1)
{
  unsigned char *p = ARR_a807d7e0 + (param_1 & 0xff) * 400;
  return *(unsigned int *)(p + 0x50) == 3;
}
