/* FUN_a00ac41c (leon2s 0xa00ac41c-0xa00ac4ec, 208 bytes), flags -mcpu=v8 -Os -g.
 * State byte DAT_a807931c against bit 0 of FUN_a00a6bb8(port, 0x460). When they differ, prints
 * s_a006c4c8 ("source set DP%d FEC ready !!\r\n") with port through FUN_a0073044. Returns when en equals
 * bit 0 of a second FUN_a00a6bb8(port, 0x460) read and force is 0. Otherwise: FUN_a00a6c98(port, 0x30,
 * 0x80, 1); en == 1 stores en in DAT_a807931c and calls FUN_a00a6c98(port, 0x460, 1, 1), any other en
 * stores 0 and calls FUN_a00a6c98(port, 0x460, 1, 0); last FUN_a00a6c98(port, 0x30, 0x80, 0) (tail call).
 * Source form: en is copied into an int local 'on' before the test (keeps en in its own register).
 */
extern unsigned char DAT_a807931c;
extern const char s_a006c4c8[];
extern unsigned char FUN_a00a6bb8(unsigned char, unsigned short);
extern void FUN_a00a6c98(unsigned int, unsigned short, unsigned int, unsigned int);
extern int FUN_a0073044(const char *, ...);

void FUN_a00ac41c(unsigned char port, unsigned char en, unsigned char force)
{
    int on;

    if (DAT_a807931c != (FUN_a00a6bb8(port, 0x460) & 1))
        FUN_a0073044(s_a006c4c8, port);
    if (en == (FUN_a00a6bb8(port, 0x460) & 1) && !force)
        return;
    FUN_a00a6c98(port, 0x30, 0x80, 1);
    on = en;
    if (on == 1) {
        DAT_a807931c = on;
        FUN_a00a6c98(port, 0x460, 1, 1);
    } else {
        DAT_a807931c = 0;
        FUN_a00a6c98(port, 0x460, 1, 0);
    }
    FUN_a00a6c98(port, 0x30, 0x80, 0);
}
