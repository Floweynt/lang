# Binary Operators

## Promotion Rules
All integral numbers shall be represented as a two's complement number 
- unsigned promotion will result in a value that compares equal the the original by zero-extension
- signed promotion will result in a value that compares equal to the original by sign-extension
- signed <=> unsigned casts are done in a bitwise manner AFTER extension

## Arithmetic Operators `+, -, *, /`
### Integral
- permit such operators types of equal sign (unsigned <op> unsigned, signed <op> signed)  
- promote to the type with larger width (i32 + i64 => i64)

## Equality `==, !=`
### Integral
- permit such operators types of equal sign (unsigned <op> unsigned, signed <op> signed)
- permit types of differing width
- comparisons occur as if the smaller type is promoted to the larger type

## Relational `<, >, <=, >=, <=>`
### Integral
Refer to `@Equality.Integral`

## Bitwise `&, |, ^`
### Integral
- permit such operators types of equal sign (unsigned <op> unsigned, signed <op> signed)
- signed numbers are treated as a unsigned value via a cast

## Shift Right `>>`
### Integral
- permit LHS of signed or unsigned
- RHS (amount to shift by) must be unsigned
- sign extend after shift

## Shift Left `<<`
### Integral
- permit LHS of unsigned ONLY
- RHS must be unsigned (as always)


