#include <Scripts/tools.hpp>


// Get project "assets" directory
std::string getAssetsPath()
{
    // Get current working directory
    char result[PATH_MAX];
    size_t count = readlink("/proc/self/exe", result, PATH_MAX);
    std::string full_path = std::string(result, (count > 0) ? count : 0);
    
    // Get "assets" path
    std::string path = full_path.substr(0, full_path.size() - 7) + "assets/";
    
    // Return path
    return path;
}

