/* leon2m FUN_a0093534 @ 0xa0093534-0xa00935e8 (45 words), flags -mcpu=v8 -O3 -g.
 * Code facts: FUN_a00a93bc((byte 0xa8025c56 + 1) & 0xff); FUN_a00a813c(1, (5c56 + 1) & 0xff, 0) (byte re-read);
 * FUN_a00a9650((word 0xa802afec - 83) & 0xff, 0); f = bit 12 of word 0xa802d290+0xa8; FUN_a00a813c(1, f + 1, 0);
 * FUN_a00a813c(1, f + 1, 1) (word re-read); word 0xa802afec = 0x11; FUN_a00a900c(3, 1); byte 0xa802b08e |= 2.
 * Source form: bit 12 as a 1-bit BIT-FIELD of the record word via a struct pointer; u8 prototypes. Aids: none.
 */
struct R290 { unsigned char pad[0xa8]; struct { unsigned int hi : 19, b12 : 1, lo : 12; } fa8; };
extern struct R290 DAT_a802d290;
extern unsigned char DAT_a8025c56;
extern unsigned char DAT_a802b08e;
extern unsigned int _DAT_a802afec;
extern void FUN_a00a813c(int, unsigned char, int);
extern void FUN_a00a900c(unsigned char, int);
extern void FUN_a00a93bc(unsigned char);
extern void FUN_a00a9650(unsigned char, int);

void FUN_a0093534(void)
{
    struct R290 *p;

    FUN_a00a93bc(DAT_a8025c56 + 1);
    FUN_a00a813c(1, DAT_a8025c56 + 1, 0);
    FUN_a00a9650(_DAT_a802afec - 83, 0);
    p = &DAT_a802d290;
    FUN_a00a813c(1, p->fa8.b12 + 1, 0);
    FUN_a00a813c(1, p->fa8.b12 + 1, 1);
    _DAT_a802afec = 0x11;
    FUN_a00a900c(3, 1);
    DAT_a802b08e |= 2;
}
