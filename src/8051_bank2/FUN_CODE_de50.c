/* 8051_bank2 FUN_CODE_de50 @ 0xde50  update agent: raw service-bus handshake (byte-exact with
 * OPTIMIZE(8,SPEED) LARGE REGFILE(R.ORC)).
 * m == 1: first ten START/STOP pairs (bus reset), then twice: START 04, START 34, START 06, START 36, STOP.
 * m != 1: once: START 04, START 34, START 06, START 3C, STOP.
 * The bytes go out with FUN_CODE_d275 after repeated STARTs, i.e. they are raw bus bytes, not 0x6E packets. Called by
 * FUN_CODE_d1bb (1 = take the scaler for an update, 0 = release it).
 */
void FUN_CODE_e423(void);
void FUN_CODE_e525(void);
unsigned char FUN_CODE_d275(unsigned char b);

void FUN_CODE_de50(unsigned char m)
{
    unsigned char i;
    if (m == 1) {
        for (i = 0; i < 10; i++) {
            FUN_CODE_e423();
            FUN_CODE_e525();
        }
    }
    for (i = 0; i < 2; i++) {
        FUN_CODE_e423();
        FUN_CODE_d275(0x04);
        FUN_CODE_e423();
        FUN_CODE_d275(0x34);
        FUN_CODE_e423();
        FUN_CODE_d275(0x06);
        FUN_CODE_e423();
        FUN_CODE_d275(m == 1 ? 0x36 : 0x3c);
        FUN_CODE_e525();
        if (m != 1) break;
    }
}
