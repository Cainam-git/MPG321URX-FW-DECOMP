/* leon2m FUN_a012c090 @ 0xa012c090-0xa012c0f8 (26 words).
 * Calls FUN_a012bb94(1, 0x2001): ORs 0x2001 into halfword +0x1c of record 1 of the table at 0xa802d8dc and sends
 * the 12-byte message {1, low byte, high byte, 0...} with FUN_a01370dc(0x56, 0xc, msg, 0).
 * FUN_a012bb94 is defined in this file and inlined.
 */
struct Rec {
    unsigned char pad0[0x1c];
    unsigned short h1c;
    unsigned char pad1e[0x24 - 0x1e];
};
extern struct Rec DAT_a802d8dc[];
extern void FUN_a01370dc(int, int, void *, int);

void FUN_a012bb94(unsigned char id, unsigned short v)
{
    unsigned char msg[12] = {0};

    DAT_a802d8dc[id].h1c |= v;
    msg[0] = id;
    msg[1] = DAT_a802d8dc[id].h1c;
    msg[2] = DAT_a802d8dc[id].h1c >> 8;
    FUN_a01370dc(0x56, 0xc, msg, 0);
}

void FUN_a012c090(void)
{
    FUN_a012bb94(1, 0x2001);
}
