/* FUN_a00cd31c (leon2s 0xa00cd31c-0xa00cd4fc, 480 bytes), flags -mcpu=v8 -Os -g. Called by FUN_a00d0968.
 * void (u8 port). Works on the 2-bit field st (bits 16..17 of word 0) of the 24-byte record DAT_a8078bb0[port]
 * (same record layout as FUN_a00cdc40) and sets st = 1. Calls func_0xa0f96400(0, 0x90, 0x68029, 0, buf) and
 * func_0xa0fc1794(2) up to three times, stopping early when bit 1 of buf[0] is set. Bit 0 of buf[0] set: st = 2.
 * Bit 1 of buf[0] clear: st = 0. Otherwise up to three attempts: set bit 2 of 0xcf018d00, call
 * func_0xa0fc1794(1) while that bit stays set (more than 30 calls: st = 0, return), then
 * func_0xa0f96400(0, 0x90, 0x68005, 1, buf); buf[0] equal to 0xcf018d38 and buf[1] equal to 0xcf018d3c:
 * FUN_a00cca38(1) and return. After the third attempt the same comparison is made once more: equal returns,
 * otherwise st = 0. volatile: hardware registers.
 * Source form: the FUN_a00cca38(1) block stands between the bit 1 test and the attempt loop and is reached by
 * goto (its position in the source gives the firmware's block order); the first loop ends on
 * 'more & !(buf[0] & 2)' with more = i < 3 in its own variable (flag arithmetic, no branch).
 */
#define R8D00 (*(volatile unsigned int *)0xcf018d00)
#define R8D38 (*(volatile unsigned int *)0xcf018d38)
#define R8D3C (*(volatile unsigned int *)0xcf018d3c)

struct Rec24 {
    unsigned int a:3;
    unsigned int f28:1;
    unsigned int cnt:4;
    unsigned int f23:1;
    unsigned int mid:5;
    unsigned int st:2;
    unsigned int x:8;
    unsigned char b3;
    unsigned char b4;
    unsigned char b5;
    unsigned char b6;
    unsigned char pad[17];
};
extern struct Rec24 DAT_a8078bb0[];
extern int func_0xa0f96400(int, int, int, int, unsigned char *);
extern void func_0xa0fc1794(unsigned int);
extern void FUN_a00cca38(unsigned int);

void FUN_a00cd31c(unsigned char port)
{
    unsigned char buf[2];
    unsigned char i;
    unsigned char k;
    unsigned int more;

    DAT_a8078bb0[port].st = 1;
    i = 0;
    do {
        func_0xa0f96400(0, 0x90, 0x68029, 0, buf);
        func_0xa0fc1794(2);
        i++;
        more = i < 3;
    } while (more & !(buf[0] & 2));
    if (buf[0] & 1)
        DAT_a8078bb0[port].st = 2;
    if (!(buf[0] & 2))
        goto fail;
    goto loop;
ok:
    FUN_a00cca38(1);
    return;
loop:
    for (k = 0; k < 3; k++) {
        R8D00 |= 4;
        for (i = 0; R8D00 & 4; ) {
            func_0xa0fc1794(1);
            i++;
            if (i > 30)
                goto fail;
        }
        func_0xa0f96400(0, 0x90, 0x68005, 1, buf);
        if (buf[0] == R8D38 && buf[1] == R8D3C)
            goto ok;
    }
    if (buf[0] == R8D38 && buf[1] == R8D3C)
        return;
fail:
    DAT_a8078bb0[port].st = 0;
}
