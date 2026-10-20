/* FUN_a014aa48: returns the address of one of three RAM areas: 0xa802cd90 for sel 1, 0xa802cc90 for sel 2,
 * 0xa802ce90 for any other sel. Callers: FUN_a00b9f30. Written as a switch that sets a pointer local.
 */
extern unsigned char DAT_a802cc90[], DAT_a802cd90[], DAT_a802ce90[];

unsigned char *FUN_a014aa48(unsigned char sel)
{
    unsigned char *p;

    switch (sel) {
    case 1:
        p = DAT_a802cd90;
        break;
    case 2:
        p = DAT_a802cc90;
        break;
    default:
        p = DAT_a802ce90;
        break;
    }
    return p;
}
