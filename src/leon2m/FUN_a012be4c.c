/* leon2m FUN_a012be4c @ 0xa012be4c-0xa012c004 (110 words).
 * Stores bit 0 of v in one bit of the first word of the 0x24-byte record id of the table at 0xa802d8dc, chosen by
 * sel: 0x24 -> bit 29, 0x52 -> bit 27, 0x53 -> bit 28, 0x54 -> bit 30, 0x5b -> bit 25; for 0x55 bit 31 is
 * written only when it differs, and then send is forced to 1. When send is nonzero, the 4-byte message {id, v, 0,
 * 0} goes to FUN_a01370dc(sel, 4, msg, 0). Other sel values only send.
 * Source forms: v is an unsigned int; the case order (0x52, 0x53, 0x54, 0x24, 0x55, 0x5b) decides the block
 * layout and registers.
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

void FUN_a012be4c(unsigned char id, unsigned char sel, unsigned int v, unsigned char send)
{
    unsigned char msg[4] = {0};

    switch (sel) {
    case 0x52:
        DAT_a802d8dc[id].f27 = v;
        break;
    case 0x53:
        DAT_a802d8dc[id].f28 = v;
        break;
    case 0x54:
        DAT_a802d8dc[id].f30 = v;
        break;
    case 0x24:
        DAT_a802d8dc[id].f29 = v;
        break;
    case 0x55:
        if (DAT_a802d8dc[id].f31 != (v & 1)) {
            DAT_a802d8dc[id].f31 = v;
            send = 1;
        }
        break;
    case 0x5b:
        DAT_a802d8dc[id].f25 = v;
        break;
    }
    if (send) {
        msg[0] = id;
        msg[1] = v;
        FUN_a01370dc(sel, 4, msg, 0);
    }
}
