#pragma once
#include <string>
namespace adas
{
struct Pose {
    int x;
    int y;
    char heading;
};
class Executor
{
public:
    static Executor* NewExecutor(const Pose& pose = {0, 0, 'N'}) noexcept;  // noexcept:�����׳�����

public:
    Executor(void) = default;            // default:Ĭ�Ϲ��캯��
    virtual ~Executor(void) = default;   // virtual:��д
    Executor(const Executor&) = delete;  // delete:���øú���
    Executor& operator=(const Executor&) = delete;

public:
    virtual void Execute(const std::string& command) noexcept = 0;
    virtual Pose Query(void) const noexcept = 0;
};
}  // namespace adas