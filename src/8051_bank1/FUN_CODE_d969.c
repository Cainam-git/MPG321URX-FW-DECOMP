/* 8051_bank1 FUN_CODE_d969 @ 0xd969  MATCH (OPTIMIZE(7,SPEED))
 * Returns 1 when the distance between param_1 and param_2 is less than param_3, else 0. The unsigned `>`
 * comparison produces the target's SETB C / SUBB compare.
 */
unsigned char FUN_CODE_d969(unsigned char param_1, unsigned char param_2, unsigned char param_3)
{
    if (param_1 > param_2) {
        if (param_1 - param_2 < param_3)
            return 1;
        return 0;
    }
    if (param_2 - param_1 < param_3)
        return 1;
    return 0;
}
