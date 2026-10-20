/* leon2s FUN_a00c0c08 @ 0xa00c0c08  MATCH (-mcpu=v8 -Os -g, gcc 3.4.4, autoc)
 * Hand-finished from the mechanical Ghidra C. Copies two fixed tables of the 0x9F1B.... data area into caller
 * buffers: 5 bytes from 0x9F1B7140 to param_1 and 282 bytes from 0x9F1B7020 to param_2. Twin of FUN_a00c0c78
 * (other table pair); located next to the HDCP key loaders. Written as plain array loops with an unsigned short
 * index.
 */
extern unsigned char DAT_9f1b7140[];
extern unsigned char DAT_9f1b7020[];

void FUN_a00c0c08(unsigned char *param_1, unsigned char *param_2)
{
    unsigned short i;
    for (i = 0; i < 5; i++)
        param_1[i] = DAT_9f1b7140[i];
    for (i = 0; i < 0x11a; i++)
        param_2[i] = DAT_9f1b7020[i];
}
