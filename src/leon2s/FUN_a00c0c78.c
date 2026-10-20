/* leon2s FUN_a00c0c78 @ 0xa00c0c78 (-mcpu=v8 -Os -g)
 * Finished by hand from mechanical Ghidra C. Copies two fixed tables out of the 0x9f1b....
 * data area into caller buffers: 5 bytes from 0x9f1b7018 to param_1 and 282 bytes from
 * 0x9f1b6ef8 to param_2. Twin of FUN_a00c0c08 (other table pair); located next to the HDCP key
 * loaders. Written as plain array loops with a u16 counter.
 */
extern unsigned char DAT_9f1b7018[];
extern unsigned char DAT_9f1b6ef8[];

void FUN_a00c0c78(unsigned char *param_1, unsigned char *param_2)
{
    unsigned short i;
    for (i = 0; i < 5; i++)
        param_1[i] = DAT_9f1b7018[i];
    for (i = 0; i < 0x11a; i++)
        param_2[i] = DAT_9f1b6ef8[i];
}
