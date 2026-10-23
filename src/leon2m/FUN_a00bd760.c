/* leon2m FUN_a00bd760 @ 0xa00bd760-0xa00bd988 (138 words).
 * Reply: fills the 11-byte buffer at 0xa802d078 with [7] = '0', [8] = '0' + bit 11 of word 0xa802d338 and [9] =
 * a digit: when bit 11 is set, the ASCII digit of byte 0xa802d411 if it is 0..7 (unchanged otherwise), else '0' +
 * (byte 0xa802d412 + 5) % 6. [0] = FUN_a015463c(0x2c, 0), [1] = 'b', [2..6] = FUN_a015463c(0x2c, 2..6), [10] = '\r'.
 * Then the port's receive state is cleared and FUN_a01487e8(port, 0xb, buffer) is tail-called. Source form: as
 * FUN_a00bd070 (switch with case 7 written first), with the !(w & 0x800) arm first and the fields read through the
 * structure at 0xa802d290; the function covers its case blocks up to 0xa00bd988.
 */
extern unsigned char DAT_a802d078[11];
struct G290 {
    unsigned char pad0[0xa8];
    unsigned int w0a8;          /* 0xa802d338 */
    unsigned char pad1[0x181 - 0xac];
    unsigned char b181;         /* 0xa802d411 */
    unsigned char b182;         /* 0xa802d412 */
};
extern struct G290 DAT_a802d290;
extern unsigned char DAT_a802b09a, DAT_a802b098, DAT_a802b09c;
extern unsigned char DAT_a802d040[], DAT_a802d098[], DAT_a802d0d0[];
extern unsigned char FUN_a015463c(unsigned short, unsigned short);
extern void FUN_a01487e8(unsigned char, int, unsigned char *);

void FUN_a00bd760(unsigned char port)
{
    unsigned int w = DAT_a802d290.w0a8;

    DAT_a802d078[7] = '0';
    DAT_a802d078[8] = ((w >> 11) & 1) + '0';
    if (!(w & 0x800))
        DAT_a802d078[9] = (DAT_a802d290.b182 + 5) % 6 + '0';
    else {
        switch (DAT_a802d290.b181) {
        case 7:
            DAT_a802d078[9] = '7';
            break;
        case 0:
            DAT_a802d078[9] = '0';
            break;
        case 1:
            DAT_a802d078[9] = '1';
            break;
        case 2:
            DAT_a802d078[9] = '2';
            break;
        case 3:
            DAT_a802d078[9] = '3';
            break;
        case 4:
            DAT_a802d078[9] = '4';
            break;
        case 5:
            DAT_a802d078[9] = '5';
            break;
        case 6:
            DAT_a802d078[9] = '6';
            break;
        }
    }
    DAT_a802d078[0] = FUN_a015463c(0x2c, 0);
    DAT_a802d078[1] = 'b';
    DAT_a802d078[2] = FUN_a015463c(0x2c, 2);
    DAT_a802d078[3] = FUN_a015463c(0x2c, 3);
    DAT_a802d078[4] = FUN_a015463c(0x2c, 4);
    DAT_a802d078[5] = FUN_a015463c(0x2c, 5);
    DAT_a802d078[6] = FUN_a015463c(0x2c, 6);
    DAT_a802d078[10] = '\r';
    if (port == 2) {
        DAT_a802b09a = 0;
        DAT_a802d040[0] = 0;
        DAT_a802d040[1] = 0;
        DAT_a802d040[7] = 0;
        DAT_a802d040[10] = 0;
        DAT_a802d040[0x19] = 0;
    } else if (port == 3) {
        DAT_a802b098 = 0;
        DAT_a802d098[0] = 0;
        DAT_a802d098[1] = 0;
        DAT_a802d098[7] = 0;
        DAT_a802d098[10] = 0;
        DAT_a802d098[0x19] = 0;
    } else {
        DAT_a802b09c = 0;
        DAT_a802d0d0[0] = 0;
        DAT_a802d0d0[1] = 0;
        DAT_a802d0d0[7] = 0;
        DAT_a802d0d0[10] = 0;
        DAT_a802d0d0[0x19] = 0;
    }
    FUN_a01487e8(port, 0xb, DAT_a802d078);
}
