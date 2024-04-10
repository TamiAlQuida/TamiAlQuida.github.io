

total_amount_of_calories = 672 + 500 # + fett
amount_of_fat_contained_in_food = 672*0.55 + 500*0.56 # +fett
#check if above is true because ...*0.55 should be of grams not of 

fat_percentage = amount_of_fat_contained_in_food/total_amount_of_calories

desired_fat_percentage = 0.7

coconut_calories_needed_to_stay_in_ketosis = (amount_of_fat_contained_in_food -(desired_fat_percentage*total_amount_of_calories))/(desired_fat_percentage-1)

print(total_amount_of_calories)
print(amount_of_fat_contained_in_food)
print(fat_percentage)
print(coconut_calories_needed_to_stay_in_ketosis)


grams_of_coconut_oil = (100/900)*coconut_calories_needed_to_stay_in_ketosis
print(grams_of_coconut_oil)

ml_of_coconut_oil = grams_of_coconut_oil*1.08

print(ml_of_coconut_oil)

total_amount_of_calories_plus_coconut_oil_calories = total_amount_of_calories + coconut_calories_needed_to_stay_in_ketosis
print(total_amount_of_calories_plus_coconut_oil_calories)