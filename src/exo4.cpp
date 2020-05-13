
#include <iostream>
#include <cmath>    //std::pow

#include <vector>
#include <utility>  //std::pair

using llong = long long;

int restesChinois(std::vector<std::pair<int,int>> v);
    llong modInverse(llong a, llong n);

int main()
{
    // Le même message est chiffré par le système RSA en utilisant les clés publiques (55,5), 
    // (119,5), (247,5), (1643,5) et (4087,5). Les messages chiffrés sont respectivement 
    // 32, 68, 101, 305, 1668 pour m = 17

    // m = 17
    std::vector<std::pair<int,int>> equations { 
        std::make_pair(32, 55), 
        std::make_pair(68, 119), 
        std::make_pair(101, 247),
        std::make_pair(305, 1643),
        std::make_pair(1668, 4087) 
    };

    // // m = 23
    // std::vector<std::pair<int,int>> equations { 
    //     std::make_pair(23, 55), 
    //     std::make_pair(109, 119), 
    //     std::make_pair(17, 247),
    //     std::make_pair(712, 1643),
    //     std::make_pair(3405, 4087) 
    // };

    llong res = restesChinois(equations);

    // racine cubique de x
    // std::cout<<"Le message clair était donc : "<<std::cbrt(res)<<std::endl;
    std::cout<<"Le message clair était donc : "<<std::pow(res, 1.0 / equations.size())<<std::endl;


    return 0;
}

// calculer x = a^-1 mod n, c'est a dire x tel que a * x mod n = 1
llong modInverse(llong a, llong n) 
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
    llong tmp;
    
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