#pragma once

#include <memory>
#include <functional>

#include "TQueue.h"

template<class T>
class TQueueImpl: public TQueue<T> {
public:
    TQueueImpl(std::function<void(std::unique_ptr<T>&)>);
    virtual ~TQueueImpl() = default;

private:
    void process() override;

    //unsupported
    TQueueImpl(TQueueImpl&& obj) = delete;
    TQueueImpl(const TQueueImpl & obj) = delete;
    TQueueImpl& operator=(const TQueueImpl& obj) = delete;
    TQueueImpl& operator=(TQueueImpl&& obj) = delete;

    std::function<void(std::unique_ptr<T>&)> m_func;
};

#include "TQueueImpl.tpp"