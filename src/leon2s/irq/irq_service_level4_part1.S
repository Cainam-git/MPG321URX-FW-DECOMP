! irq_service_level4_part1  (FUN_a0060ab4)
!
! Enter the level-4 interrupt service routine and address the LEON2 interrupt mask.
! Note: Ghidra piece 1 of the routine 0xA0060AB4..0xA0060BB7, not callable on its own; sources: status
!   0x9F12007C minus mask 0x9F120044; handlers in 0xA80787A8[0..6]; upper half of the mask word selects
!   acknowledge-after-call; known handlers: tick routine 0xA00618D8 (source 1), UART receive into ring buffer
!   0xA0061450 (source 6).
! Name basis: proven - vector table 0xA8076040 slot 3 = 0xA0060AB4; masks bit 0x10 of LEON2 mask 0x9F100090
!   and calls table 0xA80787A8
!
! Matching notes
! --------------
! leon2s FUN_a0060ab4 @ 0xa0060ab4  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060ab4
	.type FUN_a0060ab4, #function
FUN_a0060ab4:
! Service routine of interrupt level 4 (entry 4 of the vector table at 0xA8076040),
! called by irq_entry. It masks the level and marks it active in 0x9F120028, then looks at its
! seven sources one by one: a source that is signalling, not masked and has a handler in
! the table at 0xA80787A8 is acknowledged and its handler run, in the order the upper half
! of the source mask register sets for it. At the end it writes the level bit to 0x9F120034 and to
! the LEON2 interrupt clear register, drops the active bit and unmasks the level.
	save  %sp, -104, %sp              ! open a stack frame of 104 bytes (a new register window)
	sethi  %hi(0x9f100000), %o5       ! %o5 = 0x9F100000 (LEON2 interrupt registers)
	or  %o5, 0x90, %o5                ! %o5 = the LEON2 interrupt mask register
	.size FUN_a0060ab4, .-FUN_a0060ab4
