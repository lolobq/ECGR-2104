#include "food_item.h"

//Constructors:
FoodItem::FoodItem(string nameIn, int caloriesIn, int fatIn, int sugarIn, int proteinIn, int sodiumIn){
    this->foodName = nameIn;
    this->calories = caloriesIn;
    this->totalFat = fatIn;
    this->totalSugar = sugarIn;
    this->protein = proteinIn;
    this->sodium = sodiumIn;
}

//Getters:
string FoodItem::getName() const{
    return foodName;
}

int FoodItem::getCalories() const{
    return calories;
}

int FoodItem::getFat() const{
    return totalFat;
}

int FoodItem::getSugar() const{
    return totalSugar;
}

int FoodItem::getProtein() const{
    return protein;
}

int FoodItem::getSodium() const{
    return sodium;
}

//Setters:
void FoodItem::setName(string nameIn){
    this->foodName = nameIn;
}

void FoodItem::setCalories(int caloriesIn){
    this->calories = caloriesIn;
}

void FoodItem::setFat(int fatIn){
    this->totalFat = fatIn;
}

void FoodItem::setSugar(int sugarIn){
    this->totalSugar = sugarIn;
}

void FoodItem::setProtein(int proteinIn){
    this->protein = proteinIn;
}

void FoodItem::setSodium(int sodiumIn){
    this->sodium = sodiumIn;
}

//Addition Operator:
FoodItem FoodItem::operator+(FoodItem secondItem){
    int totalCalories = getCalories() + secondItem.getCalories();
    int totalFat = getFat() + secondItem.getFat();
    int totalSugar = getSugar() + secondItem.getSugar();
    int totalProtein = getProtein() + secondItem.getProtein();
    int totalSodium = getSodium() + secondItem.getSodium();
    
    return FoodItem("Total", totalCalories, totalFat, totalSugar, totalProtein, totalSodium);
}