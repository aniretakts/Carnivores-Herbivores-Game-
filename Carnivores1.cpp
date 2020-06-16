#include <iostream>
#include <string>
#include <stdlib.h>
#include "Carnivores.h"
#include "Carnivores1.h"

using namespace std;

Carnivores1::Carnivores1(){
    population++;
}

void Carnivores1::setPopulation(int p){
    population = p;
}

int Carnivores1::getPopulation(){
    return population;
}

int Carnivores1::getEaten(){
    return eaten;
}

int Carnivores1::getStarved(){
    return starved;
}
