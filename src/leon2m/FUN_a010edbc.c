/* leon2m FUN_a010edbc @ 0xa010edbc-0xa010ef64 (424 bytes)  program half the transformed row's +0x08 value into the
 * output channel register blocks. Flags -mcpu=v8 -O3 -g. Twin of FUN_a010f7a4; the bit-set counterpart of
 * FUN_a010ef64 (the next function).
 *
 * void FUN_a010edbc(c): c selects a channel record: c == 1 -> 0xA802D7C4, c == 2 -> 0xA802D784,
 *   else 0xA802D744; sets bit 0 of its byte +0x3E.
 *   v = (transformed row *DAT_a802d6a4 halfword +0x08 >> 1) << 16.
 *   Two pointer tables of 3 register blocks: T1 = 0x19AED8, T2 = 0x19AECC.
 *   Word 3 (+0x0C) = v in T1[c] then T2[c]; c > 2 means "all three blocks" (loop i = 0..2) for every write.
 *   w = word 1 (+0x04) of T1[k] | 0x4000 (bit 14), k = c or 0 for c above 2; then word 1 = w in T1 and T2 the
 *   same way.
 * Globals: DAT_a802d744/784/7c4 (+0x3E byte), DAT_a802d6a4 (pointer to the transformed 0x58-byte row, reads +0x08 only),
 *   DAT_0019aed8[3], DAT_0019aecc[3] (pointers to register blocks; writes +0x0C and +0x04, reads +0x04 of T1).
 * Callers: no direct call in asm/leon2m; Ghidra marks the entry unreachable.
 * Source form: the form of FUN_a010ef64: a switch selecting the record pointer; 'k = c; if (c > 2) k = 0;' for the
 *   read index; separate 'if (c > 2) loop / else' statements per table and word.
 */
struct Ctx { unsigned char p0[0x3e]; unsigned char b3e; };
struct PanelParam { unsigned int w0; unsigned short h4; unsigned char b6, b7; unsigned short h08; };
extern struct Ctx DAT_a802d744, DAT_a802d784, DAT_a802d7c4;
extern struct PanelParam *DAT_a802d6a4;
extern volatile unsigned int *const DAT_0019aed8[];
extern volatile unsigned int *const DAT_0019aecc[];

void FUN_a010edbc(unsigned char c)
{
    struct Ctx *s;
    unsigned int v, w, i;
    unsigned char k;

    switch (c) {
    case 1:
        s = &DAT_a802d7c4;
        break;
    case 2:
        s = &DAT_a802d784;
        break;
    default:
        s = &DAT_a802d744;
        break;
    }
    s->b3e |= 1;
    v = (DAT_a802d6a4->h08 >> 1) << 16;
    if (c > 2) {
        for (i = 0; i <= 2; i++)
            DAT_0019aed8[i][3] = v;
    } else
        DAT_0019aed8[c][3] = v;
    if (c > 2) {
        for (i = 0; i <= 2; i++)
            DAT_0019aecc[i][3] = v;
    } else
        DAT_0019aecc[c][3] = v;
    k = c;
    if (c > 2)
        k = 0;
    w = DAT_0019aed8[k][1] | 0x4000;
    if (c > 2) {
        for (i = 0; i <= 2; i++)
            DAT_0019aed8[i][1] = w;
    } else
        DAT_0019aed8[c][1] = w;
    if (c > 2) {
        for (i = 0; i <= 2; i++)
            DAT_0019aecc[i][1] = w;
    } else
        DAT_0019aecc[c][1] = w;
}
