#include "PoseHandler.hpp"
namespace adas
{
PoseHandler::PoseHandler(const Pose& pose, const char factory) noexcept
    : head(pose.x, pose.y), tail(0,0), facing(&Direction::GetDirection(pose.heading)), factory(factory)
{
    setTail();
}

void PoseHandler::Forward() noexcept
{
    head += facing->Move();
    setTail();
}

void PoseHandler::Backward() noexcept
{
    head -= facing->Move();
    setTail();
}

void PoseHandler::TurnLeft() noexcept
{
    facing = &(facing->LeftOne());
    setTail();
}

void PoseHandler::TurnRight() noexcept
{
    facing = &(facing->RightOne());
    setTail();
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

Pose PoseHandler::QueryHead() const noexcept
{
    return {head.GetX(), head.GetY(), facing->GetHeading()};
}

Pose PoseHandler::QueryTail() const noexcept
{
    return {tail.GetX(), tail.GetY(), facing->GetHeading()};
}

void PoseHandler::setTail() noexcept
{
    if(factory != 'B')
    {
        tail = head;
    }
    else
    {
        tail = head - facing->Move();
    }
}

}  // namespace adas