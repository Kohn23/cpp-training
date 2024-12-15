#pragma once
#include <list>
#include <functional>

#include "PoseHandler.hpp"
namespace adas
{
using Atom = std::function<void(PoseHandler& poseHandler)>;

enum class ActionType : uint16_t {
    FORWARD_1_STEP_ACTION = 0,
    BACKWARD_1_STEP_ACTION,
    TURNLEFT_ACTION,
    BACKWARD_TURNLEFT_ACTION,
    TURNRIGHT_ACTION,
    BACKWARD_TURNRIGHT_ACTION,
    BE_FAST_ACTION,
    BE_BACKWARD_ACTION,
};

class ActionGroup final
{
public:
    ActionGroup(void) = default;
    explicit ActionGroup(const std::list<ActionType>& actions) noexcept;
    ~ActionGroup() = default;

public:
    void PushAction(const ActionType ActionType) noexcept;
    void DoOperate(PoseHandler& poseHandler) const noexcept;

private:
    std::list<ActionType> actions;
};
}  // namespace adas

