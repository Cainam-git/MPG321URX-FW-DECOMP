/* leon2m FUN_a00bd070 @ 0xa00bd070-0xa00bd244 (117 words).
 * UART reply: fills the 11-byte buffer at 0xa802d078 with [7] = [8] = '0', [9] = the ASCII digit of byte 0xa802d411
 * when it is 0..7 (unchanged otherwise), [0] = FUN_a015463c(0x23, 0), [1] = 'b', [2..6] = FUN_a015463c(0x23, 2..6)
 * and [10] = '\r', clears the port's receive state (port 2: 0xa802b09a and the record at 0xa802d040; port 3:
 * 0xa802b098 and 0xa802d098; other ports: 0xa802b09c and 0xa802d0d0) and tail-calls FUN_a01487e8(port, 0xb, buffer).
 * Source form: a switch with one case per digit (jump table at 0x5a3e8); case 7 is written first, which makes it the
 * block that follows the jump. The function covers its case blocks up to 0xa00bd244.
 */
extern unsigned char DAT_a802d078[11];
extern unsigned char DAT_a802d411;
extern unsigned char DAT_a802b09a, DAT_a802b098, DAT_a802b09c;
extern unsigned char DAT_a802d040[], DAT_a802d098[], DAT_a802d0d0[];
extern unsigned char FUN_a015463c(unsigned short, unsigned short);
extern void FUN_a01487e8(unsigned char, int, unsigned char *);

void FUN_a00bd070(unsigned char port)
{
    DAT_a802d078[7] = '0';
    DAT_a802d078[8] = '0';
    switch (DAT_a802d411) {
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
    DAT_a802d078[0] = FUN_a015463c(0x23, 0);
    DAT_a802d078[1] = 'b';
    DAT_a802d078[2] = FUN_a015463c(0x23, 2);
    DAT_a802d078[3] = FUN_a015463c(0x23, 3);
    DAT_a802d078[4] = FUN_a015463c(0x23, 4);
    DAT_a802d078[5] = FUN_a015463c(0x23, 5);
    DAT_a802d078[6] = FUN_a015463c(0x23, 6);
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
