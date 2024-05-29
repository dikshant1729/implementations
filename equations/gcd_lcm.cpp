/*
 lcm and gcd distribute over each other:

 gcd(lcm(a1, a2), lcm(a1, a3) ... lcm(a1, an)) = lcm(a1, gcd(a2, a3 ... an)) 
 lcm(gcd(a1, a2), gcd(a1, a3) ... gcd(a1, an)) = gcd(a1, lcm(a2, a3 ... an))

 other way round
 gcd(a, lcm(b, c)) = lcm(gcd(a, b), gcd(a, c)) 
 lcm(a, gcd(b, c)) = gcd(lcm(a, b), lcm(a, c))
*/

/*

 gcd(a , b) == gcd(a%b , b)

 gcd(a/m , b/m) == gcd(a,b)/m

 gcd(a , b) == gcd(a + k*b , b)

 gcd(a*b , c) == gcd(gcd(a,c)*gcd(b,c) , c)

*/