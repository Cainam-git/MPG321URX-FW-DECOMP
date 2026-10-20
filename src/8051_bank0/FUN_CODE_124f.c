/* 8051_bank0 FUN_CODE_124f @ 0x124f  STBC boot loader: generic SPI flash transfer (byte-exact
 * with OPTIMIZE(8,SPEED)).
 * FUN_CODE_124f(n_out, out, n_in, in): sends n_out bytes (out[0] = the opcode) and then reads n_in bytes into in.
 * 0xF0E6 = (0xF0E6 & 0x0C) | 0x41; transfer length = n_out + n_in - 1 in 0xF0EB..0xF0ED (bytes 2..0); 0xF0F4 =
 * (n_out << 5) | 0x13 (transfer type with the command length); 0xF0EE = out[0]; FIFO write mode 0xF1C0 = 0x82 and
 * out[1..n_out-1] into 0xF1C3; 0xF1C0 = 0x84, 0xF1C8 = 0x81, start 0xF0E5 = 1, wait until bit 0 clears; when
 * n_in > 0: FIFO read mode 0xF1C8 = 0x82, one byte dropped, then n_in bytes from 0xF1C8 into in[]; finally
 * 0xF1C0 = 0xF1C8 = 0x80. Callers: the JEDEC ID read FUN_CODE_1777 (0x9F, 1 out, 4 in) and the bus-mode set-up
 * FUN_CODE_0c83 through the parameter set-up pieces FUN_CODE_123a / FUN_CODE_1249.
 */
extern unsigned char volatile xdata DAT_EXTMEM_f0e6, DAT_EXTMEM_f0f4, DAT_EXTMEM_f0eb, DAT_EXTMEM_f0ec, DAT_EXTMEM_f0ed, DAT_EXTMEM_f0ee;
extern unsigned char volatile xdata DAT_EXTMEM_f1c0, DAT_EXTMEM_f1c3, DAT_EXTMEM_f1c8, DAT_EXTMEM_f0e5;
void FUN_CODE_124f(unsigned int n_out, unsigned char *out, unsigned int n_in, unsigned char *in)
{
    unsigned char t;        /* mode scratch, later the dropped first FIFO byte */
    unsigned long total;
    unsigned int i;
    t = DAT_EXTMEM_f0e6 & 0x0c;
    t |= 0x41;
    DAT_EXTMEM_f0e6 = t;
    total = n_out + n_in - 1;
    DAT_EXTMEM_f0f4 = ((unsigned char)n_out << 5) | 0x13;
    DAT_EXTMEM_f0eb = total >> 16;
    DAT_EXTMEM_f0ec = total >> 8;
    DAT_EXTMEM_f0ed = (unsigned int)(total & 0xff);
    DAT_EXTMEM_f0ee = out[0];
    DAT_EXTMEM_f1c0 = 0x82;
    for (i = 1; i < n_out; i++) DAT_EXTMEM_f1c3 = out[i];
    DAT_EXTMEM_f1c0 = 0x84;
    DAT_EXTMEM_f1c8 = 0x81;
    DAT_EXTMEM_f0e5 = 1;
    while ((int)(DAT_EXTMEM_f0e5 & 1));
    if (n_in > 0) {
        DAT_EXTMEM_f1c8 = 0x82;
        t = DAT_EXTMEM_f1c8;
        for (i = 0; i < n_in; i++) in[i] = DAT_EXTMEM_f1c8;
    }
    DAT_EXTMEM_f1c0 = 0x80;
    DAT_EXTMEM_f1c8 = 0x80;
}
