/* leon2m FUN_a00d1d34 @ 0xa00d1d34-0xa00d1e08 (53 words), flags -mcpu=v8 -O3 (no -g: with -g a nop follows the
 * final call). No direct callers (reached through a table).
 * Command handler taking a pointer to a received frame: byte 7 of the frame selects n (8 -> 0, 9 -> 1, 0xd -> 2,
 * 0xf -> 3). When FUN_a01445fc(byte 0xa802d2ae) differs from n, byte 0xa802d2ae (0xa802d290+0x1e) =
 * FUN_a014459c(n) and FUN_a00b8804() runs. Other frame bytes change nothing. Then FUN_a0089f10() runs and the
 * function returns 0xe0.
 * Source form: an if/else chain with the test written in each arm (a switch gives a compare tree).
 */
struct R290 { unsigned char p000[0x1e]; unsigned char b01e; };
extern struct R290 DAT_a802d290;
extern unsigned char FUN_a01445fc(unsigned char);
extern unsigned char FUN_a014459c(unsigned char);
extern void FUN_a00b8804(void);
extern void FUN_a0089f10(void);

int FUN_a00d1d34(unsigned char *p)
{
    if (p[7] == 8) {
        if (FUN_a01445fc(DAT_a802d290.b01e) != 0) {
            DAT_a802d290.b01e = FUN_a014459c(0);
            FUN_a00b8804();
        }
    } else if (p[7] == 9) {
        if (FUN_a01445fc(DAT_a802d290.b01e) != 1) {
            DAT_a802d290.b01e = FUN_a014459c(1);
            FUN_a00b8804();
        }
    } else if (p[7] == 0xd) {
        if (FUN_a01445fc(DAT_a802d290.b01e) != 2) {
            DAT_a802d290.b01e = FUN_a014459c(2);
            FUN_a00b8804();
        }
    } else if (p[7] == 0xf) {
        if (FUN_a01445fc(DAT_a802d290.b01e) != 3) {
            DAT_a802d290.b01e = FUN_a014459c(3);
            FUN_a00b8804();
        }
    }
    FUN_a0089f10();
    return 0xe0;
}
