/* leon2m FUN_a012bb94 @ 0xa012bb94-0xa012bc00 (27 words).
 * ORs v into the halfword at +0x1c of the 0x24-byte record id of the table at 0xa802d8dc and sends the 12-byte
 * message {id, low byte, high byte of the new halfword, 0...} with FUN_a01370dc(0x56, 0xc, msg, 0).
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
