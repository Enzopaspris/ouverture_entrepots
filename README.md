<!-- PROJECT LOGO -->
<br />
<div align="center">
  <a href="https://github.com/Enzopaspris/ouverture_entrepots">
    <img src="https://img.icons8.com/?size=100&id=20425&format=png&color=000000" alt="Logo" width="80" height="80">
  </a>

  <h3 align="center">Projet tutorés n°1 : Ouverture d’entrepôts</h3>

  <p align="center">
    Une application C++ pour gérer l'approvisionnements de magasin par des entrepôts.
    <br />
  </p>
</div>

## 📑 Table des matières
- [Objectif du projet](#-objectif-du-projet)
- [Technologies utilisées](#-construit-avec)
- [Installation](#-utiliser-lapplication)
- [Fichier JSON](#fichier-json)
- [Méthodes de résolution](#options)
- [Exemple de données](#-données-par-défaut)


## 🎯 Objectif du projet

Ce projet a été réalisé dans le cadre de nos études. L'objectif est simple, une entreprise souhaite ouvrir des entrepôts à certains endroits pour approvisionner ses magasins. <br>
Un entrepôt a un coût d’ouverture, un coût d’approvisionnement par magasin et une capacité maximale qui
désigne le nombre de magasins qu’il peut approvisionner. Un magasin doit être approvisionné par un seul
entrepôt. L’objectif est de déterminer quel entrepôt doit ouvrir et pour chacun d’entre eux, quel magasin ils
approvisionnent, tel que la somme des coûts engagés est minimisée.

### 🛠️ Construit avec

<img href="https://devdocs.io/cpp/" src="https://upload.wikimedia.org/wikipedia/commons/thumb/1/18/ISO_C%2B%2B_Logo.svg/1822px-ISO_C%2B%2B_Logo.svg.png" alt="C++" width="60"/>
<img href="https://doc.qt.io/" src="https://upload.wikimedia.org/wikipedia/commons/8/81/Qt_logo_neon_2022.svg" alt="Qt" width="60"/>

## 🚀 Utiliser l'application

### Prérequis

Assurez-vous d’avoir installé un compilateur C++ (comme Clion ou Eclipse).

1.  Clone le dépôt GitHub :
    ```sh
    git clone https://github.com/Enzopaspris/ouverture_entrepots.git
    ```
2.  Aller dans le répertoire du projet :
    ```sh
    cd ouverture_entrepots
    ```
3.  Compilation :

    #### Avec Cmake
      ```sh
      mkdir build
      cd build
      cmake ..
      make
      ```
  4.  Exécution
      ```sh
      ./programme
      ```
### Fichier JSON

Le programme prends en charge les fichiers **JSON** pour obtenir les données sur les differents entrepôts et magasins. Si aucun fichier n'est sélectionné au lancement du programme les données par défaut sont utilisées *(fichier .json dans le dossier /data)*. Vous pouvez donc utilisez votre propore fichier *.json* ou modifier celui déjà présent dans le dossier.

### Options
Le programme propose deux méthodes de résolution :

#### 1. 🔹 Méthode Force brute
- Teste **toutes les combinaisons possibles**.  
- Retient **la solution la moins coûteuse**.  
- ❌ Très lente et **ne prend pas en compte les capacités réelles** des entrepôts.

#### 2. 🔹 Méthode Arborescente
- Explore **uniquement les solutions valides** (respectant les capacités).  
- Retient **le coût minimal parmi ces solutions**.  
- ✅ Plus rapide et **donne un résultat plus réaliste**.

La case *Afficher toutes les étapes* permets de **visualiser le raisonnement et les étapes de résolution** de l'algorithme lorsqu'elle est cochée.
<br> PS : ⚠️ Cette option est lourde en ressource et peut **ralentir considérablement** l’exécution du programme

## 📁 Données par défaut

Il y a 5 entrepôts pour 10 magasins

```json
[
  {
    "cout_ouv": 30,
    "cout_app": [20, 28, 74, 2, 46, 42, 1, 10, 93, 47],
    "capa_actuel": 0,
    "capa_max": 1,
    "est_ouvert": false
  },
  {
    "cout_ouv": 30,
    "cout_app": [24, 27, 97, 55, 96, 22, 5, 73, 35, 65],
    "capa_actuel": 0,
    "capa_max": 4,
    "est_ouvert": false
  },
  {
    "cout_ouv": 30,
    "cout_app": [11, 82, 71, 73, 59, 29, 73, 13, 63, 55],
    "capa_actuel": 0,
    "capa_max": 2,
    "est_ouvert": false
  },
  {
    "cout_ouv": 30,
    "cout_app": [25, 83, 96, 69, 83, 67, 59, 43, 85, 71],
    "capa_actuel": 0,
    "capa_max": 1,
    "est_ouvert": false
  },
  {
    "cout_ouv": 30,
    "cout_app": [30, 74, 70, 61, 4, 59, 56, 96, 46, 95],
    "capa_actuel": 0,
    "capa_max": 3,


## 🤝 Contribuer
Si vous souhaitez proposer des améliorations ou signaler des bugs, contactez-nous à :
- Dimitri Bougle
- Enzo Martinet
- Flavien Le Guerneve

    "est_ouvert": false
  }
]
```
