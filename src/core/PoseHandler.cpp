#include "./PoseHandler.hpp"

namespace adas
{
PoseHandler::PoseHandler(const Pose& pose,char carType) noexcept
    : point(pose.x, pose.y), facing(&Direction::GetDirection(pose.heading)),carType(carType)
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

Pose PoseHandler::Query() const noexcept
{
    return Pose{point.GetX(), point.GetY(), facing->GetHeading()};
}

void PoseHandler::Fast() noexcept
{
    fast = !fast;
}

bool PoseHandler::IsFast() const noexcept
{
    return fast;
}
void PoseHandler::Reverse() noexcept
{
    reverse = !reverse;
}
bool PoseHandler::IsReverse() const noexcept
{
    return reverse;
}

 char PoseHandler::GetCarType(void) const noexcept{
    return carType;
 }

}  // namespace adas