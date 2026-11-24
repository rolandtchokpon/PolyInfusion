
#include "../../include/commande/CmdAide.h"

namespace CMD
{

    CmdAide::CmdAide() : Commande(false) {}

    CmdAide::~CmdAide() = default;

    void CmdAide::executer(const Console::Instruction &, Machine::Systeme *sys)
    {
        std::string thes;
        for (const std::string &the : sys->thesDisponibles())
            thes += (thes.empty() ? "" : "|") + the;

        std::cout
            << "selection <" << thes << "> : sélectionner le thé à préparer.\n"
            << "infuser : préparer le nombre de portions du thé sélectionné configuré.\n"
            << "reserves : afficher les réserves d’eau et de thé.\n"
            << "remplir eau <quantite> : ajouter de l’eau, en millilitres.\n"
            << "remplir <" << thes << "> <quantite> : ajouter du thé, en grammes.\n"
            << "notifications <activer|désactiver> : gérer les notifications à distance.\n"
            << "portions <nombre> : modifier le nombre de portions\n"
            << "configuration : afficher la configuration actuelle\n"
            << "routine <nom> : appliquer la routine indiquée\n"
            << "apercu <nom> : afficher les changements de réglages de la routine\n"
            << "undo : annuler la dernière opération réversible\n"
            << "redo : rétablir la dernière opération annulée\n"
            << "h : afficher cette aide.\n"
            << "q : quitter l’application.\n";
    }

    void CmdAide::undo(Machine::Systeme *)
    {
        std::cout << "Ceci n'est pas une commande réversible." << std::endl;
    }

}