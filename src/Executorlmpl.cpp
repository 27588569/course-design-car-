#include "./Executorlmpl.hpp"
namespace adas
{
Executor* Executor::NewExecutor(const Pose& pose) noexcept
{
    return new (std::nothrow) ExecutorImpl(pose);
}
ExecutorImpl::ExecutorImpl(const Pose& pose) noexcept
{
    this->pose = pose;
}
void ExecutorImpl::Execute(const std::string& commands) noexcept  // 执行命令
{
    for (char ch : commands) {
        switch (ch) {
        case 'L':
            TurnLeft();
            break;
        case 'R':
            TurnRight();
            break;
        case 'M':
            std::unique_ptr<MoveCommand> cmder = std::make_unique<MoveCommand>();
            cmder->DoOperate(*this);
        }
    }
}
Pose ExecutorImpl::Query() const noexcept
{
    return pose;
}
void ExecutorImpl ::Move() noexcept
{
    switch (pose.heading) {
    case 'N':
        pose.y += 1;
        break;
    case 'E':
        pose.x += 1;
        break;
    case 'S':
        pose.y -= 1;
        break;
    case 'W':
        pose.x -= 1;
        break;
    }
}
void ExecutorImpl ::TurnLeft(void) noexcept
{
    switch (pose.heading) {
    case 'N':
        pose.heading = 'W';
        break;
    case 'E':
        pose.heading = 'N';
        break;
    case 'S':
        pose.heading = 'E';
        break;
    case 'W':
        pose.heading = 'S';
        break;
    }
}
void ExecutorImpl ::TurnRight(void) noexcept
{
    switch (pose.heading) {
    case 'N':
        pose.heading = 'E';
        break;
    case 'E':
        pose.heading = 'S';
        break;
    case 'S':
        pose.heading = 'W';
        break;
    case 'W':
        pose.heading = 'N';
        break;
    }
}
}  // namespace adas