
#include "../../include/commande/CmdAide.h"

namespace CMD
{

    CmdAide::CmdAide() : Commande(false) {}

    CmdAide::~CmdAide() = default;

    void CmdAide::executer(const Console::Instruction &inst, Machine::Systeme *sys)
    {
        std::cout
            << "selection <vert|noir|oolong> : sélectionner le thé à préparer.\n"
            << "infuser : préparer le nombre de portions du thé sélectionné configuré.\n"
            << "reserves : afficher les réserves d’eau et de thé.\n"
            << "remplir eau <quantite> : ajouter de l’eau, en millilitres.\n"
            << "remplir <vert|noir|oolong> <quantite> : ajouter du thé, en grammes.\n"
            << "notifications <activer|désactiver> : gérer les notifications à distance.\n"
            << "portions <nombre> : modifier le nombre de portions\n"
            << "configuration : afficher la configuration actuelle\n"
            << "routine <Solo|Duo|Matin> : appliquer la routine indiquée\n"
            << "apercu <Solo|Duo|Matin> : afficher les changements de réglages de la routine\n"
            << "undo : annuler la dernière opération réversible\n"
            << "redo : retablir la dernière opération annulée\n"
            << "h : afficher cette aide.\n"
            << "q : quitter l’application.\n";
    }

    void undo(Machine::Systeme *sys)
    {
        std::cout << "Ceci n'est pas une commande réversible." << std::endl;
    }

}