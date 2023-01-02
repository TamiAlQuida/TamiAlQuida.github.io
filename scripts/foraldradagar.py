
bas_sek = 1609
laginkomst_sek = 180
laginkomst_dagar = 90
hoginkomst_dagar = 390
totalt_antal_dagar = 480

pauline_bas_dagar = 154
pauline_delade_dagar = 26.1
pauline_laginkomst_dagar = 0
tom_bas_dagar = 26.1
tom_delade_dagar = 139.2
tom_laginkomst_dagar = 34.8

pauline_inkomst_bas = (pauline_delade_dagar + pauline_bas_dagar) * bas_sek
total_inkomst_pauline = pauline_inkomst_bas

tom_inkomst_bas = (tom_delade_dagar + tom_bas_dagar) * bas_sek
tom_inkomst_låginkomst = tom_laginkomst_dagar * laginkomst_sek
total_inkomst_tom = tom_inkomst_bas + tom_inkomst_låginkomst

total_inkomst_skillnad = total_inkomst_pauline - total_inkomst_tom

pauline_antal_dagar = pauline_bas_dagar + pauline_delade_dagar
tom_antal_dagar = tom_bas_dagar + tom_delade_dagar
antal_dagar_kvar = totalt_antal_dagar - (pauline_bas_dagar + pauline_delade_dagar + tom_bas_dagar + tom_delade_dagar + tom_laginkomst_dagar)

print(f"Pauline har tagit ut:   {pauline_antal_dagar:.2f} dagar (+ {pauline_laginkomst_dagar:.2f} låginkomsdagar),    Pauline får ut så här mycket i pengar:  {total_inkomst_pauline:.2f} sek")
print(f"Tom har tagit ut:       {tom_antal_dagar:.2f} dagar (+ {tom_laginkomst_dagar:.2f} låginkomsdagar),   Tom får ut så här mycket i pengar:      {total_inkomst_tom:.2f} sek")
print(f"Skillnaden i pengar om man antar att vi har samma lön är:   {total_inkomst_skillnad:.2f} sek. Antal dagar kvar:     {antal_dagar_kvar:.2f}")


pauline_antal_hoginkomstdagar = []
pauline_inkomst_hoginkomstdagar = 0
pauline_antal_låginkomstdagar = []
pauline_inkomst_låginkomstdagar = 0

tom_antal_hoginkomstdagar = []
tom_inkomst_hoginkomstdagar = 0
tom_antal_låginkomstdagar = []
tom_inkomst_låginkomstdagar = 0

def skapa_listor():
    pauline_manader_ledig = int(input("Hur många månader ska Pauline vara ledig?"))
    pauline_antal_dagar_betalt_per_vecka_hoginkomst = int(input("Hur många dagar höginkomst ska Pauline ha i veckan?"))
    pauline_antal_dagar_betalt_per_vecka_laginkomst = int(input("Hur många dagar låginkomst ska Pauline ha i veckan?"))
    #tom_manader_ledig = input("Hur många månader ska Tom vara ledig?")
    #tom_antal_dagar_betalt_per_vecka_hoginkomst = input("Hur många dagar höginkomst ska Tom ha i veckan?")
    #tom_antal_dagar_betalt_per_vecka_laginkomst = input("Hur många dagar låginkomst ska Tom ha i veckan?")
    
    for _ in range(pauline_manader_ledig):
        pauline_antal_hoginkomstdagar.append(pauline_antal_dagar_betalt_per_vecka_hoginkomst)
        pauline_inkomst_hoginkomstdagar =+ (pauline_antal_dagar_betalt_per_vecka_hoginkomst * bas_sek)
        pauline_antal_låginkomstdagar.append(pauline_antal_dagar_betalt_per_vecka_laginkomst)

    
    #for _ in range(tom_manader_ledig):
     #   tom_antal_hoginkomstdagar.append(tom_antal_dagar_betalt_per_vecka_hoginkomst)
     #   tom_antal_låginkomstdagar.append(tom_antal_dagar_betalt_per_vecka_laginkomst)
    
    print(pauline_antal_hoginkomstdagar)
    print(pauline_inkomst_hoginkomstdagar)
    print(pauline_antal_låginkomstdagar)

skapa_listor()