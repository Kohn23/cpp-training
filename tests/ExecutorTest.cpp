#include <gtest/gtest.h>

#include <memory>
#include <tuple>

#include "Executor.hpp"
namespace adas
{
bool operator==(const Pose& lhs, const Pose& rhs)
{  // 为Pose定义==运算符重载，使得在测试中比较Pose对象变得简单明了， std::tie提高代码可读性
    return std::tie(lhs.x, lhs.y, lhs.heading) == std::tie(rhs.x, rhs.y, rhs.heading);
}
//       测试套            测试用例名，清晰地描述了预期行为和测试的条件，更容易理解测试在验证什么
TEST(ExecutorTest, should_return_init_pose_when_without_command)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
    // when		测试遵循了 Arrange-Act-Assert (AAA) 模式，这是提高可读性和维护性的好习惯

    // then
    const Pose target({0, 0, 'E'});
    ASSERT_EQ(target, executor->Query());
}
TEST(ExecutorTest, should_return_default_pose_when_without_init_and_command)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor());
    // when		测试遵循了 Arrange-Act-Assert (AAA) 模式，这是提高可读性和维护性的好习惯

    // then
    const Pose target({0, 0, 'N'});
    ASSERT_EQ(target, executor->Query());
}
}  // namespace adas