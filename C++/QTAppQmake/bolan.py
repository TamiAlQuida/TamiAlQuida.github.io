# This Python file uses the following encoding: utf-8


huskostnad = 3000000 #input("vad kostar huset?")
ranta = 0.04
ränta_per_månad = ranta / 12
antal_manader_per_ar = 12
antal_ar = 20
antal_betalningstillfällen = antal_manader_per_ar * antal_ar

återstående_skuld = huskostnad

for i in range(antal_betalningstillfällen):
    kostnad_ranta = återstående_skuld * ränta_per_månad
    kostnad_lån = huskostnad / antal_betalningstillfällen
    att_betala = kostnad_ranta + kostnad_lån
    återstående_skuld -= kostnad_lån
    print(kostnad_ranta)
    print(kostnad_lån)
    print(att_betala)
    print(återstående_skuld, "\n")
    

#kontantinsats = int(huskostnad)*0.15
#print(kontantinsats)

quit()
