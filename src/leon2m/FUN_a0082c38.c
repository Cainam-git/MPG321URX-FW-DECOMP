/* FUN_a0082c38 (leon2m 0xa0082c38-0xa0082c4c, 20 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Returns bit 14 of the halfword DAT_a802af42. Nothing in the image refers to it: no call, branch, sethi/or
 * constant or address word. It lies between FUN_a0082c20 and FUN_a0082c4c. Source form: '(DAT_a802af42 >> 14) & 1'.
 */
extern unsigned short DAT_a802af42;

unsigned int FUN_a0082c38(void)
{
    return (DAT_a802af42 >> 14) & 1;
}
