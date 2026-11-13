/* sys_ir_ring_test_empty  (FUN_CODE_dea6)
 *
 * Report whether the IR ring is empty (bit result)
 * Returns: 1 when empty
 * Name basis: derived - bit form of sys_ir_ring_is_empty; the report builder sends the ring ('Reload IR') when
 *   it is not
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_dea6 @ 0xdea6  OPTIMIZE(7,SPEED) (also level 8).
 * Source form: the test '== 1' gives CJNE R7,#1 / SETB C / RET / CLR C / RET.
 */
unsigned char sys_ir_ring_is_empty(void);

/*
 * Bit-result form of sys_ir_ring_is_empty: 1 when the infrared pulse ring holds no data, else 0.
 * Only caller: ipc_fill_report_record, which sends the ring as a type 5 report ("Reload IR") when this returns 0.
 */
bit sys_ir_ring_test_empty(void)
{
    if (sys_ir_ring_is_empty() == 1)
        return 1;
    return 0;
}
