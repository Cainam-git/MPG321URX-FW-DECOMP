/* leon2m FUN_a00bc95c @ 0xa00bc95c-0xa00bcaa8 (83 words), flags -mcpu=v8 -O3 -g. Called by FUN_a00bfcc4.
 * Fills the 11-byte UART transmit buffer at 0xa802d078: [7] = [8] = '0', [9] = (byte 0xa802d412 + 5) % 6 + '0',
 * [0] = FUN_a015463c(0x13, 0), [1] = 'b', [2..6] = FUN_a015463c(0x13, 2..6), [10] = '\r'.
 * Then the port's receive state is cleared (port 2: byte 0xa802b09a and bytes 0, 1, 7, 10, 0x19 of the record
 * 0xa802d040; port 3: 0xa802b098 / 0xa802d098; else 0xa802b09c / 0xa802d0d0), and the tail call
 * FUN_a01487e8(port, 0xb, buffer) sends the frame. Same layout as FUN_a00bed38.
 * Source form: the record clears are written in ascending offset order (0, 1, 7, 10, 0x19) in all three arms.
 */
extern unsigned char DAT_a802d078[11];
extern unsigned char DAT_a802d412;
extern unsigned char DAT_a802b09a, DAT_a802b098, DAT_a802b09c;
extern unsigned char DAT_a802d040[], DAT_a802d098[], DAT_a802d0d0[];
extern unsigned char FUN_a015463c(unsigned short, unsigned short);
extern unsigned char FUN_a01445fc(unsigned char);
extern void FUN_a01487e8(unsigned char, int, unsigned char *);

void FUN_a00bc95c(unsigned char port)
{
    DAT_a802d078[7] = '0';
    DAT_a802d078[8] = '0';
    DAT_a802d078[9] = (DAT_a802d412 + 5) % 6 + '0';
    DAT_a802d078[0] = FUN_a015463c(0x13, 0);
    DAT_a802d078[1] = 'b';
    DAT_a802d078[2] = FUN_a015463c(0x13, 2);
    DAT_a802d078[3] = FUN_a015463c(0x13, 3);
    DAT_a802d078[4] = FUN_a015463c(0x13, 4);
    DAT_a802d078[5] = FUN_a015463c(0x13, 5);
    DAT_a802d078[6] = FUN_a015463c(0x13, 6);
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
