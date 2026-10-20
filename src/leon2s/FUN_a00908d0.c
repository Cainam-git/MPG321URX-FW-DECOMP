/* leon2s FUN_a00908d0 @ 0xa00908d0-0xa0090d7c (299 words; FUN_a0090d74 = unreachable ret/restore tail inside the
 * range), flags -mcpu=v8 -Os -g.
 *
 * What it does: the per-pass interrupt/status poll of one HDMI receiver port while the link FSM (LINK_STANDBY) is in
 * state 5 (link up, timing stable; its only caller). rec = ARR_a807d3e4[port] (0xb0-byte RX state per port).
 * Status registers are read with FUN_a00a657c(port, reg) and a set bit is cleared by writing it back (FUN_a00a65c4).
 *   rec+0xa6 = 0 first, then 1 when reg 0x72 bit 7 or reg 0x73 bit 6 is set (each written back: 0x80 / 0x40).
 *   reg 0x72 bit 1: rec+0x8a = rec+0x8b = 1; if rec+0x8c == 0: FUN_a0090498(port, rec+0x6b) (packet area 0x280).
 *   reg 0x73 bit 2: rec+0x68/0x69 = 1; rec+0x6a == 0 -> FUN_a0090718(port, rec+0x5a) (area 0x180, header 0x84);
 *     then reg 0x7a bit 2 of both ports (port 2) cleared via FUN_a00a67b8(2, 0x7a, 4, 0).
 *   reg 0x73 bit 1: only when FUN_a008f79c(port) == 0 (no FreeSync/VTEM flags): rec+0x41/0x42 = 1, rec+0x43 == 0 ->
 *     FUN_a0090568(port, rec+0x22) (area 0x160); reg 0x7a bit 1 cleared.
 *   reg 0x73 bit 0: rec+0x57/0x58 = 1, rec+0x59 == 0 -> FUN_a00907f0(port, rec+0x44) (area 0x140, header 0x82),
 *     time stamp rec+0xa8 = FUN_a00b2064(). Bit 0 clear: if FUN_a007517c(FUN_a008f4d0(port) = port == 1) and
 *     FUN_a008f990(rec+0xa8) (> 0x32 ticks since the stamp) and FUN_a008f9c0(port) (reg 0x134 bit 1): rec+0xac = 1.
 *   reg 0x74 != 0: if regs 0x280 and 0x281 are nonzero, bits 0 and 1 each pulse reg 5 bit 1 (1, 0, FUN_a00b1794(5));
 *     bit 7 -> FUN_a008f744(port); then the value is written back.
 *   reg 0x84 != 0: bit 0 -> rec+0x1f/0x20 = 1 and, if rec+0x21 == 0, FUN_a0090638(port, rec) (area 0x1b0, header
 *     0x87), else both 0; rec+0xa7 = 0 unless reg 0x29f == 2 (then, with bit 1: rec+0xa7 = reg 0x281 bit 4); reg
 *     0x1af == 9 and bit 2 -> rec+0xa7 = 2; value written back.
 * rec+0xa6 is the source of the Big chip's keep-going bit. FUN_a006d61c copies
 * FUN_a008f9e4(port) (= rec+0xa6) into port-record halfword +0xe bit 14 (byte 0xe bit 6), FUN_a006fbac sends byte 0xe
 * as mailbox word 0 bits 16..23, FUN_a01387a4 (Big chip) stores it as template byte 0xd, FUN_a0136d20 copies it to
 * entry byte 3 = DAT_a802e116[idx] h2 bit 6, which FUN_a01420e4 / FUN_a0132964 test in dc6c states 9 and 12.
 * So the bit is 1 only for a state-5 pass in which reg 0x72 bit 7 or reg 0x73 bit 6 was latched (the state 4 -> 5
 * step clears regs 0x72/0x73/0x74/0x84 with 0xff, FUN_a008fa30); in every other state-5 pass it is 0 (outside
 * state 5 nothing writes it). A change of byte 0xe sets rec[0xf] (re-publish) at the end of the LINK_STANDBY pass.
 * Header codes 0x82/0x84/0x87 are the bytes the handlers compare (the CTA-861 AVI /
 * Audio / DRM InfoFrame type codes).
 *
 * Required forms: FUN_a007517c takes FUN_a008f4d0(port)'s result; FUN_a0090638 takes the record as 2nd argument (fw leaves rec in %o1; its body writes buf[0..0x1e]).
 * Matching form: u8 status locals; the 0x74 and 0x84 blocks are static functions with a u8 port (inlined; they give the
 * fw join re-extensions of port); struct RxSt with the u32 time stamp at +0xa8 and byte +0xac; flag pairs stored in
 * source order hi-then-lo (sched1 gives the fw lo-then-hi); in the 0x74 block 'unsigned int m = r & 2' taken before
 * the 0x280 read (the fw keeps r & 2 in %l1 across the calls); u8 returns of FUN_a008f990 / FUN_a008f9c0 (both
 * return 0/1: subx / addx). Aids: none (no volatile, no asm, no dummy code).
 */
