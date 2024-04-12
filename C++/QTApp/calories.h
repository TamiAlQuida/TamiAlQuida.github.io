#include <iostream>
using namespace std;

float weight;
float gramsOfCarbohydratePer100g;
float gramsOfProteinPer100g;
float gramsOfFatPer100g;

float amountOfCaloriesIn1gCarbohydrate = 4;
float amountOfCaloriesIn1gProtein = 4;
float amountOfCaloriesIn1gFat = 9;

const float desiredFatPercentage = 0.7;

float fatPercentage;
float fatCaloriesNeededToStayInKetosis;
float gramsOfFatNeededToStayInKetosis;
float caloriesOfMeal;


void inputData (float weight, float gramsOfCarbohydratePer100g, float gramsOfProteinPer100g, float gramsOfFatPer100g) {
    float amountOfCaloriesInCarbohydratesPer1g = (gramsOfCarbohydratePer100g * amountOfCaloriesIn1gCarbohydrate) / 100;
    float amountOfCaloriesInProteinPer1g = (gramsOfProteinPer100g * amountOfCaloriesIn1gProtein) / 100;
    float amountOfCaloriesInFatPer1g = (gramsOfFatPer100g * amountOfCaloriesIn1gFat) / 100;

    float totalAmountOfCaloriesPer1g = (amountOfCaloriesInCarbohydratesPer1g + amountOfCaloriesInProteinPer1g + amountOfCaloriesInFatPer1g);
    float totalAmountOfCaloriesInThisMeal = weight * totalAmountOfCaloriesPer1g;
    float totalAmountofCaloriesInThisMealFromFat = amountOfCaloriesInFatPer1g * weight;

    cout << "totalAmountOfCaloriesInThisMeal: " << totalAmountOfCaloriesInThisMeal << "\n";

    cout << "totalAmountofCaloriesInThisMealFromFat: " << totalAmountofCaloriesInThisMealFromFat << "\n";

    fatPercentage = totalAmountofCaloriesInThisMealFromFat / totalAmountOfCaloriesInThisMeal;
    cout << "fat percentage: " << fatPercentage << "\n";

    //desiredFatPercentage = (totalAmountofCaloriesInThisMealFromFat + fatCaloriesNeededToStayInKetosis) / (totalAmountOfCaloriesInThisMeal + fatCaloriesNeededToStayInKetosis);
    fatCaloriesNeededToStayInKetosis = (totalAmountofCaloriesInThisMealFromFat - (desiredFatPercentage * totalAmountOfCaloriesInThisMeal))/(desiredFatPercentage - 1);
    cout << "calories needed from fat to stay in ketosis: " << fatCaloriesNeededToStayInKetosis << "\n\n";
    
    gramsOfFatNeededToStayInKetosis = fatCaloriesNeededToStayInKetosis / 9;
    cout << "grams of fat to stay in ketosis: " << gramsOfFatNeededToStayInKetosis << "\n\n";

    caloriesOfMeal = fatCaloriesNeededToStayInKetosis + totalAmountOfCaloriesInThisMeal;
    cout << "Calories of meal + fat: " << caloriesOfMeal << "\n\n";
};
