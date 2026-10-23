/* leon2m FUN_a00bd9d8 @ 0xa00bd9d8-0xa00bdb48 (92 words).
 * Builds a 21-byte reply in the buffer at 0xa802d078: [0] = FUN_a015463c(0x2e, 0), [1] = 'b', [2..6] =
 * FUN_a015463c(0x2e, 2..6), then the bytes 3.. of the record at 0xa802d274 (as many as its byte 2 says) from [7] on,
 * and [0x14] = '\r'. Clears the port's receive state (as in FUN_a00bed38) and tail-calls FUN_a01487e8(port, 0x15,
 * buffer). Same frame code as FUN_a00bc258.
 */
extern unsigned char DAT_a802d078[0x25];
extern unsigned char DAT_a802b09a, DAT_a802b098, DAT_a802b09c;
extern unsigned char DAT_a802d040[], DAT_a802d098[], DAT_a802d0d0[];
extern unsigned char DAT_a802d274[];
extern unsigned char FUN_a015463c(unsigned short, unsigned short);
extern void FUN_a01487e8(unsigned char, int, unsigned char *);

void FUN_a00bd9d8(unsigned char port)
{
    unsigned char i;

    DAT_a802d078[0] = FUN_a015463c(0x2e, 0);
    DAT_a802d078[1] = 'b';
    DAT_a802d078[2] = FUN_a015463c(0x2e, 2);
    DAT_a802d078[3] = FUN_a015463c(0x2e, 3);
    DAT_a802d078[4] = FUN_a015463c(0x2e, 4);
    DAT_a802d078[5] = FUN_a015463c(0x2e, 5);
    DAT_a802d078[6] = FUN_a015463c(0x2e, 6);
    for (i = 0; i < DAT_a802d274[2]; i++)
        DAT_a802d078[7 + i] = DAT_a802d274[3 + i];
    DAT_a802d078[0x14] = '\r';
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
    FUN_a01487e8(port, 0x15, DAT_a802d078);
}
