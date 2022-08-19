#include <iostream>
#include <string>
#include <vector> 
#include <stdlib.h>
#include "food_item.h"

using namespace std;

int main(){
    //Daily recommended intakes:
    const int DAILY_ENERGY = 2000;
    const int DAILY_FAT = 70;
    const int DAILY_SUGAR = 30;
    const int DAILY_PROTEIN = 50;
    const int DAILY_SODIUM = 2300;
    
    //Create the menu of FoodItem objects
    vector<FoodItem> menu = {
        FoodItem("Apple", 72, 0, 14, 0, 1),
        FoodItem("French Fries", 340, 16, 0, 4, 190),
        FoodItem("Hamburger", 250, 9, 6, 12, 510),
        FoodItem("Protein Bar", 200, 5, 3, 20, 110),
        FoodItem("Ramen", 390, 8, 5, 22, 1850),
        FoodItem("Orange", 62, 0, 12, 1, 0),
        FoodItem("Cookie", 210, 10, 20, 2, 170),
        FoodItem("Salmon Roll", 360, 4, 15, 12, 920),
        FoodItem("Ice Cream", 330, 21, 27, 6, 65),
        FoodItem("Quesadilla", 490, 28, 1, 20, 1345),
    };
    
    //Declare the variables to be used in the while loop
    FoodItem total = FoodItem("Total", 0, 0, 0, 0, 0);
    int foodItemNum = -1;
    
    //Loop until the user enters 11
    while(foodItemNum != 11)
    {
        cout << "Please choose a food from the list below by entering a number. Choose 11 if you are finished." << endl;
        
        //List the options of food items
        int printedNum = 1;
        for(int i = 0; i <= menu.size(); i++)
        {
            if(i == menu.size()) //Print out the Finished option
            {
                cout << printedNum << ". " << "Finished" << endl;
            }
            else //Print out the respective food item
            {
                cout << printedNum << ". " << menu.at(i).getName() << endl;
                printedNum++;
            }
        }
        
        string foodItemVal;
        cin >> foodItemVal;
        foodItemNum = atoi(foodItemVal.c_str());
        int foodItemIndex = foodItemNum - 1;
    
        //Force the user to input a valid number
        if(foodItemIndex >= 0 && foodItemIndex < menu.size())
        {
            total = total + menu.at(foodItemIndex - 1);
        }
        else
        {
            if(foodItemNum != 11)
            {
                cout << "Input isn't valid. Please input a different number." << endl;
                continue; 
            }
        }
        
    }
    
    //Test if the user's food exceeds the daily recommended amount
    if(total.getCalories() > DAILY_ENERGY)
    {
        int calDifference = total.getCalories() - DAILY_ENERGY;
        cout << "You have exceeded the daily recommended energy intake of " << DAILY_ENERGY << " calories by " << calDifference << " calories." << endl;
    }
    if(total.getFat() > DAILY_FAT)
    {
        int fatDifference = total.getFat() - DAILY_FAT;
        cout << "You have exceeded the daily recommended fat intake of " << DAILY_FAT << " grams by " << fatDifference << " grams." << endl;   
    }
    if(total.getSugar() > DAILY_SUGAR)
    {
        int sugarDifference = total.getSugar() - DAILY_SUGAR;
        cout << "You have exceeded the daily recommended sugar intake of " << DAILY_SUGAR << " grams by " << sugarDifference << " grams." << endl;
    }
    if(total.getProtein() > DAILY_PROTEIN)
    {
        int proteinDifference = total.getProtein() - DAILY_PROTEIN;
        cout << "You have exceeded the daily recommended protein intake of " << DAILY_PROTEIN << " grams by " << proteinDifference << " grams." << endl;  
    }
    if(total.getSodium() > DAILY_SODIUM)
    {
        int sodiumDifference = total.getSodium() - DAILY_SODIUM;
        cout << "You have exceeded the daily recommended sodium intake of " << DAILY_ENERGY << " milligrams by " << sodiumDifference << " milligrams." << endl;
    }
    
    
    return 0;
}