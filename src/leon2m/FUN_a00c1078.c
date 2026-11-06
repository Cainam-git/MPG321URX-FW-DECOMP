/* leon2m FUN_a00c1078 @ 0xa00c1078 (-mcpu=v8 -O3 -g)
 * Reads byte 0xA802D049 (port 2), 0xA802D0A1 (port 3) or 0xA802D0D9 (other ports) of the receive buffer; d = byte
 * - '0'; d > 1 (as a byte) -> returns 0xff. Else byte 0xA802D47E = d, FUN_a00b88cc(), FUN_a00baa6c(port),
 * FUN_a00ba950(port), FUN_a00bab80(port, 6) and returns 0.
 */
extern unsigned char DAT_a802d049;
extern unsigned char DAT_a802d0a1;
extern unsigned char DAT_a802d0d9;
extern unsigned char DAT_a802d47e;
extern void FUN_a00b88cc(void);
extern int FUN_a00baa6c();
extern int FUN_a00ba950();
extern int FUN_a00bab80();

static int ascii_digit(unsigned char c)
{
  return c - '0';
}

int FUN_a00c1078(int param_1)
{
    unsigned char value;
    unsigned char d;
    
    param_1 = param_1 & 0xff;
    if (param_1 == 2) {
        value = DAT_a802d049;
    } else if (param_1 == 3) {
        value = DAT_a802d0a1;
    } else {
        value = DAT_a802d0d9;
    }
    
    d = ascii_digit(value);
    if (d > 1) {
        return 0xff;
    }
    
    DAT_a802d47e = d;
    FUN_a00b88cc();
    FUN_a00baa6c(param_1);
    FUN_a00ba950(param_1);
    FUN_a00bab80(param_1, 6);
    return 0;
}
