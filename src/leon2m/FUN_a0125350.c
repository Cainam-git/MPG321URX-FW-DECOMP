/* leon2m FUN_a0125350 @ 0xa0125350 (-mcpu=v8 -O2 -g)
 * Returns bit param_1 of the byte 0xA802C9FB (0 or 1). The shift count is used unmasked
 * ('sra %g1, %o0, %g1'), so the source shifts by the parameter directly.
 * Parameter and result are unsigned char: the callers FUN_a012cd68 and FUN_a014b4b4 test the low byte of the
 * result ('btst 0xff').
 */
extern unsigned char DAT_a802c9fb; /* 0xa802c9fb */

unsigned char FUN_a0125350(unsigned char param_1)
{
    return (DAT_a802c9fb >> param_1) & 1;
}
