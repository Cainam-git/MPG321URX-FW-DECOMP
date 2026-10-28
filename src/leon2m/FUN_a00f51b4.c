/* leon2m FUN_a00f51b4 @ 0xa00f51b4-0xa00f557c, flags -mcpu=v8 -O3 -g.
 * Measures three values for block port (FUN_a00f3998/39ac/39c0 read them, FUN_a00f3918/3930/3948 write them)
 * and stores their average plus an offset. Returns 1 on success, 0 otherwise.
 *   Register 0xcf02010c = (port << 4 | port) & 0xff for port <= 7, else 0. The three values are saved, then
 *   written as 0x80; block register 0x66 = 0, registers 0x65/0x67 = 0x80 when (0xcf020114 & 7) == 5, else 0;
 *   0x63 = 0x80, 0x64 = 3; func_0x4008d1a0(300); 0x63 = 0xe0. Sampling loop (timer start func_0x4008d588,
 *   func_0x4008d1a0(0x14) per pass): FUN_a0121374(port) == 1 ends it with the counter = 10; a new value that
 *   differs from the previous one by more than 3 or is above 0xe0 sets the counter to 10; counter 10 restarts
 *   the three 16-bit sums, otherwise the values are added; when --counter reaches 0 the averages sum / 10 are
 *   taken; the loop runs while counter != 0 and func_0x4008d594(t) <= 0x12b. Registers 0x63/0x64 = 0.
 *   Counter 0: the averages are written (mode 5 of 0xcf020114: second value + 4, else all three + 4), return 1;
 *   otherwise the saved values are written back, return 0.
 * Source form: K&R definition with an unsigned char parameter; 'x = port << 4; x |= port;'; the averaging
 *   written inside the loop ('if (--cnt == 0) { ... }' with 'cnt != 0' in the loop condition), so the loop pass
 *   moves the 0xcccccccd constant in front of the loop as in the firmware.
 * volatile only on the hardware registers 0xcf02010c / 0xcf020114.
 */
#define REG_CF02010C (*(volatile unsigned int *)0xcf02010c)
#define REG_CF020114 (*(volatile unsigned int *)0xcf020114)

extern unsigned char FUN_a00f3998(void);
extern unsigned char FUN_a00f39ac(void);
extern unsigned char FUN_a00f39c0(void);
extern void FUN_a00f3918(unsigned char);
extern void FUN_a00f3930(unsigned char);
extern void FUN_a00f3948(unsigned char);
extern void FUN_a00f1ad4(unsigned char blk, unsigned char reg, unsigned char val);
extern unsigned char FUN_a0121374(unsigned int);
extern void func_0x4008d1a0(int);
extern unsigned short func_0x4008d588(void);
extern unsigned short func_0x4008d594(unsigned short);
extern int abs(int);

unsigned char FUN_a00f51b4(port)
    unsigned char port;
{
    unsigned short sum[3];
    unsigned char cur[3];
    unsigned char old[3];
    unsigned char x;
    unsigned char cnt;
    unsigned short t;
    unsigned char v;

    x = 0;
    if (port <= 7) {
        x = port << 4;
        x |= port;
    }
    REG_CF02010C = x;
    old[0] = FUN_a00f3998();
    old[1] = FUN_a00f39ac();
    old[2] = FUN_a00f39c0();
    cur[0] = 0;
    cur[1] = 0;
    cur[2] = 0;
    FUN_a00f3918(0x80);
    FUN_a00f3930(0x80);
    FUN_a00f3948(0x80);
    FUN_a00f1ad4(port, 0x66, 0);
    if ((REG_CF020114 & 7) == 5) {
        FUN_a00f1ad4(port, 0x65, 0x80);
        FUN_a00f1ad4(port, 0x67, 0x80);
    } else {
        FUN_a00f1ad4(port, 0x65, 0);
        FUN_a00f1ad4(port, 0x67, 0);
    }
    cnt = 10;
    FUN_a00f1ad4(port, 0x63, 0x80);
    FUN_a00f1ad4(port, 0x64, 3);
    sum[0] = 0;
    sum[1] = 0;
    sum[2] = 0;
    func_0x4008d1a0(300);
    FUN_a00f1ad4(port, 0x63, 0xe0);
    t = func_0x4008d588();
    do {
        func_0x4008d1a0(0x14);
        if (FUN_a0121374(port) == 1) {
            cnt = 10;
            break;
        }
        v = FUN_a00f3998();
        if (abs(cur[0] - v) > 3 || v > 0xe0)
            cnt = 10;
        cur[0] = v;
        v = FUN_a00f39ac();
        if (abs(cur[1] - v) > 3 || v > 0xe0)
            cnt = 10;
        cur[1] = v;
        v = FUN_a00f39c0();
        if (abs(cur[2] - v) > 3 || v > 0xe0)
            cnt = 10;
        cur[2] = v;
        if (cnt == 10) {
            sum[0] = cur[0];
            sum[1] = cur[1];
            sum[2] = cur[2];
        } else {
            sum[0] += cur[0];
            sum[1] += cur[1];
            sum[2] += cur[2];
        }
        if (--cnt == 0) {
            cur[0] = sum[0] / 10;
            cur[1] = sum[1] / 10;
            cur[2] = sum[2] / 10;
        }
    } while (cnt != 0 && func_0x4008d594(t) <= 0x12b);
    FUN_a00f1ad4(port, 0x63, 0);
    FUN_a00f1ad4(port, 0x64, 0);
    if (cnt == 0) {
        if ((REG_CF020114 & 7) == 5) {
            FUN_a00f3918(cur[0]);
            FUN_a00f3930(cur[1] + 4);
            FUN_a00f3948(cur[2]);
        } else {
            FUN_a00f3918(cur[0] + 4);
            FUN_a00f3930(cur[1] + 4);
            FUN_a00f3948(cur[2] + 4);
        }
        return 1;
    }
    FUN_a00f3918(old[0]);
    FUN_a00f3930(old[1]);
    FUN_a00f3948(old[2]);
    return 0;
}
