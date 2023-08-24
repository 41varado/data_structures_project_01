#pragma once

#include <chrono>
#include <string>

typedef std::chrono::year_month_day DATE;

struct PROJECT
{
    double          cost;
    int             number;
    std::string     name;
    DATE    startDate, endDate;
};

std::string format_project_date(const DATE&);