#include "tools/cpp/runfiles/runfiles.h"

using bazel::tools::cpp::runfiles::Runfiles;

static Runfiles* runfiles = nullptr;

extern "C" void InitializeRunfiles(const char *argv0)
{
    std::string error;

    runfiles = Runfiles::Create(argv0, &error);
}

extern "C" const char *GetBazelFile(const char *filename)
{
    static std::string result{};
    
    result = runfiles->Rlocation(std::string("_main/games/doom_headless/") + filename);

    return result.c_str();
}
