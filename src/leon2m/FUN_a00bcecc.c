/* FUN_a00bcecc (leon2m 0xa00bcecc-0xa00bd070, 420 bytes), flags -mcpu=v8 -O3 -g.
 * Fills the 11-byte buffer at 0xa802d078 with [7] = [8] = '0', [9] = '0' + d where d is taken from
 * byte 0xa802d434 by the mapping 0 -> 0, 1 -> 1, 2 -> 2, 4 -> 3, 3 -> 5, 5 -> 7, 6 -> 8 (any other value -> 0),
 * [0] = FUN_a015463c(0x22, 0), [1] = 'b', [2..6] = FUN_a015463c(0x22, 2..6) and [10] = '\r'; then clears the port's
 * receive bytes (the inlined body of FUN_a00ba950) and tail-calls FUN_a01487e8(port, 0xb, buffer).
 * Source form: an if/else chain tested in the order 0, 1, 2, 4, 3, 5, 6.
 */
extern unsigned char DAT_a802d078[11];
extern unsigned char DAT_a802d434;
extern unsigned char DAT_a802b09a, DAT_a802b098, DAT_a802b09c;
extern unsigned char DAT_a802d040[], DAT_a802d098[], DAT_a802d0d0[];
extern unsigned char FUN_a015463c(unsigned short, unsigned short);
extern void FUN_a01487e8(unsigned char, unsigned short, unsigned char *);

void FUN_a00bcecc(unsigned char port)
{
    unsigned char d = 0;

    if (DAT_a802d434 == 0)
        d = 0;
    else if (DAT_a802d434 == 1)
        d = 1;
    else if (DAT_a802d434 == 2)
        d = 2;
    else if (DAT_a802d434 == 4)
        d = 3;
    else if (DAT_a802d434 == 3)
        d = 5;
    else if (DAT_a802d434 == 5)
        d = 7;
    else if (DAT_a802d434 == 6)
        d = 8;
    DAT_a802d078[7] = '0';
    DAT_a802d078[8] = '0';
    DAT_a802d078[9] = d + '0';
    DAT_a802d078[0] = FUN_a015463c(0x22, 0);
    DAT_a802d078[1] = 'b';
    DAT_a802d078[2] = FUN_a015463c(0x22, 2);
    DAT_a802d078[3] = FUN_a015463c(0x22, 3);
    DAT_a802d078[4] = FUN_a015463c(0x22, 4);
    DAT_a802d078[5] = FUN_a015463c(0x22, 5);
    DAT_a802d078[6] = FUN_a015463c(0x22, 6);
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
