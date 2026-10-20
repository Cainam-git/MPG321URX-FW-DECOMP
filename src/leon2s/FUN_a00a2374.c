/* FUN_a00a2374 (leon2s 0xa00a2374-0xa00a2418, 164 bytes), flags -mcpu=v8 -Os -g.
 * Sets bits 0x10 and 0x12 of the word array at r4 + 0x24 bytes (0x34-byte port record DAT_a807db00[port])
 * by mode: 0 clears both, 2 sets 0x10 and clears 0x12, any other mode sets both (FUN_a00a73ac sets,
 * FUN_a00a73d4 clears a bit). Every access indexes the record with (port & 0xff).
 */
struct port_rec {
    volatile unsigned int *r0;
    volatile unsigned int *r4;
    unsigned char _08[0x34 - 8];
};
extern struct port_rec DAT_a807db00[];
extern void FUN_a00a73ac(unsigned int, volatile unsigned int *);
extern void FUN_a00a73d4(unsigned int, volatile unsigned int *);

void FUN_a00a2374(unsigned int port, unsigned char mode)
{
    if (mode == 0) {
        FUN_a00a73d4(0x10, DAT_a807db00[port & 0xff].r4 + 9);
        FUN_a00a73d4(0x12, DAT_a807db00[port & 0xff].r4 + 9);
    } else if (mode == 2) {
        FUN_a00a73ac(0x10, DAT_a807db00[port & 0xff].r4 + 9);
        FUN_a00a73d4(0x12, DAT_a807db00[port & 0xff].r4 + 9);
    } else {
        FUN_a00a73ac(0x10, DAT_a807db00[port & 0xff].r4 + 9);
        FUN_a00a73ac(0x12, DAT_a807db00[port & 0xff].r4 + 9);
    }
}
