# DiceTester

Test the accuracy of a die or pool of dice.

## How to build

- Depends on GSL, install with `apt install libgsl-dev` on debian-based systems.  
- Set SIDES to the number of sides of the die/dice in question.  
- Build with `make dt`

## How to use

Manually roll dice and input the numbers into a file one per line.  
Use pipes to load the data:  
`<input.dat ./dt`

Randomness is calculated using the Chi Squared test.  
For best results make sure the observed sample size is greater than 5x number of sides.

## Future improvements

Interactive Mode: -i flag to prompt for dice input instead of only using stdin/stdout  
Auto-detect range: Maximum and minimum values determine degrees of freedom
