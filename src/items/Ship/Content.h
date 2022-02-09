#pragma once

#include <memory>

#include "IContent.h"
#include "Specification.h"

class Content : public IContent {
private:
    ContentType m_content;
public:
    Content(ContentType);
    ~Content();
    virtual ContentType getContent();
};