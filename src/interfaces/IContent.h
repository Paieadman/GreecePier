#pragma once

#include "Specification.h"

class IContent {
public:
    virtual std::shared_ptr<ContentType> getContent() = 0;
};