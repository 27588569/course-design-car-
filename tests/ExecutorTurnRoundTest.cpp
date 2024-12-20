#include <gtest/gtest.h>

#include "./PoseEq.hpp"
#include "Executor.hpp"
namespace adas
{
TEST(ExecutorTurnRoundTest, should_normal_tr_build_left_forward_left)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'},'N'));
    executor->Execute("TR");
    const Pose target({0, 1, 'W'});
    ASSERT_EQ(target, executor->Query());
}

TEST(ExecutorTurnRoundTest, should_fast_tr_build_left_forward_left)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'},'N'));
    executor->Execute("FTR");
    const Pose target({1, 1, 'W'});
    ASSERT_EQ(target, executor->Query());
}

TEST(ExecutorTurnRoundTest, in_the_B_state_the_reverse_command_will_be_ignored)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'},'N'));
    executor->Execute("BTR");
    const Pose target({0, 0, 'E'});
    ASSERT_EQ(target, executor->Query());
}
}  // namespace adas