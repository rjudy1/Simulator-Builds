## 32-bit Intcode Computer
### modeled from Advent of Code 2019 Intcode problems

### Commands:

1 - add next two arguments to third  - 3 args

2 - multiply next two arguments  - 3 args

3 - input to next param  - 1 args

4 - output, print  - 1 arg

5 - jump if true - 2 args

6 - jump if false - 2 args

7 - less than - 3 args 

8 - equals - 3 args

9 - adjust base + parameter - 1 arg

99 - halt

Opcode is last two digits (base 10) of the command.


### Parameter Modes

0 - absolute: address of operand in array

1 - immediate: actual value of operand given - no output parameter is immediate

2 - relative: parameter + value of a base register gives address

The hundreds place corresponds to the parameter mode of the first argument, the thousands to the seconds, and so on.


### Sequence of Operations (7 cycles per operation)

0: read opcode from memory

1-3: read arguments

4-5: read actual values/input from keyboard

6: Pass through ALU and assign accordingly

7: increment pc as appropriate



### Usage

1. Write intcode program, numbers comma separated (view dec_program for example)
2. Run the intcode_to_hex.py script.
	python intcode_to_hex.py <intcode program file> <output hex file>
3. Finally, load image to instruction RAM in main_computer. Set input mode as 1 (numbers) or 0 (characters) with the labeled constant. 
4. Run simulation with Enable and set rate and ticks.


### Example intcode programs

Take input, add 3, multiply by 4, output
	203,1,101,3,1,0,102,4,0,0,4,0,99

Set base as 8, Compare input with 'h', if less, jump next instruction and print input, if more, jump next and print 0x68
	109,8,203,-7,7,1,12,2,1005,2,14,104,104,99,204,-7,99

Set base to 9, check if addr[203]=addr[base-6], if so replace it with 110 and print, if false, print 203
	9,0,2008,203,-6,0,1006,0,13,1102,10,11,3,4,3,99