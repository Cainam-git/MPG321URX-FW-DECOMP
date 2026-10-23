/* FUN_CODE_cd68, 8051_bank2 (helper chip updater), range 0xCD68..0xCE2A (194 B).
 * Options: OPTIMIZE(8,SPEED) LARGE REGFILE(R.ORC).
 * Without REGFILE(R.ORC) it is 243 B: both loop counters stay in R4:R5 across the
 * d275 / e462 / db1c calls only when the register-usage file says those callees leave R4/R5 alone.
 * Code facts: bit-banged I2C read on the service bus. LARGE parameters dev (0x08F0), buf (generic pointer,
 * 0x08F1..0x08F3) and len (uint, memory parameter 0x08F4..0x08F5); locals b (0x08F6) and n (uint, 0x08F7..0x08F8).
 * START (e423), then the read address dev | 1 is sent up to 10 times (d275 returns 0 on ACK, e462 half-bit delay
 * between tries); after 10 NACKs: STOP (e525), return 1. Then e44b(1), two db1c(0) reads whose values the firmware
 * stores to n and b and then drops (n is overwritten with len), then len bytes are read into buf[j] (?C?CSTOPTR);
 * the last byte gets six e462 delays and db1c(1) (NACK = last), the others db1c(0). STOP, return 0.
 * Shape lever: the last-byte arm and the other arm each have their own 'buf[j] = db1c(k);' (Keil cross-jumps the
 * shared tail). A flag variable 'b = 1 / b = 0; buf[j] = db1c(b)' stores b and is 206 B.
 * Caller: FUN_CODE_ce2a (0xCE87). No aids.
 */
void FUN_CODE_e423(void);
void FUN_CODE_e525(void);
void FUN_CODE_e462(void);
void FUN_CODE_e44b(unsigned char n);
unsigned char FUN_CODE_d275(unsigned char b);
unsigned char FUN_CODE_db1c(unsigned char last);
unsigned char FUN_CODE_cd68(unsigned char dev, unsigned char *buf, unsigned int len)
{
    unsigned char b;
    unsigned int n;
    unsigned int j;
    FUN_CODE_e423();
    for (j = 0; j != 10; j++) {
        if (FUN_CODE_d275(dev | 1) == 0) break;
        FUN_CODE_e462();
    }
    if (j == 10) {
        FUN_CODE_e525();
        return 1;
    }
    FUN_CODE_e44b(1);
    n = FUN_CODE_db1c(0);
    b = FUN_CODE_db1c(0);
    n = len;
    for (j = 0; j < n; j++) {
        if (j == n - 1) {
            FUN_CODE_e462();
            FUN_CODE_e462();
            FUN_CODE_e462();
            FUN_CODE_e462();
            FUN_CODE_e462();
            FUN_CODE_e462();
            buf[j] = FUN_CODE_db1c(1);
        } else buf[j] = FUN_CODE_db1c(0);
    }
    FUN_CODE_e525();
    return 0;
}
