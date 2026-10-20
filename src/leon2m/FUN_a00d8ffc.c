/* leon2m FUN_a00d8ffc @ 0xa00d8ffc-0xa00d9120 (73 words).
 * Reads bit 31 of the word at 0xa802d290+0x11c and writes it back. The value selects m (0, 1, 2). m becomes 0
 * when FUN_a014bd70(0) returns 1, or when FUN_a01438dc(0) returns 1 and FUN_a014ba68() returns 1..4.
 * FUN_a01492b8(m & 3) is called; when bit 31 of the word is then clear, FUN_a00d8cd4() follows as a tail call.
 * The bit is read into an unsigned char m, copied to sel, written back, and the case labels 0..2 of sel set m.
 * Each case of the FUN_a014ba68 switch has its own body (shared labels give a range test).
 */
struct W11c {
    unsigned int top : 1;
    unsigned int rest : 31;
};
struct R290 {
    unsigned char pad0[0x11c];
    struct W11c w11c;
};
extern struct R290 DAT_a802d290;
extern unsigned char FUN_a014bd70(int);
extern unsigned char FUN_a01438dc(int);
extern unsigned char FUN_a014ba68(void);
extern void FUN_a01492b8(unsigned char);
extern void FUN_a00d8cd4(void);

void FUN_a00d8ffc(void)
{
    unsigned char m = DAT_a802d290.w11c.top;
    unsigned char sel = m;

    DAT_a802d290.w11c.top = sel;
    switch (sel) {
    case 0: m = 0; break;
    case 1: m = 1; break;
    case 2: m = 2; break;
    }
    if (FUN_a014bd70(0) == 1)
        m = 0;
    else if (FUN_a01438dc(0) == 1) {
        switch (FUN_a014ba68()) {
        case 1: m = 0; break;
        case 2: m = 0; break;
        case 3: m = 0; break;
        case 4: m = 0; break;
        }
    }
    FUN_a01492b8(m & 3);
    if (!DAT_a802d290.w11c.top)
        FUN_a00d8cd4();
}
