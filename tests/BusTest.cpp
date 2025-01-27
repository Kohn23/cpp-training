#include <gtest/gtest.h>

#include <memory>

#include "Executor.hpp"
#include "PoseEq.hpp"
namespace adas
{

// command指令测试
TEST(BusTest, should_return_x_plus_1_given_command_is_M_and_facing_is_E)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}, 'B'));
    // when
    executor->Execute("M");
    // then
    const Pose targetHead({1, 0, 'E'});
    const Pose targetTail({0, 0, 'E'});
    ASSERT_EQ(targetHead, executor->QueryHead());
    ASSERT_EQ(targetTail, executor->QueryTail());
}

TEST(BusTest, should_return_x_minus_1_given_command_is_M_and_facing_is_W)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'W'}, 'B'));
    // when
    executor->Execute("M");
    // then
    const Pose targetHead({-1, 0, 'W'});
    const Pose targetTail({0, 0, 'W'});
    ASSERT_EQ(targetHead, executor->QueryHead());
    ASSERT_EQ(targetTail, executor->QueryTail());
}

TEST(BusTest, should_return_y_plus_1_given_command_is_M_and_facing_is_N)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'}, 'B'));
    // when
    executor->Execute("M");
    // then
    const Pose targetHead({0, 1, 'N'});
    const Pose targetTail({0, 0, 'N'});
    ASSERT_EQ(targetHead, executor->QueryHead());
    ASSERT_EQ(targetTail, executor->QueryTail());
}

TEST(BusTest, should_return_y_minus_1_given_command_is_M_and_facing_is_S)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'S'}, 'B'));
    // when
    executor->Execute("M");
    // then
    const Pose targetHead({0, -1, 'S'});
    const Pose targetTail({0, 0, 'S'});
    ASSERT_EQ(targetHead, executor->QueryHead());
    ASSERT_EQ(targetTail, executor->QueryTail());
}

TEST(BusTest, should_return_facing_N_and_x_plus_1_given_command_is_L_and_facing_is_E)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}, 'B'));
    // when
    executor->Execute("L");
    // then
    const Pose targetHead({1, 0, 'N'});
    const Pose targetTail({1, -1, 'N'});
    ASSERT_EQ(targetHead, executor->QueryHead());
    ASSERT_EQ(targetTail, executor->QueryTail());
}

TEST(BusTest, should_return_facing_S_and_x_minus_1_given_command_is_L_and_facing_is_W)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'W'}, 'B'));
    // when
    executor->Execute("L");
    // then
    const Pose targetHead({-1, 0, 'S'});
    const Pose targetTail({-1, 1, 'S'});
    ASSERT_EQ(targetHead, executor->QueryHead());
    ASSERT_EQ(targetTail, executor->QueryTail());
}

TEST(BusTest, should_return_facing_W_and_y_plus_1_given_command_is_L_and_facing_is_N)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'}, 'B'));
    // when
    executor->Execute("L");
    // then
    const Pose targetHead({0, 1, 'W'});
    const Pose targetTail({1, 1, 'W'});
    ASSERT_EQ(targetHead, executor->QueryHead());
    ASSERT_EQ(targetTail, executor->QueryTail());
}

TEST(BusTest, should_return_facing_E_and_y_minus_1_given_command_is_L_and_facing_is_S)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'S'}, 'B'));
    // when
    executor->Execute("L");
    // then
    const Pose targetHead({0, -1, 'E'});
    const Pose targetTail({-1, -1, 'E'});
    ASSERT_EQ(targetHead, executor->QueryHead());
}

TEST(BusTest, should_return_facing_E_and_y_plus_1_given_command_is_R_and_facing_is_N)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'}, 'B'));
    // when
    executor->Execute("R");
    // then
    const Pose targetHead({0, 1, 'E'});
    const Pose targetTail({-1, 1, 'E'});
    ASSERT_EQ(targetHead, executor->QueryHead());
    ASSERT_EQ(targetTail, executor->QueryTail());
}

TEST(BusTest, should_return_facing_W_and_y_minus_1_given_command_is_R_and_facing_is_S)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'S'}, 'B'));
    // when
    executor->Execute("R");
    // then
    const Pose targetHead({0, -1, 'W'});
    const Pose targetTail({1,-1, 'W'});
    ASSERT_EQ(targetHead, executor->QueryHead());
    ASSERT_EQ(targetTail, executor->QueryTail());
}

TEST(BusTest, should_return_facing_S_and_x_plus_1_given_command_is_R_and_facing_is_E)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}, 'B'));
    // when
    executor->Execute("R");
    // then
    const Pose targetHead({1, 0, 'S'});
    const Pose targetTail({1, 1, 'S'});
    ASSERT_EQ(targetHead, executor->QueryHead());
    ASSERT_EQ(targetTail, executor->QueryTail());
}

