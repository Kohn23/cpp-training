#include "ActionGroup.hpp"
#include <vector>
#include <algorithm>

namespace adas
{
class ForwardAction final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        poseHandler.Forward();
    }
};

class BackwardAction final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        poseHandler.Backward();
    }
};

class TurnLeftAction final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        poseHandler.TurnLeft();
    }
};

class TurnRightAction final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        poseHandler.TurnRight();
    }
};

class BackwardTurnLeftAction final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        poseHandler.TurnRight();
    }
};

class BackwardTurnRightAction final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        poseHandler.TurnLeft();
    }
};

class BeFastAction final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        poseHandler.Fast();
    }
};

class BeBackwardAction final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        poseHandler.Back();
    }
};

ActionGroup::ActionGroup(const std::list<ActionType>& actions) noexcept : actions(actions)
{
}
void ActionGroup::PushAction(const ActionType ActionType) noexcept
{
    actions.push_back(ActionType);
}

void ActionGroup::DoOperate(PoseHandler& poseHandler) const noexcept
{
    static std::vector<Atom> actionVec = {
        ForwardAction(), BackwardAction(), TurnLeftAction(), BackwardTurnLeftAction(), 
        TurnRightAction(), BackwardTurnRightAction(), BeFastAction(), BeBackwardAction() };
    
    std::for_each(actions.begin(), actions.end(), [&poseHandler](const ActionType actionType) mutable noexcept {actionVec[static_cast<uint16_t>(actionType)](poseHandler);});
}
}