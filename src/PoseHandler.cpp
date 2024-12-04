#include "PoseHandler.hpp"
namespace adas
{
PoseHandler::PoseHandler(const Pose& pose) noexcept : pose(pose)
{
}
void PoseHandler::Move() noexcept
{
    if (pose.heading == 'E')
    {
        ++pose.x;
    }
    else if (pose.heading == 'W')
    {
        --pose.x;
    }
    else if (pose.heading == 'N')
    {
        ++pose.y;
    }
    else if (pose.heading == 'S')
    {
        --pose.y;
    }
}

void PoseHandler::TurnLeft() noexcept
{
    if (pose.heading == 'E')
    {
        pose.heading = 'N';
    }
    else if (pose.heading == 'N')
    {
        pose.heading = 'W';
    }
    else if (pose.heading == 'W')
    {
        pose.heading = 'S';
    }
    else if (pose.heading == 'S')
    {
        pose.heading = 'E';
    }
}

void PoseHandler::TurnRight() noexcept
{
    if (pose.heading == 'E')
    {
        pose.heading = 'S';
    }
    else if (pose.heading == 'S')
    {
        pose.heading = 'W';
    }
    else if (pose.heading == 'W')
    {
        pose.heading = 'N';
    }
    else if (pose.heading == 'N')
    {
        pose.heading = 'E';
    }
}

Pose PoseHandler::Query() const noexcept
{
    return pose;
}

void PoseHandler::Fast() noexcept
{
    fast = !fast;
}

bool PoseHandler::IsFast() const noexcept
{
    return fast;
}
}