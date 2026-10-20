/* FUN_a009262c (leon2s, 0xa009262c-0xa00926e0, 45 words). Flags -mcpu=v8 -Os -g.
 * Twin of FUN_a0093084 (regs 0x180..).
 * void (u8 port, u8 *buf). FUN_a00a8054(port, 0, reg, val) writes buf[0], buf[1], buf[2] to 0x160, 0x161,
 * 0x162; then for i < buf[2] (re-read every pass): FUN_a00a8054(port, 0, 0x164 + i (u16), buf[2]) and
 * sum += buf[4 + i]; finally a tail call writing the u8 checksum -sum to 0x163.
 * The loop call's 4th argument is buf[2] (firmware %o3 = the loop-test load); FUN_a00a8054 has the prototype
 * (u8, u8, u16, u8).
 */
extern void FUN_a00a8054(unsigned char, unsigned char, unsigned short, unsigned char);

void FUN_a009262c(unsigned char port, unsigned char *buf)
{
    unsigned char i;
    unsigned char sum;

    FUN_a00a8054(port, 0, 0x160, buf[0]);
    FUN_a00a8054(port, 0, 0x161, buf[1]);
    FUN_a00a8054(port, 0, 0x162, buf[2]);
    sum = 0;
    for (i = 0; i < buf[2]; i++) {
        FUN_a00a8054(port, 0, i + 0x164, buf[2]);
        sum += buf[i + 4];
    }
    FUN_a00a8054(port, 0, 0x163, -sum);
}
