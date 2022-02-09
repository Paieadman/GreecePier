#include <thread>
#include <atomic>
#include <functional>
#include <stdint.h>

#include "IManager.h"


class Manager : public IManager {
private:
    std::thread m_thread;
    std::atomic<bool> isExit;
    //std::chrono::milliseconds m_updateTime;
    int64_t m_updateTime;
    const std::function<void()>& m_func;

    void updater();
public:
    explicit Manager(const std::function<void()>&);
    virtual ~Manager();
    void sayHello() override;
};