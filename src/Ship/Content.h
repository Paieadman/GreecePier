#pragma once

#include <memory>

#include "IContent.h"
#include "Specification.h"

class Content : public IContent {
private:
    std::shared_ptr<ContentType> m_content;
public:
    Content(ContentType);
    ~Content();
    virtual std::shared_ptr<ContentType> getContent();
};