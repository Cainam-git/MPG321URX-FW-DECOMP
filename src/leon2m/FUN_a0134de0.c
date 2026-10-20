/* leon2m FUN_a0134de0 @ 0xa0134de0-0xa0135004 (548 bytes) -mcpu=v8 -O3 -g
 * (jf.py 100 % match=True, rawcmp.py 137 words, mismatches 0).
 *
 * What it does: the Big chip's receive poll for messages from mailbox portal 0 (the 8051).
 * The portal has 4 message slots of 20 bytes (5 words) at offsets
 * 0x60 + 20 * slot. Up to 100 rounds: scan the 4 slots starting at the round-robin index DAT_a802cb8c (byte),
 * reading each slot's first word; a slot whose low nibble (status & 0xf) is non-zero holds a message. The index
 * advances after each empty slot and wraps 3 -> 0. If the first scan found a slot after skipping some (i = 1..3),
 * the index is restored to where the round started and the scan is repeated (same code, second copy). No slot
 * found (i == 4): return. Found: slot = index, index advanced; with debug level 0x20 enabled (FUN_a00dd614) it
 * prints "S2L validslot" (string 0x1A54F8) and, after reading the 5 words of the slot into buf, the first four
 * words (string 0x1A5510); hands buf to the decoder FUN_a013497c; then writes 0 into the slot's first word
 * (MailBox_Write func_0x4008c5f8) to release it. Then the next round.
 * Inputs: none. Output: none. Globals: DAT_a802cb8c (u8 slot index 0..3, read and written).
 * Calls: func_0x4008c4d0 = MailBox_Read(portal, offset, buf, words), func_0x4008c5f8 = MailBox_Write (same args),
 *   FUN_a00dd614 (debug level test), FUN_a00df170 (debug printf), FUN_a013497c (message decoder).
 * Caller: FUN_a01387a4.
 * Match key: the index advance is written 'if (++idx > 3) idx = 0;' at all three places; the if/else form
 *   (idx + 1 > 3 ? 0 : idx + 1) gives separate %hi registers for the stores (67 %).
 * The two strings at 0x1A54F8 / 0x1A5510 are referenced by symbol.
 */
extern void func_0x4008c4d0(unsigned char portal, unsigned char offset, unsigned int *buf, unsigned char count);
extern void func_0x4008c5f8(unsigned char portal, unsigned char offset, unsigned int *buf, unsigned char count);
extern unsigned char FUN_a00dd614(unsigned int level);
extern int FUN_a00df170();
extern void FUN_a013497c(unsigned int *msg);
extern unsigned char DAT_a802cb8c;
extern const char s_001a54f8[];
extern const char s_001a5510[];

void FUN_a0134de0(void)
{
    unsigned char rounds = 100;
    unsigned char saved, i, slot, off;
    unsigned int status;
    unsigned int buf[5];
    unsigned int zero;

    do {
        status = 0;
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
        if (slot == 0xfe) return;
        if (FUN_a00dd614(0x20)) FUN_a00df170(s_001a54f8, slot);
        off = slot * 20 + 0x60;
        func_0x4008c4d0(0, off, buf, 5);
        if (FUN_a00dd614(0x20)) FUN_a00df170(s_001a5510, buf[0], buf[1], buf[2], buf[3]);
        FUN_a013497c(buf);
        zero = 0;
        func_0x4008c5f8(0, off, &zero, 1);
    } while (--rounds);
}
