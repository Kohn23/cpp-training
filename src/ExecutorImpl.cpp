#include "ExecutorImpl.hpp" 
namespace adas
{
    // 这里重新定义了抽象类的构造函数，并且用自己的构造函数代替
    Executor* Executor::NewExecutor(const Pose& pose) noexcept
    {
        return new (std::nothrow) ExecutorImpl(pose);
    }
    ExecutorImpl::ExecutorImpl(const Pose& pose) noexcept
    {
        this->pose = pose;
    }
    void ExecutorImpl::Execute(const std::string& commands) noexcept
    {
    }
    Pose ExecutorImpl::Query() const noexcept
    {
        return pose;
    }
}