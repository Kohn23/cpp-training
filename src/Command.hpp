#pragma once
#include <functional>

#include "PoseHandler.hpp"
#include "ActionGroup.hpp"

namespace adas
{
namespace car
{
    class MoveCommand final
    {
        public:
            ActionGroup operator()(PoseHandler& poseHandler) const noexcept;
    };
    class TurnLeftCommand final
    {
        public:
            ActionGroup operator()(PoseHandler& poseHandler) const noexcept;
    };
    class TurnRightCommand final
    {
        public:
            ActionGroup operator()(PoseHandler& poseHandler) const noexcept;
    };
    class FastCommand final
    {
        public:
            ActionGroup operator()(PoseHandler& poseHandler) const noexcept;
    };
    class BackCommand final
    {
        public:
            ActionGroup operator()(PoseHandler& poseHandler) const noexcept;
    };
}  // namespace car

namespace sportsCar
{
    class MoveCommand final
    {
    public:
        ActionGroup operator()(PoseHandler& poseHandler) const noexcept;
    };
    class TurnLeftCommand final
    {
    public:
        ActionGroup operator()(PoseHandler& poseHandler) const noexcept;
    };
    class TurnRightCommand final
    {
    public:
        ActionGroup operator()(PoseHandler& poseHandler) const noexcept;
    };
    class FastCommand final
    {
    public:
        ActionGroup operator()(PoseHandler& poseHandler) const noexcept;
    };
    class BackCommand final
    {
    public:
        ActionGroup operator()(PoseHandler& poseHandler) const noexcept;
    };
}  // namespace sportscar

namespace bus
{
    class MoveCommand final
    {
    public:
        ActionGroup operator()(PoseHandler& poseHandler) const noexcept;
    };
    class TurnLeftCommand final
    {
    public:
        ActionGroup operator()(PoseHandler& poseHandler) const noexcept;
    };
    class TurnRightCommand final
    {
    public:
        ActionGroup operator()(PoseHandler& poseHandler) const noexcept;
    };
    class FastCommand final
    {
    public:
        ActionGroup operator()(PoseHandler& poseHandler) const noexcept;
    };
    class BackCommand final
    {
    public:
        ActionGroup operator()(PoseHandler& poseHandler) const noexcept;
    };
}  // namespace sportsCar

}  // namespace adas