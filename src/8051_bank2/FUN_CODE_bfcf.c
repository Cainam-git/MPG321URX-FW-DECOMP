/* 8051_bank2 FUN_CODE_bfcf @ 0xbfcf  update agent: I2C master write of one service-bus packet
 * (OPTIMIZE(8,SPEED) LARGE REGFILE(R.ORC)).
 * FUN_CODE_bfcf(addr, len, buf): bus start (FUN_CODE_e423); send the slave address byte addr (FUN_CODE_d275 returns
 * non-zero on NACK), retrying up to 10 times with FUN_CODE_e462 between tries; after 10 failures: stop
 * (FUN_CODE_e525) and return 0x0F. Then send buf[0..len-1], OR-ing every byte's NACK status, while keeping an XOR
 * checksum that starts with addr; send the checksum byte last; stop; return the status of that checksum byte.
 * So every packet on the 0x6E service bus (04 78 .. register writes, 03 87 .. reads, 01 25 / 01 11 / 02 A3 commands)
 * ends with an XOR checksum over address + payload.
 */
void FUN_CODE_e423(void);
unsigned char FUN_CODE_d275(unsigned char b);
void FUN_CODE_e462(void);
void FUN_CODE_e525(void);

unsigned char FUN_CODE_bfcf(unsigned char addr, unsigned char len, unsigned char *buf)
{
    unsigned int i, chk, st;
    st = 0;
    FUN_CODE_e423();
    for (i = 0; i < 10; i++) {
        if (!FUN_CODE_d275(addr)) break;
        FUN_CODE_e462();
    }
    if (i == 10) {
        FUN_CODE_e525();
        return 0x0f;
    }
    chk = addr;
    for (i = 0; i < len; i++) {
        st |= FUN_CODE_d275(buf[i]);
        chk ^= buf[i];
    }
    st = FUN_CODE_d275(chk);
    FUN_CODE_e525();
    return st;
}
