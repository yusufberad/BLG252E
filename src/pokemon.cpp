//--- 2023-2024 Spring BLG 252E Object Oriented Programing Assignment 1 ---//
//--------------------------//
//---Name & Surname: Yusuf Bera Danışık
//---Student Number: 150210105
//--------------------------//

//-------------Do Not Add New Libraries-------------//
//-------------All Libraries Needed Were Given-------------//
#include <iostream>
#include <stdio.h>
#include <string.h>

#include "pokemon.h"

using namespace std;

//-------------You Can Add Your Functions Down Below-------------//

pokemon::pokemon(){
    this->name = "Pikachu";
    this->hpValue = 100;
    this->atkValue = 20;
}

pokemon::pokemon(string name, int attack){
    this->name = name;
    this->hpValue = 100;
    this->atkValue = attack;
}

pokemon::pokemon(pokemon &old){
    this->name = old.name;
    this->hpValue = old.hpValue;
    this->atkValue = old.atkValue;
}

int pokemon::getHP(){
    return this->hpValue;
}

int pokemon::getAtk(){
    return this->atkValue;
}

string pokemon::getName(){
    return this->name;
}

pokedex::pokedex(){
    this->value = 0;
}

void pokedex::updatePokedex(pokemon newPokemon){
        bool isExist = false;
        for (int i = 0; i < this->value; i++){
            if(newPokemon.getName() == pokedexArray[i].getName()){
                isExist = true;
                break;
            }
            
        }

        if(!isExist){
            pokedexArray[value] = newPokemon;
            value++;
        }
       }

void pokedex::printPokedex(){
    for(int i = 0; i < this->value; i++){
        cout << pokedexArray[i].getName() << '\n';
    }
}

player::player(){
    this->name = 'Ash';
    this->pokemonNumber = 0;
    this->pokeballNumber = 0;
    this->badgeNumber = 0;
    this->playerPokemon = *new pokemon();
}

player::player(string name, pokemon poke){
    this->name = name;
    this->playerPokemon = poke;
}

int player::showPokemonNumber(){
    return pokemonNumber;
}

int player::showPokemonNumber(){
    return pokeballNumber;
}

int player::showBadgeNumber(){
    return badgeNumber;
}

pokemon player::getPokemon(){
    return this->playerPokemon;
}