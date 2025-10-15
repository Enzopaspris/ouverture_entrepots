#include <QApplication>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <QTextEdit>
#include <QObject>
#include <QString>
#include <functional>

#include "../include/fonctions_forcebrute.hpp"
#include "../include/fonctions_arborescente.hpp"

using namespace std;

void lancer_menu() {
    int argc = 0;
    char **argv = nullptr;
    QApplication app(argc, argv);

    QWidget *window = new QWidget();
    window->setWindowTitle("Menu Entrepôt");

    // Création des boutons dynamiquement
    QPushButton *btnForceBrute = new QPushButton("Méthode Force Brute", window);
    QPushButton *btnArbo = new QPushButton("Méthode Arborescente", window);
    QPushButton *btnQuitter = new QPushButton("Quitter", window);

    // Style des boutons
    QString style = "QPushButton { background-color: lightgray; color: black; font-weight: bold; padding: 8px; border-radius: 5px; }"
                    "QPushButton:hover { background-color: gray; }";

    btnForceBrute->setStyleSheet(style);
    btnArbo->setStyleSheet(style);
    btnQuitter->setStyleSheet(style);

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
        lancer_force_brute(ui_callback, false);
    });

    QObject::connect(btnArbo, &QPushButton::clicked, [=]() {
        resultDisplay->clear();
        lancer_arborescente(ui_callback, false);
    });

    QObject::connect(btnQuitter, &QPushButton::clicked, &app, &QApplication::quit);

    // Mise en page
    QVBoxLayout *layout = new QVBoxLayout(window);
    layout->addWidget(btnForceBrute);
    layout->addWidget(btnArbo);
    layout->addWidget(btnQuitter);
    layout->addWidget(resultDisplay);

    window->setLayout(layout);
    window->resize(500, 400);
    window->show();

    app.exec();
}
