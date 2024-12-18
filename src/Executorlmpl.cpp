#include "./Executorlmpl.hpp"

#include <unordered_map>

#include "./cmder/CmderFactory.hpp"
#include "./cmder/Command.hpp"
#include "./core/Singleton.hpp"
namespace adas
{
Executor* Executor::NewExecutor(const Pose& pose,char carType) noexcept
{
    return new (std::nothrow) ExecutorImpl(pose,carType);
}
ExecutorImpl::ExecutorImpl(const Pose& pose,char carType) noexcept : poseHandler(pose,carType)
{
}
void ExecutorImpl::Execute(const std::string& commands) noexcept  // 执行命令
{
    const auto cmders = Singleton<CmderFactory>::Instance().GetCmders(commands);
    std::for_each(cmders.begin(), cmders.end(),
                  [this](const Cmder& cmder) noexcept { cmder(poseHandler).DoOperate(poseHandler); });
}
Pose ExecutorImpl::Query() const noexcept
{
    return poseHandler.Query();
}
}  // namespace adas