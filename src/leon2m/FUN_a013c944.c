/* leon2m FUN_a013c944 @ 0xa013c944..0xa013cd4c (258 words): input-channel records reset, start-up step 7 of
 * FUN_a015266c, called AFTER FUN_a0141964 (src/leon2m/FUN_a015266c.c: FUN_a012cfac, FUN_a00fd558, FUN_a0141964,
 * FUN_a015209c, FUN_a013c944), so it runs only when the display start-up path has returned.
 * BYTE-EXACT: -mcpu=v8 -O3 -g -msoft-float: jf 100.00 match=True, rawcmp 0/258, tools/exact.py
 * exact() = None. (Without -msoft-float: 20.54; the loop pass then hoists other mask constants.)
 * In plain words: it puts the four input-channel records (RAM 0xA802DF30, 4 x 0x78 bytes, the records the channel
 * state machine FUN_a013dc6c steps through) into their start state: channel 0 gets state 5, the other three state 0,
 * each gets its id, port number, a 500 timer value and cleared flags, and the output-timing halves are copied from
 * the active panel row. Pure RAM writes: no hardware register, no wait, all loops are fixed (i < 4).
 * What it does (code facts from this C; field names of word +0 as in FUN_a013dc6c / FUN_a013ce10):
 *  - E[0]: h74 = 500; w0: state 5, f24 5, step 0, f4 0, id 0, port 0, f16 0; w70: bits 24, 30, 20 set, bits 17, 16
 *    cleared, field 13..12 = 1.
 *  - i = 1..3: w0 state 0, f24 0, step 0; w70 bit 24 cleared, bit 23 set, bits 20, 17, 16 cleared, field 13..12 = 1;
 *    h74 = 500; i == 1: id 1 and w70 bit 30 set, else bit 30 cleared and id 2; port = ROM byte 0x1A57C0[i] (FW.021:
 *    00 02 01 03, so ports 2, 1, 3; flash file offset 0x2AD7C0), f4 = 1 for i == 1 (switch default)
 *    and 4 for i == 2 / 3; f16 = i.
 *    The table address comes from sethi %hi(0x1A5400) + or 0x3C0 = 0x1A57C0 (DAT_001a57c0).
 *  - i = 0..3: w0 bit 0 = (i == 0) (if/else); w70 bits 31, 29, 28, 27, 26, 25 cleared, field 15..14 = 0, bit 18 set,
 *    bit 22 cleared (bit 22 = 'run the state machine again in this call', FUN_a013dc6c); w68 bit 23 set, bit 20
 *    cleared; halves +0x4A = +0x4C = R.h08, +0x52 = +0x54 = R.h0A, +0x4E = +0x50 = R.h28 + R.h26, +0x58 = +0x56 =
 *    R.h32 + R.h30, +0x5A = +0x5C = 0 (R = the active panel row RAM 0xA802E378).
 *  - Tail: if RAM word 0xA802E3D0 bit 21 is set, FUN_a01302e0(3, 1) as a tail call.
 * It neither waits nor fails: every loop has a fixed bound, the only call is the tail call, no hardware access.
 * Levers (documented, no-code):
 *  (1) one bitfield statement per field (struct W0 / W70 / W68 over the words +0 / +0x70 / +0x68): the fw's chains of
 *      and/or masks are exactly gcc's bitfield stores; combine merges the small masks (f4 + id -> 'and -255') and
 *      widens the field 13..12 clear with the known-zero bits ('andn 0x33000' / 'andn 0x133000').
 *  (2) loop 1: the switch arms in the order default (f4 = 1), case 2, case 3: 91 jf vs 31..84 for other orders (the
 *      case-3 arm then reads ROM[3] with the constant index as in the fw).
 *  (3) E[0]: 'h74 = 500' as the first statement (fw stores h74 before w70); chained 'a = b = x' stores b first, so
 *      the pairs are written in the fw's store order (h4a = h4c, h52 = h54, h4e = h50, h58 = h56, h5c = h5a).
 *  (4) loop 3: the w68 statements after the halves and 'b22 = 0' last.
 *  (5) -msoft-float (as for FUN_a01243dc / FUN_a012cfac): changes which mask constants loop.c hoists.
 */
struct W0 { unsigned int state:4, f24:4, step:4, f16:4, port:4, f8:4, f4:4, id:3, b0:1; };
struct W70 { unsigned int b31:1, b30:1, b29:1, b28:1, b27:1, b26:1, b25:1, b24:1, b23:1, b22:1, b21:1, b20:1,
             b19:1, b18:1, b17:1, b16:1, f14:2, f12:2, rest:12; };
