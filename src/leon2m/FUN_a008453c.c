/* FUN_a008453c (leon2m 0xa008453c-0xa008454c, 16 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Returns bit 0 of the byte DAT_a802af41 (ldub; and 1 in the retl delay slot). Nothing in the image refers to it:
 * no call, branch, sethi/or constant or address word. It lies between FUN_a00844f8 and FUN_a008454c. Source form:
 * 'DAT_a802af41 & 1' returned as unsigned char.
 */
extern unsigned char DAT_a802af41;

unsigned char FUN_a008453c(void)
{
    return DAT_a802af41 & 1;
}
