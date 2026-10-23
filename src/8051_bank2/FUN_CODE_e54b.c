/* 8051_bank2 FUN_CODE_e54b @ 0xe54b
 * cca2(off zero-extended to unsigned long, buf): CLR A / MOV R4,A / MOV R5,A / LJMP cca2. Prototype as the caller's
 * declaration in FUN_CODE_9f8f.c, 'FUN_CODE_e54b(unsigned int off, unsigned char *buf)'.
 * Callers 0xa128 (FUN_CODE_9f8f), 0xae61. Byte-exact with OPTIMIZE(8,SPEED) LARGE.
 */
void FUN_CODE_cca2(unsigned long off, unsigned char *buf);
void FUN_CODE_e54b(unsigned int off, unsigned char *buf)
{
    FUN_CODE_cca2(off, buf);
}
