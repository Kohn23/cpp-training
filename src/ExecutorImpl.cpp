#include "ExecutorImpl.hpp" 
#include <memory>
namespace adas
{
    // 这里实现了抽象类的构造函数，返回的是一个子类
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
        for (const auto cmd : commands){
            switch (cmd)
            {
            case 'M':{
                std::unique_ptr<MoveCommand> cmder = std::make_unique<MoveCommand>();
                cmder->DoOperate(*this);
                break;
            }  
            case 'L':{
                std::unique_ptr<TurnLeftCommand> cmder = std::make_unique<TurnLeftCommand>();
                cmder->DoOperate(*this);
                break;
            }
            case 'R':{
                std::unique_ptr<TurnRightCommand> cmder = std::make_unique<TurnRightCommand>();
                cmder->DoOperate(*this);
                break;
            }
            default:
                break;
            }
        }

    }
    Pose ExecutorImpl::Query() const noexcept
    {
        return pose;
    }
    void ExecutorImpl::Move() noexcept
    {
        if (pose.heading == 'E') {
            ++pose.x;
        } else if (pose.heading == 'W') {
            --pose.x;
        } else if (pose.heading == 'N') {
            ++pose.y;
        } else if (pose.heading == 'S') {
            --pose.y;
        }
    }
    void ExecutorImpl::TurnLeft() noexcept
    {
        switch (pose.heading)
                {
                case 'N':
                    pose.heading = 'W';
                    break;
                case 'S':
                    pose.heading = 'E';
                    break;
                case 'E':
                    pose.heading = 'N';
                    break;
                case 'W':
                    pose.heading = 'S';
                    break;
                default:
                    break;
                }
    }

    void ExecutorImpl::TurnRight() noexcept
    {
        switch (pose.heading)
                {
                case 'N':
                    pose.heading = 'E';
                    break;
                case 'S':
                    pose.heading = 'W';
                    break;
                case 'E':
                    pose.heading = 'S';
                    break;
                case 'W':
                    pose.heading = 'N';
                    break;
                default:
                    break;
                }
    }
}