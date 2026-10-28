/* leon2m FUN_a00bdf28 @ 0xa00bdf28-0xa00be0a0 (94 words).
 * Builds a 22-byte reply in the buffer at 0xa802d078: [0] = FUN_a015463c(0x43, 0), [1] = 'b', [2..6] =
 * FUN_a015463c(0x43, 2..6), then the bytes 3.. of the record at 0xa802d274 (as many as its byte 2 says) from [7] on,
 * [0x14] = the 8-bit sum of the copied bytes and [0x15] = '\r'. Clears the port's receive state (as in
 * FUN_a00bed38) and tail-calls FUN_a01487e8(port, 0x16, buffer). Same frame code as FUN_a00bd9d8 plus the sum.
 */
extern unsigned char DAT_a802d078[0x25];
extern unsigned char DAT_a802b09a, DAT_a802b098, DAT_a802b09c;
extern unsigned char DAT_a802d040[], DAT_a802d098[], DAT_a802d0d0[];
extern unsigned char DAT_a802d274[];
extern unsigned char FUN_a015463c(unsigned short, unsigned short);
extern void FUN_a01487e8(unsigned char, unsigned short, unsigned char *);

void FUN_a00bdf28(unsigned char port)
{
    unsigned char i, sum = 0;

    DAT_a802d078[0] = FUN_a015463c(0x43, 0);
    DAT_a802d078[1] = 'b';
    DAT_a802d078[2] = FUN_a015463c(0x43, 2);
    DAT_a802d078[3] = FUN_a015463c(0x43, 3);
    DAT_a802d078[4] = FUN_a015463c(0x43, 4);
    DAT_a802d078[5] = FUN_a015463c(0x43, 5);
    DAT_a802d078[6] = FUN_a015463c(0x43, 6);
    for (i = 0; i < DAT_a802d274[2]; i++) {
        DAT_a802d078[7 + i] = DAT_a802d274[3 + i];
        sum += DAT_a802d274[3 + i];
    }
    DAT_a802d078[0x14] = sum;
    DAT_a802d078[0x15] = '\r';
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
    FUN_a01487e8(port, 0x16, DAT_a802d078);
}
