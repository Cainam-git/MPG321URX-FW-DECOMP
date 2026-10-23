/* leon2m FUN_a002f550 @ 0xa002f550 (RAM copy, runs at 0x4008F550)  refresh the four port entries from the Small-chip
 * templates and patch their type/flag bits (flags -mcpu=v8 -O3 -g).
 *
 * Entries E0..E3 = 18-byte records at 0xA802E116 / E128 / E13A / E14C (h0 bits 15..12 = type nibble).
 * For n = 0..3: FUN_a0136d20(n) (call shows as 'call 0xd6d20' = func_0x000d6d20) copies template t = n + 2 into En.
 *   E0 / E1 (n = 0 / 1): if the type is 5: bit 0x400 = FUN_a0110f4c(2 / 3) & 1, bit 0x200 = FUN_a0110f4c(2 / 3) & 1,
 *     and if bit 0x200 is then set, bit 0x100 = FUN_a0110f54(2 / 3) & 1. (In FW.021 FUN_a0110f4c returns 0, so for a
 *     type-5 entry bits 0x400 and 0x200 end up cleared and 0x100 is left alone.) The 'else' arm (clear 0x600) is dead
 *     code: the outer and inner tests are the same 'type == 5', written once through an (unsigned char) read.
 *   E2 / E3 (n = 2 / 3, flag bit b = 1 / 2): if type != 5: 0xA802CC0B &= ~b. If type == 5 AND 0xA802E3D0 bit 19 (0x80000)
 *     AND E +2 bit 15 (template flags bit 5): on first sight (0xA802CC0B bit b clear) set it and store the tick
 *     FUN_a002d588() in 0xA802CC0C[n - 2]; then while FUN_a002d594(start) (= ticks since) < 1000 print
 *     'Mute when Hdcp22Auth\r\n' and set the type nibble to 2. Finally if type != 5: 0xA802CC0A &= ~b.
 * Entry bit 4 (0x10, source of the 0xA802CBD4 port bit): this function never touches it; it only
 *   calls FUN_a0136d20 (which writes it) and changes bits 0x400/0x200/0x100 (E0/E1) and the type nibble 5 -> 2 (E2/E3,
 *   for up to 1000 ticks after first sight, the window in which it prints 'Mute when Hdcp22Auth').
 *   A type rewritten to 2 makes FUN_a0142910's type-5 test fail for that port.
 * Callers: FUN_a0153018 (call 0x4008F550 at 0xA015301C, its first statement; FUN_a0142910 is called right after).
 * Source form: one extern per entry (E0/E1 addressed with their own %hi/%lo); E2/E3 through a pointer local
 *   (gcc keeps &E in a register: 'or %l0,0x13a,%l1', then [l1], [l1+2]); the outer test as
 *   '(unsigned char)e.type == 5' (keeps the sll/srl 28 extraction) and the inner/other tests as plain 'e.type == 5'
 *   (fold turns those into '(h & 0xf000) == 0x5000'); bitfield struct for the flags.
 */
struct EntryBits {
    unsigned short type:4;     /* h0 bits 15..12 */
    unsigned short b11:1;
    unsigned short f10:1;      /* 0x400 */
    unsigned short f9:1;       /* 0x200 */
    unsigned short f8:1;       /* 0x100 */
    unsigned short lo:8;
    unsigned short f5:1;       /* +2 bit 15 */
    unsigned short h2_rest:15;
};
struct Entry {
    struct EntryBits b;
    unsigned short h[7];
};
extern struct Entry DAT_a802e116, DAT_a802e128, DAT_a802e13a, DAT_a802e14c;
extern unsigned char DAT_a802cc0a, DAT_a802cc0b;
extern unsigned short DAT_a802cc0c[];
extern unsigned int DAT_a802e3d0;
extern char s_001a6ac0[];                      /* "Mute when Hdcp22Auth\r\n" */
extern void func_0x000d6d20(unsigned char);
extern int func_0x000b0f4c();
extern int func_0x000b0f54();
extern int func_0x0007f170();
extern unsigned short FUN_a002d588(void);
extern unsigned short FUN_a002d594(unsigned short);

#define OUTER(e) ((unsigned char)(e).b.type == 5)     /* keeps the sll/srl extraction */
#define IS5(e) ((e).b.type == 5)                      /* folded to (h & 0xf000) == 0x5000 */

void FUN_a002f550(void)
{
    struct Entry *p;

    func_0x000d6d20(0);
    if (OUTER(DAT_a802e116)) {
        if (IS5(DAT_a802e116)) {
            DAT_a802e116.b.f10 = func_0x000b0f4c(2);
            DAT_a802e116.b.f9 = func_0x000b0f4c(2);
            if (DAT_a802e116.b.f9)
                DAT_a802e116.b.f8 = func_0x000b0f54(2);
        } else {
            DAT_a802e116.b.f10 = 0;
            DAT_a802e116.b.f9 = 0;
        }
    }
    func_0x000d6d20(1);
    if (OUTER(DAT_a802e128)) {
        if (IS5(DAT_a802e128)) {
            DAT_a802e128.b.f10 = func_0x000b0f4c(3);
            DAT_a802e128.b.f9 = func_0x000b0f4c(3);
            if (DAT_a802e128.b.f9)
                DAT_a802e128.b.f8 = func_0x000b0f54(3);
        } else {
            DAT_a802e128.b.f10 = 0;
            DAT_a802e128.b.f9 = 0;
        }
    }
    func_0x000d6d20(2);
    p = &DAT_a802e13a;
    if (!IS5(*p))
        DAT_a802cc0b &= ~1;
    if (OUTER(*p) && (DAT_a802e3d0 & 0x80000) && p->b.f5) {
        if (!(DAT_a802cc0b & 1)) {
            DAT_a802cc0b |= 1;
            DAT_a802cc0c[0] = FUN_a002d588();
        }
        if (FUN_a002d594(DAT_a802cc0c[0]) < 1000) {
            func_0x0007f170(s_001a6ac0);
            p->b.type = 2;
        }
    }
    if (!IS5(*p))
        DAT_a802cc0a &= ~1;
    func_0x000d6d20(3);
    p = &DAT_a802e14c;
    if (!IS5(*p))
        DAT_a802cc0b &= ~2;
    if (OUTER(*p) && (DAT_a802e3d0 & 0x80000) && p->b.f5) {
        if (!(DAT_a802cc0b & 2)) {
            DAT_a802cc0b |= 2;
            DAT_a802cc0c[1] = FUN_a002d588();
        }
        if (FUN_a002d594(DAT_a802cc0c[1]) < 1000) {
            func_0x0007f170(s_001a6ac0);
            p->b.type = 2;
        }
    }
    if (!IS5(*p))
        DAT_a802cc0a &= ~2;
}
