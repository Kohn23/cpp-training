#include "CmderFactory.hpp"
namespace adas
{
CmderList CmderFactory::GetCmders(const std::string& commands) const noexcept
{
    CmderList cmders;
    for (const auto cmd : commands) {
        const auto it = cmderMap.find(cmd);
        if (it != cmderMap.end()) {
            cmders.push_back(it->second);
        }
    }
    return cmders;
}
}  // namespace adas