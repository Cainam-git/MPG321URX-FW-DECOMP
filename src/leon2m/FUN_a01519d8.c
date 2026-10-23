/* leon2m FUN_a01519d8
 * For one byte value sel (the group bits 0x04, 0x08, 0x10, 0x20 that FUN_a0151aa4 tests as a mask) makes the calls
 * below with the second argument 1, where FUN_a0151aa4 passes 0. Input entries E[k] = the 18-byte table 0xA802E116 (byte +0x10 = port number).
 *  - 0x04: FUN_a012cd68(FUN_a0125124(E[0].port), 1), then FUN_a0124df8(E[0].port).
 *  - 0x08: the same for E[1].
 *  - 0x10: FUN_a0107ba4(0, 1), FUN_a0124df8(E[2].port), FUN_a0107a20(0, 1).
 *  - 0x20: the same with 1 and E[3].
 *  Other values do nothing. Callers: FUN_a0086ae8 (twice), FUN_a0153018.
 */
struct Ent { unsigned short h0; unsigned char rest[14]; unsigned char port, b11; };
extern struct Ent DAT_a802e116[];
extern unsigned char FUN_a0125124(unsigned char);
extern void FUN_a012cd68(unsigned char, unsigned char);
extern void FUN_a0124df8(unsigned int);
extern void FUN_a0107a20(unsigned char, unsigned char);
extern void FUN_a0107ba4(unsigned char, unsigned char);

void FUN_a01519d8(unsigned char sel)
{
    switch (sel) {
    case 0x04:
        FUN_a012cd68(FUN_a0125124(DAT_a802e116[0].port), 1);
        FUN_a0124df8(DAT_a802e116[0].port);
        break;
    case 0x08:
        FUN_a012cd68(FUN_a0125124(DAT_a802e116[1].port), 1);
        FUN_a0124df8(DAT_a802e116[1].port);
        break;
    case 0x10:
        FUN_a0107ba4(0, 1);
        FUN_a0124df8(DAT_a802e116[2].port);
        FUN_a0107a20(0, 1);
        break;
    case 0x20:
        FUN_a0107ba4(1, 1);
        FUN_a0124df8(DAT_a802e116[3].port);
        FUN_a0107a20(1, 1);
        break;
    }
}
