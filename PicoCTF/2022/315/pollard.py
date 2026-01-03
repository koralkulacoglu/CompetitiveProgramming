# Python code for Pollard p-1 
# factorization Method
   
# importing "math" for 
# calculating GCD
import math
   
# importing "sympy" for 
# checking prime
import sympy
   
      
# function to generate 
# prime factors
def pollard(n):
   
    # defining base
    a = 2
   
    # defining exponent
    i = 2
   
    # iterate till a prime factor is obtained
    while(True):
   
        # recomputing a as required
        a = (a**i) % n
   
        # finding gcd of a-1 and n
        # using math function
        d = math.gcd((a-1), n)
   
        # check if factor obtained
        if (d > 1):
   
            #return the factor
            return d
   
            break
   
        # else increase exponent by one 
        # for next round
        i += 1
  
# Driver code
n = 20315635651124912984515569804452163686341850013696892660906128136819797136606166640512061300871730082678852347289683414577875315257508863419744829862488421097701544807033763259388480678656857978660244117118689602255153016442082895618088059053583100081354744782493262222426645984606929075871402224281598594638235185526390929947790501952697045041909826861574502730293803688921033556459704034559812852198923488900069859792723698642820535563982856768476810396332992067479261742048065374953660516092070308284902658070062102875855809825285192031458455730978690531668790277680784534612991113697188852474181761134441264323981
# n = 1403
   
# temporarily storing n
num = n
   
# list for storing prime factors
ans = []
   
# iterated till all prime factors
# are obtained
while(True):
   
    # function call
    d = pollard(num)
   
    # add obtained factor to list
    ans.append(d)
   
    # reduce n
    r = int(num/d)
   
    # check for prime using sympy
    if(sympy.isprime(r)):
   
        # both prime factors obtained
        ans.append(r)
   
        break
   
    # reduced n is not prime, so repeat
    else:
   
        num = r
  
print("Prime factors of", n, "are", *ans)
