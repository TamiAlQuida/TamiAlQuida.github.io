# This Python file uses the following encoding: utf-8
import matplotlib.pyplot as plt

huskostnad = 3500000 #input("vad kostar huset?")
ranta_del_1 = 0.0287
ranta_del_2 = 0.031
ranta_del_3 = 0.0341
amortering = 8000

att_betala_lista = []
tid = []


def ploting(att_betala_lista, tid):
    # Create a figure and axis
    fig, ax = plt.subplots()
    # Plot the data
    ax.plot(tid, att_betala_lista, marker='o', linestyle='-', color='b')
    # Set the x-axis ticks to show months
    ax.set_xticks(tid)
    ax.set_xticklabels    

    # Add labels and title
    plt.xlabel('Months')
    plt.ylabel('Money')
    plt.title('Scatter Plot Example')
    plt.show()
    

def bolan(huskostnad, ranta_del_1, ranta_del_2, ranta_del_3, amortering):
    kvar_på_lån_totalt = huskostnad * 0.85
    kvar_på_lån_del_1 = kvar_på_lån_totalt / 3
    kvar_på_lån_del_2 = kvar_på_lån_totalt / 3
    kvar_på_lån_del_3 = kvar_på_lån_totalt / 3

    kontantinsats = huskostnad * 0.15
    ränta_per_månad_del_1 = ranta_del_1 / 12
    ränta_per_månad_del_2 = ranta_del_2 / 12
    ränta_per_månad_del_3 = ranta_del_3 / 12
    
    print("\n", "kontaninsats  : ", kontantinsats)
    print("lån           : ", kvar_på_lån_totalt, "\n")
    
    totalt_betalat = 0
    månad = 0
    ar = 0
    

    while kvar_på_lån_totalt > 0:
        if månad < 12:
            månad += 1
        else:
            månad = 1
            ar += 1

        kostnad_ranta_del_1 = kvar_på_lån_del_1 * ränta_per_månad_del_1
        kostnad_ranta_del_2 = kvar_på_lån_del_2 * ränta_per_månad_del_2
        kostnad_ranta_del_3 = kvar_på_lån_del_3 * ränta_per_månad_del_3
        kostnad_ranta = kostnad_ranta_del_1 + kostnad_ranta_del_2 + kostnad_ranta_del_3

        if kvar_på_lån_del_1 > 0:
            amortering_del_1 = amortering * 3 / 3
            amortering_del_2 = amortering * 0 / 3
            amortering_del_3 = amortering * 0 / 3
        if kvar_på_lån_del_1 <= 0 and kvar_på_lån_del_2 > 0:
            amortering_del_1 = amortering * 0 / 3
            amortering_del_2 = amortering * 3 / 3
            amortering_del_3 = amortering * 0 / 3
            kvar_på_lån_del_1 = 0
        if kvar_på_lån_del_1 <= 0 and kvar_på_lån_del_2 <= 0 and kvar_på_lån_del_3 > 0:
            amortering_del_1 = amortering * 0 / 3
            amortering_del_2 = amortering * 0 / 3
            amortering_del_3 = amortering * 3 / 3
            kvar_på_lån_del_2 = 0

        amortering_totalt = amortering_del_1 + amortering_del_2 + amortering_del_3

        att_betala = kostnad_ranta + amortering_totalt
        att_betala_lista.append(att_betala)

        kvar_på_lån_totalt -= amortering
        kvar_på_lån_del_1 -= amortering_del_1
        kvar_på_lån_del_2 -= amortering_del_2
        kvar_på_lån_del_3 -= amortering_del_3
        tid.append(ar * 12 + månad)

        totalt_betalat += att_betala

        print("år: ", ar)
        print("månad: ", månad, "\n")

        print("kostnad_ranta : ", kostnad_ranta)
        print("kostnad_ranta del 1: ", kostnad_ranta_del_1)
        print("kostnad_ranta del 2: ", kostnad_ranta_del_2)
        print("kostnad_ranta del 3: ", kostnad_ranta_del_3, "\n")

        print("amortering   : ", amortering_totalt)
        print("amortering del 1: ", amortering_del_1)
        print("amortering del 2: ", amortering_del_2)
        print("amortering del 3: ", amortering_del_3, "\n")
        
        print("kvar_på_lån   : ", kvar_på_lån_totalt)
        print("lån del 1     : ", kvar_på_lån_del_1)
        print("lån del 2     : ", kvar_på_lån_del_2)
        print("lån del 3     : ", kvar_på_lån_del_3, "\n")

        print("att_betala    : ", att_betala)
        print("totalt_betalat: ", totalt_betalat, "\n")

        print("\n","###############################", "\n")


if __name__ == "__main__":
    bolan(huskostnad, ranta_del_1, ranta_del_2, ranta_del_3, amortering)
    #ploting(att_betala_lista, tid)
    quit()
