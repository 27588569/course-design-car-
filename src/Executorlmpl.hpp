#pragma once
#include <algorithm>
#include <memory>

#include "../include/Executor.hpp"
namespace adas
{
class ExecutorImpl final : public Executor
{
public:
    explicit ExecutorImpl(const Pose& pose) noexcept;
    ~ExecutorImpl() noexcept = default;
    ExecutorImpl(const ExecutorImpl&) = delete;
    ExecutorImpl& operator=(const ExecutorImpl&) = delete;

public:
    void Execute(const std::string& command) noexcept override;
    Pose Query(void) const noexcept override;

private:
    Pose pose;

private:
    void Move(void) noexcept;
    void TurnLeft(void) noexcept;
    void TurnRight(void) noexcept;

private:
    class Icommand
    {
    public:
        virtual ~Icommand() = default;
        virtual void DoOperate(ExecutorImpl& executor) const noexcept = 0;
    };

private:
    class MoveCommand final : public Icommand
    {
    public:
        void DoOperate(ExecutorImpl& executor) const noexcept override
        {
            executor.Move();
        }
    };
    class TurnLeftCommand final : public Icommand
    {
    public:
        void DoOperate(ExecutorImpl& executor) const noexcept override
        {
            executor.TurnLeft();
        }
    };
    class TurnRightCommand final : public Icommand
    {
    public:
        void DoOperate(ExecutorImpl& executor) const noexcept override
        {
            executor.TurnRight();
        }
    };
};
}  // namespace adas
