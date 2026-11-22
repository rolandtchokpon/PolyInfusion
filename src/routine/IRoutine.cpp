

#include "../../include/routine/IRoutine.h"

namespace Routine
{

    IRoutine::~IRoutine() = default;

    IRoutine::IRoutine(unsigned int portions, std::string the) : portions_(portions), the_(the) {};

}