/*
 * FUN_a0095e08 (leon2s 0xa0095e08-0xa0095ea4, 156 bytes), flags -mcpu=v8 -Os -g. Called by FUN_a0095ea4.
 * void (u8 port); nothing for port > 1. Port 0 / 1: when the low byte of FUN_a0070404() / FUN_a0070414() is set,
 * tail-calls FUN_a0095d78(0) / FUN_a0095d78(1). Otherwise, when the low byte of FUN_a0091bac(port) is set, calls
 * FUN_a00950a0(port, 9) and FUN_a0091578(port) (same call pairs as FUN_a009584c).
 * Source form: the two FUN_a0095d78 calls stand at the end of the function, reached by goto tail0 / tail1 (as
 * separate blocks after a label they keep their own 0 / 1 argument; written in the port tests, the argument
 * becomes the known port value).
 */
extern unsigned char FUN_a0070404(void);
extern unsigned char FUN_a0070414(void);
extern unsigned int FUN_a0091bac(unsigned char);
extern void FUN_a00950a0(unsigned char, unsigned char);
extern void FUN_a0091578(unsigned char);
extern void FUN_a0095d78(unsigned char);

void FUN_a0095e08(unsigned char port)
{
    if (port > 1)
        return;
    if (port == 0) {
        if (FUN_a0070404())
            goto tail0;
        if (FUN_a0091bac(0) & 0xff) {
            FUN_a00950a0(0, 9);
            FUN_a0091578(0);
        }
    } else if (port == 1) {
        if (FUN_a0070414())
            goto tail1;
        if (FUN_a0091bac(1) & 0xff) {
            FUN_a00950a0(1, 9);
            FUN_a0091578(1);
        }
    }
    return;
tail0:
    FUN_a0095d78(0);
    return;
tail1:
    FUN_a0095d78(1);
}
