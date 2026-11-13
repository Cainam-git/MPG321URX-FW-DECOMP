# irq_set_handler_and_arg  (fn_4000a4c8): 0x4000a4c8-0x4000a513 (firmware file offset 0x3a4c8-0x3a513), 28 instructions
# Name basis: proven - table irq_handler_table read by the level 1/3/5 dispatchers; level bytes
#   irq_level_of_interrupt
# Called from: irq_set_handler
# Stores handler and its argument in the entry of interrupt n of irq_handler_table (entry of
# interrupt n at +8 * (21 - n): {handler, arg}). handler 0 puts back the default irq_default_handler
# (irq_default_handler) with arg n. Refuses (returns 0) when n is outside 0..21 or when the level byte of n in
# irq_level_of_interrupt is 7 or more.
# a2 = n: interrupt number. a3 = handler (0 = default). a4 = arg: value passed to the handler.
# No stack locals (register code).
# Returns: the handler that was there before, or 0 when it was the default handler or n was refused.
# Addresses loaded: irq_level_of_interrupt, irq_handler_table, irq_default_handler

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	irq_set_handler_and_arg, @function
irq_set_handler_and_arg:                # fn_4000a4c8
	entry	a1, 32                  # 4000a4c8
	# if (n < 0 || n > 21) return 0;
	bltz	a2, .L4000a500          # 4000a4cb
	movi.n	a5, 21                  # 4000a4ce
	blt	a5, a2, .L4000a500      # 4000a4d0
	# if (irq_level_of_interrupt[n] >= 7) return 0;
	l32r	a8, lit_3ffe234c        # 4000a4d3  = irq_level_of_interrupt
	add.n	a8, a2, a8              # 4000a4d6
	l8ui	a8, a8, 0               # 4000a4d8
	l32r	a7, lit_3ffe2350        # 4000a4db  = irq_handler_table
	bgeui	a8, 7, .L4000a500       # 4000a4de
	# entry = &irq_handler_table[21 - n]; old = entry->handler;
	slli	a8, a2, 3               # 4000a4e1
	sub	a7, a7, a8              # 4000a4e4
	l32r	a8, lit_3ffe2354        # 4000a4e7  = irq_default_handler
	l32i	a6, a7, 168             # 4000a4ea
	# if (handler == 0) {
	bnez.n	a3, .L4000a504          # 4000a4ed
	#   entry->handler = irq_default_handler; entry->arg = n;
	s32i	a8, a7, 168             # 4000a4ef
	s32i	a2, a7, 172             # 4000a4f2
	#   return (old == irq_default_handler) ? 0 : old;
	sub	a9, a6, a8              # 4000a4f5
	movi.n	a2, 0                   # 4000a4f8
	movnez	a2, a6, a9              # 4000a4fa
	retw.n                          # 4000a4fd
	.balign	4, 0                    # 1 zero byte up to the 4-byte boundary 0x4000a500
.L4000a500:
	# return 0;   (n refused)
	movi.n	a2, 0                   # 4000a500
	retw.n                          # 4000a502
.L4000a504:
	# } else { entry->handler = handler; entry->arg = arg;
	s32i	a3, a7, 168             # 4000a504
	s32i	a4, a7, 172             # 4000a507
	#   return (old == irq_default_handler) ? 0 : old; }
	sub	a10, a6, a8             # 4000a50a
	movi.n	a2, 0                   # 4000a50d
	movnez	a2, a6, a10             # 4000a50f
	retw.n                          # 4000a512
	.size	irq_set_handler_and_arg, . - irq_set_handler_and_arg
