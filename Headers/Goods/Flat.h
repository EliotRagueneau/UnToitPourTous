//
// Created by eliot on 25/02/19.
//

#ifndef UNTOITPOURTOUS_FLATS_H
#define UNTOITPOURTOUS_FLATS_H


#include "Residential.h"

class Flat : public Residential {
private:
    int floor;
    bool cave;
    bool balcony;
    int nbBuildingFlats;
public:
    explicit Flat(Seller &sellerRef);

    Flat(double price, const std::string &address, double area, Seller &sellerRef, int nbRooms, bool garage, int floor,
         bool cave, bool balcony, int nbBuildingFlats);

    virtual void show() const;

    virtual void save(std::ofstream& file) const;

};


#endif //UNTOITPOURTOUS_FLATS_H