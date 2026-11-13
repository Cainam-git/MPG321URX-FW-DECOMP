# ldc_build_command_index  (fn_400037d8): 0x400037d8-0x40003810 (firmware file offset 0x337d8-0x33810), 25 instructions
# Name basis: proven - code; used by ldc_poll_mailbox_command
# Called from: sys_init_and_run_main_loop
# Addresses loaded: ldc_command_table
# Other literal values: 0x3ffe3f60
#
# Fills the index 0x3FFE3F60 (one word per command number) so that index[cmd] is the position of cmd in the 46
# entries of ldc_command_table ({command number, handler} pairs). Called once from the main
# routine sys_init_and_run_main_loop.
# Arguments: none.
# Locals: a1+0 = i, a1+4 = count (46).
# Returns: nothing.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_build_command_index, @function
ldc_build_command_index:                # fn_400037d8
	entry	a1, 48                  # 400037d8
	# i = 0; count = 46
	movi.n	a6, 0                   # 400037db
	s32i.n	a6, a1, 0               # 400037dd
	movi.n	a5, 46                  # 400037df
	s32i.n	a5, a1, 4               # 400037e1
	# for (i = 0; i < count; i++) command_index[ldc_command_table[i].cmd] = i
	movi.n	a4, 0                   # 400037e3
	s32i.n	a4, a1, 0               # 400037e5
	l32i.n	a3, a1, 4               # 400037e7
	l32i.n	a2, a1, 0               # 400037e9
	bgeu	a2, a3, .L4000380f      # 400037eb
.L400037ee:
	l32i.n	a11, a1, 0              # 400037ee
	l32r	a12, lit_3ffe1cb4       # 400037f0  = ldc_command_table
	addx8	a11, a11, a12           # 400037f3
	l32i.n	a11, a11, 0             # 400037f6
	l32r	a12, lit_3ffe1cb8       # 400037f8  = 0x3ffe3f60
	addx4	a11, a11, a12           # 400037fb
	l32i.n	a10, a1, 0              # 400037fe
	s32i.n	a10, a11, 0             # 40003800
	l32i.n	a9, a1, 0               # 40003802
	addi.n	a9, a9, 1               # 40003804
	s32i.n	a9, a1, 0               # 40003806
	l32i.n	a8, a1, 4               # 40003808
	l32i.n	a7, a1, 0               # 4000380a
	bltu	a7, a8, .L400037ee      # 4000380c
.L4000380f:
	retw.n                          # 4000380f
	.size	ldc_build_command_index, . - ldc_build_command_index
