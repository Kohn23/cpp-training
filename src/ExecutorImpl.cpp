#include "ExecutorImpl.hpp"

#include <algorithm>
#include <memory>
#include <unordered_map>
namespace adas
{
// 这里实现了抽象类的构造函数，返回的是一个子类
Executor* Executor::NewExecutor(const Pose& pose) noexcept
{
    return new (std::nothrow) ExecutorImpl(pose);
}
ExecutorImpl::ExecutorImpl(const Pose& pose) noexcept : poseHandler(pose)
{
}

void ExecutorImpl::Execute(const std::string& commands) noexcept
{
    const std::unordered_map<char, std::function<void(PoseHandler & poseHandler)>> cmderMap
    {
        {'M', MoveCommand()},
        {'L', TurnLeftCommand()},
        {'R', TurnRightCommand()},
        {'F', FastCommand()},
    };
    
    for (const auto cmd : commands)
    {
        const auto it = cmderMap.find(cmd);
        if (it != cmderMap.end())
        {
            it->second(poseHandler);
        }
    }
}

Pose ExecutorImpl::Query() const noexcept
{
    return poseHandler.Query();
}

}  // namespace adas