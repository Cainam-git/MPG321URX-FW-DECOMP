# dbg_printf  (fn_400099bc): 0x400099bc-0x40009a31 (firmware file offset 0x399bc-0x39a31), 52 instructions
# Name basis: proven - 48 callers pass printf format texts; uart_print_tx_test_lines prints 'printf test'
#   through it
# Called from: LDC_LoadPanel, ldc_cmd_set_peaking, ldc_cmd_dpll_init_check, ldc_cmd_set_segment_merge_mode,
#              ldc_gain_table_set_point, ldc_print_debug_dump, ldc_poll_mailbox_command,
# The program's printf: formats the text a2 with the further arguments into a 1024-byte buffer on its own stack
# (lib_vsprintf), sends the buffer through uart_puts and returns the character count.
# 48 routines print through it; uart_selftest calls it around the "*** UART TX Test ***" texts.
# Arguments: a2 format text; a3..a7 the first five further arguments (more follow on the caller's stack).
# Stack: a7 = a1+32 is the frame base; a7+16..a7+0x40F buf[1024]; a7+0x400..a7+0x414 the saved a2..a7 (argument
#   save area, a2 = format at a7+0x400); a7+0x420 the caller's stack arguments.
# Locals: a1+4 buf address, a1+8..a1+16 the argument list (va_list: +0 stack argument area a7+0x420,
#   +4 save area a7+0x400, +8 offset 4 = first argument after the format), a1+20 count.
# Returns: the number of characters lib_vsprintf produced.
#              dbg_memcmd_mr, dbg_memcmd_cfg, dbg_init_uart_print_banner, dbg_memcmd_poll_console, dbg_cmd_mem, dbg_cmd_mdw, dbg_cmd_wmem,
#              dbg_find_and_run_command, dbg_run_text_command, dbg_run_hex_packet, dbg_run_star_request, dbg_console_poll, dbg_console_init, dbg_print_sw_value,
#              dbg_cmd_help, dbg_cmd_gpio_test, uart_selftest, DRV_LDC_SetPanelResolution, DRV_LDC_UpdateSegmentBoundary, DRV_LDC_SetLDCSegment, DRV_LDC_SetDSRegisters,
#              DRV_LDC_Intensity_Gain_Update, ldc_test_dump_grid_values, ldc_as3824_apply_ldc_mode, LED_AS3824_SetPwmPeriod, ldc_as3824_set_current_on, ldc_as3824_set_hdr_mode, ldc_as3824_set_pwm_ctrl,
#              ldc_as3824_set_curr_ctrl, ldc_as3824_set_dacref_bit, ldc_as3824_set_options, ldc_as3824_set_direct_pwm_bit, LED_AS3824_Unlock, LED_AS3824_Init, ldc_as3824_print_state,
#              gpio_switch_mux, gpio_set_input, gpio_output_clear, gpio_output_set, uart_print_tx_test_lines, sys_init_and_run_main_loop
# Calls: lib_vsprintf, uart_puts
# Other literal values: 0x00000400, 0x00000404, 0x00000408, 0x0000040c, 0x00000410, 0x00000414, 0x00000420

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	dbg_printf, @function
dbg_printf:                             # fn_400099bc
	entry	a1, 0x460               # 400099bc
# save a2..a7 (format and first five arguments) at frame+0x400..+0x414
	mov.n	a8, a7                  # 400099bf
	movi.n	a7, 32                  # 400099c1
	add.n	a7, a1, a7              # 400099c3
	l32r	a14, lit_3ffe228c       # 400099c5  = 0x00000400
	add.n	a14, a7, a14            # 400099c8
	s32i.n	a2, a14, 0              # 400099ca
	l32r	a13, lit_3ffe2290       # 400099cc  = 0x00000404
	add.n	a13, a7, a13            # 400099cf
	s32i.n	a3, a13, 0              # 400099d1
	l32r	a12, lit_3ffe2294       # 400099d3  = 0x00000408
	add.n	a12, a7, a12            # 400099d6
	s32i.n	a4, a12, 0              # 400099d8
	l32r	a11, lit_3ffe2298       # 400099da  = 0x0000040c
	add.n	a11, a7, a11            # 400099dd
	s32i.n	a5, a11, 0              # 400099df
	l32r	a10, lit_3ffe229c       # 400099e1  = 0x00000410
	add.n	a10, a7, a10            # 400099e4
	s32i.n	a6, a10, 0              # 400099e6
	l32r	a9, lit_3ffe22a0        # 400099e8  = 0x00000414
	add.n	a9, a7, a9              # 400099eb
	s32i.n	a8, a9, 0               # 400099ed
# va_start(args, format): args = { frame+0x420, frame+0x400, 4 }
	addi	a2, a7, 16              # 400099ef
	s32i.n	a2, a1, 4               # 400099f2
	addi.n	a2, a1, 8               # 400099f4
	l32r	a15, lit_3ffe22a4       # 400099f6  = 0x00000420
	add.n	a15, a7, a15            # 400099f9
	mov.n	a15, a15                # 400099fb
	s32i.n	a15, a2, 0              # 400099fd
	addi.n	a15, a1, 8              # 400099ff
	l32r	a14, lit_3ffe228c       # 40009a01  = 0x00000400
	add.n	a14, a7, a14            # 40009a04
	mov.n	a14, a14                # 40009a06
	s32i.n	a14, a15, 4             # 40009a08
	addi.n	a13, a1, 8              # 40009a0a
	movi.n	a12, 4                  # 40009a0c
	s32i.n	a12, a13, 8             # 40009a0e
# count = lib_vsprintf(buf, format, args);
	l32i.n	a10, a1, 4              # 40009a10
	l32r	a11, lit_3ffe228c       # 40009a12  = 0x00000400
	add.n	a11, a7, a11            # 40009a15
	l32i.n	a11, a11, 0             # 40009a17
	addi.n	a14, a1, 8              # 40009a19
	l32i.n	a12, a14, 0             # 40009a1b
	l32i.n	a13, a14, 4             # 40009a1d
	l32i.n	a14, a14, 8             # 40009a1f
	call8	lib_vsprintf            # 40009a21
	s32i.n	a10, a1, 20             # 40009a24
# uart_puts(buf);
	addi.n	a3, a1, 8               # 40009a26
	addi	a10, a7, 16             # 40009a28
	call8	uart_puts               # 40009a2b
# return count;
	l32i.n	a2, a1, 20              # 40009a2e
	retw.n                          # 40009a30
	.size	dbg_printf, . - dbg_printf
