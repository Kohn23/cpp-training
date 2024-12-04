#include "ExecutorImpl.hpp" 
#include <memory>
#include <unordered_map>
#include <algorithm>
namespace adas
{
    // 这里实现了抽象类的构造函数，返回的是一个子类
    Executor* Executor::NewExecutor(const Pose& pose) noexcept
    {
        return new (std::nothrow) ExecutorImpl(pose);
    }
    ExecutorImpl::ExecutorImpl(const Pose& pose) noexcept : poseHandler(pose){}

    void ExecutorImpl::Execute(const std::string& commands) noexcept
    {
        std::unordered_map<char, std::unique_ptr<ICommand>> cmderMap;
        cmderMap.emplace('M', std::make_unique<MoveCommand>());
        cmderMap.emplace('L', std::make_unique<TurnLeftCommand>());
        cmderMap.emplace('R', std::make_unique<TurnRightCommand>());
        cmderMap.emplace('F', std::make_unique<FastCommand>());
        
        for (const auto cmd : commands) {
            const auto it = cmderMap.find(cmd);
            if (it != cmderMap.end())
            {
                it->second->DoOperate(poseHandler);
            }
        }
    }

    Pose ExecutorImpl::Query() const noexcept
    {
        return poseHandler.Query();
    }

}