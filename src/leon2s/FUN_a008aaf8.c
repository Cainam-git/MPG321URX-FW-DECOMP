/* FUN_a008aaf8 (leon2s 0xa008aaf8-0xa008ab5c, 100 bytes), flags -mcpu=v8 -Os -g.
 * Passes the halfword v to FUN_a008aab0, FUN_a008aadc and FUN_a008a9ec, each for 0 then 1, and tail-calls
 * FUN_a008a95c with the high byte of v.
 */
extern void FUN_a008aab0(unsigned char, unsigned short);
extern void FUN_a008aadc(unsigned char, unsigned short);
extern void FUN_a008a9ec(unsigned char, unsigned short);
extern void FUN_a008a95c(unsigned char);

void FUN_a008aaf8(unsigned short v)
{
    FUN_a008aab0(0, v);
    FUN_a008aab0(1, v);
    FUN_a008aadc(0, v);
    FUN_a008aadc(1, v);
    FUN_a008a9ec(0, v);
    FUN_a008a9ec(1, v);
    FUN_a008a95c(v >> 8);
}
