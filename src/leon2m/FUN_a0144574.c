/* leon2m FUN_a0144574 @ 0xa0144574 (-mcpu=v8 -O2 -g)
 * Returns FUN_a01421c4(FUN_a0142218(FUN_a0125198(param_1 & 0xFF) & 0xFF) & 0xFF) & 0xFF. The function takes one
 * parameter and returns a plain int; Ghidra's second parameter and CONCAT44 return do not exist in the code.
 */
extern int FUN_a0125198(int);  /* 0xa0125198 */
extern int FUN_a0142218(int);  /* 0xa0142218 */
extern int FUN_a01421c4(int);  /* 0xa01421c4 */

int FUN_a0144574(int param_1)
{
    int r1 = FUN_a0125198(param_1 & 0xff);
    int r2 = FUN_a0142218(r1 & 0xff);
    int r3 = FUN_a01421c4(r2 & 0xff);
    return r3 & 0xff;
}
