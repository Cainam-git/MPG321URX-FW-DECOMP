/* FUN_CODE_d53d, 8051_bank2 (helper chip updater), range 0xD53D..0xD5C5 (136 B).
 * Options: OPTIMIZE(8,SPEED) LARGE REGFILE(R.ORC).
 * Without REGFILE(R.ORC) it is 251 B: the firmware keeps nak in R2 and the XOR sum in
 * R3 across every FUN_CODE_d275 call, which Keil only does when the register-usage file says d275 leaves R2/R3 alone.
 * Code facts: the ulong parameter v lives in its LARGE home 0x08F0..0x08F3 (?C?LSTXDATA at entry). It sends one
 * bit-banged I2C frame on the service bus: START (e423), the bytes 0x6E, 0x04, 0x4A, v bits 16..23, v bits 8..15,
 * v bits 0..7, then the XOR of those six bytes, then STOP (e525). Returns the OR of the six-plus-one d275 results
 * (0 = every byte ACKed, 1 = some NACK). The v >> 16 and v >> 8 bytes go through ?C?ULSHR; the low byte is read
 * straight from 0x08F3. Caller: FUN_CODE_ce2a (0xCE6D). No aids.
 */
void FUN_CODE_e423(void);
void FUN_CODE_e525(void);
unsigned char FUN_CODE_d275(unsigned char b);
unsigned char FUN_CODE_d53d(unsigned long v)
{
    unsigned char nak;
    unsigned char cs;
    unsigned char b;
    cs = 0;
    FUN_CODE_e423();
    nak = FUN_CODE_d275(0x6e);
    cs ^= 0x6e;
    nak |= FUN_CODE_d275(4);
    cs ^= 4;
    nak |= FUN_CODE_d275(0x4a);
    cs ^= 0x4a;
    b = v >> 16;
    nak |= FUN_CODE_d275(b);
    cs ^= b;
    b = v >> 8;
    nak |= FUN_CODE_d275(b);
    cs ^= b;
    b = v;
    nak |= FUN_CODE_d275(b);
    cs ^= b;
    nak |= FUN_CODE_d275(cs);
    FUN_CODE_e525();
    return nak;
}
