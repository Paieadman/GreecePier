#include <iostream>
#include <memory>

#include "Specification.h"
#include "Content.h"

Content::Content(ContentType content): m_content(content) {
    //m_content = ContentType(content);
    //std::cout << "Content created" << std::endl;
}

Content::~Content() {
    //std::cout << "Content destroied" << std::endl;
}

ContentType Content::getContent() {
    return m_content;
}