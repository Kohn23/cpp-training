#pragma once

#include "Executor.hpp"
#include "PoseHandler.hpp"
#include "FactorySubject.hpp"

namespace adas
{
class ExecutorImpl final : public Executor
{
public:
    explicit ExecutorImpl(const Pose& pose,  const char factory) noexcept;
    ~ExecutorImpl() noexcept = default;
    ExecutorImpl(const ExecutorImpl&) = delete;
    ExecutorImpl& operator=(const ExecutorImpl&) = delete;

public:
    void Execute(const std::string& command) noexcept override;
    Pose Query(void) const noexcept override;

private:
    PoseHandler poseHandler;
    CmderFactory& cmderFactory;
};
}  // namespace adas
