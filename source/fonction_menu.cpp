#include <QApplication>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <QTextEdit>
#include <QCheckBox>
#include <QObject>
#include <QString>
#include <functional>

// Inclure les headers de tes fonctions
#include "fonctions_forcebrute.hpp"
#include "fonctions_arborescente.hpp"

void lancer_menu() {
    int argc = 0;
    char **argv = nullptr;
    QApplication app(argc, argv);

    QWidget *window = new QWidget();
    window->setWindowTitle("Menu Entrepôt");

    // Boutons
    QPushButton *btnForceBrute = new QPushButton("Méthode Force Brute", window);
    QPushButton *btnArbo = new QPushButton("Méthode Arborescente", window);
    QPushButton *btnQuitter = new QPushButton("Quitter", window);

    // Case à cocher pour afficher toutes les étapes
    QCheckBox *chkAfficherTout = new QCheckBox("Afficher toutes les étapes", window);
    chkAfficherTout->setChecked(false); // par défaut non coché

    // Zone pour afficher les résultats
    QTextEdit *resultDisplay = new QTextEdit(window);
    resultDisplay->setReadOnly(true);

    // Callback pour afficher les résultats dans l'interface
    auto ui_callback = [resultDisplay](const QString &msg) {
        resultDisplay->append(msg);
    };

    // Connexion des boutons
    QObject::connect(btnForceBrute, &QPushButton::clicked, [=]() {
        resultDisplay->clear();
        lancer_force_brute(ui_callback, chkAfficherTout->isChecked());
    });

    QObject::connect(btnArbo, &QPushButton::clicked, [=]() {
        resultDisplay->clear();
        lancer_arborescente(ui_callback, chkAfficherTout->isChecked());
    });

    QObject::connect(btnQuitter, &QPushButton::clicked, &app, &QApplication::quit);

    // Mise en page
    QVBoxLayout *layout = new QVBoxLayout(window);
    layout->addWidget(btnForceBrute);
    layout->addWidget(btnArbo);
    layout->addWidget(chkAfficherTout); // case à cocher
    layout->addWidget(btnQuitter);
    layout->addWidget(resultDisplay);

    window->setLayout(layout);
    window->resize(500, 500);
    window->show();

    app.exec();
}