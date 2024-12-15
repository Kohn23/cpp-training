#pragma once
#include "Direction.hpp"
#include "Executor.hpp"
namespace adas
{
class PoseHandler final
{
public:
    PoseHandler(const Pose& pose, const char factory) noexcept;
    PoseHandler(const PoseHandler&) = delete;
    PoseHandler& operator=(const PoseHandler&) = delete;

public:
    void Forward(void) noexcept;
    void Backward(void) noexcept;
    void TurnLeft(void) noexcept;
    void TurnRight(void) noexcept;
    void Fast(void) noexcept;
    bool IsFast(void) const noexcept;
    void Back(void) noexcept;
    bool IsBackward(void) const noexcept;
    Pose QueryHead(void) const noexcept;
    Pose QueryTail(void) const noexcept;

private:
    void setTail(void) noexcept;
private:
    Point head;
    Point tail;
    const Direction* facing;
    char factory;
    bool fast{false};
    bool backward{false};
};
}  // namespace adas