/* leon2m FUN_a00d4164 @ 0xa00d4164 (-mcpu=v8 -O2 -g)
 * Returns the low byte of FUN_a0145660(FUN_a0144414() & 0xFF, 0x15). The function reads no input registers and is
 * declared without parameters.
 */
extern int FUN_a0144414(void); /* 0xa0144414 */
extern int FUN_a0145660(int a, int b); /* 0xa0145660 */

int FUN_a00d4164(void)
{
    int a = FUN_a0144414() & 0xff;
    return FUN_a0145660(a, 0x15) & 0xff;
}
