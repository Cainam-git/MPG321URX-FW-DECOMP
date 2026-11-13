! trap_interrupt_level_15_entry  (FUN_a00281f0)
!
! Trap table slot 0x1f (interrupt level 15): reads %psr and %tbr and jumps to the handler at 0xa00290ec.
! Name basis: proven - trap table position and the slot's own instructions
!
! Matching notes
! --------------
! leon2m FUN_a00281f0 @ 0xa00281f0  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a00281f0
	.type FUN_a00281f0, #function
FUN_a00281f0:
! Slot of trap type 0x1F, interrupt level 15. The trap has already put the PC and nPC of the
! trapped instruction in %l1 and %l2; the slot adds PSR and TBR and jumps on to
! the common interrupt entry in irq_entry (0xA00290EC), which saves the state and
! calls the service routine of the level through irq_dispatch.
	rd  %psr, %l0                     ! processor state register (PSR) to %l0
	sethi  %hi(0xa0029000), %l4       ! upper bits of the handler address 0xA00290EC
	jmp  %l4 + 0xec                   ! jump to 0xA00290EC: common interrupt entry
	rd  %tbr, %l3                     ! delay slot, runs before the jump: TBR (holds the trap type) to %l3
	.size FUN_a00281f0, .-FUN_a00281f0
