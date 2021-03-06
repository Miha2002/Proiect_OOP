//
//

#ifndef PROIECT_POO_SCULPTURA_H
#define PROIECT_POO_SCULPTURA_H

#include <iostream>
#include <string>
#include "opera_arta.h"

class sculptura : public opera_arta {
    std::string material; //ex. metal, piatra, marmura, lut
    int greutate; //greutatea in kg
    float inaltime; //inaltimea in metri

public:
    sculptura(const std::string &titlu, const std::string &artist, const std::string &stil, int anPub, bool afisare,
              const std::string &material, int greutate, float inaltime);

    friend std::ostream &operator<<(std::ostream &os, const sculptura &sculptura);

    const std::string &getTitlu() const;

    std::shared_ptr<opera_arta> clone() const override;

    void descriere() override;

    void suvenir() override;
};

#endif //PROIECT_POO_SCULPTURA_H
