#include "llvm/Support/ErrorOr.h"
#include "llvm/Support/Program.h"
#include "llvm/Support/Signals.h"
#include <system_error>

namespace llvm {

void initSignalsOptions() {}

namespace sys {

void RunInterruptHandlers() {}
void PrintStackTraceOnErrorSignal(StringRef, bool) {}
void AddSignalHandler(SignalHandlerCallback, void *, bool) {}
void SetOneShotPipeSignalFunction(void (*)()) {}
void DefaultOneShotPipeSignalHandler() {}

ErrorOr<std::string> findProgramByName(StringRef Name, ArrayRef<StringRef>) {
  return Name.str();
}

int ExecuteAndWait(StringRef, ArrayRef<StringRef>,
                   std::optional<ArrayRef<StringRef>>,
                   ArrayRef<std::optional<StringRef>>, unsigned, unsigned,
                   std::string *, bool *,
                   std::optional<ProcessStatistics> *, BitVector *) {
  return -1;
}

std::error_code ChangeStdinMode(fs::OpenFlags) { return {}; }
std::error_code ChangeStdoutMode(fs::OpenFlags) { return {}; }

} // namespace sys
} // namespace llvm

extern "C" int posix_madvise(void *, size_t, int) { return 0; }
