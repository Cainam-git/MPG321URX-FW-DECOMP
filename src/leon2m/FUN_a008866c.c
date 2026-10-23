/* leon2m FUN_a008866c @ 0xa008866c (-mcpu=v8 -O2 -g)
 * Returns bit 1 of byte 0xA802AF99 and clears that bit. Same code as FUN_a00b5014 with other constants.
 */
extern unsigned char DAT_a802af99;   // 0xa802af99

int FUN_a008866c(void)
{
    int bVar1;

    bVar1 = DAT_a802af99 >> 1;
    DAT_a802af99 = DAT_a802af99 & 0xfd;
    return bVar1 & 1;
}