TEST(BusTest, should_return_facing_N_and_x_minus_1_given_command_is_R_and_facing_is_W)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'W'}, 'B'));
    // when
    executor->Execute("R");
    // then
    const Pose targetHead({-1, 0, 'N'});
    const Pose targetTail({-1, -1, 'N'});
    ASSERT_EQ(targetHead, executor->QueryHead());
    ASSERT_EQ(targetTail, executor->QueryTail());
}

TEST(BusFastTest, should_return_x_plus_2_given_status_is_fast_command_is_M_and_facing_is_E)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}, 'B'));
    // when
    executor->Execute("FM");
    // then
    const Pose targetHead{2, 0, 'E'};
    const Pose targetTail{1, 0, 'E'};
    ASSERT_EQ(targetHead, executor->QueryHead());
    ASSERT_EQ(targetTail, executor->QueryTail());
}

TEST(BusFastTest, should_return_N_and_x_plus_2_given_status_is_fast_command_is_L_and_facing_is_E)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}, 'B'));
    // when
    executor->Execute("FL");
    // then
    const Pose targetHead{2, 0, 'N'};
    const Pose targetTail{2, -1, 'N'};
    ASSERT_EQ(targetHead, executor->QueryHead());
    ASSERT_EQ(targetTail, executor->QueryTail());
}

TEST(BusFastTest, should_return_S_and_x_plus_2_given_status_is_fast_given_command_is_R_and_facing_is_E)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}, 'B'));
    // when
    executor->Execute("FR");
    // then
    const Pose targetHead{2, 0, 'S'};
    const Pose targetTail{2, 1, 'S'};
    ASSERT_EQ(targetHead, executor->QueryHead());
    ASSERT_EQ(targetTail, executor->QueryTail());
}

TEST(BusFastTest, should_return_y_plus_1_given_command_is_FFM_and_facing_is_N)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'}, 'B'));
    // when
    executor->Execute("FFM");
    // then
    const Pose targetHead{0, 1, 'N'};
    ASSERT_EQ(targetHead, executor->QueryHead());
}

TEST(BusBackTest, should_return_y_minus_1_given_status_is_backward_command_is_M_and_facing_is_N)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'}, 'B'));
    // when
    executor->Execute("BM");
    // then
    const Pose targetHead{0, -1, 'N'};
    const Pose targetTail{0, -2, 'N'};
    ASSERT_EQ(targetHead, executor->QueryHead());
    ASSERT_EQ(targetTail, executor->QueryTail());
}

TEST(BusBackTest, should_return_S_and_x_minus_1_given_status_is_backward_command_is_L_and_facing_is_E)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}, 'B'));
    // when
    executor->Execute("BL");
    // then
    const Pose targetHead{-1, 0, 'S'};
    const Pose targetTail{-1, 1, 'S'};
    ASSERT_EQ(targetHead, executor->QueryHead());
    ASSERT_EQ(targetTail, executor->QueryTail());
}

TEST(BusBackTest, should_return_N_and_x_minus_1_given_status_is_backward_command_is_R_and_facing_is_E)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}, 'B'));
    // when
    executor->Execute("BR");
    // then
    const Pose targetHead{-1, 0, 'N'};
    const Pose targetTail{-1, -1, 'N'};
    ASSERT_EQ(targetHead, executor->QueryHead());
    ASSERT_EQ(targetTail, executor->QueryTail());
}

TEST(BusBackTest, should_return_x_minus_2_given_status_is_fast_and_backward_command_is_M_and_facing_is_E)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}, 'B'));
    // when
    executor->Execute("BFM");
    // then
    const Pose targetHead{-2, 0, 'E'};
    const Pose targetTail{-3, 0, 'E'};
    ASSERT_EQ(targetHead, executor->QueryHead());
    ASSERT_EQ(targetTail, executor->QueryTail());
}

TEST(BusBackTest, should_return_S_and_x_minus_2_given_status_is_fast_and_backward_command_is_L_and_facing_is_E)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}, 'B'));
    // when
    executor->Execute("BFL");
    // then
    const Pose targetHead{-2, 0, 'S'};
    const Pose targetTail{-2, 1, 'S'};
    ASSERT_EQ(targetHead, executor->QueryHead());
    ASSERT_EQ(targetTail, executor->QueryTail());
}

TEST(BusBackTest, should_return_N_and_x_minus_2_given_status_is_fast_and_backward_command_is_R_and_facing_is_E)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}, 'B'));
    // when
    executor->Execute("BFR");
    // then
    const Pose targetHead{-2, 0, 'N'};
    const Pose targetTail{-2, -1, 'N'};
    ASSERT_EQ(targetHead, executor->QueryHead());
    ASSERT_EQ(targetTail, executor->QueryTail());
}

TEST(BusBackTest, should_return_y_plus_1_given_command_is_BBM_and_facing_is_N)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'}, 'B'));
    // when
    executor->Execute("BBM");
    // then
    const Pose targetHead{0, 1, 'N'};
    const Pose targetTail{0, 0, 'N'};
    ASSERT_EQ(targetHead, executor->QueryHead());
    ASSERT_EQ(targetTail, executor->QueryTail());
}

}  // namespace adas