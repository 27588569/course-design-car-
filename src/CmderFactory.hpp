#pragma once
#include <functional>
#include <list>
#include <unordered_map>

#include "./ActionGroup.hpp"
#include "./Command.hpp"
namespace adas
{
using Cmder = std::function<ActionGroup(PoseHandler& poseHandler)>;
using CmderList = std::list<Cmder>;
class CmderFactory final
{
public:
    CmderFactory(void) = default;
    ~CmderFactory(void) noexcept = default;
    CmderFactory(const CmderFactory&) noexcept = delete;
    CmderFactory& operator=(const CmderFactory&) noexcept = delete;

public:
    CmderList GetCmders(const std::string& commands) const noexcept;

private:
    const std::unordered_map<char, Cmder> cmderMap{{'M', MoveCommand()},
                                                   {'L', TurnLeftCommand()},
                                                   {'R', TurnRightCommand()},
                                                   {'F', FastCommand()},
                                                   {'B', ReverseCommand()}};
};
}  // namespace adas