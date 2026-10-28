/* leon2m FUN_a013453c @ 0xa013453c-0xa0134684 (82 words), flags -mcpu=v8 -O3 -g. No direct callers.
 * Scans the 4 slots of mailbox portal 0 at offsets 0x10 + 20 * slot, starting at the round-robin index
 * DAT_a802cb8d (byte): reads each slot's first word with func_0x4008c4d0(0, offset, &status, 1) and stops at the
 * first slot whose low nibble is 0; the index advances after each other slot and wraps 3 -> 0. If the scan
 * stopped after skipping some slots (i = 1..3), the index is restored and the scan repeated. Returns the index of
 * the slot found, or 0xff when all 4 slots were skipped.
 * Source form: the scan of FUN_a0134de0 (the receive poll over offsets 0x60 + 20 * slot), written twice, with
 * '(status & 0xf) == 0' as the stop test.
 */
extern unsigned char DAT_a802cb8d;
extern void func_0x4008c4d0(unsigned char portal, unsigned char offset, unsigned int *buf, unsigned char count);

unsigned char FUN_a013453c(void)
{
    unsigned char saved, i, slot;
    unsigned int status = 0;

    saved = DAT_a802cb8d;
    for (i = 0; i < 4; i++) {
        func_0x4008c4d0(0, DAT_a802cb8d * 20 + 0x10, &status, 1);
        if ((status & 0xf) == 0) break;
        if (++DAT_a802cb8d > 3) DAT_a802cb8d = 0;
    }
    if (i != 0 && i != 4) {
        DAT_a802cb8d = saved;
        for (i = 0; i < 4; i++) {
            func_0x4008c4d0(0, DAT_a802cb8d * 20 + 0x10, &status, 1);
            if ((status & 0xf) == 0) break;
            if (++DAT_a802cb8d > 3) DAT_a802cb8d = 0;
        }
    }
    if (i == 4) slot = 0xff;
    else
        slot = DAT_a802cb8d;
    return slot;
}
