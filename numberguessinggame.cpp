#include <iostream>
#include <ctime>

int main()
{
    std::cout <<"enter guess limit:";
    int lim; std::cin >>lim;
    srand( time(0) ^ clock() );
    const int num = rand() % lim;
    while(true){
        std::cout<<"enter your guess:";
        int guess; std::cin>>guess;
        if(guess<num){
            std::cout<<"your guess is too small,please continue";
        }else if(guess>num){
            std::cout<<"your guess is too large,please continue";
        }else{
            std::cout<<"you have guessed correctly!\n";
            break;
        }
    }
    return 0;
}