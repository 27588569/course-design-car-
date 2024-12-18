#pragma once
#include <functional>

#include "./PoseHandler.hpp"
namespace adas
{

class MoveCommand final
{
public:
    void operator()(PoseHandler& poseHandler) noexcept
    {
        if (poseHandler.IsFast()) {
            poseHandler.Move();
        }
        poseHandler.Move();
    };
};

class TurnLeftCommand final
{
public:
    void operator()(PoseHandler& poseHandler) noexcept
    {
        if (poseHandler.IsFast()) {
            poseHandler.Move();
        }
        poseHandler.TurnLeft();
    };
};

class TurnRightCommand final
{
public:
    void operator()(PoseHandler& poseHandler) noexcept
    {
        if (poseHandler.IsFast()) {
            poseHandler.Move();
        }
        poseHandler.TurnRight();
    };
};
class FastCommand final
{
public:
    void operator()(PoseHandler& poseHandler) noexcept
    {
        poseHandler.Fast();
    };
};
}  // namespace adas