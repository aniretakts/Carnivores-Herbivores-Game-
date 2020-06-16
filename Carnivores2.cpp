#include <iostream>
#include <string>
#include <stdlib.h>
#include "Carnivores.h"
#include "Carnivores2.h"

using namespace std;

Carnivores2::Carnivores2(){
    population++;
}

void Carnivores2::setPopulation(int p){
    population = p;
}

int Carnivores2::getPopulation(){
    return population;
}

int Carnivores2::getEaten(){
    return eaten;
}

int Carnivores2::getStarved(){
    return starved;
}
