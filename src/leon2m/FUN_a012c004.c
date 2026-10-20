/* leon2m FUN_a012c004 @ 0xa012c004-0xa012c088 (33 words).
 * When bit 0 of v differs from bit 31 of the first word of the 0x24-byte record id at 0xa802d8dc, stores it there
 * and sends the 4-byte message {id, v, 0, 0} with FUN_a01370dc(0x55, 4, msg, 0).
 */
struct Rec {
    unsigned int f31 : 1;
    unsigned int f30 : 1;
    unsigned int f29 : 1;
    unsigned int f28 : 1;
    unsigned int f27 : 1;
    unsigned int f26 : 1;
    unsigned int f25 : 1;
    unsigned int rest : 25;
    unsigned char pad4[0x24 - 4];
};
extern struct Rec DAT_a802d8dc[];
extern void FUN_a01370dc(int, int, void *, int);

void FUN_a012c004(unsigned char id, unsigned int v)
{
    unsigned char msg[4] = {0};
    unsigned char send = 0;

    if (DAT_a802d8dc[id].f31 != (v & 1)) {
        DAT_a802d8dc[id].f31 = v;
        send = 1;
    }
    if (send) {
        msg[0] = id;
        msg[1] = v;
        FUN_a01370dc(0x55, 4, msg, 0);
    }
}
