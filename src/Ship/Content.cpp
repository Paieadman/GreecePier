#include <iostream>
#include <memory>

#include "Specification.h"
#include "Content.h"

Content::Content(ContentType content) {
    m_content = std::make_shared<ContentType>(content);
    std::cout << "Content created" << std::endl;
}

Content::~Content() {
    std::cout << "Content destroied" << std::endl;
}

std::shared_ptr<ContentType> Content::getContent() {
    return m_content;
}