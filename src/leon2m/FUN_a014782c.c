/* leon2m FUN_a014782c @ 0xa014782c-0xa01478a8 (31 words). BYTE-EXACT: -mcpu=v8 -O3 -g, jf 100 match=True,
 * rawcmp 0/31, jump table proven by tools/exact.py.
 * What it does: action switch on act (u8, 8-entry jump table at fw 0xe33f8; values > 7 do nothing):
 *   1: if FUN_a013ce6c(0) (the state nibble, bits 28..31, of channel 0's record) is not 0: FUN_a00fca4c();
 *   2: FUN_a00fcb1c();  3: FUN_a00fcbec();  5: FUN_a00fce40();  6: FUN_a00fd074(0x6d);  7: FUN_a00fd298();
 *   0 and 4: nothing. All calls are tail calls; the five FUN_a00fcXXX/fdXXX callees take no arguments
 *   (their asm never reads %i0) except FUN_a00fd074 (u8). They all program the 0xcf012000 register area.
 * Caller: the APP action dispatcher (reads the raw port state).
 * Not rate-dependent; it dispatches one of six register-programming actions.
 * volatile: none. Aids: none.
 */
extern unsigned char FUN_a013ce6c(unsigned char ch);
extern void FUN_a00fca4c(void);
extern void FUN_a00fcb1c(void);
extern void FUN_a00fcbec(void);
extern void FUN_a00fce40(void);
extern void FUN_a00fd074(unsigned char v);
extern void FUN_a00fd298(void);

void FUN_a014782c(unsigned char act)
{
    switch (act) {
    case 1:
        if (FUN_a013ce6c(0))
            FUN_a00fca4c();
        break;
    case 2: FUN_a00fcb1c(); break;
    case 3: FUN_a00fcbec(); break;
    case 5: FUN_a00fce40(); break;
    case 6: FUN_a00fd074(0x6d); break;
    case 7: FUN_a00fd298(); break;
    }
}
