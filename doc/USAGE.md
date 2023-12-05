<h1 align="center">
AbstractVM - Epitech 2023 - How to use
</h1>

</br>

## How to use abstractVM 📝

### Different types of instructions 📜

- **`push`**: Pushes the value at the top of the stack. The value will be copied to the top of the stack.
- **`pop`**: Unstacks the value from the top of the stack. If the stack is empty, the program execution will stop with an error.
- **`clear`**: Clears the stack. (Emptying it)
- **`dup`**: Duplicates the value at the top of the stack and pushes it to the stack. If the stack is empty, the program execution will stop with an error.
- **`swap`**: Swaps the two values at the top of the stack. If the stack is empty, the program execution will stop with an error. If there is only one value, the program execution will also stop with an error.
- **`dump`**: Displays each value of the stack, from the most recent one to the oldest one WITHOUT CHANGING the stack. Each value is separated from the next one by a newline.
- **`assert _v_`**: Asserts that the value at the top of the stack is equal to the one passed as parameter for this instruction. If it is not the case, the program execution will stop with an error. The value v has the same form that those passed as parameters to the instruction push.
- **`add`**: Unstacks the first two values on the stack, adds them together and stacks the result. If the number of values on the stack is strictly inferior to 2, the program execution will stop with an error.
- **`sub`**: Unstacks the first two values on the stack, subtracts them, then stacks the result. If the number of values on the stack is strictly inferior to 2, the program execution will stop with an error.
- **`mul`**: Unstacks the first two values on the stack, multiplies them, then stacks the result. If the number of values on the stack is strictly inferior to 2, the program execution will stop with an error.
- **`div`**: Unstacks the first two values on the stack, divides them, then stacks the result. If the number of values on the stack is strictly inferior to 2, the program execution will stop with an error. If the divisor is equal to 0, the program execution will also stop with an error.
- **`mod`**: Unstacks the first two values on the stack, calculates the modulus, then stacks the result. If the number of values on the stack is strictly inferior to 2, the program execution will stop with an error. If the divisor is equal to 0, the program execution will also stop with an error.
- **`store _i_`**: Removes the value at the top of the stack and adds it in the register _i_. If the register _i_ does not exist, the program execution will stop with an error. If the number of values on the stack is 0 the program execution will also stop with an error.
- **`load _i_`**: Takes a value from the register _i_ and pushes it at the top of the stack. If the register _i_ does not exist, the program execution will stop with an error.
- **`print`**: Asserts that the value at the top of the stack is an 8-bit integer. (If not, see the instruction assert), then interprets it as an ASCII value and displays the corresponding character on the standard output.
- **`exit`**: Terminate the execution of the current program. If this instruction does not appears while all others instruction has been processed, the execution will stop with an error.
- **`;;`**: If you're using the program without an input file, you can use this instruction to stop the program right after putting exit.
- **`;`**: You can use this instruction to comment a line in your input file or to comment the rest of the line.

### Different types of values 🔢

- **`int8`**: An 8-bit integer. (From -128 to 127)
- **`int16`**: A 16-bit integer. (From -32768 to 32767)
- **`int32`**: A 32-bit integer. (From -2147483648 to 2147483647)
- **`float`**: A float. (From -3.4e38 to 3.4e38)
- **`double`**: A double. (From -1.7e308 to 1.7e308)

### Different types of errors ❌

- **`Overflow or underflow on a value`**: If the result of an operation is outside of the range of values defined by the type of the operands or if the value inputed is outside of the range of values defined by the type of the operand.
- **`Division/Modulo by zero`**: If the divisor is equal to 0.
- **`Missing exit instruction`**: If the program doesn't have an exit instruction.
- **`[instruction] on empty stack`**: If the stack is empty when the instruction is called.
- **`Assert failed`**: If the assert instruction is not true.
- **`Unknown instruction`**: If the instruction is unknown.
- **`invalid assert instruction`**: If the assert instruction is not valid (non existing type or not a number).
- **`[instruction] on stack with less than 2 elements`**: If the stack has less than 2 elements when the instruction is called.
- **`Invalid index`**: If the register index is not valid (non existing register (over 15) or not a number) when the store or load instruction is called.
- **`Register is empty`**: If the register is empty when the load instruction is called.
- **`Print on non INT8 value`**: If the value at the top of the stack is not an INT8 when the print instruction is called.

### Example of input file 📄

```
; -------------     ; comment
; exemple.avm -     ; comment
; -------------     ; comment
push int32(42)      ; add 42 to the stack as an int32
push int32(33)      ; add 33 to the stack as an int32
add                 ; pops 42 and 33, adds them, and pushes the result (75) to the stack

push float(44.55)   ; add 44.55 to the stack as a float
mul                 ; pops 75 and 44.55, multiplies them, and pushes the result (3341.25) to the stack

push double(42.42)  ; add 42.42 to the stack as a double
push int32(42)      ; add 42 to the stack as an int32
store int32(2)      ; pops 42 and stores it in register 2

clear               ; clears the stack

push int32(2)       ; add 2 to the stack as an int32
push int32(0)       ; add 0 to the stack as an int32
load int8(2)        ; loads register 2 (42) and pushes it to the stack

dump                ; prints 42, 0, 2

div                 ; pops 0 and 2, divides them, and pushes the result (0) to the stack
assert int32(0)     ; checks that the value at the top of the stack is equal to 0 and is an int32

push int8(97)       ; add 97 to the stack as an int8
print               ; prints 'a'

push int8(98)       ; add 98 to the stack as an int8
print               ; prints 'b'

push int8(115)      ; add 115 to the stack as an int8
print               ; prints 's'

push int8(116)      ; add 116 to the stack as an int8
print               ; prints 't'

push int8(114)      ; add 114 to the stack as an int8
print               ; prints 'r'

push int8(97)       ; add 97 to the stack as an int8
print               ; prints 'a'

push int8(99)       ; add 97 to the stack as an int8
print               ; prints 'c'

push int8(116)      ; add 97 to the stack as an int8
print               ; prints 't'

clear               ; clears the stack
dump                ; prints nothing

exit                ; stops the execution of the program
```