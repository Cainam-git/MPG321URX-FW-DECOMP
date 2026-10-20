/* leon2s FUN_a006d414 @ 0xa006d414  set the type byte (+0) of one input port record
 * Flags: -mcpu=v8 -Os -g, over 0xa006d414-0xa006d46c.
 *
 * rec = port record 0xA807A824 + 20 * n (9 records, the same table FUN_a006fbac / FUN_a00700cc read).
 * n 0..8: rec[n].b0 = type. n == 0xFF: records 0..5 only (not 6..8) get the type. Any other n: no change.
 * The low nibble of b0 is the port type that FUN_a00700cc packs into mailbox word 0 bits 4..31 (4 bits per port,
 * ports 0..6) for the Big chip (FUN_a01387a4 -> template byte +0 -> 18-byte entry type nibble; the line-rate
 * switch is used only for type 5). Only caller in decomp/leon2s.c: FUN_a0070b7c, which passes
 * (w & 0xff, (w >> 8) & 0xff) of the word at param_1 + 4 (a command word).
 * Layout key: the 'n > 8' test written first (if n > 8 { if n == 0xff ... } else ...) gives the firmware block
 * order (0xFF case falls through, single-record store at the end).
 */
struct PortRec { unsigned char b0, b1; unsigned short h2, h4, h6, h8, ha; unsigned char bc, bd, be, bf, b10, b11, b12, b13; };
extern struct PortRec DAT_a807a824[];

void FUN_a006d414(unsigned char n, unsigned char type)
{
    if (n > 8) {
        if (n == 0xff) {
            DAT_a807a824[0].b0 = type;
            DAT_a807a824[1].b0 = type;
            DAT_a807a824[2].b0 = type;
            DAT_a807a824[3].b0 = type;
            DAT_a807a824[4].b0 = type;
            DAT_a807a824[5].b0 = type;
        }
    } else
        DAT_a807a824[n].b0 = type;
}
