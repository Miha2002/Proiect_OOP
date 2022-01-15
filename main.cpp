//Aplicatie Muzeu de arta

#include "opera_arta.h"
#include "colectie.h"
#include "muzeu.h"
#include "pictura.h"
#include "sculptura.h"
#include "erori.h"

void functie1(){
    muzeu M("Muzeul de Arta Universala", 20);
    M.setBilet(30);
    colectie C1{"Trecutul alb-negru", 101};
    colectie C2{"Arta contemporana", 102};
    colectie C3{"Adevarul despre arta", 103};

    pictura p1{"Camp cu maci", "Claude Monet", "impresionism", 1870, 1, "ulei", 50, 65};
    pictura p2{"Floarea soarelui", "Vincent Van Gogh", "post-impresionism", 1888, 1, "ulei", 92, 73};
    pictura p3{"Flumequine", "Damien Hirst", "contemporan", 2007, 0, "acrilic", 140, 108};

    sculptura s1{"Pieta", "Michelangelo Buonarroti", "renascentism", 1499, 0, "marmura", 3040, 1.95};
    sculptura s2{"Cainele balon", "Jeff Koons", "contemporan", 1993, 1, "otel", 1000, 3.10};

    C1.adauga(p1);
    C1.adauga(p2);
    C1.adauga(s1);
    C2.adauga(p3);
    C2.adauga(s2);

    M.adauga(C1);
    M.adauga(C2);
    M.adauga(C3);

//    M.program();
//    M.cost_bilete();
//    p1.descriere();
    M.colectie_random();
}

int main () {
    try {
        functie1();
    }
    catch (eroare_opera &error) {
        std::cout << error.what() << "\n";
    }

    return 0;
}