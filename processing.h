#ifndef PROCESSING_H
#define PROCESSING_H

#include "person.h"

void splitPassedFailed(
    const std::vector<Person>& all,
    std::vector<Person>& failed,
    std::vector<Person>& passed
);

#endif
