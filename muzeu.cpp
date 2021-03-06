//
//
#include "muzeu.h"

template <typename A, typename B>
std::ostream &operator<<(std::ostream &os, const muzeu<A,B> &muzeu) {
    os << "\nnume: " << muzeu.nume << "\nbilet: " << muzeu.bilet
    << "\nbuget:" << muzeu.buget << " RON" << "\ncolectii:";
    for(const auto &colectie : muzeu.colectii)
        os << "\n" << colectie;
    return os;
}

template <typename A, typename B>
muzeu<A,B>::muzeu(const std::string &nume, A bilet) : nume(nume), bilet(bilet) {

    this->buget = (rand() % 50 + 50) * 100;
}

template <typename A, typename B>
void muzeu<A,B>::setBilet(A bilet) {
    muzeu::bilet = bilet;
}

template <typename A, typename B>
void muzeu<A,B>::adauga(const colectie &colectie) {
    colectii.push_back(colectie);
}

enum zile {
    Luni, Marti, Miercuri, Joi, Vineri, Sambata, Duminica
    };

template <typename A, typename B>
void muzeu<A,B>::program() {
    int x;
    std::cout<< "In ce zi doriti sa vizitati?\nPrecizati ziua (2-7)";
    std::cin>>x;
    if(x==1)
        throw eroare_luni();
    else
        if (x<1 || x>7)
            throw eroare_zi();
        else
            std::cout<< "Muzeul este deschis de la ora 08:00 pana la 22:00!\n";
}

template <typename A, typename B>
void muzeu<A,B>::cost_bilete() const {
    float cost;
    int x,y,g;
    std::cout<< "Cati oameni vor sa viziteze muzeul?\n";
    std::cin>> x;
    std::cout<< "Cati dintre acestia sunt copii?\n";
    std::cin>> y;
    std::cout<< "Doriti ghid?\nNU-0\nDA-1\n";
    std::cin>> g;
    if (x<10)
        cost=bilet*(x-y) + bilet*0.5*y;
    else {
        cost=bilet*(x-y) + bilet*0.5*y;
        cost= cost * 0.90;
    }
    if (g==1)
        cost = cost + 1000;
    std::cout<< "Pretul total al biletelor este: " << cost <<"RON\n\n";
}

template <typename A, typename B>
void muzeu<A,B>::colectie_random() {
    int x = rand() % colectii.size();
    std::cout<< x << "\n" << colectii[x]<<"\n";
}

template <typename A, typename B>
void muzeu<A,B>::proces_licitatie(int cost_initial) {
    int cost_lici;                  //pretul dupa ce creste la licitatie
    bool ultima_oferta = false;     //=true reprezinta ca ultimul pret a fost oferit de muzeu
    bool sfarsit = false;           //=true, se termina licitatia
    int count=0;                    //numara ofertele

    std::cout<< "Opera costa " << cost_initial << " RON.\n";
    cost_lici = cost_initial;

    if (cost_initial < buget * 0.80) {
        while (cost_lici < buget || !sfarsit) {
            if (rand() % 3  == 0 && ultima_oferta) {
                cost_lici = cost_lici + (rand() % 70 + 30) * 10;
                    std::cout << "Altcineva ofera " << cost_lici << " RON.\n";
                    ultima_oferta = false;
                    count++;
            }
            else if (rand() % 3  == 1 && !ultima_oferta) {
                cost_lici = cost_lici + (rand() % 70 + 30) * 10;
                std::cout << "Muzeul ofera " << cost_lici << " RON.\n";
                ultima_oferta = true;
                count++;
            }
                else {
                    if (ultima_oferta && count) {
                        std::cout << "Muzeu castiga licitatia!\n\n";
                        buget = buget - cost_lici;
                        sfarsit = true;
                        break;}
                    if (!ultima_oferta && count) {
                        std::cout << "Muzeu pierde licitatia!\n\n";
                        sfarsit = true;
                        break;}
                }
            }
    }
    else
        std::cout<< "Muzeul nu are destui bani!" << "\n\n";
}

template <typename A, typename B>
void muzeu<A,B>::licitatii() {
    std::cout << "\n\nINCEPUTUL LICITATIILOR\n"
    << "Bugetul initial este: " << buget << " RON\n\n";

    static int count=0;
    while (buget > 2000 && count < 12) {
        proces_licitatie((rand() % 70 + 30) * 50);
        count++;
    }
    std::cout << "Muzeul nu vrea/poate sa cumpere alte opere de arta.\n\n";

    std::cout << "Bugetul final este: " << buget << " RON\n"
    <<"SFARSITUL LICITATIILOR\n\n";
}

template <typename A, typename B>
void muzeu<A,B>::buget_plus() {
    buget = buget + (rand() % 50 + 50) * 100;
    std::cout << "S-au adaugat bani la buget.\nBugetul este: " << buget << " RON\n";
}