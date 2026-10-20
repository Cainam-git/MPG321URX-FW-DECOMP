/* leon2m FUN_a0142ea8 @ 0xa0142ea8-0xa0142ed0 (10 words).
 * Stores the current tick count (func_0x4008d588) in halfword 0x12 of entry blk of the 0x2a-byte table at
 * 0xa802e224.
 * The entry offset is blk * 0x2a; the tick count is the 16-bit return value of func_0x4008d588 (FUN_a002d588).
 */
struct Ent { unsigned char p[0x12]; unsigned short h12; unsigned char rest[0x16]; };
extern struct Ent DAT_a802e224[];
extern unsigned short func_0x4008d588(void);

void FUN_a0142ea8(unsigned char blk)
{
    DAT_a802e224[blk].h12 = func_0x4008d588();
}
