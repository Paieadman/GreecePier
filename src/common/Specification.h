#pragma once

enum CapacityType {
    SMALL = 0,
    BIG = 1,
};

enum ContentType {
    TYPE_ONE,
    TYPE_TWO,
};

CapacityType getRandomCapacity();