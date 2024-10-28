#include "cosh/utils/log.h"
#include <iostream>
#include <memory>
#include <spdlog/sinks/rotating_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>
#include <vector>

namespace hello::log {
constexpr size_t MAX_LOG_SIZE = 300 * 1024;
constexpr size_t MAX_FILE_CNT = 1;

Log::Log() { init(); }
Log::~Log() { spdlog::shutdown(); }
void Log::init() {

  auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
  console_sink->set_level(spdlog::level::trace);

  auto rotate_sink = std::make_shared<spdlog::sinks::rotating_file_sink_mt>(
      "logs/rotating.txt", MAX_LOG_SIZE, MAX_FILE_CNT);
  rotate_sink->set_level(spdlog::level::trace);
  // 创建一个logger，并将控制台和文件sink添加到logger中
  std::vector<spdlog::sink_ptr> sinks{console_sink, rotate_sink};
  auto logger =
      std::make_shared<spdlog::logger>("factory", begin(sinks), end(sinks));
  // 设置logger的格式
  logger->set_pattern("[%H:%M:%S.%e] [%t] [%s:%#] %^[%L] : %v%$");

  spdlog::set_default_logger(logger);
  spdlog::set_level(spdlog::level::trace);
  SPDLOG_INFO("start log");
}
void Log::hello() { SPDLOG_INFO("hello"); }
void test() {}
void init_log() {
  auto &log = Log::get_instance();
}
} // namespace hello::log
