#include "./PoseHandler.hpp"
namespace adas
{
PoseHandler::PoseHandler(const Pose& pose) noexcept : pose(pose)
{
}

void PoseHandler::Move() noexcept
{
    if (pose.heading == 'N') {
        pose.y += 1;
    } else if (pose.heading == 'E') {
        pose.x += 1;
    } else if (pose.heading == 'S') {
        pose.y -= 1;
    } else if (pose.heading == 'W') {
        pose.x -= 1;
    }
}
void PoseHandler::TurnLeft() noexcept
{
    if (pose.heading == 'N') {
        pose.heading = 'W';
    } else if (pose.heading == 'E') {
        pose.heading = 'N';
    } else if (pose.heading == 'S') {
        pose.heading = 'E';
    } else if (pose.heading == 'W') {
        pose.heading = 'S';
    }
}

void PoseHandler::TurnRight() noexcept
{
    if (pose.heading == 'N') {
        pose.heading = 'E';
    } else if (pose.heading == 'E') {
        pose.heading = 'S';
    } else if (pose.heading == 'S') {
        pose.heading = 'W';
    } else if (pose.heading == 'W') {
        pose.heading = 'N';
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
}  // namespace adas