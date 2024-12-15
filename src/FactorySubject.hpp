#pragma once
#include<unordered_map>
#include<functional>

#include "CmderFactory.hpp"
#include "Singleton.hpp"

namespace adas
{
using Factory = std::function<CmderFactory&()>;

class FactorySubject final
{
public:
    FactorySubject(void) = default;
    ~FactorySubject(void) noexcept = default;
    FactorySubject(const FactorySubject&) noexcept = delete;
    FactorySubject& operator=(const FactorySubject&) noexcept = delete;
public:
    CmderFactory& GetFactory(const char factory) const noexcept;
private:
    const std::unordered_map<char, Factory> factoryMap{
        {'C', []() -> CmderFactory& { return Singleton<CarFactory>::Instance(); }},
        {'S', []() -> CmderFactory& { return Singleton<SportsCarFactory>::Instance(); }},
        {'B', []() -> CmderFactory& { return Singleton<BusFactory>::Instance(); }}
    };
};
}