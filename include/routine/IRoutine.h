
#pragma once

namespace Machine { class Systeme; }

namespace Routine
{

    class IRoutine {
        public:
            virtual ~IRoutine() = 0;
            virtual void appliquer(Machine::Systeme* sys) const = 0;

        protected:
            IRoutine();

    };

}
