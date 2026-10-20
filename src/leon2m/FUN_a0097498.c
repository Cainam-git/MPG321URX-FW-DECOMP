/* leon2m FUN_a0097498 @ 0xa0097498-0xa0097508 (28 words), flags -mcpu=v8 -O3 -g. No direct callers (reached
 * through a table).
 * With s = byte 0xa802d430 (0xa802d290 + 0x1a0): when s is not 0, copies byte 0xa802d290 + 0x197 + s into byte
 * +0x1a1 and byte 0xa802d290 + 0x19b + s into byte +0x1a2. Then stores s into byte 0xa802afea, sets bit 14 (0x4000)
 * of the halfword 0xa802cff4, clears word 0xa802afec, calls FUN_a00b5080 and sets bit 1 (0x02) of byte 0xa802b08e.
 * Exact form: both bytes are read into locals (+0x197 first) before the two stores.
 */
extern unsigned char DAT_a802d290[];
extern unsigned char DAT_a802afea;
extern unsigned int DAT_a802afec;
extern unsigned short DAT_a802cff4;
extern unsigned char DAT_a802b08e;
extern void FUN_a00b5080(void);

void FUN_a0097498(void)
{
    unsigned char s = DAT_a802d290[0x1a0];

    if (s != 0) {
        unsigned char b = DAT_a802d290[s + 0x197];
        unsigned char a = DAT_a802d290[s + 0x19b];
        DAT_a802d290[0x1a1] = b;
        DAT_a802d290[0x1a2] = a;
    }
    DAT_a802afea = s;
    DAT_a802cff4 |= 0x4000;
    DAT_a802afec = 0;
    FUN_a00b5080();
    DAT_a802b08e |= 2;
}
