from matplotlib import pyplot as plt
import numpy as np

bas_sek = 1166
laginkomst_sek = 180
laginkomst_dagar = 90
hoginkomst_dagar = 390
totalt_antal_dagar = 480
veckor_manad = 4.35
pauline_antal_hoginkomstdagar = [0]
pauline_antal_hoginkomstdagar_manad_for_manad = [0]
pauline_hoginkomst_summering = [0]
pauline_antal_laginkomstdagar = [0]
pauline_laginkomst_summering = [0]
pauline_laginkomst_och_hoginkomst_summering = []
tom_antal_hoginkomstdagar = [0]
tom_antal_hoginkomstdagar_manad_for_manad = [0]
tom_hoginkomst_summering = [0]
tom_antal_laginkomstdagar = [0]
tom_laginkomst_summering = [0]
tom_laginkomst_och_hoginkomst_summering = []

def lagg_till_dagar_pauline():
    pauline_manader_ledig = int(input("Hur många månader ska Pauline vara ledig?"))
    pauline_antal_dagar_betalt_per_vecka_hoginkomst = int(input("Hur många dagar höginkomst ska Pauline ha i veckan?"))
    pauline_antal_dagar_betalt_per_vecka_laginkomst = int(input("Hur många dagar låginkomst ska Pauline ha i veckan?"))
  
    for _ in range(pauline_manader_ledig):
        pauline_antal_hoginkomstdagar.append(pauline_antal_dagar_betalt_per_vecka_hoginkomst)
        pauline_antal_hoginkomstdagar_manad_for_manad.append(pauline_antal_hoginkomstdagar_manad_for_manad[-1] + pauline_antal_dagar_betalt_per_vecka_hoginkomst)
        pauline_hoginkomst_summering.append(pauline_hoginkomst_summering[-1] + (pauline_antal_dagar_betalt_per_vecka_hoginkomst * veckor_manad * bas_sek))
        pauline_antal_laginkomstdagar.append(pauline_antal_dagar_betalt_per_vecka_laginkomst)
        pauline_laginkomst_summering.append(pauline_laginkomst_summering[-1] + (pauline_antal_dagar_betalt_per_vecka_laginkomst * veckor_manad * laginkomst_sek))
    

def lagg_till_dagar_tom():
    tom_manader_ledig = int(input("Hur många månader ska Tom vara ledig?"))
    tom_antal_dagar_betalt_per_vecka_hoginkomst = int(input("Hur många dagar höginkomst ska Tom ha i veckan?"))
    tom_antal_dagar_betalt_per_vecka_laginkomst = int(input("Hur många dagar låginkomst ska Tom ha i veckan?"))
    
    for _ in range(tom_manader_ledig):
        tom_antal_hoginkomstdagar.append(tom_antal_dagar_betalt_per_vecka_hoginkomst)
        tom_antal_hoginkomstdagar_manad_for_manad.append(tom_antal_hoginkomstdagar_manad_for_manad[-1] + tom_antal_dagar_betalt_per_vecka_hoginkomst)
        tom_hoginkomst_summering.append(tom_hoginkomst_summering[-1] + (tom_antal_dagar_betalt_per_vecka_hoginkomst * veckor_manad * bas_sek))
        tom_antal_laginkomstdagar.append(tom_antal_dagar_betalt_per_vecka_laginkomst)
        tom_laginkomst_summering.append(tom_laginkomst_summering[-1] + (tom_antal_dagar_betalt_per_vecka_laginkomst * veckor_manad * laginkomst_sek))


def skapa_listor():
    lagg_till_dagar_pauline()
    while True:
        fler_dagar_pauline = str(input("Vill du lägga till fler dagar? (y/n)"))
        if fler_dagar_pauline == ('n' or 'No' or 'no' or 'N' or 'nej'):
            break
        else:
            lagg_till_dagar_pauline()
        
    lagg_till_dagar_tom()
    while True:
        fler_dagar_tom = str(input("Vill du lägga till fler dagar? (y/n)"))
        if fler_dagar_tom == ('n' or 'No' or 'no' or 'N' or 'nej'):
            break
        else:
            lagg_till_dagar_tom()
    
    pauline_laginkomst_och_hoginkomst_summering = np.add(pauline_hoginkomst_summering, pauline_laginkomst_summering)
    tom_laginkomst_och_hoginkomst_summering = np.add(tom_hoginkomst_summering, tom_laginkomst_summering)

    #print('1', pauline_antal_hoginkomstdagar)
    #print('2', pauline_antal_hoginkomstdagar_manad_for_manad)
    #print('3', pauline_hoginkomst_summering)
    #print('4', pauline_antal_laginkomstdagar)
    #print('5', pauline_laginkomst_summering)
    #print('6', pauline_laginkomst_och_hoginkomst_summering)
    #print('7', tom_antal_hoginkomstdagar)
    #print('8', tom_hoginkomst_summering)
    #print('9', tom_antal_laginkomstdagar)
    #print('10', tom_laginkomst_summering)
    #print('11', tom_laginkomst_och_hoginkomst_summering)

    manader_pauline = []
    for i in range(len(pauline_laginkomst_och_hoginkomst_summering)):
        manader_pauline.append(i)
    
    manader_tom = []
    for i in range(len(tom_laginkomst_och_hoginkomst_summering)):
        manader_tom.append(i)
    
        
    plt.plot(manader_pauline, pauline_laginkomst_och_hoginkomst_summering, label='Pauline')
    plt.plot(manader_tom, tom_laginkomst_och_hoginkomst_summering, label='Tom')
    plt.legend()
    plt.show()

    pauline_antal_hoginkomstdagar_totalt = sum(pauline_antal_hoginkomstdagar) * 4.35
    pauline_antal_laginkomstdagar_totalt = sum(pauline_antal_laginkomstdagar) * 4.35
    tom_antal_hoginkomstdagar_totalt = sum(tom_antal_hoginkomstdagar) * 4.35
    tom_antal_laginkomstdagar_totalt = sum(tom_antal_laginkomstdagar) * 4.35
    hoginkomst_dagar_kvar = hoginkomst_dagar - pauline_antal_hoginkomstdagar_totalt - tom_antal_hoginkomstdagar_totalt
    laginkomst_dagar_kvar = laginkomst_dagar - pauline_antal_laginkomstdagar_totalt - tom_antal_laginkomstdagar_totalt

    plt.bar('hoginkomstdagar Pauline', pauline_antal_hoginkomstdagar_totalt)
    plt.bar('laginkomstdagar Pauline', pauline_antal_laginkomstdagar_totalt)

    plt.bar('hoginkomstdagar Tom', tom_antal_hoginkomstdagar_totalt)
    plt.bar('laginkomstdagar Tom', tom_antal_laginkomstdagar_totalt)

    plt.bar('laginkomst dagar kvar', laginkomst_dagar_kvar)
    plt.bar('hoginkomst dagar kvar', hoginkomst_dagar_kvar)
    plt.show()

while True:
    skapa_listor()
    quit()
