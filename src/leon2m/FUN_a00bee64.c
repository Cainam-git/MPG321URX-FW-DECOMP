/* leon2m FUN_a00bee64 @ 0xa00bee64-0xa00bef90 (75 words), flags -mcpu=v8 -O3 -g. Called by FUN_a00bfcc4.
 * Fills the 11-byte transmit buffer at 0xa802d078: [7] = [8] = '0', [9] = FUN_a01445fc(byte 0xa802d2b0) + '0',
 * [0] = FUN_a015463c(0x34, 0), [1] = 'b', [2..6] = FUN_a015463c(0x34, 2..6), [10] = '\r'. Then port == 2: clear
 * byte 0xa802b09a and record 0xa802d040 bytes 0, 1, 7, 10, 0x19; port == 3: byte 0xa802b098 and record
 * 0xa802d098; else byte 0xa802b09c and record 0xa802d0d0. Tail call FUN_a01487e8(port, 0xb, buffer).
 * Same code as FUN_a00bed38 with row 0x34 and byte 0xa802d2b0.
 * Source form: the record clears are written in ascending offset order (0, 1, 7, 10, 0x19) in all three arms.
 */
extern unsigned char DAT_a802d078[11];
extern unsigned char DAT_a802d2b0;
extern unsigned char DAT_a802b09a, DAT_a802b098, DAT_a802b09c;
extern unsigned char DAT_a802d040[], DAT_a802d098[], DAT_a802d0d0[];
extern unsigned char FUN_a015463c(unsigned short, unsigned short);
extern unsigned char FUN_a01445fc(unsigned char);
extern void FUN_a01487e8(unsigned char, unsigned short, unsigned char *);

void FUN_a00bee64(unsigned char port)
{
    DAT_a802d078[7] = '0';
    DAT_a802d078[8] = '0';
    DAT_a802d078[9] = FUN_a01445fc(DAT_a802d2b0) + '0';
    DAT_a802d078[0] = FUN_a015463c(0x34, 0);
    DAT_a802d078[1] = 'b';
    DAT_a802d078[2] = FUN_a015463c(0x34, 2);
    DAT_a802d078[3] = FUN_a015463c(0x34, 3);
    DAT_a802d078[4] = FUN_a015463c(0x34, 4);
    DAT_a802d078[5] = FUN_a015463c(0x34, 5);
    DAT_a802d078[6] = FUN_a015463c(0x34, 6);
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
