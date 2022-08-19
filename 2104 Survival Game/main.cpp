#include <iostream>
#include <sstream>
#include <time.h>

using namespace std;

////////////////////////////////////////////////////////////////////////////////
//Player class
class Player {
    public:
    Player(int x, int y){
        health = MAX_HEALTH;
        hunger = MAX_HUNGER;
        thirst = MAX_THIRST;
        
        this->x = x;
        this->y = y;
        this->score = 0;
    }
    
    int getScore() const {
        return score;
    }
    
    void takeDamage(int val){
        this->health -= val;
        if(this->health < 0) this->health = 0;
    }
    
    void takeTurn(){
        this->thirst--;
        this->hunger--;
        
        if(this->thirst <= 0){
            this->health--;
            this->thirst = 0;
        }
        
        if(this->hunger <= 0){
            this->health--;
            this->hunger = 0;
        }
        
        this->score++;
    }
    
    string getStats() const {
        stringstream ss;
        ss  << "============\n"
            << "Health: " << this->health << "\n" 
            << "Hunger: " << this->hunger << "\n" 
            << "Thirst: " << this->thirst << "\n"
            << "============\n";
        return ss.str();
    }
    
    bool isAlive() const {
        return this->health > 0;
    }
    
    void changeThirst(int val){
        this->thirst = this->thirst + val;
        if(this->thirst > MAX_THIRST) this->thirst = MAX_THIRST;
    }
    
    void changeHunger(int val){
        this->hunger += val;
        if(this->hunger > MAX_HUNGER) this->hunger = MAX_HUNGER;
    }
    
    int x, y;
    private:
    int health, hunger, thirst, score;
    const int MAX_HEALTH = 3;
    const int MAX_HUNGER = 5;
    const int MAX_THIRST = 3;
};


////////////////////////////////////////////////////////////////////////////////
//Land base class
class Land {
    public:
    virtual string getDescription() = 0;
    virtual string visit(Player& player) = 0;
};


////////////////////////////////////////////////////////////////////////////////
//Forest class derived from Land
class Forest : public Land {
    public:
    string getDescription(){
        return "a densely wooded forest.";
    }
    
    string visit(Player& player){
        int randomNum = rand() % 100;
        
        if(randomNum > 74){
            player.takeDamage(1);
            return "You are attacked by a bear while foraging for berries.";
        } else {
            player.changeHunger(1);
            return "You forage for berries in the woods and eat a few.";
        }
    }
};


////////////////////////////////////////////////////////////////////////////////
//Lake class derived from Land
class Lake : public Land {
    public:
    string getDescription(){
        return "a clear sparkling lake.";
    }
    
    string visit(Player& player){
        player.changeThirst(2);
        return "You visit the lake and drink its clean water";
    }
};


////////////////////////////////////////////////////////////////////////////////
//Town class derived from Land
class Town : public Land {
    public:
    string getDescription(){
        return "a comforting town with kind inhabitants... or are they??";
    }
    
    string visit(Player& player){
        int randomNum = rand() % 100;
        
        if(randomNum > 50){
            player.takeDamage(2);
            return "You are attacked by a vicious mob carrying torches and chased out of the town.";
        } else {
            player.changeHunger(2);
            return "The kind inhabitants fed you lots of hamburgers.";
        }
    }
};


////////////////////////////////////////////////////////////////////////////////
//Mountain class derived from Land
class Mountain : public Land {
    public:
    string getDescription(){
        return "a tall mountain with steep cliffs";
    }
    
    string visit(Player& player){
        int randomNum = rand() % 100;
        
        if(randomNum > 50){
            player.takeDamage(3);
            return "You fall down the mountain and break your leg.";
        } else {
            player.changeThirst(2);
            return "You found a stream at the top of the mountain.";
        }
    }
};


////////////////////////////////////////////////////////////////////////////////
//Desert class derived from Land
class Desert : public Land {
    public:
    string getDescription(){
        return "a dry desert with ample sand dunes";
    }
    
    string visit(Player& player){
        player.changeThirst(-2);
        return "The heat made your mouth drier than the Sahara.";
    }
};


////////////////////////////////////////////////////////////////////////////////
//Map Info:
const int MAP_SIZE = 20;
Land* map[MAP_SIZE][MAP_SIZE];

void populateMap(){
    for(int i = 0; i < MAP_SIZE; i++){
        for(int j = 0; j < MAP_SIZE; j++){
            int randomNum = rand() % 5;
            switch(randomNum){
                case 0: // Forest
                    map[i][j] = new Forest;
                    break;
                case 1: // Lake
                    map[i][j] = new Lake;
                    break;
                case 2: // Town
                    map[i][j] = new Town;
                    break;
                case 3: // Mountain
                    map[i][j] = new Mountain;
                    break;
                case 4: // Desert
                    map[i][j] = new Desert;
                    break;
                default:
                    cout << "Invalid land type selected" << endl;
                    break;
            }
        }
    }
}


////////////////////////////////////////////////////////////////////////////////
//Main routine
int main(){
    srand(time(0));
    
    populateMap();
    
    Player player(MAP_SIZE/2, MAP_SIZE/2);
    
    cout << "You wake up and find yourself lost in the middle of a strange wilderness." << endl;
    
    while(player.isAlive()){
        cout << "To the north you see " << map[player.x][player.y - 1]->getDescription() << endl;
        cout << "To the east you see " << map[player.x + 1][player.y]->getDescription() << endl;
        cout << "To the south you see " << map[player.x][player.y + 1]->getDescription() << endl;
        cout << "To the west you see " << map[player.x - 1][player.y]->getDescription() << endl;
        
        cout << "Which way will you go? Enter N, E, S, or W:" << endl;
        char userInput;
        cin >> userInput;
        
        switch(userInput){
            case 'N':
                if(player.y == 0){
                    player.y = MAP_SIZE - 1;
                }
                else{
                    player.y = player.y - 1;
                }
                break;
            case 'E':
                if(player.x == MAP_SIZE - 1){
                    player.x = 0;
                }
                else{
                    player.x = player.x + 1;
                }
                break;
            case 'S':
                if(player.y == MAP_SIZE - 1){
                    player.y = 0;
                }
                else{
                    player.y = player.y + 1;
                }
                break;
            case 'W':
                if(player.x == 0){
                    player.x = MAP_SIZE - 1;
                }
                else{
                    player.x = player.x - 1;
                }
                break;
            default:
                break;
        }
        
        cout << map[player.x][player.y]->visit(player) << endl;
        
        cout << player.getStats() << endl;
        player.takeTurn();
    }
    
    cout << "You died." << endl;
    cout << player.getScore() << endl;
    
    return 0;
}