#include "ExecutorImpl.hpp"

#include <algorithm>
#include <memory>
#include <unordered_map>
namespace adas
{
// 这里实现了抽象类的构造函数，返回的是一个子类

Executor* Executor::NewExecutor(const Pose& pose, const char factory) noexcept
{
    return new (std::nothrow) ExecutorImpl(pose, factory);
}

ExecutorImpl::ExecutorImpl(const Pose& pose, const char factory) noexcept
    : poseHandler(pose), cmderFactory(FactorySubject().GetFactory(factory))
{
}

void ExecutorImpl::Execute(const std::string& commands) noexcept
{
    const auto cmders = cmderFactory.GetCmders(commands);
    std::for_each(cmders.begin(), cmders.end(), [this](const Cmder& cmder) noexcept { cmder(poseHandler).DoOperate(poseHandler); });
}

Pose ExecutorImpl::Query() const noexcept
{
    return poseHandler.Query();
}

}  // namespace adas