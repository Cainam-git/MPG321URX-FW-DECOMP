/* leon2m FUN_a00bed38 @ 0xa00bed38-0xa00bee64 (75 words), flags -mcpu=v8 -O3 -g.
 * Code facts: fills the 11-byte buffer at 0xa802d078: [7] = [8] = '0', [9] = FUN_a01445fc(byte
 * 0xa802d2ae) + '0', [0] = FUN_a015463c(0x35, 0), [1] = 'b', [2..6] = FUN_a015463c(0x35, 2..6),
 * [10] = '\r'. Then port == 2: clear byte 0xa802b09a and record 0xa802d040 bytes 0, 1, 7, 10, 0x19;
 * port == 3: byte 0xa802b098 and record 0xa802d098; else byte 0xa802b09c and record 0xa802d0d0.
 * Tail call FUN_a01487e8(port, 0xb, buffer).
 * Source form: the record clears are written in ASCENDING offset order (0, 1, 7, 10, 0x19) in all three
 * arms; of the 120 possible orders only this one is exact (other orders schedule the +0xa clear early).
 * The fw store order is then 0, 0x19, 1, 7, 10. Aids: none.
 */
extern unsigned char DAT_a802d078[11];
extern unsigned char DAT_a802d2ae;
extern unsigned char DAT_a802b09a, DAT_a802b098, DAT_a802b09c;
extern unsigned char DAT_a802d040[], DAT_a802d098[], DAT_a802d0d0[];
extern unsigned char FUN_a015463c(unsigned short, unsigned short);
extern unsigned char FUN_a01445fc(unsigned char);
extern void FUN_a01487e8(unsigned char, int, unsigned char *);

void FUN_a00bed38(unsigned char port)
{
    DAT_a802d078[7] = '0';
    DAT_a802d078[8] = '0';
    DAT_a802d078[9] = FUN_a01445fc(DAT_a802d2ae) + '0';
    DAT_a802d078[0] = FUN_a015463c(0x35, 0);
    DAT_a802d078[1] = 'b';
    DAT_a802d078[2] = FUN_a015463c(0x35, 2);
    DAT_a802d078[3] = FUN_a015463c(0x35, 3);
    DAT_a802d078[4] = FUN_a015463c(0x35, 4);
    DAT_a802d078[5] = FUN_a015463c(0x35, 5);
    DAT_a802d078[6] = FUN_a015463c(0x35, 6);
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
