#pragma once

template<class T>
TQueueImpl<T>::TQueueImpl(std::function<void(std::unique_ptr<T>&)> func):
    TQueue<T>::TQueue(),
    m_func(func)
{}

template<class T>
void TQueueImpl<T>::process() {
    this->mQueueMutex.lock();
    if (this->mQueue->empty()) {
        this->mQueueMutex.unlock();
        return;
    }
    std::unique_ptr<T> qItem = std::move(this->mQueue->front());
    this->mQueueMutex.unlock();
    m_func(qItem);

    this->mQueueMutex.lock();
    if (!this->mQueue->empty()) {
        this->mQueue->pop();
    }
    this->mQueueMutex.unlock();
}