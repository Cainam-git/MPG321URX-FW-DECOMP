/* FUN_a0089758 (leon2s, 0xa0089758-0xa008983c, 228 bytes, 57 words; includes the merged unreachable
 * ret/restore tail FUN_a0089834). Flags: -mcpu=v8 -Os -g.
 * Judge: jf 100.00 match=True, rawcmp_l2s 0/57 mismatches.
 * Code facts: port = (u8)param_1, on = (u8)param_2. Port 0: on == 1: FUN_a00a7940(0, 0x70, 0x10, 1),
 * then bit 0 of the register 0xcf018e80 is set when (u8)FUN_a0089750() == 1; on != 1:
 * FUN_a00a7940(0, 0x70, 0x10, 0), and when (u8)FUN_a0086bd8() == 0 and (u8)FUN_a0089750() == 1:
 * clear bit 0 of 0xcf018e80 and tail call FUN_a0088f4c(1). Other ports: tail call
 * FUN_a00a7940(port, 0x70, 0x10, on == 1).
 * Fixes vs draft: void (the fw sets no return value; the draft returned 0/1), FUN_a0088f4c(1) is a
 * tail call. FUN_a00a7940 declared with unsigned int params as in the draft: its own entry
 * extends them (u8/u16), and a u8 prototype here makes this caller re-extend %i0 (86.44).
 * Aids: none.
 */
#define _DAT_cf018e80 (*(volatile unsigned int *)0xcf018e80)
extern void FUN_a00a7940(unsigned int param_1, unsigned int param_2, unsigned int param_3, unsigned int param_4);
extern int FUN_a0089750(void);
extern int FUN_a0086bd8(void);
extern void FUN_a0088f4c(unsigned char param_1);

void FUN_a0089758(unsigned int param_1, unsigned int param_2)
{
    unsigned int uVar1;
    unsigned int uVar2;

    uVar1 = param_1 & 0xff;
    uVar2 = param_2 & 0xff;

    if (uVar1 == 0) {
        if (uVar2 == 1) {
            FUN_a00a7940(0, 0x70, 0x10, 1);
            if ((FUN_a0089750() & 0xff) == 1)
                _DAT_cf018e80 |= 1;
        } else {
            FUN_a00a7940(0, 0x70, 0x10, 0);
            if ((FUN_a0086bd8() & 0xff) == 0) {
                if ((FUN_a0089750() & 0xff) == 1) {
                    _DAT_cf018e80 &= ~1;
                    FUN_a0088f4c(1);
                }
            }
        }
        return;
    }

    if (uVar2 == 1)
        FUN_a00a7940(uVar1, 0x70, 0x10, 1);
    else
        FUN_a00a7940(uVar1, 0x70, 0x10, 0);
}
