/* leon2m FUN_a00962ac @ 0xa00962ac-0xa0096338 (35 words), flags -mcpu=v8 -O3 -g.
 * Code facts: bits 16..19 of the word at DAT_a802d290 + 0x34 (0xa802d2c4) = byte DAT_a8025c56
 * & 0xf (ld, andn 0xf0000, or, st); FUN_a00d58f8(); FUN_a00d58d8(); FUN_a00d4998();
 * FUN_a00a93bc((u8)(word DAT_a802afec - 100)); FUN_a00a9650(field, 0); FUN_a00a813c(1, field, 1)
 * (the field is re-read each time with lduh [base + 0x34] & 0xf); DAT_a802afec = 0x17; tail call
 * FUN_a00a900c(2, 1). void, no params. The tail call takes 2 arguments.
 * Source form: the nibble is a 4-bit BIT-FIELD of the record DAT_a802d290 (pad[0x34], hi:12, f:4, lo:16;
 * big-endian) = the fw's lduh reads and [base + 0x34] addressing. Aids: none.
 */
extern unsigned char DAT_a8025c56;
extern unsigned int DAT_a802afec;
struct Rec290 {
    unsigned char pad[0x34];
    unsigned int hi : 12;
    unsigned int f : 4;
    unsigned int lo : 16;
};
extern struct Rec290 DAT_a802d290;
extern void FUN_a00a813c(int, unsigned char, int);
extern void FUN_a00a900c(unsigned int, unsigned int);
extern void FUN_a00a93bc(unsigned char);
extern void FUN_a00a9650(unsigned char, int);
extern void FUN_a00d4998(void);
extern void FUN_a00d58d8(void);
extern void FUN_a00d58f8(void);

void FUN_a00962ac(void)
{
    DAT_a802d290.f = DAT_a8025c56;
    FUN_a00d58f8();
    FUN_a00d58d8();
    FUN_a00d4998();
    FUN_a00a93bc(DAT_a802afec - 100);
    FUN_a00a9650(DAT_a802d290.f, 0);
    FUN_a00a813c(1, DAT_a802d290.f, 1);
    DAT_a802afec = 0x17;
    FUN_a00a900c(2, 1);
}
