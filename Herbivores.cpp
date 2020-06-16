#include <iostream>
#include <string>
#include <stdlib.h>
#include "Animals.h"
#include "Herbivores.h"
#include "Herbivores1.h"
#include "Herbivores2.h"

using namespace std;


Herbivores::Herbivores(){
    population++;
}

int Herbivores::getPopulation(){
    return population;
}

int Herbivores::getEaten(){
    return eaten;
}

int Herbivores::getStarved(){
    return starved;
}
