#include <gtest/gtest.h>

#include "../include/Executor.hpp"
#include "./PoseEq.hpp"
namespace adas
{
TEST(ExecutorReverseTest, should_return_x_plus_1_given_status_is_reverse_command_is_M_and_facing_is_W)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'W'}));
    executor->Execute("BM");
    const Pose target({1, 0, 'W'});
    ASSERT_EQ(target, executor->Query());
}

TEST(ExecutorReverseTest, should_return_x_minus_1_given_status_is_reverse_command_is_M_and_facing_is_E)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
    executor->Execute("BM");
    const Pose target({-1, 0, 'E'});
    ASSERT_EQ(target, executor->Query());
}

TEST(ExecutorReverseTest, should_return_y_plus_1_given_status_is_reverse_command_is_M_and_facing_is_S)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'S'}));
    executor->Execute("BM");
    const Pose target({0, 1, 'S'});
    ASSERT_EQ(target, executor->Query());
}

TEST(ExecutorReverseTest, should_return_y_minus_1_given_status_is_reverse_command_is_M_and_facing_is_N)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'}));
    executor->Execute("BM");
    const Pose target({0, -1, 'N'});
    ASSERT_EQ(target, executor->Query());
}

TEST(ExecutorReverseTest, should_return_x_plus_2_given_status_is_reverse_and__fast_command_is_M_and_facing_is_W)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'W'}));
    executor->Execute("BFM");
    const Pose target({2, 0, 'W'});
    ASSERT_EQ(target, executor->Query());
}

TEST(ExecutorReverseTest, should_return_x_plus_1_given_command_is_BBM_and_facing_is_E)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
    executor->Execute("BBM");
    const Pose target({1, 0, 'E'});
    ASSERT_EQ(target, executor->Query());
}
}  // namespace adas