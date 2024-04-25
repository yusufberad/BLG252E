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
    #include <fstream>

    #include "../include/pokemon.h"

    using namespace std;

    //-------------Do Not Change These Global Variables-------------//
    int NAME_COUNTER = 0;   //Use this to keep track of the enemy names
    int POK_COUNTER = 0;    //Use this to keep track of the pokemon names
    int PLAYER_POKEMON_ATTACK = 20; //You don't have to use this variable but its here if you need it
    int ENEMY_POKEMON_ATTACK = 10;  //You don't have to use this variable but its here if you need it
    //--------------------------------------------------------------//

    //---If Necessary Add Your Global Variables Here---// 
    // 
    //
    //
    //-------------------------------------------------//

    //-------------Do Not Change These Function Definitions-------------//
    string* readEnemyNames(const char*);
    string* readPokemonNames(const char*);
    player characterCreate(string, int);
    void mainMenu();
    void fightEnemy(player*, string*, string*);
    void catchPokemon(player*, string*);
    //------------------------------------------------------------------//

    //---If Necessary Add Your Function Definitions Here---// 
    //
    //
    //
    //-----------------------------------------------------//

    //-------------Do Not Change This Function-------------//
    int main(int argc, char* argv[]){
        system("clear");

        //---Creating Enemy and Pokemon Name Arrays---//
        string* enemyNames = readEnemyNames(argv[1]);         
        string* pokemonNames = readPokemonNames(argv[2]);
        

        string playerName;
        int pokemonChoice;

        cout << "Welcome to the Pokemon Game! \n" << endl;
        cout << "Please enter your name: "; 
        cin >> playerName;
        cout << "Please choose one of these pokemons as your pokemon: \n1- Bulbasaur \n2- Charmender \n3- Squirtle \nChoice: ";
        cin >> pokemonChoice;

        //---Character Creation--//
        player newPlayer = characterCreate(playerName, pokemonChoice);
        
        int menuChoice;

        while(true){
            mainMenu(); 
            cin>>menuChoice;

            switch (menuChoice){
            case 1:
                fightEnemy(&newPlayer, enemyNames, pokemonNames);
                break;
            case 2:
                catchPokemon(&newPlayer, pokemonNames);
                break;
            case 3:
                cout<<newPlayer.showPokemonNumber()<<endl;
                break;
            case 4:
                cout<<newPlayer.showPokeballNumber()<<endl;
                break;
            case 5:
                cout<<newPlayer.showBadgeNumber()<<endl;
                break;
            case 6:
                cout << endl;
                cout << "------- Pokedex -------" <<endl;
                newPlayer.playerPokedex.printPokedex();
                break;
            case 7:
                //---Deletes Dynamic Arrays From Memory and Exits---//
                delete[] enemyNames;
                delete[] pokemonNames;
                delete &newPlayer;
                return EXIT_SUCCESS;
                break;
    
            default:
                cout << "Please enter a valid number!!!" << endl;
                break;
            }
        }
        return EXIT_FAILURE;
    };
    //-----------------------------------------------------//

    //-------------Code This Function-------------//
    string* readEnemyNames(const char* argv){
        ifstream file(argv);
        string line;

        if(file.is_open()){
            getline(file, line);
            int size = stoi(line);
            string *enemyNames = new string[size];
            string name;
            for(int i = 0 ; i < size -1 ;i++){
                getline(file,name);
                enemyNames[i] = name;
            }

            return enemyNames;
        }
        return nullptr;
    };
    //-----------------------------------------------------//

    //-------------Code This Function-------------//
    string* readPokemonNames(const char* argv){
        ifstream file(argv);

        string line;
        if(file.is_open()){
            getline(file, line);
            int size = stoi(line);
            string *pokemonNames = new string[size];
            string name;
            for(int i = 0; i < size - 1 ; i++){
                getline(file, name);
                pokemonNames[i] = name;
            }
            return pokemonNames;
        }
        return nullptr;
    };
    //-----------------------------------------------------//

    //-------------Code This Function-------------//
    player characterCreate(string playerName, int pokemonChoice){
        pokemon newPokemon;
        switch(pokemonChoice){
            case 1:
                newPokemon = pokemon("Bulbasaur", PLAYER_POKEMON_ATTACK);
                break;
            case 2:
                newPokemon = pokemon("Charmender", PLAYER_POKEMON_ATTACK);
                break;
            case 3:
                newPokemon = pokemon("Squirtle", PLAYER_POKEMON_ATTACK);
                break;
            default:
                newPokemon = pokemon("Bulbasaur", PLAYER_POKEMON_ATTACK);
                break;
        }
        player newPlayer(playerName, newPokemon);
        return newPlayer;
    };
    //--------------------------------------------//

    //-------------Do Not Change This Function-------------//
    void mainMenu(){
        cout << endl;
        cout << "-------- Menu --------" << endl;
        cout << "1. Fight for a badge" << endl;
        cout << "2. Catch a Pokemon" << endl;
        cout << "3. Number of Pokemons" << endl;
        cout << "4. Number of Pokeballs " << endl;
        cout << "5. Number of Badges" << endl;
        cout << "6. Pokedex" << endl;
        cout << "7. Exit" << endl;
        cout << endl;
        cout << "Choice: ";
    };
    //-----------------------------------------------------//

    //-------------Code This Function-------------//
    void fightEnemy(player* newPlayer, string* enemyNames, string* pokemonNames){


        
        pokemon enemyPokemon(pokemonNames[POK_COUNTER %5],ENEMY_POKEMON_ATTACK);
        POK_COUNTER +=1;
        
        enemy newEnemy(enemyNames[NAME_COUNTER % 6], enemyPokemon);
        NAME_COUNTER +=1;
        
        int enemyPokeHP = newEnemy.getPokemon().getHP();
        int enemyPokeAtk = newEnemy.getPokemon().getAtk();



        int playerPokeHP = newPlayer->getPokemon().getHP();
        int playerPokeAtk = newPlayer->getPokemon().getAtk();

        newPlayer->playerPokedex.updatePokedex(enemyPokemon);

        int choice = 0;
        cout << "You encounter with Misty and his/hers pokemon Alakazam(.*)Alakazam Health: 100 Attack: 10(.*)1- Fight(.*)2- Runaway(.*)Choice: ";
        cin >> choice;
        
        while(choice == 1){
            
            enemyPokeHP = enemyPokeHP - playerPokeAtk;
            playerPokeHP = playerPokeHP - enemyPokeAtk;
            if(playerPokeHP <= 0){
                break;
            }
            if(enemyPokeHP <= 0){
                cout << "Your Pokemons Healt: " << playerPokeHP << " Misty Pokemons Healt: " << enemyPokeHP << " You Won! ";
                newPlayer->battleWon();
                break;
            }


            cout << "Your Pokemons Healt: " << playerPokeHP << " Misty Pokemons Healt: " << enemyPokeHP << " 1- Fight 2- Runaway Choice: ";
            cin >> choice;   
            
        }
    };
    //--------------------------------------------//

    //-------------Code This Function-------------//
    void catchPokemon(player* newPlayer, string* pokemonNames){
        

        
        pokemon enemyPokemon(pokemonNames[POK_COUNTER %5],ENEMY_POKEMON_ATTACK);
        POK_COUNTER +=1;

        // player new_player(*newPlayer);

        newPlayer->playerPokedex.updatePokedex(enemyPokemon);
        
        int choise;
        cout << "You encounter with " << enemyPokemon.getName() << " Health: " << enemyPokemon.getHP() << " Attack: " << enemyPokemon.getAtk() << " 1- Catch 2- Runaway Choice: ";
        cin >> choise;

        if(choise == 1){
            cout <<"You catch " << enemyPokemon.getName()<< "\n";
            newPlayer->catchPokemon();
        }

    };
    //--------------------------------------------//
