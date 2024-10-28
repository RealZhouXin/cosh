#pragma once

#include "cosh/utils/sington.h"
#include <spdlog/spdlog.h>
#define logi(...) SPDLOG_INFO(__VA_ARGS__)
#define logd(...) SPDLOG_DEBUG(__VA_ARGS__)
#define logw(...) SPDLOG_WARN(__VA_ARGS__)
#define loge(...) SPDLOG_ERROR(__VA_ARGS__)
namespace hello::log {
void init_log();
class Log : public Sington<Log> {
  friend class Sington<Log>;

public:
  void hello();

private:
  Log();
  ~Log();
  void init();
};
void test();
} // namespace hello::log
