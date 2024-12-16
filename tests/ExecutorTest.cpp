#include <gtest/gtest.h>

#include <memory>
#include <tuple>

#include "Executor.hpp"
namespace adas
{
bool operator==(const Pose& lhs, const Pose& rhs)
{  // ΪPose����==��������أ�ʹ���ڲ����бȽ�Pose�����ü����ˣ� std::tie��ߴ���ɶ���
    return std::tie(lhs.x, lhs.y, lhs.heading) == std::tie(rhs.x, rhs.y, rhs.heading);
}
//       ������            ������������������������Ԥ����Ϊ�Ͳ��Ե������������������������֤ʲô

TEST(ExecutorTest, should_return_default_pose_when_without_init_and_command)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor());
    const Pose target({0, 0, 'N'});
    ASSERT_EQ(target, executor->Query());
}

TEST(ExecutorTest, should_return_x_plus_1_given_command_is_M_and_facing_is_E)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({1, 2, 'E'}));
    executor->Execute("M");
    const Pose target({1, 2, 'E'});
    ASSERT_EQ(target, executor->Query());
}
/*should_return_x_plus_1_given_command_is_M_and_facing_is_E
should_return_x_minus_1_given_command_is_M_and_facing_is_W
should_return_y_plus_1_given_command_is_M_and_facing_is_N
should_return_y_minus_1_given_command_is_M_and_facing_is_S
*/
}  // namespace adas
