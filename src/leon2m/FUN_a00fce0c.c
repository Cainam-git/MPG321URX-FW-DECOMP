/* leon2m FUN_a00fce0c @ 0xa00fce0c  MATCH (-mcpu=v8 -O3 -g)
 * Copies the five bytes at DAT_a802c968 to d[0..4], one byte at a time (byte loads and stores, so neither side
 * needs any alignment). Referenced from FUN_a0147760.
 * DAT_a802c968 is declared as a five-byte array; the copy is five plain assignments.
 */
extern unsigned char DAT_a802c968[5];

void FUN_a00fce0c(unsigned char *d)
{
    d[0] = DAT_a802c968[0];
    d[1] = DAT_a802c968[1];
    d[2] = DAT_a802c968[2];
    d[3] = DAT_a802c968[3];
    d[4] = DAT_a802c968[4];
}
