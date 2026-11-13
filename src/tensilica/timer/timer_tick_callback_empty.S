# timer_tick_callback_empty  (fn_4000a3c4): 0x4000a3c4-0x4000a3c8 (firmware file offset 0x3a3c4-0x3a3c8), 2 instructions
# Name basis: proven - empty body; passed to timer_start_tick by sys_init_and_run_main_loop
# Address stored in the words at: 0x4000d024
# Empty routine: the tick callback that the main routine sys_init_and_run_main_loop passes to timer_start_tick
# (timer_start_tick), so every tick of interrupt 13 runs nothing extra.
# No arguments, no locals.
# Returns: nothing.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	timer_tick_callback_empty, @function
timer_tick_callback_empty:              # fn_4000a3c4
	# return;
	entry	a1, 32                  # 4000a3c4
	retw.n                          # 4000a3c7
	.size	timer_tick_callback_empty, . - timer_tick_callback_empty
