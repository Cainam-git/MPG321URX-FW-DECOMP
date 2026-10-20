/* FUN_a014f998: for each set bit n (0..6) of the byte DAT_a802cc87 calls FUN_a011dd9c(0x10 + n, v) (v passed as
 * u16; the flag byte is re-read after every call because the call may change it). No direct callers were found
 * (the address may be reached through a pointer). Written as seven independent ifs in bit order.
 */
extern unsigned char DAT_a802cc87;
extern void FUN_a011dd9c(unsigned char ch, unsigned short v);

void FUN_a014f998(unsigned int v)
{
    if (DAT_a802cc87 & 0x1)
        FUN_a011dd9c(0x10, v);
    if (DAT_a802cc87 & 0x2)
        FUN_a011dd9c(0x11, v);
    if (DAT_a802cc87 & 0x4)
        FUN_a011dd9c(0x12, v);
    if (DAT_a802cc87 & 0x8)
        FUN_a011dd9c(0x13, v);
    if (DAT_a802cc87 & 0x10)
        FUN_a011dd9c(0x14, v);
    if (DAT_a802cc87 & 0x20)
        FUN_a011dd9c(0x15, v);
    if (DAT_a802cc87 & 0x40)
        FUN_a011dd9c(0x16, v);
}
