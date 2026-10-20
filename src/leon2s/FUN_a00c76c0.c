/* FUN_a00c76c0 (leon2s 0xa00c76c0-0xa00c7770, 176 bytes), flags -mcpu=v8 -Os -g.
 * Read-modify-write of one 8-bit hardware register: for idx > 2 a tail call of the ROM print
 * func_0xa0f83044(s_9f1c1f48, s_9f1c1ef0, idx, reg, mask, set) and nothing else. Otherwise the word at
 * ((DAT_9f1c1ec8[idx] + reg) << 2) | 0xcf000000 is read into an unsigned char, mask is ORed in when
 * set == 1 and cleared otherwise, and the byte is written back to the same address.
 * Same address form as the read and write routines FUN_a00c7770 and FUN_a00c7654 (table and strings as
 * symbols, volatile only on the 0xcf... register).
 */
extern unsigned int DAT_9f1c1ec8[];
extern char s_9f1c1f48[], s_9f1c1ef0[];
extern int func_0xa0f83044(const char *, ...);

void FUN_a00c76c0(unsigned char idx, unsigned short reg, unsigned char mask, unsigned char set)
{
    unsigned char v;

    if (idx > 2) {
        func_0xa0f83044(s_9f1c1f48, s_9f1c1ef0, idx, reg, mask, set);
        return;
    }
    v = *(volatile unsigned int *)(((DAT_9f1c1ec8[idx] + reg) << 2) | 0xcf000000);
    if (set == 1)
        v |= mask;
    else
        v &= ~mask;
    *(volatile unsigned int *)(((DAT_9f1c1ec8[idx] + reg) << 2) | 0xcf000000) = v;
}
