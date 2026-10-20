/* leon2m FUN_a014a820 @ 0xa014a820-0xa014a860 (16 words).
 * Sets byte 0xa802e403 to 0 when v is 0 and to 1 for any other v. Source form: a switch with the cases 0 and 1 and a
 * default case that both store 1; an if/else chain gives other code.
 */
extern unsigned char DAT_a802e403;

void FUN_a014a820(unsigned char v)
{
    switch (v) {
    case 0:
        DAT_a802e403 = 0;
        break;
    case 1:
        DAT_a802e403 = 1;
        break;
    default:
        DAT_a802e403 = 1;
        break;
    }
}
