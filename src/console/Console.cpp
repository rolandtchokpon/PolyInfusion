#include "../../include/console/Console.h"

#include <cmath>
#include <iostream>
#include <locale>
#include <sstream>
#include <vector>

namespace Console
{

    InterfaceConsole::InterfaceConsole() = default;

    InterfaceConsole::~InterfaceConsole() = default;

    bool InterfaceConsole::estUnThe(const std::string &valeur)
    {
        return valeur == "vert" || valeur == "noir" || valeur == "oolong";
    }

    Instruction InterfaceConsole::invalide(const std::string &message)
    {
        Instruction resultat;
        resultat.type = TypeInstruction::Invalide;
        resultat.erreur = message;
        return resultat;
    }

    bool InterfaceConsole::lireQuantite(const std::string &texte, double &quantite)
    {
        // Le point est le séparateur décimal, indépendamment de la langue du système.
        std::istringstream entree(texte);
        entree.imbue(std::locale::classic());
        if (!(entree >> quantite))
        {
            return false;
        }
        entree >> std::ws;
        return entree.eof() && std::isfinite(quantite) && quantite > 0.0;
    }

    Mot InterfaceConsole::lireMot(const std::string &nom)
    {
        static const std::unordered_map<std::string, Mot> table = {
            {"selection", Mot::Selection},
            {"remplir", Mot::Remplir},
            {"notifications", Mot::Notifications},
            {"infuser", Mot::Infuser},
            {"reserves", Mot::Reserves},
            {"portions", Mot::Portions},
            {"configuration", Mot::Configuration},
            {"routine", Mot::Routine},
            {"apercu", Mot::Apercu},
            {"undo", Mot::Undo},
            {"redo", Mot::Redo},
            {"h", Mot::Aide},
            {"q", Mot::Quitter}};

        const auto it = table.find(nom);
        return it == table.end() ? Mot::Inconnu : it->second;
    }

    const Instruction InterfaceConsole::analyser(const std::string &ligne)
    {
        std::istringstream entree(ligne);
        std::vector<std::string> mots;
        for (std::string mot; entree >> mot;)
        {
            mots.push_back(mot);
        }

        Instruction resultat;
        if (mots.empty())
        {
            return resultat;
        }

        switch (lireMot(mots.front()))
        {
        case Mot::Selection:
            if (mots.size() != 2 || !estUnThe(mots[1]))
            {
                return invalide("Utilisation : selection <vert|noir|oolong>.");
            }
            resultat.type = TypeInstruction::Selection;
            resultat.the = mots[1];
            break;

        case Mot::Remplir:
            if (mots.size() != 3 || (mots[1] != "eau" && !estUnThe(mots[1])))
            {
                return invalide("Utilisation : remplir <eau|vert|noir|oolong> <quantite>.");
            }
            if (!lireQuantite(mots[2], resultat.quantite))
            {
                return invalide("La quantité doit être un nombre positif et fini, avec un point décimal au besoin.");
            }
            resultat.type = mots[1] == "eau" ? TypeInstruction::RemplirEau : TypeInstruction::RemplirThe;
            resultat.the = mots[1] == "eau" ? "" : mots[1];
            break;

        case Mot::Notifications:
            if (mots.size() != 2 || (mots[1] != "activer" && mots[1] != "désactiver" && mots[1] != "desactiver"))
            {
                return invalide("Utilisation : notifications <activer|désactiver>.");
            }
            resultat.type = TypeInstruction::Notifications;
            resultat.notificationsActives = mots[1] == "activer";
            break;

        case Mot::Infuser:
        case Mot::Reserves:
        case Mot::Aide:
        case Mot::Quitter:
            if (mots.size() != 1)
            {
                return invalide("Cette instruction ne prend aucun argument.");
            }
            switch (lireMot(mots.front()))
            {
            case Mot::Infuser:
                resultat.type = TypeInstruction::Infuser;
                break;
            case Mot::Reserves:
                resultat.type = TypeInstruction::Reserves;
                break;
            case Mot::Aide:
                resultat.type = TypeInstruction::Aide;
                break;
            default:
                resultat.type = TypeInstruction::Quitter;
                break;
            }
            break;

        case Mot::Portions:
            if (mots.size() != 2)
            {
                return invalide("Utilisation : portions <nombre>.");
            }

            int portions = std::stoi(mots[1]);

            if (portions <= 0)
            {
                return invalide("Le nombre de portions doit être un entier positif.");
            }
            resultat.type = TypeInstruction::Portion;
            resultat.portions = portions;
            break;

        case Mot::Routine:
            if (mots.size() != 2)
            {
                return invalide("Utilisation : routine <nom>.");
            }
            resultat.type = TypeInstruction::Routine;
            resultat.routine = mots[1];
            break;

        case Mot::Apercu:
            if (mots.size() != 2)
            {
                return invalide("Utilisation : apercu <nom>.");
            }
            resultat.type = TypeInstruction::Apercu;
            resultat.routine = mots[1];
            break;

        case Mot::Configuration:
        case Mot::Undo:
        case Mot::Redo:
            if (mots.size() != 1)
            {
                return invalide("Cette instruction ne prend aucun argument.");
            }
            switch (lireMot(mots.front()))
            {
            case Mot::Configuration:
                resultat.type = TypeInstruction::Config;
                break;
            case Mot::Undo:
                resultat.type = TypeInstruction::Undo;
                break;
            default:
                resultat.type = TypeInstruction::Redo;
                break;
            }
            break;

        case Mot::Inconnu:
        default:
            return invalide("Instruction inconnue. Entrez h pour afficher l’aide.");
        }

        return resultat;
    }
} // namespace Console
