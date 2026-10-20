/* FUN_a0093084 (leon2s, 0xa0093084-0xa0093138, 45 words). Flags -mcpu=v8 -Os -g. Twin of FUN_a009262c (regs 0x160..).
 Code facts: void (u8 port, u8 *buf). FUN_a00a8054(port, 0, reg, val) writes buf[0], buf[1], buf[2] to 0x180, 0x181, 0x182; then for i < buf[2]
 (re-read every pass, the call may change memory): FUN_a00a8054(port, 0, 0x184 + i (u16), buf[2]) and sum += buf[4 + i]; finally a tail call
 writing the u8 checksum -sum to 0x183.
 Fixes vs draft: BEHAVIOUR the loop call has a 4th argument and it is buf[2] (fw passes the %o3 that holds the loop-test load of buf[2];
 code fact, it is not buf[4 + i]); the 0x182 value is buf[2] (the draft used an uninitialised local); real a8054 prototype (u8,u8,u16,u8). Aids: none.
 */
extern void FUN_a00a8054(unsigned char, unsigned char, unsigned short, unsigned char);

void FUN_a0093084(unsigned char port, unsigned char *buf)
{
    unsigned char i;
    unsigned char sum;

    FUN_a00a8054(port, 0, 0x180, buf[0]);
    FUN_a00a8054(port, 0, 0x181, buf[1]);
    FUN_a00a8054(port, 0, 0x182, buf[2]);
    sum = 0;
    for (i = 0; i < buf[2]; i++) {
        FUN_a00a8054(port, 0, i + 0x184, buf[2]);
        sum += buf[i + 4];
    }
    FUN_a00a8054(port, 0, 0x183, -sum);
}
