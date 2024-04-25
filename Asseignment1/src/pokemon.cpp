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

#include "../include/pokemon.h"

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

pokemon::pokemon(const pokemon &old){
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
            
            value = value + 1;
            
        }
       }

void pokedex::printPokedex(){

    for(int i = 0; i < this->value; i++){
        cout << pokedexArray[i].getName() << "\n";
    }
}



player::player(){
    this->name = "Ash";
    this->pokemonNumber = 0;
    this->pokeballNumber = 10;
    this->badgeNumber = 0;
    this->playerPokemon = pokemon();
    this->playerPokedex = pokedex();
}

player::player(string name, pokemon &poke){
    this->name = name;
    this->playerPokemon = poke;
    this->pokemonNumber = 0;
    this->pokeballNumber = 10;
    this->badgeNumber = 0;
    this->playerPokedex = pokedex();
    
}



int player::showPokemonNumber(){
    return pokemonNumber;
}

int player::showPokeballNumber(){
    return pokeballNumber;
}

int player::showBadgeNumber(){
    return badgeNumber;
}

pokemon player::getPokemon(){
    return this->playerPokemon;
}

void player::battleWon(){
    this->badgeNumber = badgeNumber + 1;
    this->pokeballNumber = pokeballNumber + 3;
}

void player::catchPokemon(){
    this->pokemonNumber = pokemonNumber + 1;
    this->pokeballNumber = pokeballNumber -1;
}

enemy::enemy(){
    this->name = "Misty";
    this->enemyPokemon = pokemon();
}

enemy::enemy(string name, pokemon p){
    this->name = name,
    this->enemyPokemon = p;
}

pokemon enemy::getPokemon(){
    return this->enemyPokemon;
}

string enemy::getName(){
    return this->name;
}