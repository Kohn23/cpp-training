#include "FactorySubject.hpp"
namespace adas
{
CmderFactory& FactorySubject::GetFactory(const char factory) const noexcept{
    const auto it = factoryMap.find(factory);
    if (it!= factoryMap.end()) {
        return it->second();
    }
    else {
        // 这里返回一个默认的工厂
        return Singleton<CarFactory>::Instance();
    }
}
}
