#include "processing.h"

void splitPassedFailed(
    const std::vector<Person>& all,
    std::vector<Person>& failed,
    std::vector<Person>& passed
) {
    for (const auto& s : all) {

        double avg = s.averagePath(); //const safe

        if (avg < 5.0)
            failed.push_back(s);
        else
            passed.push_back(s);
    }
}
