# This Python file uses the following encoding: utf-8

huskostnad = 3500000 #input("vad kostar huset?")
ranta = 0.04
antal_ar = 20
    

def bolan(huskostnad, ranta, antal_ar):
    kvar_på_lån = huskostnad * 0.85
    kvar_på_lån_2 = kvar_på_lån
    kontantinsats = huskostnad * 0.15
    ränta_per_månad = ranta / 12
    antal_manader_per_ar = 12
    antal_betalningstillfällen = antal_manader_per_ar * antal_ar

    totalt_betalat = 0
    år = 0
    print("kontaninsats  : ", kontantinsats)
    print("lån           : ", kvar_på_lån)

    for i in range(antal_betalningstillfällen):
        #år = 12 % i
        #print(år)

        kostnad_ranta = kvar_på_lån * ränta_per_månad
        kostnad_lån = kvar_på_lån_2 / antal_betalningstillfällen
        att_betala = kostnad_ranta + kostnad_lån
        kvar_på_lån -= kostnad_lån
        totalt_betalat += att_betala
        print("kostnad_ranta : ", kostnad_ranta)
        print("kostnad_lån   : ", kostnad_lån)
        print("att_betala    : ", att_betala)
        print("kvar_på_lån   : ", kvar_på_lån)
        print("totalt_betalat: ", totalt_betalat, "\n")

if __name__ == "__main__":
    bolan(huskostnad, ranta, antal_ar)
    quit()
