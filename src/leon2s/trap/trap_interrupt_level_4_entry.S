! trap_interrupt_level_4_entry  (FUN_a0060140)
!
! Trap table slot 0x14 (interrupt level 4): reads %psr and %tbr and jumps to the handler at 0xa00603ac.
! Name basis: proven - trap table position and the slot's own instructions
!
! Matching notes
! --------------
! leon2s FUN_a0060140 @ 0xa0060140  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060140
	.type FUN_a0060140, #function
FUN_a0060140:
! Slot of trap type 0x14, interrupt level 4. The trap has already put the PC and nPC of the
! trapped instruction in %l1 and %l2; the slot adds PSR and TBR and jumps on to
! the common interrupt entry irq_entry (0xA00603AC), which saves the state and
! calls the service routine of the level from the vector table at 0xA8076040.
	rd  %psr, %l0                     ! processor state register (PSR) to %l0
	sethi  %hi(0xa0060000), %l4       ! upper bits of the handler address 0xA00603AC
	jmp  %l4 + 0x3ac                  ! jump to 0xA00603AC: common interrupt entry
	rd  %tbr, %l3                     ! delay slot, runs before the jump: TBR (holds the trap type) to %l3
	.size FUN_a0060140, .-FUN_a0060140
