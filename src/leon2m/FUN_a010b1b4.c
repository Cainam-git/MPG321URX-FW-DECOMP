/* leon2m FUN_a010b1b4 @ 0xa010b1b4  MATCH (-mcpu=v8 -O2 -g)
 * Fills a 32-byte stack buffer with FUN_a013c910(buf, 0x19ae1c, 0x20), then calls FUN_a00f2e98(0xb6, 0, 0x20, p)
 * with p = param_1, or the local buffer when param_1 is NULL. param_2 (%i1) is never referenced.
 */
extern int FUN_a013c910(void *buf, unsigned int addr, unsigned int size);
extern int FUN_a00f2e98(unsigned int a, unsigned int b, unsigned int c, void *d);

void FUN_a010b1b4(unsigned char *param_1, unsigned int param_2)
{
    unsigned char buf[32];
    unsigned char *p;

    FUN_a013c910(buf, 0x19ae1c, 0x20);

    p = param_1;
    if (param_1 == 0)
        p = buf;
    FUN_a00f2e98(0xb6, 0, 0x20, p);
}
