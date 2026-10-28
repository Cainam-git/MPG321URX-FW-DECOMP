/* leon2m FUN_a0139ddc @ 0xa0139ddc-0xa0139ed0 (61 words), flags -mcpu=v8 -O3 -g. No direct callers.
 * When the u16 DAT_a802a45c differs from the u16 argument: s = arg * 4095 / 1023 (u16); v = 0xffffffff at
 * %fp-12; ROM func_0x4008c4d0(2, 0x20, &v, 1) reads one word; while v != 0 (at most 100 rounds) ROM
 * func_0x4008d1a0(1), then read again. If v ended 0: v = 0x30000000 | s, written with ROM
 * func_0x4008c5f8(2, 0x20, &v, 1). Every path, also the equal-value exit, ends with DAT_a802a45c = arg.
 * Source form: the polling skeleton of FUN_a0139a30 (goto send / check / done); the equal-value test jumps to
 * the final store (the firmware's early branch targets that sth). The ROM mailbox routines are declared without
 * parameter lists, as in FUN_a013a500; with prototypes the -1 store is scheduled one slot earlier.
 */
extern unsigned short DAT_a802a45c;
extern void func_0x4008c4d0();
extern void func_0x4008c5f8();
extern int func_0x4008d1a0(int ms);
void FUN_a0139ddc(unsigned short arg)
{
    unsigned int v;
    int n;
    unsigned short s;

    if (DAT_a802a45c == arg)
        goto done;
    s = (unsigned int)arg * 4095 / 1023;
    v = 0xffffffff;
    func_0x4008c4d0(2, 0x20, &v, 1);
    n = 100;
    if (v == 0)
        goto send;
    do {
        func_0x4008d1a0(1);
        n--;
        func_0x4008c4d0(2, 0x20, &v, 1);
        if (n == 0)
            goto check;
    } while (v != 0);
    goto send;
check:
    if (v != 0)
        goto done;
send:
    v = 0x30000000 | s;
    func_0x4008c5f8(2, 0x20, &v, 1);
done:
    DAT_a802a45c = arg;
}
