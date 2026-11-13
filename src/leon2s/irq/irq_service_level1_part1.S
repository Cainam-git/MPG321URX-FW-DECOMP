! irq_service_level1_part1  (FUN_a00608f8)
!
! Enter the level-1 interrupt service routine.
! Note: Ghidra piece 1 of the routine 0xA00608F8..0xA00609FB, not callable on its own; sources: status
!   0x9F120070 minus mask 0x9F120038; handlers in 0xA80787C4[0..5]; upper half of the mask word selects
!   acknowledge-after-call; known handlers: 0xA0072900, DP TX test-pattern checks 0xA0089E74/0xA0089F00,
!   stack-overflow report 0xA00B1CB0.
! Name basis: proven - vector table 0xA8076040 slot 0 = 0xA00608F8; masks bit 0x2 of LEON2 mask 0x9F100090 and
!   calls table 0xA80787C4
!
! Matching notes
! --------------
! leon2s FUN_a00608f8 @ 0xa00608f8  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a00608f8
	.type FUN_a00608f8, #function
FUN_a00608f8:
! Service routine of interrupt level 1 (entry 1 of the vector table at 0xA8076040),
! called by irq_entry. It masks the level and marks it active in 0x9F120028, then looks at its
! six sources one by one: a source that is signalling, not masked and has a handler in
! the table at 0xA80787C4 is acknowledged and its handler run, in the order the upper half
! of the source mask register sets for it. At the end it writes the level bit to 0x9F120034 and to
! the LEON2 interrupt clear register, drops the active bit and unmasks the level.
	save  %sp, -104, %sp              ! open a stack frame of 104 bytes (a new register window)
	sethi  %hi(0x9f100000), %o5       ! %o5 = 0x9F100000 (LEON2 interrupt registers)
	.size FUN_a00608f8, .-FUN_a00608f8
