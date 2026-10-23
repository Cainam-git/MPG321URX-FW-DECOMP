/* FUN_a012e82c (leon2m 0xa012e82c-0xa012e838, 12 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Returns the byte DAT_a802cb10. Called by FUN_a0088724. It lies between FUN_a012e6c0 and FUN_a012e838. Source
 * form: a direct read of the extern symbol (sethi %hi + load with the %lo offset in the retl delay slot).
 */
extern unsigned char DAT_a802cb10;

unsigned char FUN_a012e82c(void)
{
    return DAT_a802cb10;
}
