#include<stdio.h>
#include<math.h>
#include<time.h>
#include<bits/stdc++.h>
using namespace std;
long long int q, G, x, a, y, b, ka, kb, dato; 
long long int numa,numb,bal1,bal2;
/*
************************************************************
*************************(a^b) mod q************************
************************************************************
*/
long long int power(long long int a, long long int b, long long int q) //a ^ b mod q
{ 
    if (b == 1)
        return a;
 
    else
        {   dato=a;
            while(--b)
                dato *= b, dato %=q;
            return (long long int)dato;
            
        }
}
/*
**************************************************************
***********This part finds primitive root*********************
**************************************************************
*/
int powerG(int x, unsigned int y, int p) {
   int res = 1;
   x = x % p;
   while (y > 0){
      if (y & 1)
      res = (res*x) % p;
      y = y >> 1;
      x = (x*x) % p;
   }
   return res;
}
void GeneratePrimes(unordered_set<int> &s, int n) {
   while (n%2 == 0){
      s.insert(2);
      n = n/2;
   }
   for (int i = 3; i <= sqrt(n); i = i+2){
      while (n%i == 0){
         s.insert(i);
         n = n/i;
      }
   }
   if (n > 2)
   s.insert(n);
}
int findPrimitiveRoot(int n) {
   unordered_set<int> s;

   int ETF = n-1;
   GeneratePrimes(s, ETF);
   for (int r=2; r<=ETF; r++){
      bool flag = false;
      for (auto it = s.begin(); it != s.end(); it++){
         if (powerG(r, ETF/(*it), n) == 1){
            flag = true;
            break;
         }
      }
      if (flag == false)
      return r;
   }
   return 0;
}
/*
*****************ENDS Here of Primitive root****************
************************************************************
*/
/*
************************************************************
*******Finds a Random prime value in the range of 100*******
************************************************************
*/
int prinu(){//get prime number


    srand (time(0));
    int primeArray[19] = { 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
    int inDex = rand()%19;
    int Value = primeArray[inDex];
    //printf("Reference: %d\n", Value);

    return Value;

}
/*
************************************************************
***********To give an random privet key for alice***********
************************************************************
*/
int printRandomsA() 
{ 
   //srand (time(0));
   
    bal2 = rand();
    printf("bal:%d\n",bal2);
    
    numa = (bal2 % q ) + 1;  
    return numa;

}
/*
************************************************************
***********To give an random privet key for bob***********
************************************************************
*/
int printRandomsB() 
{ 
    
  // srand (time(0));
   
    bal1 = rand()+rand();
    printf("bal:%d\n",bal1);
    
    numb = (bal1 % q ) + 1;  
    return (int) numb;

}
/*
************************************************************
*******************To give an key for alice*****************
************************************************************
*/
int Alice(){//sudhu A er jonno 

     // Alice will choose the private key a 
    a = printRandomsA(); // a is the random privet key which is smaller than q

    printf("The private key a for Alice : %lld\n", a);
    x = power(G, a, q); // gets the generated key

    //generating key 
    

    return (long long int) a,x;

}
/*
************************************************************
*********************To give an key for bob*****************
************************************************************
*/
int Bob(){//sudhu B er jonnoooooooooo

    // Bob will choose the private key b
    //b = 3; // b is the random privet key which is smaller than q
    b=printRandomsB();
    printf("The private key b for Bob : %lld\n\n", b);
    y = power(G, b, q); // gets the generated key

   

    return (long long int) b,y;

}
 /*
************************************************************
************************Main Human**************************
************************************************************
*/
int main()
{
    
    //randomstuff();
    // Both the persons will be agreed upon the 
        // public keys G and P 
    q = prinu(); // A prime number P is taken
    printf("The value of q : %lld\n", q); 
 
    G = findPrimitiveRoot(q); // A primitve root for q, G is taken
    printf("The value of G : %lld\n\n", G); 
    
    Alice();
    Bob();
    
   
      //generating key
    ka = power(y, a, q); // Secret key for Alice
    kb = power(x, b, q); // Secret key for Bob
    
 
    // Generating the secret key after the exchange
        // of keys
    
    
     
    printf("Secret key for the Alice is : %lld\n", ka);
    printf("Secret Key for the Bob is : %lld\n", kb);
     
    return 0;
}
