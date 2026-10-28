/* leon2m FUN_a01346ac @ 0xa01346ac-0xa013480c (88 words), flags -mcpu=v8 -O3 -g. No direct callers.
 * Scans the 4 slots of mailbox portal 0 at offsets 0x60 + 20 * slot, starting at the round-robin index
 * DAT_a802cb8c (byte): reads each slot's first word with func_0x4008c4d0(0, offset, &status, 1) and stops at the
 * first slot whose low nibble is non-zero; the index advances after each empty slot and wraps 3 -> 0. If the scan
 * stopped after skipping some slots (i = 1..3), the index is restored and the scan repeated. Returns the slot found
 * (and advances the index past it), or 0xfe when all 4 slots were empty.
 * Source form: the slot search of FUN_a0134de0, written as in that function.
 */
extern unsigned char DAT_a802cb8c;
extern void func_0x4008c4d0(unsigned char portal, unsigned char offset, unsigned int *buf, unsigned char count);

unsigned char FUN_a01346ac(void)
{
    unsigned char saved, i, slot;
    unsigned int status = 0;

    saved = DAT_a802cb8c;
    for (i = 0; i < 4; i++) {
        func_0x4008c4d0(0, DAT_a802cb8c * 20 + 0x60, &status, 1);
        if (status & 0xf) break;
        if (++DAT_a802cb8c > 3) DAT_a802cb8c = 0;
    }
    if (i != 0 && i != 4) {
        DAT_a802cb8c = saved;
        for (i = 0; i < 4; i++) {
            func_0x4008c4d0(0, DAT_a802cb8c * 20 + 0x60, &status, 1);
            if (status & 0xf) break;
            if (++DAT_a802cb8c > 3) DAT_a802cb8c = 0;
        }
    }
    if (i == 4) slot = 0xfe;
    else {
        slot = DAT_a802cb8c;
        if (++DAT_a802cb8c > 3) DAT_a802cb8c = 0;
    }
    return slot;
}
