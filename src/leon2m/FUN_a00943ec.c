/* leon2m FUN_a00943ec @ 0xa00943ec-0xa0094438 (19 words), flags -mcpu=v8 -O3 -g. No direct callers (reached
 * through a table). Copies byte 0xa802d3cf (0xa802d290 + 0x13f) into byte 0xa8025c55, sets word 0xa802afec to 0x108
 * and byte 0xa802d433 (0xa802d290 + 0x1a3) to 1, calls FUN_a00b5080 and func_0x4008e2a4 twice, and ends with the
 * tail call FUN_a00a6b98(1, 1, 0). Same sequence as FUN_a00943a4 (byte +0x13e, value 0) and FUN_a0094368.
 */
extern unsigned char DAT_a802d290[];
extern unsigned char DAT_a8025c55;
extern unsigned int DAT_a802afec;
extern void FUN_a00b5080(void);
extern void func_0x4008e2a4(void);
extern void FUN_a00a6b98(int, int, int);

void FUN_a00943ec(void)
{
    DAT_a8025c55 = DAT_a802d290[0x13f];
    DAT_a802afec = 0x108;
    DAT_a802d290[0x1a3] = 1;
    FUN_a00b5080();
    func_0x4008e2a4();
    func_0x4008e2a4();
    FUN_a00a6b98(1, 1, 0);
}
