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
            if (poseHandler.IsReverse()) {
                poseHandler.Backward();
            } else {
                poseHandler.Forward();
            };
        }
        if (poseHandler.IsReverse()) {
            poseHandler.Backward();
        } else {
            poseHandler.Forward();
        }
    }
};

class TurnLeftCommand final
{
public:
    void operator()(PoseHandler& poseHandler) noexcept
    {
        if (poseHandler.IsFast()) {
            if (poseHandler.IsReverse()) {
                poseHandler.Backward();
            } else {
                poseHandler.Forward();
            };
        }
        if (poseHandler.IsReverse()) {
            poseHandler.TurnRight();
        } else {
            poseHandler.TurnLeft();
        }
    };
};

class TurnRightCommand final
{
public:
    void operator()(PoseHandler& poseHandler) noexcept
    {
        if (poseHandler.IsFast()) {
            if (poseHandler.IsReverse()) {
                poseHandler.Backward();
            } else {
                poseHandler.Forward();
            };
        }
        if (poseHandler.IsReverse()) {
            poseHandler.TurnLeft();
        } else {
            poseHandler.TurnRight();
        }
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
class ReverseCommand final
{
public:
    void operator()(PoseHandler& poseHandler) noexcept
    {
        poseHandler.Reverse();
    };
};
}  // namespace adas