struct W68 { unsigned int r24:8, b23:1, b22:1, b21:1, b20:1, rest:20; };
struct Chan {
    struct W0 w0;                    /* +0x00 */
    unsigned char p04[0x4a - 0x04];
    unsigned short h4a, h4c, h4e, h50, h52, h54, h56, h58, h5a, h5c;
    unsigned char p5e[0x68 - 0x5e];
    struct W68 w68;                  /* +0x68 */
    unsigned char p6c[4];
    struct W70 w70;                  /* +0x70 */
    unsigned short h74;              /* +0x74 */
    unsigned char p76[2];
};
struct Row378 { unsigned char p00[8]; unsigned short h08, h0a; unsigned char p0c[0x26 - 0x0c];
                unsigned short h26, h28; unsigned char p2a[0x30 - 0x2a]; unsigned short h30, h32; };
extern struct Chan DAT_a802df30[4];
extern struct Row378 DAT_a802e378;
extern unsigned int DAT_a802e3d0;
extern const unsigned char DAT_001a57c0[];
extern void FUN_a01302e0(unsigned char, unsigned char);

void FUN_a013c944(void)
{
    unsigned char i;

    DAT_a802df30[0].h74 = 500;
    DAT_a802df30[0].w0.state = 5;
    DAT_a802df30[0].w0.f24 = 5;
    DAT_a802df30[0].w0.step = 0;
    DAT_a802df30[0].w0.f4 = 0;
    DAT_a802df30[0].w0.id = 0;
    DAT_a802df30[0].w0.port = 0;
    DAT_a802df30[0].w0.f16 = 0;
    DAT_a802df30[0].w70.b24 = 1;
    DAT_a802df30[0].w70.b30 = 1;
    DAT_a802df30[0].w70.b20 = 1;
    DAT_a802df30[0].w70.b17 = 0;
    DAT_a802df30[0].w70.b16 = 0;
    DAT_a802df30[0].w70.f12 = 1;
    for (i = 1; i < 4; i++) {
        DAT_a802df30[i].w0.state = 0;
        DAT_a802df30[i].w0.f24 = 0;
        DAT_a802df30[i].w70.b24 = 0;
        DAT_a802df30[i].w0.step = 0;
        DAT_a802df30[i].w70.b23 = 1;
        DAT_a802df30[i].w70.b20 = 0;
        DAT_a802df30[i].w70.b17 = 0;
        DAT_a802df30[i].w70.b16 = 0;
        DAT_a802df30[i].w70.f12 = 1;
        DAT_a802df30[i].h74 = 500;
        if (i == 1) {
            DAT_a802df30[i].w0.id = 1;
            DAT_a802df30[i].w70.b30 = 1;
        } else {
            DAT_a802df30[i].w70.b30 = 0;
            DAT_a802df30[i].w0.id = 2;
        }
        switch (i) {
        default:
            DAT_a802df30[i].w0.port = DAT_001a57c0[i];
            DAT_a802df30[i].w0.f4 = 1;
            break;
        case 2:
            DAT_a802df30[i].w0.port = DAT_001a57c0[i];
            DAT_a802df30[i].w0.f4 = 4;
            break;
        case 3:
            DAT_a802df30[i].w0.port = DAT_001a57c0[i];
            DAT_a802df30[i].w0.f4 = 4;
            break;
        }
        DAT_a802df30[i].w0.f16 = i;
    }

    for (i = 0; i < 4; i++) {
        if (i == 0)
            DAT_a802df30[i].w0.b0 = 1;
        else
            DAT_a802df30[i].w0.b0 = 0;
        DAT_a802df30[i].w70.b31 = 0;
        DAT_a802df30[i].w70.b29 = 0;
        DAT_a802df30[i].w70.b28 = 0;
        DAT_a802df30[i].w70.b27 = 0;
        DAT_a802df30[i].w70.b26 = 0;
        DAT_a802df30[i].w70.b25 = 0;
        DAT_a802df30[i].w70.f14 = 0;
        DAT_a802df30[i].w70.b18 = 1;
        DAT_a802df30[i].h4a = DAT_a802df30[i].h4c = DAT_a802e378.h08;
        DAT_a802df30[i].h52 = DAT_a802df30[i].h54 = DAT_a802e378.h0a;
        DAT_a802df30[i].h4e = DAT_a802df30[i].h50 = DAT_a802e378.h28 + DAT_a802e378.h26;
        DAT_a802df30[i].h58 = DAT_a802df30[i].h56 = DAT_a802e378.h32 + DAT_a802e378.h30;
        DAT_a802df30[i].w68.b23 = 1;
        DAT_a802df30[i].w68.b20 = 0;
        DAT_a802df30[i].h5c = DAT_a802df30[i].h5a = 0;
        DAT_a802df30[i].w70.b22 = 0;
    }
    if (DAT_a802e3d0 & 0x200000)
        FUN_a01302e0(3, 1);
}
