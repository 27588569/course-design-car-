#pragma once
#include "./Executorlmpl.hpp"

namespace adas
{
class Icommand
{
public:
    virtual ~Icommand() = default;
    virtual void DoOperate(ExecutorImpl& executor) const noexcept = 0;
};

class MoveCommand final : public Icommand
{
public:
    void DoOperate(ExecutorImpl& executor) const noexcept override
    {
        if (executor.IsFast()) {
            executor.Move();
        }
        executor.Move();
    }
};

class TurnLeftCommand final : public Icommand
{
public:
    void DoOperate(ExecutorImpl& executor) const noexcept override
    {
        if (executor.IsFast()) {
            executor.Move();
        }
        executor.TurnLeft();
    }
};

class TurnRightCommand final : public Icommand
{
public:
    void DoOperate(ExecutorImpl& executor) const noexcept override
    {
        if (executor.IsFast()) {
            executor.Move();
        }
        executor.TurnRight();
    }
};
class FastCommand final : public Icommand
{
public:
    void DoOperate(ExecutorImpl& executor) const noexcept override
    {
        executor.Fast();
    }
};
}