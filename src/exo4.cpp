
#include <iostream>
#include <cmath>    //std::cbrt

#include <vector>
#include <utility>  //std::pair

using llong = long long;

int restesChinois(std::vector<std::pair<int,int>> v);
    int modInverse(int a, int n);

int main()
{
    // Le même message est chiffré par le système RSA en utilisant les clés publiques (391,3), 
    // (55,3) et (87,3). Les messages chiffrés sont respectivement 208, 38 et 32.

    std::vector<std::pair<int,int>> equations { 
        std::make_pair(208, 391), 
        std::make_pair(38, 55), 
        std::make_pair(32, 87) 
    };

    int res = restesChinois(equations);

    // racine cubique de x
    std::cout<<"Le message clair était donc : "<<std::cbrt(res)<<std::endl;


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

int restesChinois(std::vector<std::pair<int,int>> v)
{
    std::cout<<"On cherche à résoudre x tel que :"<<std::endl;
    for(const auto& p : v)
        std::cout<<"x = "<<p.first<<" mod "<<p.second<<std::endl;

    llong produitDesN = 1;
    llong sum = 0;
    long tmp;
    
    for(const auto& p : v)
        produitDesN *= p.second;
    
    for(const auto& p : v)
    {
        tmp = produitDesN / p.second;
        sum += p.first * tmp * (modInverse(tmp, p.second));
    }

    std::cout<<std::endl<<"x = "<<sum % produitDesN<<std::endl;

    return sum % produitDesN;
}