#pragma once
#include <functional>

#include "PoseHandler.hpp"
#include "ActionGroup.hpp"

namespace adas
{
class MoveCommand final
{
public:
    ActionGroup operator()(PoseHandler& poseHandler) const noexcept
    {
        ActionGroup actionGroup;
        const auto moveAction = poseHandler.IsBackward() ? ActionType::BACKWARD_1_STEP_ACTION : ActionType::FORWARD_1_STEP_ACTION;
        if (poseHandler.IsFast())
        {
            actionGroup.PushAction(moveAction);
        }
        actionGroup.PushAction(moveAction);
        return actionGroup;
    }
};

class TurnLeftCommand final
{
public:
    ActionGroup operator()(PoseHandler& poseHandler) const noexcept
    {
        ActionGroup actionGroup;
        const auto turnLeftAction = poseHandler.IsBackward()? ActionType::BACKWARD_TURNLEFT_ACTION : ActionType::TURNLEFT_ACTION;
        const auto moveAction = poseHandler.IsBackward()? ActionType::BACKWARD_1_STEP_ACTION : ActionType::FORWARD_1_STEP_ACTION;
        if (poseHandler.IsFast())
        {
            actionGroup.PushAction(moveAction);
        }
        actionGroup.PushAction(turnLeftAction);
        return actionGroup;
    }
};

class TurnRightCommand final
{
public:
    ActionGroup operator()(PoseHandler& poseHandler) const noexcept
    {
        ActionGroup actionGroup;
        const auto turnRightAction = poseHandler.IsBackward()? ActionType::BACKWARD_TURNRIGHT_ACTION : ActionType::TURNRIGHT_ACTION;
        const auto moveAction = poseHandler.IsBackward()? ActionType::BACKWARD_1_STEP_ACTION : ActionType::FORWARD_1_STEP_ACTION;
        if (poseHandler.IsFast())
        {
            actionGroup.PushAction(moveAction);
        }
        actionGroup.PushAction(turnRightAction);
        return actionGroup;
    }
};

class FastCommand final
{
public:
    ActionGroup operator()(PoseHandler& poseHandler) const noexcept
    {
        ActionGroup actionGroup;
        actionGroup.PushAction(ActionType::BE_FAST_ACTION);
        return actionGroup;
    }
};

class BackCommand final
{
public:
    ActionGroup operator()(PoseHandler& poseHandler) const noexcept
    {
        ActionGroup actionGroup;
        actionGroup.PushAction(ActionType::BE_BACKWARD_ACTION);
        return actionGroup;
    }
};

}  // namespace adas