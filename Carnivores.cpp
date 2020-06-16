#include <iostream>
#include <string>
#include <stdlib.h>
#include "Animals.h"
#include "Carnivores.h"
#include "Carnivores1.h"
#include "Carnivores2.h"


using namespace std;

Carnivores::Carnivores(){
    population++;
}

int Carnivores::getPopulation(){
    return population;
}

int Carnivores::getEaten(){
    return eaten;
}

int Carnivores::getStarved(){
    return starved;
}
