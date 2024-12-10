#include "PoseHandler.hpp"
namespace adas
{
PoseHandler::PoseHandler(const Pose& pose) noexcept
    : point(pose.x, pose.y), facing(&Direction::GetDirection(pose.heading))
{
}

void PoseHandler::Forward() noexcept
{
    point += facing->Move();
}

void PoseHandler::Backward() noexcept
{
    point -= facing->Move();
}

void PoseHandler::TurnLeft() noexcept
{
    facing = &(facing->LeftOne());
}

void PoseHandler::TurnRight() noexcept
{
    facing = &(facing->RightOne());
}

void PoseHandler::Fast() noexcept
{
    fast = !fast;
}

bool PoseHandler::IsFast() const noexcept
{
    return fast;
}

void PoseHandler::Back() noexcept
{
    backward = !backward;
}

bool PoseHandler::IsBackward() const noexcept
{
    return backward;
}

Pose PoseHandler::Query() const noexcept
{
    return {point.GetX(), point.GetY(), facing->GetHeading()};
}

}  // namespace adas