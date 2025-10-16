#include <QApplication>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <QCheckBox>
#include <QTextEdit>
#include <QFileDialog>
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QDir>
#include <QDebug>
#include <functional>
#include <vector>

// Inclure les headers de tes fonctions

#include "../include/structure.hpp"
#include "fonctions_forcebrute.hpp"
#include "fonctions_arborescente.hpp"


// ----------------------
// Fonction pour charger JSON ou valeurs par défaut
// ----------------------
static vector<Entrepot> charger_entrepots_par_defaut(QTextEdit* resultDisplay) {
    vector<Entrepot> entrepots;
    auto ui_callback = [resultDisplay](const QString &msg){ resultDisplay->append(msg); };

    QString cheminParDefaut = QDir::currentPath() + "/data/entrepots_par_defaut.json";
    QFile f(cheminParDefaut);
    bool json_ok = false;
    if (f.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QByteArray raw = f.readAll();
        f.close();
        QJsonParseError err;
        QJsonDocument doc = QJsonDocument::fromJson(raw, &err);
        if (err.error == QJsonParseError::NoError && doc.isArray()) {
            QJsonArray arr = doc.array();
            for (const QJsonValue &v : arr) {
                if (!v.isObject()) continue;
                QJsonObject o = v.toObject();
                Entrepot e;
                e.cout_ouv = o.value("cout_ouv").toInt(30);
                e.capa_max = o.value("capa_max").toInt(1);
                e.capa_actuel = o.value("capa_actuel").toInt(0);
                e.est_ouvert = o.value("est_ouvert").toBool(false);
                QJsonArray couts = o.value("cout_app").toArray();
                e.cout_app.clear();
                for (const QJsonValue &c : couts) e.cout_app.push_back(c.toInt());
                entrepots.push_back(e);
            }
            if (!entrepots.empty()) {
                json_ok = true;
                ui_callback(QString("Chargé %1 entrepôt(s) depuis : %2").arg(entrepots.size()).arg(cheminParDefaut));
            } else {
                ui_callback("Fichier JSON vide ou format invalide, utilisation des valeurs par défaut.");
            }
        } else {
            ui_callback("Erreur parsing JSON — utilisation des valeurs par défaut.");
        }
    } else {
        ui_callback("Fichier JSON par défaut introuvable, utilisation des valeurs codées en dur.");
    }

    if (!json_ok) {
        entrepots = {
            {30, {20, 28, 74, 2, 46, 42, 1, 10, 93, 47}, 0, 1, false},
            {30, {24, 27, 97, 55, 96, 22, 5, 73, 35, 65}, 0, 4, false},
            {30, {11, 82, 71, 73, 59, 29, 73, 13, 63, 55}, 0, 2, false},
            {30, {25, 83, 96, 69, 83, 67, 59, 43, 85, 71}, 0, 1, false},
            {30, {30, 74, 70, 61, 4, 59, 56, 96, 46, 95}, 0, 3, false},
        };
        ui_callback("Valeurs par défaut chargées en dur.");
    }

    return entrepots;
}


void lancer_menu() {
    int argc = 0;
    char **argv = nullptr;
    QApplication app(argc, argv);

    QWidget *window = new QWidget();
    window->setWindowTitle("Menu Entrepôt");

    // Boutons
    QPushButton *btnImporter = new QPushButton("Importer JSON", window);
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
    vector<Entrepot> entrepotsImportes = charger_entrepots_par_defaut(resultDisplay);
    // Style bouton (optionnel)
    QString style = "QPushButton { background-color: lightgray; color: black; font-weight: bold; padding: 8px; border-radius: 5px; }"
                    "QPushButton:hover { background-color: gray; }";
    btnImporter->setStyleSheet(style);
    btnForceBrute->setStyleSheet(style);
    btnArbo->setStyleSheet(style);
    btnQuitter->setStyleSheet(style);

    

    // Connexion des boutons

    QObject::connect(btnImporter, &QPushButton::clicked, [=, &entrepotsImportes]() {
        QString chemin = QFileDialog::getOpenFileName(window, "Importer un fichier JSON", "", "Fichiers JSON (*.json)");
        if (chemin.isEmpty()) return;
        QFile f2(chemin);
        if (!f2.open(QIODevice::ReadOnly | QIODevice::Text)) {
            ui_callback(" Impossible d'ouvrir le fichier sélectionné.");
            return;
        }
        QByteArray raw = f2.readAll();
        f2.close();
        QJsonParseError err;
        QJsonDocument doc = QJsonDocument::fromJson(raw, &err);
        if (err.error != QJsonParseError::NoError || !doc.isArray()) {
            ui_callback("Fichier JSON invalide.");
            return;
        }
        // Remplace entrepotsImportes par le contenu du fichier importé
        entrepotsImportes.clear();
        for (const QJsonValue &v : doc.array()) {
            if (!v.isObject()) continue;
            QJsonObject o = v.toObject();
            Entrepot e;
            e.cout_ouv = o.value("cout_ouv").toInt(30);
            e.capa_max = o.value("capa_max").toInt(1);
            e.capa_actuel = o.value("capa_actuel").toInt(0);
            e.est_ouvert = o.value("est_ouvert").toBool(false);
            QJsonArray couts = o.value("cout_app").toArray();
            e.cout_app.clear();
            for (const QJsonValue &c : couts) e.cout_app.push_back(c.toInt());
            entrepotsImportes.push_back(e);
        }
        ui_callback(QString("✅ %1 entrepôt(s) importé(s) depuis %2").arg(entrepotsImportes.size()).arg(chemin));
    });

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
    layout->addWidget(btnImporter);
    layout->addWidget(btnForceBrute);
    layout->addWidget(btnArbo);
    layout->addWidget(chkAfficherTout); // case à cocher
    layout->addWidget(btnQuitter);
    layout->addWidget(resultDisplay);

    window->setLayout(layout);
    window->resize(1600, 900);
    window->show();

    app.exec();
}