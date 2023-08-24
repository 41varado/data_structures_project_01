#include <chrono>
#include <iomanip>

#include "project.h"

std::string format_project_date(const DATE& projectDate)
{
    return std::format("{:%d/%m/%Y}", projectDate);
}