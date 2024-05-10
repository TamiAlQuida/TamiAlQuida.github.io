#include <iostream>
#include <fstream>
using namespace std;

//variables
float kvar_pa_lan;
float kvar_pa_lan_2;
float kontantinsats;
float ranta_per_manad;
int antal_manader_per_ar;
int antal_betalningstillfallen;
float totalt_betalat;
float kostnad_ranta;
float kostnad_lan;
float att_betala;


//function
void bolan (int huskostnad, double ranta, int antal_ar) {
    kvar_pa_lan = huskostnad * 0.85;
    kvar_pa_lan_2 = kvar_pa_lan;
    kontantinsats = huskostnad * 0.15;
    ranta_per_manad = ranta / 12;
    antal_manader_per_ar = 12;
    antal_betalningstillfallen = antal_manader_per_ar * antal_ar;
    totalt_betalat = kontantinsats;

    ofstream out("output.txt");
    
    cout << "##################################################################" << "\n\n";
    out << "############################################################" << "\n\n";
    std::cout << std::fixed;
    cout << "kontaninsats  : " << kontantinsats << "\n";
    out << "kontaninsats  : " << kontantinsats << "\n";

    cout << "lån           : " << kvar_pa_lan << "\n\n";
    out << "lån           : " << kvar_pa_lan << "\n\n";

    for (int i = 0; i < antal_betalningstillfallen; i++)
    {
        int year = i / 12;
        int month = i % 12 + 1;
        kostnad_ranta = kvar_pa_lan * ranta_per_manad;
        kostnad_lan = kvar_pa_lan_2 / antal_betalningstillfallen;
        att_betala = kostnad_ranta + kostnad_lan;
        kvar_pa_lan -= kostnad_lan;
        totalt_betalat += att_betala;

        cout << "year: " << year << " month: " << month << "\n";
        out << "year: " << year << " month: " << month << "\n";
        cout << "kostnad_ranta : " << kostnad_ranta << "\n";
        out << "kostnad_ranta : " << kostnad_ranta << "\n";
        cout << "kostnad_lån   : " << kostnad_lan << "\n";
        out << "kostnad_lån   : " << kostnad_lan << "\n";
        cout << "att_betala    : " << att_betala << "\n";
        out << "att_betala    : " << att_betala << "\n";
        cout << "kvar_på_lån   : " << kvar_pa_lan << "\n";
        out <<"kvar_på_lån   : " << kvar_pa_lan << "\n";
        cout << "totalt_betalat: " << totalt_betalat << "\n\n";
        out << "totalt_betalat: " << totalt_betalat << "\n\n";
    }
    out.close();
};
