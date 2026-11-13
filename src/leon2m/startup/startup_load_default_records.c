/* startup_load_default_records  (FUN_a0142380)
 *
 * Load the default part record, settings record and panel timing row.
 * Name basis: proven - nvram_load_default_part_record, nvram_load_default_settings_record and the default row
 *   copy; called from start-up
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0142380 @ 0xa0142380, flags -mcpu=v8 -O2 -g.
 * Source form: the routine has six unsigned int parameters that are passed on, in order, to the last call; the
 * system start-up declares it without parameters.
 */
extern int startup_load_default_panel_row();
extern int nvram_load_default_part_record();
extern int nvram_load_default_settings_record();

/*
 * Load the three default records at power-on (phase 5 of the system start-up, startup_bring_up_system): the part record
 * and the settings record, then the ROM default panel timing row into the active row. The six parameters are
 * handed on to startup_load_default_panel_row unchanged; the caller declares none.
 */
void startup_load_default_records(unsigned int param_1,unsigned int param_2,unsigned int param_3,unsigned int param_4,
                 unsigned int param_5,unsigned int param_6)

{
  nvram_load_default_part_record();
  nvram_load_default_settings_record();
  startup_load_default_panel_row(param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}
