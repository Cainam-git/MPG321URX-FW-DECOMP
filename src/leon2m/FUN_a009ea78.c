/* FUN_a009ea78 (leon2m 0xa009ea78-0xa009ea88, 16 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Stores 0x112 to the word DAT_a802afec. Nothing in the image refers to it: no call, branch, sethi/or constant or
 * address word. It lies between FUN_a009ea5c and FUN_a009ea88. Source form: a direct store of a constant to the
 * extern symbol (the store sits in the retl delay slot).
 */
extern unsigned int DAT_a802afec;

void FUN_a009ea78(void)
{
    DAT_a802afec = 0x112;
}
