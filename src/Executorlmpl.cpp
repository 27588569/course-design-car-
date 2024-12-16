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
    /* const char directions[] = {'N', 'E', 'S', 'W'};
     const int numDirections = 4;

     for (char ch : commands) {
         switch (ch) {
         case 'L':
             // 左转
             pose.heading = directions[(std::find(directions, directions + numDirections, pose.heading) - directions -
                                        1 + numDirections) %
                                       numDirections];
             break;
         case 'R':
             // 右转
             pose.heading =
                 directions[(std::find(directions, directions + numDirections, pose.heading) - directions + 1) %
                            numDirections];
             break;
         case 'M':
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
     }*/
}
Pose ExecutorImpl::Query() const noexcept
{
    return pose;
}
}  // namespace adas