/* leon2m FUN_a0097d3c @ 0xa0097d3c-0xa0097dec (44 words), flags -mcpu=v8 -O3 -g. Caller: FUN_a00db1ac.
 * For word 0xa802afec == 0x7f: when byte 0xa802d2bf (0xa802d290 + 0x2f) is not 0, sets it to 0. For 0xa802afec ==
 * 0x80: when that byte is not 1, sets it to 1. After a change it calls FUN_a00d91fc(0), FUN_a0148268(0, 1),
 * FUN_a0148268(1, 1) and tail-calls FUN_a00da254. Other values of 0xa802afec do nothing.
 */
extern unsigned int DAT_a802afec;
extern unsigned char DAT_a802d290[];
extern void FUN_a00d91fc(int);
extern void FUN_a0148268(int, int);
extern void FUN_a00da254(void);

void FUN_a0097d3c(void)
{
    if (DAT_a802afec == 0x7f) {
        if (DAT_a802d290[0x2f] != 0) {
            DAT_a802d290[0x2f] = 0;
            FUN_a00d91fc(0);
            FUN_a0148268(0, 1);
            FUN_a0148268(1, 1);
            FUN_a00da254();
        }
    } else if (DAT_a802afec == 0x80) {
        if (DAT_a802d290[0x2f] != 1) {
            DAT_a802d290[0x2f] = 1;
            FUN_a00d91fc(0);
            FUN_a0148268(0, 1);
            FUN_a0148268(1, 1);
            FUN_a00da254();
        }
    }
}
