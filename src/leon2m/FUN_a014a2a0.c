/* FUN_a014a2a0 (leon2m 0xa014a2a0-0xa014a388, 232 bytes), flags -mcpu=v8 -O3 -g.
 * For c = 0, 1, 2 stores v to the byte DAT_a802e3df, DAT_a802e3e0 or DAT_a802e3e1 and calls FUN_a013b5fc,
 * FUN_a013b5a0 or FUN_a013b544 with (v * 200 + 50) / 100 + 28 (unsigned) as a tail call; other c do nothing. Called
 * by FUN_a00d4690, FUN_a00d46c4, FUN_a00d46f8. Source form: a switch with the expression written in every case.
 */
extern unsigned char DAT_a802e3df, DAT_a802e3e0, DAT_a802e3e1;
extern void FUN_a013b5a0(unsigned char);
extern void FUN_a013b544(unsigned char);
extern void FUN_a013b5fc(unsigned char);
void FUN_a014a2a0(unsigned char c, unsigned char v)
{
    switch (c) {
    case 0:
        DAT_a802e3df = v;
        FUN_a013b5fc((unsigned int)(v * 200 + 50) / 100 + 28);
        break;
    case 1:
        DAT_a802e3e0 = v;
        FUN_a013b5a0((unsigned int)(v * 200 + 50) / 100 + 28);
        break;
    case 2:
        DAT_a802e3e1 = v;
        FUN_a013b544((unsigned int)(v * 200 + 50) / 100 + 28);
        break;
    }
}
