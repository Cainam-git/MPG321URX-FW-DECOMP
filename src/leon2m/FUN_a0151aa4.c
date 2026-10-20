/* leon2m FUN_a0151aa4 @ 0xa0151aa4..0xa0151c84 (120 words)  switch the input ports of a mask on, called with
 * (0xFF, 1) by FUN_a01439d8 in start-up step 5, before WAIT 3 and before the hook.
 * Input entries E[k] = the 18-byte table 0xA802E116 (byte +0x10 = port number, set by FUN_a0141b60: 3, 4, 5/6, 6/5).
 * What it does (code facts), mask bits in this order (bits 0, 1, 6, 7 are ignored):
 *  - 0x04: if on == 1 or FUN_a0124bf4(E[0].port) != 0: FUN_a0124da4(E[0].port); FUN_a012cd68(FUN_a0125124(E[0].port),
 *    0); FUN_a0137920(0) (mailbox command 0x12 with code 2 to the other processor); FUN_a013b754(4, 1000) (software
 *    timer 4 = 1000).
 *  - 0x08: the same for E[1] with FUN_a0137920(1) (code 3) and timer 5 = 1000.
 *  - 0x10: if on == 1, or bit 31 of the settings word 0xA802E1A0 is clear, or FUN_a012b394(0) != 1:
 *    FUN_a0124da4(E[2].port); FUN_a0107a20(0, 0); FUN_a0107ba4(0, 0); timer 6 = 800.
 *  - 0x20: the same for E[3] with FUN_a012b394(1), FUN_a0107a20(1, 0), FUN_a0107ba4(1, 0), timer 7 = 800 (tail call).
 *  FW.021 start-up call (0xFF, 1): all four groups run (on == 1).
 * Can it fail or wait? No loop in this function; FUN_a013b754 only sets a RAM timer; FUN_a0137920 -> FUN_a01370dc
 * (mailbox) and the other callees are not followed here. Runs before the hooked FUN_a0106d64.
 * Exact form: plain if-chains as written; no aids. The bit-31 test is the signed compare (int) word >= 0.
 */
struct Ent { unsigned short h0; unsigned char rest[14]; unsigned char port, b11; };
extern struct Ent DAT_a802e116[];
extern int DAT_a802e1a0;
extern unsigned char FUN_a0124bf4(unsigned char);
extern void FUN_a0124da4(unsigned char);
extern unsigned char FUN_a0125124(unsigned char);
extern void FUN_a012cd68(unsigned char, unsigned char);
extern void FUN_a0137920(unsigned char);
extern void FUN_a013b754(unsigned char, unsigned short);
extern unsigned char FUN_a012b394(unsigned char);
extern void FUN_a0107a20(unsigned char, unsigned char);
extern void FUN_a0107ba4(unsigned char, unsigned char);

void FUN_a0151aa4(unsigned char mask, unsigned char on)
{
    if (mask & 0x04) {
        if (on == 1 || FUN_a0124bf4(DAT_a802e116[0].port)) {
            FUN_a0124da4(DAT_a802e116[0].port);
            FUN_a012cd68(FUN_a0125124(DAT_a802e116[0].port), 0);
            FUN_a0137920(0);
            FUN_a013b754(4, 1000);
        }
    }
    if (mask & 0x08) {
        if (on == 1 || FUN_a0124bf4(DAT_a802e116[1].port)) {
            FUN_a0124da4(DAT_a802e116[1].port);
            FUN_a012cd68(FUN_a0125124(DAT_a802e116[1].port), 0);
            FUN_a0137920(1);
            FUN_a013b754(5, 1000);
        }
    }
    if (mask & 0x10) {
        if (on == 1 || DAT_a802e1a0 >= 0 || FUN_a012b394(0) != 1) {
            FUN_a0124da4(DAT_a802e116[2].port);
            FUN_a0107a20(0, 0);
            FUN_a0107ba4(0, 0);
            FUN_a013b754(6, 800);
        }
    }
    if (mask & 0x20) {
        if (on == 1 || DAT_a802e1a0 >= 0 || FUN_a012b394(1) != 1) {
            FUN_a0124da4(DAT_a802e116[3].port);
            FUN_a0107a20(1, 0);
            FUN_a0107ba4(1, 0);
            FUN_a013b754(7, 800);
        }
    }
}
