#include <iostream>
#include <string>
#include <stdlib.h>
#include "Animals.h"
#include "Simulator.h"

using namespace std;

Simulator::Simulator()
{
}

void Simulator::showEaten(){
    cout << "Herbivores1 eaten: " << Herbivores1::getEaten() << endl;
    cout << "Herbivores2 eaten: " << Herbivores2::getEaten() << endl;
    cout << "Carnivores1 eaten: " << Carnivores1::getEaten() << endl;
    cout << "Carnivores2 eaten: " << Carnivores2::getEaten() << endl;
}
void Simulator::showStarved(){
    //Ποσα ζωα πεθαναν απο πεινα
    cout << "Herbovires1 that died  from starvation: " << Herbivores1::getStarved() << endl;
    cout << "Herbovires2 that died  from starvation: " << Herbivores2::getStarved() << endl;
    cout << "Carnivores1 that died  from starvation: " << Carnivores1::getStarved() << endl;
    cout << "Carnovires2 that died  from starvation: " << Carnivores2::getStarved() << endl;
}
void Simulator::showPlants(int plants_population, int size){
    //Ποσοστο φυτων στον χαρτη
    float percent;
    if (size != 0){
        percent = (float)plants_population / size;
        cout << "Plants rate: " << percent * 100 << "%" << endl;
    }
    else{
        cout << "There is no enough space in the map..." << endl;
    }
}
void Simulator::showPopulation(){
    //Πληθυσμος φυτοφαγων
    cout << "Population of all herbivores: " << Herbivores::getPopulation() << endl;
    cout << "Population of herbivores1: " << Herbivores1::getPopulation() << endl;
    cout << "Population of herbivores2: " << Herbivores2::getPopulation() << endl;

    //Πληθυσμος σαρκοφαγων
    cout << "Population of all carnivores: " << Carnivores::getPopulation() << endl;
    cout << "Population of carnivores1: " << Carnivores1::getPopulation() << endl;
    cout << "Population of carnivores2: " << Carnivores2::getPopulation() << endl;
}
void Simulator::showMap(int rows, int cols,string **map){
    //Εμφανιση χαρτη
    int i, j;
    for (i = 0; i<rows; i++)
    {
        for (j = 0; j<cols; j++)
        {
            cout << map[i][j] << "\t";
        }
        cout << endl;
    }
}

