/* FUN_a01544d4 (leon2m 0xa01544d4-0xa0154574, 160 bytes), flags -mcpu=v8 -g.
 * When the top four bits of the byte DAT_a802cf9c are 8: stores 3 (byte DAT_a802cf9d = 3) or 0 to the word
 * DAT_a802cf98 and calls FUN_a01004cc(DAT_a802cf98). Called by FUN_a0154580. Source form: unoptimised code (the
 * file is compiled -mcpu=v8 -g like its neighbour FUN_a0154574); a switch with case 3 and default.
 */
extern unsigned char DAT_a802cf9c, DAT_a802cf9d;
extern unsigned int DAT_a802cf98;
extern void FUN_a01004cc(unsigned int);

void FUN_a01544d4(void)
{
    if ((DAT_a802cf9c & 0xf0) == 0x80) {
        switch (DAT_a802cf9d) {
        case 3:
            DAT_a802cf98 = 3;
            FUN_a01004cc(DAT_a802cf98);
            break;
        default:
            DAT_a802cf98 = 0;
            FUN_a01004cc(DAT_a802cf98);
            break;
        }
    }
}
