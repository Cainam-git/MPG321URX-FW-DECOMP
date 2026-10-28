/* leon2m FUN_a00bd59c @ 0xa00bd59c-0xa00bd6e4 (82 words), flags -mcpu=v8 -O3 -g. Called by FUN_a00bfcc4.
 * Fills the 11-byte transmit buffer at 0xa802d078 with the two-digit decimal value v = byte 0xa802d41c
 * (0..19): [7] = '0', [8] = '1' and [9] = v - 10 + '0' when v > 9, else [8] = '0' and [9] = v + '0';
 * [0] = FUN_a015463c(0x2a, 0), [1] = 'b', [2..6] = FUN_a015463c(0x2a, 2..6), [10] = '\r'.
 * Then the port's receive state is cleared (port 2: byte 0xa802b09a and bytes 0, 1, 7, 10, 0x19 of the record
 * 0xa802d040; port 3: 0xa802b098 / 0xa802d098; else 0xa802b09c / 0xa802d0d0), and the tail call
 * FUN_a01487e8(port, 0xb, buffer) sends the frame. Same layout as FUN_a00bed38.
 * Source form: the record clears are written in ascending offset order (0, 1, 7, 10, 0x19) in all three arms;
 * v is an unsigned char local of an inner block and the v > 9 arm comes first.
 */
extern unsigned char DAT_a802d078[11];
extern unsigned char DAT_a802d41c;
extern unsigned char DAT_a802b09a, DAT_a802b098, DAT_a802b09c;
extern unsigned char DAT_a802d040[], DAT_a802d098[], DAT_a802d0d0[];
extern unsigned char FUN_a015463c(unsigned short, unsigned short);
extern unsigned char FUN_a01445fc(unsigned char);
extern void FUN_a01487e8(unsigned char, unsigned short, unsigned char *);

void FUN_a00bd59c(unsigned char port)
{
    {
        unsigned char v = DAT_a802d41c;
        DAT_a802d078[7] = '0';
        if (v > 9) {
            DAT_a802d078[8] = '1';
            DAT_a802d078[9] = v - 10 + '0';
        } else {
            DAT_a802d078[8] = '0';
            DAT_a802d078[9] = v + '0';
        }
    }
    DAT_a802d078[0] = FUN_a015463c(0x2a, 0);
    DAT_a802d078[1] = 'b';
    DAT_a802d078[2] = FUN_a015463c(0x2a, 2);
    DAT_a802d078[3] = FUN_a015463c(0x2a, 3);
    DAT_a802d078[4] = FUN_a015463c(0x2a, 4);
    DAT_a802d078[5] = FUN_a015463c(0x2a, 5);
    DAT_a802d078[6] = FUN_a015463c(0x2a, 6);
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
