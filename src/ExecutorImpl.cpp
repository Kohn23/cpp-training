#include "ExecutorImpl.hpp" 
namespace adas
{
    Executor* Executor::NewExecutor(const Pose& pose) noexcept
    {
        return new (std::nothrow) ExecutorImpl(pose);
    }
    ExecutorImpl::ExecutorImpl(const Pose& pose) noexcept
    {
    }
    void ExecutorImpl::Execute(const std::string& commands) noexcept
    {
    }
    Pose ExecutorImpl::Query() const noexcept
    {
        return pose;
    }
}