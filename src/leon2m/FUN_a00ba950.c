/* leon2m FUN_a00ba950 @ 0xa00ba950-0xa00ba9d0 (32 words).
 * Clears the receive state of one UART port: port 2 clears byte 0xa802b09a and bytes 0, 1, 7, 10, 0x19 of the
 * receive record at 0xa802d040; port 3 clears byte 0xa802b098 and the same bytes of the record at 0xa802d098; any
 * other port clears byte 0xa802b09c and the record at 0xa802d0d0.
 * The same clears appear inline in the reply builders (FUN_a00bed38 and others). The clears are written in
 * ascending offset order; the compiler emits them as 0, 0x19, 1, 7, 10.
 */
extern unsigned char DAT_a802b09a, DAT_a802b098, DAT_a802b09c;
extern unsigned char DAT_a802d040[], DAT_a802d098[], DAT_a802d0d0[];

void FUN_a00ba950(unsigned char port)
{
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
}
