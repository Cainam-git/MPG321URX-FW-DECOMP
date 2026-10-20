/* leon2m FUN_a008a184 @ 0xa008a184, flags -mcpu=v8 -O3 -g
 * APP event post: appends event 'ev' to the 10-entry event queue DAT_a802afa8[] (count DAT_a802afa1),
 * except events 0x3F, 0x4F, 0x84, 0xC7, which are dropped; a full queue (count 10) drops the event.
 */
extern unsigned char DAT_a802afa1;
extern unsigned char DAT_a802afa8[];

void FUN_a008a184(unsigned char ev)
{
    unsigned char n;

    if (ev == 0x3f || ev == 0x4f || ev == 0x84 || ev == 0xc7)
        return;
    n = DAT_a802afa1;
    if (n == 10)
        return;
    DAT_a802afa8[n] = ev;
    n++;
    if (n > 10)
        DAT_a802afa1 = 10;
    else
        DAT_a802afa1 = n;
}
