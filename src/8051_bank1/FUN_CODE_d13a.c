/* 8051_bank1 FUN_CODE_d13a @ 0xd13a  MATCH (OPTIMIZE(7,SPEED))
 * What if the function takes 3 parameters: (byte in R7, byte in R5, word in R2:R3)? That gives:
 * - Call 1: R7=0x00, R5=0x80, R2:R3=0x01c2
 * - Call 2: R7=0x10, R5=0x00, R2:R3=0x0640
 * - Call 3: R7=0x20, R5=0x80, R2:R3=0x0002
 * - Call 4: R7=0x30, R5=0x80, R2:R3=0x001c
 * - Call 5: R7=0x50, R5=0x80, R2:R3=0x0136
 */
extern void FUN_CODE_ca44(unsigned char, unsigned char, unsigned int);

void FUN_CODE_d13a(void) 
{
    FUN_CODE_ca44(0x00, 0x80, 0x01c2);
    FUN_CODE_ca44(0x10, 0x00, 0x0640);
    FUN_CODE_ca44(0x20, 0x80, 0x0002);
    FUN_CODE_ca44(0x30, 0x80, 0x001c);
    FUN_CODE_ca44(0x50, 0x80, 0x0136);
}
