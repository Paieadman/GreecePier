#pragma once

#include <memory>
#include <map>

#include "Pier.h"
#include "Specification.h"
#include "IShip.h"

class PierManager {
public:
    PierManager();
    ~PierManager() = default;
    void sendShip(std::unique_ptr<IShip>&);

private:
    // std::pair<ContentType, std::unique_ptr<Pier>> mPiercesMap[];
    std::map<ContentType, const std::unique_ptr<Pier>&> mPiercesMap {
        {ContentType::TYPE_ONE, std::make_unique<Pier>(ContentType::TYPE_ONE)},
        {ContentType::TYPE_TWO, std::make_unique<Pier>(ContentType::TYPE_TWO)},
    };
};