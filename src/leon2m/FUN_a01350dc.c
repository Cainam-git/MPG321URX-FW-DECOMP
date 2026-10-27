/* leon2m FUN_a01350dc @ 0xa01350dc-0xa0135344 (616 bytes) -mcpu=v8 -O3 -g.
 * Send counterpart of FUN_a0134de0 on mailbox portal 0, with the same slot layout (4 slots of 20 bytes, here from
 * offset 0x10 + 20 * slot) and round-robin index byte DAT_a802cb8d. Up to 100 rounds: scan the 4 slots from the
 * index for one whose first word has a zero low nibble (free), advancing the index (3 wraps to 0) after each busy
 * slot; if the first scan found a slot after skipping some (i = 1..3) the index is restored and the scan repeated.
 * No free slot: return. Otherwise one 20-byte message is taken from the 37-entry ring DAT_a802da6c (read index
 * byte DAT_a802cb96, wraps after 0x24; write index byte DAT_a802cb97); an empty ring gives words 0..3 = 0. A zero
 * first word ends the function; else words 1..4 are written to offset slot * 20 + 0x14 and then word 0 to
 * slot * 20 + 0x10 (MailBox_Write func_0x4008c5f8), and the index is advanced.
 * Callers: FUN_a01356fc.
 * Source form: the message is a 5-word local structure initialised to zero at its declaration (std pairs); the
 * empty-ring branch clears words 3, 2, 1, 0 in that order; index advances as 'if (++idx > 3) idx = 0;'.
 */
struct Msg { unsigned int w[5]; };
extern void func_0x4008c4d0(unsigned char portal, unsigned char offset, unsigned int *buf, unsigned char count);
extern void func_0x4008c5f8(unsigned char portal, unsigned char offset, unsigned int *buf, unsigned char count);
extern unsigned char DAT_a802cb8d, DAT_a802cb96, DAT_a802cb97;
extern struct Msg DAT_a802da6c[];

void FUN_a01350dc(void)
{
    unsigned char rounds = 100;
    unsigned char saved, i, slot;
    unsigned int status;
    struct Msg msg = { { 0 } };

    do {
        status = 0;
        saved = DAT_a802cb8d;
        for (i = 0; i < 4; i++) {
            func_0x4008c4d0(0, DAT_a802cb8d * 20 + 0x10, &status, 1);
            if (!(status & 0xf)) break;
            if (++DAT_a802cb8d > 3) DAT_a802cb8d = 0;
        }
        if (i != 0 && i != 4) {
            DAT_a802cb8d = saved;
            for (i = 0; i < 4; i++) {
                func_0x4008c4d0(0, DAT_a802cb8d * 20 + 0x10, &status, 1);
                if (!(status & 0xf)) break;
                if (++DAT_a802cb8d > 3) DAT_a802cb8d = 0;
            }
        }
        if (i == 4) slot = 0xff;
        else slot = DAT_a802cb8d;
        if (slot == 0xff) return;
        if (DAT_a802cb97 == DAT_a802cb96) {
            msg.w[3] = 0;
            msg.w[2] = 0;
            msg.w[1] = 0;
            msg.w[0] = 0;
        } else {
            msg = DAT_a802da6c[DAT_a802cb96];
            if (++DAT_a802cb96 > 0x24) DAT_a802cb96 = 0;
        }
        if (msg.w[0] == 0) return;
        func_0x4008c5f8(0, slot * 20 + 0x14, &msg.w[1], 4);
        func_0x4008c5f8(0, slot * 20 + 0x10, &msg.w[0], 1);
        if (++DAT_a802cb8d > 3) DAT_a802cb8d = 0;
    } while (--rounds);
}
