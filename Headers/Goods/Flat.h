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
    Flat(double price, const std::string &address, double area, const std::shared_ptr<Seller>& seller, bool sold,
         int nbRooms, bool garage, int floor, bool cave, bool balcony, int nbBuildingFlats);

    explicit Flat(const std::shared_ptr<Seller>& seller);

    virtual void show() const;

    virtual void save(std::ofstream &file) const;

    virtual std::string getType() const;
};


#endif //UNTOITPOURTOUS_FLATS_H
