/* startup_run_partition_loader  (FUN_CODE_1899)
 *
 * Call startup_load_partition_table with a null pointer argument.
 * Name basis: derived - the only caller of the table loader
 *
 * Matching notes
 * --------------
 * Built with the section default OPTIMIZE(7,SPEED).
 * Source form: the result goes through bit 0x20.1 (cleared, set on failure, returned in the carry flag).  The
 * call passes the generic null pointer 00:0000 (MOV R3/R2/R1,#0), although startup_load_partition_table uses
 * no argument; the exact build depends on it.
 */
unsigned char bdata _bdata_20 _at_ 0x20;
sbit load_failed = _bdata_20 ^ 1;   /* bit 0x20.1 */

bit startup_load_partition_table(void *);

/* startup_run_partition_loader
 *
 * Runs startup_load_partition_table and turns its result around: returns 1 when the table loader returns 0
 * (failure), 0 when it returns 1.  Only caller: startup_boot_main, which prints "Can't find valid partition
 * table!!!" and stops on 1, and starts the next program on 0.  startup_load_partition_table always returns 1, so
 * this routine always returns 0.
 */
bit startup_run_partition_loader(void)
{
    load_failed = 0;
    if (!startup_load_partition_table((void *)0)) {
        load_failed = 1;
    }
    return load_failed;
}
