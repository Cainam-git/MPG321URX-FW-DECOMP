/* leon2m FUN_a009eaf8 @ 0xa009eaf8 (-mcpu=v8 -O3 -g)
 * Calls FUN_a008ad20(); calls FUN_a008b2bc() when byte 0xA802D284 == 0x3F; stores the result of FUN_a0147724() in
 * halfword 0xA802AFE8.
 * Source form: Ghidra's type and symbol names are kept.
 */
extern unsigned char DAT_a802d284; /* 0xa802d284 */
extern unsigned short DAT_a802afe8; /* 0xa802afe8 */
extern int FUN_a008ad20(void); /* 0xa008ad20 */
extern int FUN_a008b2bc(void); /* 0xa008b2bc */
extern int FUN_a0147724(void); /* 0xa0147724 */

void FUN_a009eaf8(void)
{
    FUN_a008ad20();
    if (DAT_a802d284 == 0x3f) {
        FUN_a008b2bc();
    }
    DAT_a802afe8 = FUN_a0147724();
}
