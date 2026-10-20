/* leon2s MAILBOX_DUMP @ 0xa0072b04-0xa0072b7c (30 words), flags -mcpu=v8 -Os -g.
 * buf = 48 words (0xc0 bytes) at %fp-200; FUN_a00b15ac(buf, 0, 0xc0) (it returns its destination:
 * mov %o0,%g1); FUN_a0072970(1, 0, buf, 0x30); for i = 0..0x2f (u8) logs FUN_a0073044(string 0xa0066550
 * "0x%8lX", buf[i]); then FUN_a0073044(string 0xa0066560 "MAILBOX_DUMP 0x%d", i) (the %d arg is the final
 * counter, left in %o1). void. Strings are named by address.
 * Source form: FUN_a00b15ac is declared returning void * (a void prototype moves the %o0 set before
 * %o1/%o2).
 */
extern const char s_a0066550[];
extern const char s_a0066560[];
extern void *FUN_a00b15ac(void *, int, unsigned int);
extern void FUN_a0072970(unsigned char, unsigned char, unsigned int *, unsigned char);
extern void FUN_a0073044(const char *fmt, ...);

void MAILBOX_DUMP(void)
{
    unsigned int buf[48];
    unsigned char i;

    FUN_a00b15ac(buf, 0, 0xc0);
    FUN_a0072970(1, 0, buf, 0x30);
    for (i = 0; i < 0x30; i++)
        FUN_a0073044(s_a0066550, buf[i]);
    FUN_a0073044(s_a0066560, i);
}
