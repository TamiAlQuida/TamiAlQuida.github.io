
##Tesla 

pauline_mil_om_året = 3036+1500

inköpspris_tesla = 618000
service_tesla = 4500 * 5
försäkring_tesla = 1000 * 12 * 10
elkostnad_per_mil = 2.9 #3.7
elkostnad_per_10_år = pauline_mil_om_året * elkostnad_per_mil * 10
total_kostnad_elbil = elkostnad_per_10_år +inköpspris_tesla + service_tesla + försäkring_tesla

inköp_bensinbil = 120000 + 120000
service = 5000 * 10
försäkring_bensin = 353 * 12 * 10
bensinkostnad_per_mil = 21
bensinkostnad_per_10_år = pauline_mil_om_året * bensinkostnad_per_mil * 10
total_kostnad_bensinbil = bensinkostnad_per_10_år + inköp_bensinbil + service + försäkring_bensin


print(total_kostnad_elbil, "\n")

print(total_kostnad_bensinbil)