/* leon2m FUN_a00bc3f8 @ 0xa00bc3f8-0xa00bc574 (95 words).
 * Fills the 11-byte message buffer at 0xa802d078: [7], [8], [9] = the hundreds, tens and ones digit of the byte
 * 0xa802d2a2 as ASCII, [0] = FUN_a015463c(0x7, 0), [1] = 'b', [2..6] = FUN_a015463c(0x7, 2..6), [10] = '\r'
 * (row 0x7 of the command table read by FUN_a015463c). Then, by port: port 2 clears byte 0xa802b09a and bytes
 * 0, 1, 7, 10, 0x19 of the record at 0xa802d040; port 3 clears byte 0xa802b098 and the same bytes of the record at
 * 0xa802d098; any other port clears byte 0xa802b09c and the record at 0xa802d0d0. Ends with the tail call
 * FUN_a01487e8(port, 0xb, buffer).
 * Same code as FUN_a00bbda0 with another source byte and table row; the same source form applies (digits computed
 * into unsigned char locals of one inner block, stored afterwards).
 */
extern unsigned char DAT_a802d078[11];
extern unsigned char DAT_a802d2a2;
extern unsigned char DAT_a802b09a, DAT_a802b098, DAT_a802b09c;
extern unsigned char DAT_a802d040[], DAT_a802d098[], DAT_a802d0d0[];
extern unsigned char FUN_a015463c(unsigned short, unsigned short);
extern void FUN_a01487e8(unsigned char, unsigned short, unsigned char *);

void FUN_a00bc3f8(unsigned char port)
{
    {
        unsigned char v = DAT_a802d2a2, h, r, t, o;
        h = v / 100;
        r = v - h * 100;
        t = r / 10;
        o = r - t * 10;
        DAT_a802d078[7] = h + '0';
        DAT_a802d078[8] = t + '0';
        DAT_a802d078[9] = o + '0';
    }
    DAT_a802d078[0] = FUN_a015463c(7, 0);
    DAT_a802d078[1] = 'b';
    DAT_a802d078[2] = FUN_a015463c(7, 2);
    DAT_a802d078[3] = FUN_a015463c(7, 3);
    DAT_a802d078[4] = FUN_a015463c(7, 4);
    DAT_a802d078[5] = FUN_a015463c(7, 5);
    DAT_a802d078[6] = FUN_a015463c(7, 6);
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
