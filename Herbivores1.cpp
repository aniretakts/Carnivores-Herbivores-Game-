#include <iostream>
#include <string>
#include <stdlib.h>
#include "Herbivores.h"
#include "Herbivores1.h"

using namespace std;

Herbivores1::Herbivores1(){
    population++;
}

void Herbivores1::setPopulation(int p){
    population = p;
}

int Herbivores1::getPopulation(){
    return population;
}

int Herbivores1::getEaten(){
    return eaten;
}

int Herbivores1::getStarved(){
    return starved;
}
