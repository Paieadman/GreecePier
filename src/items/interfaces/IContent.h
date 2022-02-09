#pragma once

#include <memory>

#include "Specification.h"

class IContent {
public:
    virtual ContentType getContent() = 0;
    virtual ~IContent() = default;
};