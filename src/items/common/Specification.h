#pragma once

#include <stdint.h>
#include <string>

enum CapacityType {
    SMALL = 0,
    BIG = 1,
};

enum ContentType {
    TYPE_ONE,
    TYPE_TWO,
};

enum State {
    INIT,
    RUN,
    STOP,
};

CapacityType getRandomCapacity();
ContentType getRandomContent();

static std::pair<CapacityType, uint16_t> capacityValue[] = {
    {CapacityType::BIG, 100},
    {CapacityType::SMALL, 50},
};

static std::pair<ContentType, std::string> contentValue[] = {
    {ContentType::TYPE_ONE, "type_one"},
    {ContentType::TYPE_TWO, "type_two"},
};