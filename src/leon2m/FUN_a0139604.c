/* leon2m FUN_a0139604 @ 0xa0139604-0xa01396d8 (53 words), flags -mcpu=v8 -O3 -g.
 * jf 100.00 match=True, rawcmp 0/53 mismatches.
 * Code facts: if the u16 DAT_a802a458 already equals the u16 argument, return. Else
 * v = 0xffffffff at %fp-12; ROM func_0x4008c4d0(2, 0x20, &v, 1) reads one word; while
 * v != 0 (at most 100 rounds): ROM delay func_0x4008d1a0(1), read again. If v ended 0:
 * v = 0x35000000 | arg, ROM func_0x4008c5f8(2, 0x20, &v, 1) writes it. In every non-early
 * path DAT_a802a458 = arg (sth in the delay slots).
 * Fix vs the autoc draft (84.91): the 0x35000000 operand is a SEPARATE u16 copy 's = arg'
 * taken AFTER the early-return test (fw 'mov %i0,%l1' keeps the store value; the or re-extends
 * %i0 and reuses %i0 for the sethi). With the copy before the test, the param pseudo dies at
 * the compare's sll and sched1 puts the sll before the sethi (reg weight 0 < 1). Aids: none.
 */
extern unsigned short DAT_a802a458;
extern int func_0x4008c4d0(unsigned char portal, unsigned char offset, unsigned int *buf, unsigned char count);
extern int func_0x4008c5f8(unsigned char portal, unsigned char offset, unsigned int *buf, unsigned char count);
extern int func_0x4008d1a0(int ms);
void FUN_a0139604(unsigned short arg)
{
    unsigned int v;
    int n;
    unsigned short s;
    if (DAT_a802a458 == arg)
        return;
    s = arg;
    v = 0xffffffff;
    func_0x4008c4d0(2, 0x20, &v, 1);
    if (v != 0) {
        n = 100;
        do {
            func_0x4008d1a0(1);
            n--;
            func_0x4008c4d0(2, 0x20, &v, 1);
            if (n == 0)
                break;
        } while (v != 0);
    }
    if (v == 0) {
        v = 0x35000000 | s;
        func_0x4008c5f8(2, 0x20, &v, 1);
    }
    DAT_a802a458 = arg;
}
