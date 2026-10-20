/* FUN_a008e5ac (leon2s, 0xa008e5ac-0xa008e654, 42 words). Flags -mcpu=v8 -Os -g. jf 100.00 match=True, rawcmp_l2s 0 mismatches.
 Code facts: void (u8 p1, p2, p3, p4). p2 == 0: dbd4(p1,0,p4), db4c(p1,1), db90(p1,0). p3 == 1: db4c(p1,0), dbd4(p1,1,p4), db90(p1,1).
 Else: dbd4(p1,0,p4), db4c(p1,1), db90(p1,1). Then tail call FUN_a00b1794(10).
 Fixes vs draft: BEHAVIOUR the 3rd arg of FUN_a008dbd4 is p4 in all arms (fw loads 'and %i3,0xff,%o2' once at entry and keeps it to
 both 0-arm calls; the draft passed 0); void with a sibcall (FUN_a00b1794 declared void). Aids: none.
 */
extern void FUN_a008db4c(unsigned char, unsigned char); /* 0xa008db4c */
extern void FUN_a008db90(unsigned char, unsigned char); /* 0xa008db90 */
extern void FUN_a008dbd4(unsigned char, unsigned char, unsigned char); /* 0xa008dbd4 */
extern void FUN_a00b1794(int); /* 0xa00b1794 */

void FUN_a008e5ac(unsigned char param_1, unsigned char param_2, unsigned char param_3, unsigned char param_4)
{
    if (param_2 == 0) {
        FUN_a008dbd4(param_1, 0, param_4);
        FUN_a008db4c(param_1, 1);
        FUN_a008db90(param_1, 0);
    } else if (param_3 == 1) {
        FUN_a008db4c(param_1, 0);
        FUN_a008dbd4(param_1, 1, param_4);
        FUN_a008db90(param_1, 1);
    } else {
        FUN_a008dbd4(param_1, 0, param_4);
        FUN_a008db4c(param_1, 1);
        FUN_a008db90(param_1, 1);
    }

    FUN_a00b1794(10);
}
