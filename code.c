#include<stdio.h>
#include<math.h>
 
long long int q, G, x, a, y, b, ka, kb, dato; 
long long int numa,numb,bal1,bal2;

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
int randomstuff(){
    
    int rnd_val = rand()+time(0);
    srand(rnd_val);
}
int prinu(){//get prime number


    srand ( time(NULL) );
    int primeArray[19] = { 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
    int inDex = rand() % 19;
    int Value = primeArray[inDex];
    //printf("Reference: %d\n", Value);

    return Value;

}
int printRandomsA() 
{ 
   srand (time(0));
   
    bal2 = rand();
    printf("bal:%d\n",bal2);
    
    numa = (bal2 % q ) + 1;  
    return numa;

}
int printRandomsB() 
{ 
    
   srand (time(0));
   
    bal1 = rand()+rand();
    printf("bal:%d\n",bal1);
    
    numb = (bal1 % q ) + 1;  
    return (int) numb;

}
int Alice(){//sudhu A er jonno 

     // Alice will choose the private key a 
    a = printRandomsA(); // a is the random privet key which is smaller than q

    printf("The private key a for Alice : %lld\n", a);
    x = power(G, a, q); // gets the generated key

    //generating key 
    

    return (long long int) a,x;

}

int Bob(){//sudhu B er jonnoooooooooo

    // Bob will choose the private key b
    //b = 3; // b is the random privet key which is smaller than q
    b=printRandomsB();
    printf("The private key b for Bob : %lld\n\n", b);
    y = power(G, b, q); // gets the generated key

   

    return (long long int) b,y;

}
 
int main()
{
    
    randomstuff();
    // Both the persons will be agreed upon the 
        // public keys G and P 
    q = prinu(); // A prime number P is taken
    printf("The value of q : %lld\n", q); 
 
    G = 9; // A primitve root for q, G is taken
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
