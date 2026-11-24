
#pragma once

namespace CMD
{

    class CmdReglage;

    // Patron Iterator : parcourt, dans l'ordre d'exécution, les changements élémentaires
    // d'un réglage ou d'une routine (sous-routines comprises), sans exposer sa structure interne.
    class IterateurReglage
    {
    public:
        virtual ~IterateurReglage() = 0;

        virtual bool aSuivant() = 0;
        virtual const CmdReglage &suivant() = 0;
    };

} // namespace CMD
