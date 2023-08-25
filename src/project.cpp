#include <chrono>
#include <iomanip>

#include "project.h"

bool PROJECT::operator ==(const PROJECT& otherProject) const
{
    return this->number == otherProject.number;
}

std::string format_project_date(const DATE& projectDate)
{
    return std::format("{:%d/%m/%Y}", projectDate);
}