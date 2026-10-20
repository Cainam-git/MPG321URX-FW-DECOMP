/* leon2s FUN_a00a63a8 @ 0xa00a63a8-0xa00a6428 (32 words), flags -mcpu=v8 -Os -g.
 * Code facts: record init through p (u16 *): bytes 4, 0xc, 0xd, 0xe = 1; u16 0 and 2 = 0; byte 5 = 2;
 * bytes 6..0xb and 0xf = 0; FUN_a00a6260(port & 0xff, p); byte 0x3f = 2; bytes 0x3a..0x3e and 0x40
 * = 0; word +0x44 = (u16 +0x20) >> 3. Returns void (%i0 is left unchanged).
 * Source form: the source order is not the fw store order; sched2 hoists the store whose chain is
 * longest. The +0x44 store is LAST in the source, and the '= 1' stores are in ascending offset order
 * (4, 0xc, 0xd, 0xe) before the u16 clears; among the 720 orders of the first six stores the first
 * exact one is this ascending one. Aids: none.
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void FUN_a00a6260(unsigned int, u16 *);
void FUN_a00a63a8(u16 *p, unsigned int port)
{
    u8 *b = (u8 *)p;
    b[4] = 1;
    b[0xc] = 1;
    b[0xd] = 1;
    b[0xe] = 1;
    p[0] = 0;
    p[1] = 0;
    b[5] = 2;
    b[6] = 0;
    b[7] = 0;
    b[8] = 0;
    b[9] = 0;
    b[0xa] = 0;
    b[0xb] = 0;
    b[0xf] = 0;
    FUN_a00a6260(port & 0xff, p);
    b[0x3f] = 2;
    b[0x3a] = 0;
    b[0x3b] = 0;
    b[0x3c] = 0;
    b[0x3d] = 0;
    b[0x3e] = 0;
    b[0x40] = 0;
    *(unsigned int *)(b + 0x44) = p[0x10] >> 3;
}
