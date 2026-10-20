/* leon2s FUN_a00a284c @ 0xa00a284c  MATCH (-mcpu=v8 -Os -g)
 * Returns the u16 at byte offset 0x2A (element 0x15) of the 400-byte entry (param_1 & 0xFF) of the table at
 * 0xA807D7E0 (200 u16 elements per entry).
 */
extern unsigned short ARR_a807d7e0[];

unsigned short FUN_a00a284c(unsigned int param_1)
{
    return ARR_a807d7e0[(param_1 & 0xff) * 200 + 0x15];
}
