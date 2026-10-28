/* leon2m FUN_a00bf7dc @ 0xa00bf7dc-0xa00bfb28 (211 words), flags -mcpu=v8 -O3 -g. Called by FUN_a00bfcc4.
 * Reply: reads x = FUN_a0145660(0, 7) and y = FUN_a0145660(0, 8) as unsigned shorts and fills the 11-byte buffer
 * at 0xa802d078 with [7] = '0', [8] = '0' and [9] = a character chosen by the (x, y) pair: (0x1400, 0x5a0) '?',
 * (0xd70, 0x5a0) '>', (0xf00, 0x438) '=', (0xf00, 0x870) '<', (0xa00, 0x438) ';', (0xa00, 0x5a0) ':',
 * (0x780, 0x4b0) '9', (0x780, 0x438) '8', (0x690, 0x41a) '7', (0x640, 0x384) '6', (0x5a0, 0x384) '5',
 * (0x5a0, 0x41a) '4', (0x556, 0x300) '3', (0x500, 0x400) '2', (0x400, 0x300) '1', any other pair '0'.
 * [0] = FUN_a015463c(0x49, 0), [1] = 'b', [2..6] = FUN_a015463c(0x49, 2..6), [10] = '\r'. Then the port's receive
 * state is cleared and FUN_a01487e8(port, 0xb, buffer) is tail-called.
 * Source form: an if/else-if chain of (x == a && y == b) tests; GCC evaluates each pair as two flag values.
 */
extern unsigned char DAT_a802d078[11];
extern unsigned char DAT_a802b09a, DAT_a802b098, DAT_a802b09c;
extern unsigned char DAT_a802d040[], DAT_a802d098[], DAT_a802d0d0[];
extern unsigned char FUN_a015463c(unsigned short, unsigned short);
extern int FUN_a0145660(int, int);
extern void FUN_a01487e8(unsigned char, unsigned short, unsigned char *);

void FUN_a00bf7dc(unsigned char port)
{
    unsigned short x = FUN_a0145660(0, 7);
    unsigned short y = FUN_a0145660(0, 8);

    DAT_a802d078[7] = '0';
    DAT_a802d078[8] = '0';
    if (x == 0x1400 && y == 0x5a0)
        DAT_a802d078[9] = '?';
    else if (x == 0xd70 && y == 0x5a0)
        DAT_a802d078[9] = '>';
    else if (x == 0xf00 && y == 0x438)
        DAT_a802d078[9] = '=';
    else if (x == 0xf00 && y == 0x870)
        DAT_a802d078[9] = '<';
    else if (x == 0xa00 && y == 0x438)
        DAT_a802d078[9] = ';';
    else if (x == 0xa00 && y == 0x5a0)
        DAT_a802d078[9] = ':';
    else if (x == 0x780 && y == 0x4b0)
        DAT_a802d078[9] = '9';
    else if (x == 0x780 && y == 0x438)
        DAT_a802d078[9] = '8';
    else if (x == 0x690 && y == 0x41a)
        DAT_a802d078[9] = '7';
    else if (x == 0x640 && y == 0x384)
        DAT_a802d078[9] = '6';
    else if (x == 0x5a0 && y == 0x384)
        DAT_a802d078[9] = '5';
    else if (x == 0x5a0 && y == 0x41a)
        DAT_a802d078[9] = '4';
    else if (x == 0x556 && y == 0x300)
        DAT_a802d078[9] = '3';
    else if (x == 0x500 && y == 0x400)
        DAT_a802d078[9] = '2';
    else if (x == 0x400 && y == 0x300)
        DAT_a802d078[9] = '1';
    else
        DAT_a802d078[9] = '0';
    DAT_a802d078[0] = FUN_a015463c(0x49, 0);
    DAT_a802d078[1] = 'b';
    DAT_a802d078[2] = FUN_a015463c(0x49, 2);
    DAT_a802d078[3] = FUN_a015463c(0x49, 3);
    DAT_a802d078[4] = FUN_a015463c(0x49, 4);
    DAT_a802d078[5] = FUN_a015463c(0x49, 5);
    DAT_a802d078[6] = FUN_a015463c(0x49, 6);
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
