/* FUN_a00dffcc (leon2m 0xa00dffcc-0xa00dffd8, 12 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Returns the word DAT_a802b530. Nothing in the image refers to it: no call, branch, sethi/or constant or address
 * word. It lies between FUN_a00dffb4 and FUN_a00dffd8. Source form: a direct read of the extern symbol (sethi %hi +
 * load with the %lo offset in the retl delay slot).
 */
extern unsigned int DAT_a802b530;

unsigned int FUN_a00dffcc(void)
{
    return DAT_a802b530;
}
