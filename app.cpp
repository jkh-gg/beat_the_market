#include <iostream>
#include <random>  
#include <chrono>  

int main() {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine rng(seed);

    std::uniform_int_distribution<int> distribution(1, 100);
    int randomNumber = distribution(rng);

    std::string test = "Random number is ";
    std::cout << test << randomNumber << std::endl;

  return 0;
}
