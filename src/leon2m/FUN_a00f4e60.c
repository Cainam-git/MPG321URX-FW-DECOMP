/* leon2m FUN_a00f4e60 @ 0xa00f4e60-0xa00f51b4, flags -mcpu=v8 -O3 -g.
 * Measures three values for block p (FUN_a00f3960/3974/3988 read them, FUN_a00f38d4/38ec/3904 write them) and
 * stores their average. Returns 1 on success, 0 otherwise.
 *   Register 0xcf02010c = (p << 4 | p) & 0xff for p <= 7, else 0. The three values are saved, FUN_a00f31bc(2),
 *   block registers 0x5e/0x5f/0x60 = 0x71/0xff/0; the three values are written as 0xff, registers 0x65/0x66/0x67 =
 *   0xf4/0xf1/0xec, 0x63 = 0x80, 0x64 = 3. Sampling loop (timer start func_0x4008d588, func_0x4008d1a0(2) per
 *   pass): FUN_a0121374(p) == 1 ends it with the counter n = 10; each new value that differs from the previous one
 *   by more than 3 sets n = 10; n == 10 restarts the three 16-bit sums, otherwise the values are added; when
 *   --n reaches 0 the averages sum / 10 are taken; the loop runs while n != 0 and func_0x4008d594(t0) <= 0x12b.
 *   Then registers 0x63..0x67 and 0x5e = 0, FUN_a00f31bc(3); n != 0: the saved values are written back, return 0;
 *   else the averages are written, DAT_a802b798 = 1, return 1.
 * Source form: K&R definition with an unsigned char parameter; the register value as 'v = p << 4; v |= p;';
 *   n = 10 set after the 0xcf02010c store; differences through abs(); the averaging written inside the loop
 *   ('if (--n == 0) { ... }' with 'n != 0' in the loop condition), so the loop pass moves the 0xcccccccd
 *   constant in front of the loop as in the firmware.
 */
#define R(a) (*(volatile unsigned int *)(a))
extern unsigned char DAT_a802b798;
extern unsigned char FUN_a00f3960(void);
extern unsigned char FUN_a00f3974(void);
extern unsigned char FUN_a00f3988(void);
extern void FUN_a00f38d4(unsigned char);
extern void FUN_a00f38ec(unsigned char);
extern void FUN_a00f3904(unsigned char);
extern void FUN_a00f31bc(unsigned char);
extern unsigned char FUN_a0121374(unsigned char);
extern void FUN_a00f1ad4(unsigned char blk, unsigned char reg, unsigned char val);
extern unsigned short func_0x4008d588(void);
extern unsigned short func_0x4008d594(unsigned short);
extern void func_0x4008d1a0(int ms);

extern int abs(int);

unsigned char FUN_a00f4e60(p)
unsigned char p;
{
    unsigned short sum[3];
    unsigned char cur[3];
    unsigned char save[3];
    unsigned char n;
    unsigned char v;
    unsigned short t0;

    v = 0;
    if (p <= 7) {
        v = p << 4;
        v |= p;
    }
    R(0xcf02010c) = v;
    n = 10;
    save[0] = FUN_a00f3960();
    save[1] = FUN_a00f3974();
    save[2] = FUN_a00f3988();
    FUN_a00f31bc(2);
    FUN_a00f1ad4(p, 0x5e, 0x71);
    FUN_a00f1ad4(p, 0x5f, 0xff);
    FUN_a00f1ad4(p, 0x60, 0);
    cur[0] = 0;
    cur[1] = 0;
    cur[2] = 0;
    FUN_a00f38d4(0xff);
    FUN_a00f38ec(0xff);
    FUN_a00f3904(0xff);
    FUN_a00f1ad4(p, 0x65, 0xf4);
    FUN_a00f1ad4(p, 0x66, 0xf1);
    FUN_a00f1ad4(p, 0x67, 0xec);
    FUN_a00f1ad4(p, 0x63, 0x80);
    FUN_a00f1ad4(p, 0x64, 3);
    sum[0] = 0;
    sum[1] = 0;
    sum[2] = 0;
    t0 = func_0x4008d588();
    do {
        func_0x4008d1a0(2);
        if (FUN_a0121374(p) == 1) {
            n = 10;
            break;
        }
        v = FUN_a00f3960();
        if (abs(cur[0] - v) > 3)
            n = 10;
        cur[0] = v;
        v = FUN_a00f3974();
        if (abs(cur[1] - v) > 3)
            n = 10;
        cur[1] = v;
        v = FUN_a00f3988();
        if (abs(cur[2] - v) > 3)
            n = 10;
        cur[2] = v;
        if (n == 10) {
            sum[0] = cur[0];
            sum[1] = cur[1];
            sum[2] = cur[2];
        } else {
            sum[0] += cur[0];
            sum[1] += cur[1];
            sum[2] += cur[2];
        }
        if (--n == 0) {
            cur[0] = sum[0] / 10;
            cur[1] = sum[1] / 10;
            cur[2] = sum[2] / 10;
        }
    } while (n != 0 && func_0x4008d594(t0) <= 0x12b);
    FUN_a00f1ad4(p, 0x63, 0);
    FUN_a00f1ad4(p, 0x64, 0);
    FUN_a00f1ad4(p, 0x65, 0);
    FUN_a00f1ad4(p, 0x66, 0);
    FUN_a00f1ad4(p, 0x67, 0);
    FUN_a00f1ad4(p, 0x5e, 0);
    FUN_a00f31bc(3);
    if (n != 0) {
        FUN_a00f38d4(save[0]);
        FUN_a00f38ec(save[1]);
        FUN_a00f3904(save[2]);
        return 0;
    }
    FUN_a00f38d4(cur[0]);
    FUN_a00f38ec(cur[1]);
    FUN_a00f3904(cur[2]);
    DAT_a802b798 = 1;
    return 1;
}
