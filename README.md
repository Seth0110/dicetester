# DiceTester

Test the accuracy of a die or pool of dice.

Set SIDES to the number of sides of the die/dice in question  
Build with make dt

Manually roll dice and input the numbers, use pipes to save/reload data:  
`./dt > output.dat`  
`<input.dat ./dt`

# Future improvements

Planned features:  
- Interactive Mode: -i flag to prompt for dice input, otherwise just use stdin/stdout and end at EOF
- Chi Squared Test: "Simple" randomness test, defined below
  
# Chi Squared Test

Total samples should be >= degrees of freedom * 5

Sum of (O-E)^2/E = Χ^2 where O = Observed value, E = Expected value.  
Then compare Χ^2 result against Chi Squared Distribution for the proper degrees of freedom minus one to get %  
PDF Chi Squared Distribution: f(x) = 2^(1-n/2)*x^(n-1)*e^(-(x^2)/2) / G(n/2)  
Can use CDF to get an exact answer without integrating, or calculate an approximate integral of PDF
  n -> Degrees of freedom
  G -> Gamma function G(x) => Included in GNU math.h
  
Probability for the probability of the percent calculated and up -> P value  
P < Alpha -> Reject hypothesis (dice are random)  
P >= Alpha -> Do not reject hypothesis (dice still could be not random but looks good via the test)
  P = (Integral of 0 to P)-1
Alpha -> Significance level -> Usually .05, can be .01 to .1
