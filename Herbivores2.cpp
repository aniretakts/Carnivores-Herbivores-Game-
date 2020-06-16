#include <iostream>
#include <string>
#include <stdlib.h>
#include "Herbivores.h"
#include "Herbivores2.h"

using namespace std;

Herbivores2::Herbivores2(){
    population++;
}

void Herbivores2::setPopulation(int p){
    population = p;
}

int Herbivores2::getPopulation(){
    return population;
}

int Herbivores2::getEaten(){
    return eaten;
}

int Herbivores2::getStarved(){
    return starved;
}
