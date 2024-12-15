#include "Command.hpp"

namespace adas
{
namespace sportsCar
{
ActionGroup MoveCommand::operator()(PoseHandler& poseHandler) const noexcept
{
    ActionGroup actionGroup;
    const auto moveAction =
        poseHandler.IsBackward() ? ActionType::BACKWARD_1_STEP_ACTION : ActionType::FORWARD_1_STEP_ACTION;
    // 组合原子指令
    if (poseHandler.IsFast()) {
        actionGroup.PushAction(moveAction);
        actionGroup.PushAction(moveAction);
    }
    actionGroup.PushAction(moveAction);
    actionGroup.PushAction(moveAction);
    return actionGroup;
}

ActionGroup TurnLeftCommand::operator()(PoseHandler& poseHandler) const noexcept
{
    ActionGroup actionGroup;
    const auto turnLeftAction =
        poseHandler.IsBackward() ? ActionType::BACKWARD_TURNLEFT_ACTION : ActionType::TURNLEFT_ACTION;
    const auto moveAction =
        poseHandler.IsBackward() ? ActionType::BACKWARD_1_STEP_ACTION : ActionType::FORWARD_1_STEP_ACTION;
    // 组合原子指令
    if (poseHandler.IsFast()) {
        actionGroup.PushAction(moveAction);
    }
    actionGroup.PushAction(turnLeftAction);
    actionGroup.PushAction(moveAction);
    return actionGroup;
}

ActionGroup TurnRightCommand::operator()(PoseHandler& poseHandler) const noexcept
{
    ActionGroup actionGroup;
    const auto turnRightAction =
        poseHandler.IsBackward() ? ActionType::BACKWARD_TURNRIGHT_ACTION : ActionType::TURNRIGHT_ACTION;
    const auto moveAction =
        poseHandler.IsBackward() ? ActionType::BACKWARD_1_STEP_ACTION : ActionType::FORWARD_1_STEP_ACTION;
    // 组合原子指令
    if (poseHandler.IsFast()) {
        actionGroup.PushAction(moveAction);
    }
    actionGroup.PushAction(turnRightAction);
    actionGroup.PushAction(moveAction);
    return actionGroup;
}

ActionGroup FastCommand::operator()(PoseHandler& poseHandler) const noexcept
{
    ActionGroup actionGroup;
    actionGroup.PushAction(ActionType::BE_FAST_ACTION);
    return actionGroup;
}

ActionGroup BackCommand::operator()(PoseHandler& poseHandler) const noexcept
{
    ActionGroup actionGroup;
    actionGroup.PushAction(ActionType::BE_BACKWARD_ACTION);
    return actionGroup;
}

}  // namespace car
}  // namespace adas