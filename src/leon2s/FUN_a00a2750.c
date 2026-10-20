/* leon2s FUN_a00a2750 @ 0xa00a2750  MATCH (-mcpu=v8 -Os -g)
 * Returns halfword 0x19 (byte offset 0x32) of the 0x190-byte (200-halfword) per-port record p (p = the parameter
 * byte) in the table at 0xA807D7E0 (0xA807D400 + 0x3E0). Same pattern as the sibling getters at offsets 0x15 and
 * 0x0E.
 */
extern unsigned short ARR_a807d7e0[];

unsigned short FUN_a00a2750(unsigned int param_1)
{
    return ARR_a807d7e0[(param_1 & 0xff) * 200 + 0x19];
}
