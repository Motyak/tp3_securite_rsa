
#include <iostream>
#include <cmath>    //std::cbrt std::pow

#include <vector>
#include <utility>  //std::pair

using llong = long long;

int extendedEuc(int a, int b, int &x, int &y);
int modExp(int a, int b, int n);
int modInverse(int a, int n);

int main()
{
// Le message m est chiffré par le système RSA en utilisant les clés publiques (493, 3) 
// et (493, 5). Les messages chiffrés sont 293 et 421.

// Comme 3 et 5 sont premiers entre eux et que les deux clé publiques possèdent un même N, alors
// on peut effectuer une attaque par modulo pour retrouver le message clair.

    int x, y;   //les coefs de Bezout
    int n = 493;
    int e1 = 5, e2 = 3;   //les e
    int c1 = 421, c2 = 293; //les messages chiffrés
    int pgcd = extendedEuc(e1, e2, x, y);
    std::cout<<"On cherche à résoudre x et y tel que :"<<std::endl;
    std::cout <<e1<<"*x + "<<e2<<"*y = pgcd("<<e1<<","<<e2<<")"<<std::endl;
    std::cout <<e1<<"*"<<x<<" + "<<e2<<"*"<<y<<" = "<<pgcd<<std::endl<<std::endl;

    std::cout<<"m = ("<<c1<<"^"<<x<<" * "<<c2<<"^"<<y<<") mod "<<n<<std::endl;

    long facteurA, facteurB;
    if(x < 0)
        facteurA = std::pow(modInverse(c1, n), x / (-1));
    else
        facteurA = std::pow(c1, x);
    if(y < 0)
        facteurB = std::pow(modInverse(c2, n), y / (-1));
    else
        facteurB = std::pow(c2, y);
    
    std::cout<<"m = "<<"("<<facteurA<<" * "<<facteurB<<") % "<<n<<std::endl;
    std::cout<<"m = "<<(facteurA * facteurB) % n<<std::endl;

    return 0;
}

// calculer x = a^-1 mod n, c'est a dire x tel que a * x mod n = 1
int modInverse(int a, int n) 
{ 
    a = a % n; 
    for (int x = 1 ; x < n ; ++x) 
       if ((a * x) % n == 1) 
          return x; 
}

//a^b mod n
int modExp(int a, int b, int n)
{
	//algo expo rapide/exponential squaring
	
	if (b == 0) 
        return 1; 
  
    if (b == 1) 
        return a % n; 
  
    long long t = modExp(a, b / 2, n); 
    t = (t * t) % n; 
  
    // if exponent is even value 
    if (b % 2 == 0) 
        return t; 
  
    // if exponent is odd value 
    else
        return ((a % n) * t) % n; 
}

// calculer x et y tel que ax+by = pgcd(a,b)
int extendedEuc(int a, int b, int &x, int &y)  
{  
    // Base Case  
    if (a == 0)  
    {  
        x = 0;  
        y = 1;  
        return b;  
    }  
  
    int x1, y1; // To store results of recursive call  
    int gcd = extendedEuc(b % a, a, x1, y1);  
  
    // Update x and y using results of  
    // recursive call  
    x = y1 - (b / a) * x1;  
    y = x1;  
  
    return gcd;  
}  