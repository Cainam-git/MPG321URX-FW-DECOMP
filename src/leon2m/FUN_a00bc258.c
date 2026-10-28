/* leon2m FUN_a00bc258 @ 0xa00bc258-0xa00bc3b0 (86 words).
 * Builds a 37-byte reply in the buffer at 0xa802d078: [0] = FUN_a015463c(0x4b, 0), [1] = 'b', [2..6] =
 * FUN_a015463c(0x4b, 2..6) (row 0x4b of the command table), [7] = 0x12, [8..0x19] = the 18 characters of
 * "SDC QMC315AA01_D01" (string 0x198280), [0x24] = '\r'. Then, by port: port 2 clears byte 0xa802b09a and bytes 0,
 * 1, 7, 10, 0x19 of the receive record at 0xa802d040; port 3 clears byte 0xa802b098 and the record at 0xa802d098;
 * any other port clears byte 0xa802b09c and the record at 0xa802d0d0. Ends with the tail call FUN_a01487e8(port,
 * 0x25, buffer). Same frame layout as FUN_a00bed38. Source form: the length 0x12 is a variable that gives both byte 7
 * and the loop limit (a constant limit compiles to cmp 0x11; bleu).
 */
extern unsigned char DAT_a802d078[0x25];
extern unsigned char DAT_a802b09a, DAT_a802b098, DAT_a802b09c;
extern unsigned char DAT_a802d040[], DAT_a802d098[], DAT_a802d0d0[];
extern const char s_00198280[];
extern unsigned char FUN_a015463c(unsigned short, unsigned short);
extern void FUN_a01487e8(unsigned char, unsigned short, unsigned char *);

void FUN_a00bc258(unsigned char port)
{
    unsigned char i, len = 0x12;

    DAT_a802d078[0] = FUN_a015463c(0x4b, 0);
    DAT_a802d078[1] = 'b';
    DAT_a802d078[2] = FUN_a015463c(0x4b, 2);
    DAT_a802d078[3] = FUN_a015463c(0x4b, 3);
    DAT_a802d078[4] = FUN_a015463c(0x4b, 4);
    DAT_a802d078[5] = FUN_a015463c(0x4b, 5);
    DAT_a802d078[6] = FUN_a015463c(0x4b, 6);
    DAT_a802d078[7] = len;
    for (i = 0; i < len; i++)
        DAT_a802d078[8 + i] = s_00198280[i];
    DAT_a802d078[0x24] = '\r';
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
    FUN_a01487e8(port, 0x25, DAT_a802d078);
}
