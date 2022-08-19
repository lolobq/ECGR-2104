#ifndef FOOD_ITEM_H
#define FOOD_ITEM_H

#include <iostream>
#include <string>

using namespace std;

class FoodItem{
    private:
    //Member Variables:
    string foodName;
    int calories;
    int totalFat;
    int totalSugar;
    int protein;
    int sodium;
    
    public:
    //Constructors:
    FoodItem(string nameIn, int caloriesIn, int fatIn, int sugarIn, int proteinIn, int sodiumIn);
    
    //Getters:
    string getName() const;
    int getCalories() const;
    int getFat() const;
    int getSugar() const;
    int getProtein() const;
    int getSodium() const;
    
    //Setters:
    void setName(string nameIn);
    void setCalories(int caloriesIn);
    void setFat(int fatIn);
    void setSugar(int sugarIn);
    void setProtein(int proteinIn);
    void setSodium(int sodiumIn);
    
    //Addition Operator
    FoodItem operator+(FoodItem secondItem);
};

#endif