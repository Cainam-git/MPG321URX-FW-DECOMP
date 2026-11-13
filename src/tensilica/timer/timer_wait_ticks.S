# timer_wait_ticks  (fn_4000912c): 0x4000912c-0x400091a0 (firmware file offset 0x3912c-0x391a0), 51 instructions
# Name basis: derived - busy loop on 0x3ffe5598 +24 (counted by timer_service_tick); 13 callers
# Called from: ldc_cmd_set_led_current_on, dbg_cmd_gpio_test, DRV_LDC_SetLDCSegment,
#              ldc_test_dump_grid_values, ldc_as3824_write_pwm_ht, ldc_as3824_write_bdac,
#              ldc_as3824_write_byte,
# Waits until timer_state.tick_count (0x3FFE5598 +24, counted by timer_service_tick) has moved on by at least
# n from its value on entry. Each read of the count is made with interrupts masked (rsil 15) and PS restored.
# a2 = n: number of ticks.
# Locals: a1+48 n, a1+12 start, a1+28 now, a1+36 diff; a1+40, a1+0, a1+4, a1+8, a1+16 and a1+44, a1+20, a1+24,
# a1+32 hold copies of the saved PS.
# Returns: nothing.
#              ldc_as3824_write_byte_to_device, ldc_as3824_send_dev1_reg_bit7, ldc_as3824_write_word, ldc_as3824_write_word_to_device, ldc_as3824_write_bytes, ldc_as3824_set_dac
# Other literal values: 0x3ffe5598
# Special registers: ps

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	timer_wait_ticks, @function
timer_wait_ticks:                       # fn_4000912c
	entry	a1, 96                  # 4000912c
	s32i.n	a2, a1, 48              # 4000912f
	# saved = rsil(15); start = timer_state.tick_count; PS = saved;
	rsil	a4, 15                  # 40009131
	s32i.n	a4, a1, 40              # 40009134
	l32i.n	a6, a1, 40              # 40009136
	s32i.n	a6, a1, 0               # 40009138
	l32i.n	a5, a1, 0               # 4000913a
	s32i.n	a5, a1, 4               # 4000913c
	l32i.n	a8, a1, 4               # 4000913e
	s32i.n	a8, a1, 8               # 40009140
	l32r	a7, lit_3ffe2258        # 40009142  = 0x3ffe5598
	l32i.n	a7, a7, 24              # 40009145
	s32i.n	a7, a1, 12              # 40009147
	l32i.n	a10, a1, 8              # 40009149
	s32i.n	a10, a1, 16             # 4000914b
	l32i.n	a9, a1, 16              # 4000914d
	wsr.ps	a9                      # 4000914f
	rsync                           # 40009152
.L40009155:
	# do { saved = rsil(15); now = timer_state.tick_count; PS = saved;
	rsil	a11, 15                 # 40009155
	s32i.n	a11, a1, 44             # 40009158
	l32i.n	a13, a1, 44             # 4000915a
	s32i.n	a13, a1, 20             # 4000915c
	l32i.n	a12, a1, 20             # 4000915e
	s32i.n	a12, a1, 24             # 40009160
	l32i.n	a15, a1, 24             # 40009162
	s32i.n	a15, a1, 8              # 40009164
	l32r	a14, lit_3ffe2258       # 40009166  = 0x3ffe5598
	l32i.n	a14, a14, 24            # 40009169
	s32i.n	a14, a1, 28             # 4000916b
	l32i.n	a3, a1, 8               # 4000916d
	s32i.n	a3, a1, 32              # 4000916f
	l32i.n	a2, a1, 32              # 40009171
	wsr.ps	a2                      # 40009173
	rsync                           # 40009176
	# if (start < now) diff = now - start; else diff = now - start;   (both branches subtract the same way)
	l32i.n	a5, a1, 28              # 40009179
	l32i.n	a4, a1, 12              # 4000917b
	bgeu	a4, a5, .L4000918c      # 4000917d
	l32i.n	a7, a1, 12              # 40009180
	l32i.n	a6, a1, 28              # 40009182
	sub	a6, a6, a7              # 40009184
	s32i.n	a6, a1, 36              # 40009187
	j	.L40009195              # 40009189
.L4000918c:
	l32i.n	a9, a1, 12              # 4000918c
	l32i.n	a8, a1, 28              # 4000918e
	sub	a8, a8, a9              # 40009190
	s32i.n	a8, a1, 36              # 40009193
.L40009195:
	# } while (diff < n);
	l32i.n	a11, a1, 48             # 40009195
	l32i.n	a10, a1, 36             # 40009197
	bgeu	a10, a11, .L4000919f    # 40009199
	j	.L40009155              # 4000919c
.L4000919f:
	retw.n                          # 4000919f
	.size	timer_wait_ticks, . - timer_wait_ticks
