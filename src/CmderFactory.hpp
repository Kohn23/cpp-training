#pragma once
#include <functional>
#include <list>
#include <unordered_map>

#include "Command.hpp"
namespace adas
{
using Cmder = std::function<ActionGroup(PoseHandler& poseHandler)>;
using CmderList = std::list<Cmder>;

// 抽象工厂接口
class CmderFactory
{
public:
    CmderFactory(void) = default;  // 这里noexcept会导致编译失败，原因是与constexpr构造函数冲突
    virtual ~CmderFactory(void) noexcept = default;
    CmderFactory(const CmderFactory&) noexcept = delete;
    CmderFactory& operator=(const CmderFactory&) noexcept = delete;

public:
    virtual CmderList GetCmders(const std::string& commands) const noexcept = 0;
};

// 实体工厂
class CarFactory final: public CmderFactory
{
public:
    CarFactory(void) = default;
    ~CarFactory(void) noexcept = default;
    CarFactory(const CmderFactory&) noexcept = delete;
    CarFactory& operator=(const CmderFactory&) noexcept = delete;

public:
    CmderList GetCmders(const std::string& commands) const noexcept override;

private:
    const std::unordered_map<char, Cmder> cmderMap{
        {'M', car::MoveCommand()}, {'L', car::TurnLeftCommand()}, {'R', car::TurnRightCommand()},
        {'F', car::FastCommand()}, {'B', car::BackCommand()},
    };
};



}  // namespace adas