struct RxSt { unsigned char b[0xa8]; unsigned int t; unsigned char bac, bad, bae, baf; };
extern struct RxSt ARR_a807d3e4[];
extern unsigned char FUN_a008f4d0(unsigned char);
extern unsigned char FUN_a007517c(unsigned int);
extern void FUN_a008f744(unsigned char);
extern unsigned char FUN_a008f79c(unsigned char);
extern unsigned char FUN_a008f990(unsigned int t0);
extern unsigned char FUN_a008f9c0(unsigned char);
extern void FUN_a0090498(unsigned char, unsigned char *);
extern void FUN_a0090568(unsigned char, unsigned char *);
extern void FUN_a0090638(unsigned char, unsigned char *);
extern void FUN_a0090718(unsigned char, unsigned char *);
extern int FUN_a00907f0(unsigned char, unsigned char *);
extern unsigned int FUN_a00a657c(unsigned int, unsigned short);
extern void FUN_a00a65c4(unsigned int, unsigned short, unsigned int);
extern void FUN_a00a67b8(unsigned int, unsigned int, unsigned int, unsigned int);
extern void FUN_a00b1794(int);
extern unsigned int FUN_a00b2064(void);

static void h74(unsigned char port)
{
    unsigned int m; unsigned char r;
    r = FUN_a00a657c(port, 0x74);
    if (r != 0) {
        m = r & 2;
        if (FUN_a00a657c(port, 0x280) & 0xff) {
            if (FUN_a00a657c(port, 0x281) & 0xff) {
                if (r & 1) {
                    FUN_a00a67b8(port, 5, 2, 1);
                    FUN_a00a67b8(port, 5, 2, 0);
                    FUN_a00b1794(5);
                }
                if (m) {
                    FUN_a00a67b8(port, 5, 2, 1);
                    FUN_a00a67b8(port, 5, 2, 0);
                    FUN_a00b1794(5);
                }
            }
        }
        if (r & 0x80)
            FUN_a008f744(port);
        FUN_a00a65c4(port, 0x74, r);
    }
}
static void h84(unsigned char port)
{
    unsigned char r;
    r = FUN_a00a657c(port, 0x84);
    if (r != 0) {
        if (r & 1) {
            ARR_a807d3e4[port].b[0x20] = 1;
            ARR_a807d3e4[port].b[0x1f] = 1;
            if (ARR_a807d3e4[port].b[0x21] == 0)
                FUN_a0090638(port, ARR_a807d3e4[port].b);
        } else {
            ARR_a807d3e4[port].b[0x20] = 0;
            ARR_a807d3e4[port].b[0x1f] = 0;
        }
        if ((FUN_a00a657c(port, 0x29f) & 0xff) == 2) {
            if (r & 2) {
                if (FUN_a00a657c(port, 0x281) & 0x10)
                    ARR_a807d3e4[port].b[0xa7] = 1;
                else
                    ARR_a807d3e4[port].b[0xa7] = 0;
            }
        } else {
            ARR_a807d3e4[port].b[0xa7] = 0;
        }
        if ((FUN_a00a657c(port, 0x1af) & 0xff) == 9 && (r & 4))
            ARR_a807d3e4[port].b[0xa7] = 2;
        FUN_a00a65c4(port, 0x84, r);
    }
}
void FUN_a00908d0(unsigned char port)
{
    unsigned char one;
    unsigned char r;

    one = FUN_a008f4d0(port);
    ARR_a807d3e4[port].b[0xa6] = 0;

    r = FUN_a00a657c(port, 0x72);
    if (r != 0) {
        if (r & 0x80) {
            ARR_a807d3e4[port].b[0xa6] = 1;
            FUN_a00a65c4(port, 0x72, 0x80);
        }
        if (r & 2) {
            ARR_a807d3e4[port].b[0x8b] = 1;
            ARR_a807d3e4[port].b[0x8a] = 1;
            if (ARR_a807d3e4[port].b[0x8c] == 0)
                FUN_a0090498(port, &ARR_a807d3e4[port].b[0x6b]);
            FUN_a00a65c4(port, 0x72, 2);
        }
    }

    r = FUN_a00a657c(port, 0x73);
    if (r & 0x40) {
        ARR_a807d3e4[port].b[0xa6] = 1;
        FUN_a00a65c4(port, 0x73, 0x40);
    }
    if (r & 4) {
        ARR_a807d3e4[port].b[0x69] = 1;
        ARR_a807d3e4[port].b[0x68] = 1;
        if (ARR_a807d3e4[port].b[0x6a] == 0)
            FUN_a0090718(port, &ARR_a807d3e4[port].b[0x5a]);
        FUN_a00a65c4(port, 0x73, 4);
        FUN_a00a67b8(2, 0x7a, 4, 0);
    }
    if (r & 2) {
        if (FUN_a008f79c(port) == 0) {
            ARR_a807d3e4[port].b[0x42] = 1;
            ARR_a807d3e4[port].b[0x41] = 1;
            if (ARR_a807d3e4[port].b[0x43] == 0)
                FUN_a0090568(port, &ARR_a807d3e4[port].b[0x22]);
        }
        FUN_a00a65c4(port, 0x73, 2);
        FUN_a00a67b8(2, 0x7a, 2, 0);
    }
    if (r & 1) {
        ARR_a807d3e4[port].b[0x58] = 1;
        ARR_a807d3e4[port].b[0x57] = 1;
        if (ARR_a807d3e4[port].b[0x59] == 0)
            FUN_a00907f0(port, &ARR_a807d3e4[port].b[0x44]);
        FUN_a00a65c4(port, 0x73, 1);
        ARR_a807d3e4[port].t = FUN_a00b2064();
    } else if (FUN_a007517c(one)) {
        if (FUN_a008f990(ARR_a807d3e4[port].t))
            if (FUN_a008f9c0(port))
                ARR_a807d3e4[port].bac = 1;
    }

    h74(port);
    h84(port);
}
