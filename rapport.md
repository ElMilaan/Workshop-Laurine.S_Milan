# RAPPORT WORKSHOP 
Réalisé par Milan Junges et Laurine Suel
<div style= "text-align: right;"> Semaine du 20/11/2023 </div>

## Introduction 
<div style= "text-align: justify; margin-bottom : 25px"> La manipulation d'images représente un domaine fascinant qui fusionne créativité et compétences techniques et scientifiques.   Dans ce rapport vous trouverez le rendu d'un atelier enrichissant qui s'est tenu dans le cadre d'un workshop, dédié à l'exploration et à la maîtrise du codage d'effets sur des images.  Au cours de cette semaine, nous avons ont été guidés à travers des exercices en utilisant le langage de programmation C++. Nous avons donc pu coder plusieurs effets visuels, allant des transformations simples d'une image aux manipulations plus avancées comme la créations d'effets sur image.</div>
<div style= "text-align: justify;"> Nous avons travaillé à partir de deux images données, le logo Imac (image 1) et une photographie (image 2).</div>



| ![logo Imac](img/../img/logo.png "image 1"){: height="200px";} | ![photographie](img/photo.jpg "image 2"){: height="200px";} |
| -------------------------------------------------------------- | ----------------------------------------------------------- |



## Première journée de workshop
<div style= "text-align: justify;"> Nous avons entamé cette première journée de workshop par cinq exercices de niveau ⭐ (1 étoile).</div>

#### ⭐ Ne gardez que le vert
| ![logo Imac](img/../img/logo.png "image 1"){: height="200px"; width="175px";} | ![logo imac vert](output/green.png "image 3"){: height="200px";width="175";} |
| ----------------------------------------------------------------------------- | ---------------------------------------------------------------------------- |


#### ⭐ Échanger les canaux
| ![logo Imac](img/../img/logo.png "image 1"){: height="200px";width="175";} | ![logo imac échangé](output/exchange.png "image 4"){: height="200px";width="175";} |
| -------------------------------------------------------------------------- | ---------------------------------------------------------------------------------- |


#### ⭐ Noir & blanc
| ![logo Imac](img/../img/logo.png "image 1"){: height="200px";width="175px";} | ![logo imac noir et blanc](output/black_and_white.png "image 5"){: height="200";width="175";} |
| ---------------------------------------------------------------------------- | --------------------------------------------------------------------------------------------- |

#### ⭐ Négatif
| ![logo Imac](img/../img/logo.png "image 1"){: height="200px";width="175";} | ![logo imac négatif](output/negative.png "image 6"){: height="200px";width="175px";} |
| -------------------------------------------------------------------------- | ------------------------------------------------------------------------------------ |

#### ⭐ Dégradé
| ![image noire](output/black.png "image noire"){: height="200px";width="200px";} | ![dégradé](output/gradient_b_w.png "image 7"){: height="200px"; width="200px"} |
| ------------------------------------------------------------------------------- | ------------------------------------------------------------------------------ |

<div style= "text-align: justify;"> Nous avons poursuivi par six exercices de niveau ⭐⭐ (2 étoiles).</div>

#### ⭐⭐ Miroir
| ![logo Imac](img/../img/logo.png "image 1"){: height="200px";width="175px";} | ![logo imac fake miroir](output/fake_mirror.png "image 8"){: height="200px";width="175px";} | ![logo imac miroir](output/mirror.png "image 9"){: height="200px";width="175px";} |
| ---------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------- | --------------------------------------------------------------------------------- |
| logo classique                                                               | miroir raté                                                                                 | résultat final                                                                    |

<div style= "text-align: justify;"> Notre premier essaie de programme a permis de créer le miroir raté. Dans ce programme on parcourait l'image entière. Arrivé à la moitié de l'image, le programme avait reporté la partie gauche sur la partie droite de la bonne manière. Mais par symétrie, cette nouvelle partie droite était reportée en miroir sur la partie gauche qui avait déjà été parcourue. L'effet donné fut le report de la partie droite (déjà modifiée) sur la partie gauche de l'image (ça n'a donc pas modifié cette partie gauche).</div>

#### ⭐⭐ Bruitage
| ![logo Imac](img/../img/logo.png "image 1"){: height="200px";width="175px";} | ![logo imac bruité](output/bruit.png "image 10"){: height="200px"; width="175px"} |
| ---------------------------------------------------------------------------- | --------------------------------------------------------------------------------- |


#### ⭐⭐ Rotation de 90
| ![logo Imac](img/../img/logo.png "image 1"){: height="200px";width="175px";} | ![logo imac rotation](output/rotation_90.png "image 11"){: height="175px"; width="200px"} |
| ---------------------------------------------------------------------------- | ----------------------------------------------------------------------------------------- |

#### ⭐⭐ Split
| ![logo Imac](img/../img/logo.png "image 1"){: height="200px";width="175px";} | ![logo imac split](output/rgb_split.png "image 12"){: height="200px";width="175px";} | ![logo imac split rose](output/rgb_split_without_green.png "image 13"){: height="200px";width="175px";} |
| ---------------------------------------------------------------------------- | ------------------------------------------------------------------------------------ | ------------------------------------------------------------------------------------------------------- |
| logo classique                                                               | split demandé                                                                        | split sans vert                                                                                         |


#### ⭐⭐ Luminosité
| ![logo Imac](img/../img/logo.png "image 1"){: height="200px";width="175px";} | ![logo imac split](output/rgb_split.png "image 12"){: height="200px";width="175px";} | ![logo imac split rose](output/rgb_split_without_green.png "image 13"){: height="200px";width="175px";} |
| ---------------------------------------------------------------------------- | ------------------------------------------------------------------------------------ | ------------------------------------------------------------------------------------------------------- |
| logo classique                                                               | split demandé                                                                        | split sans vert                                                                                         |

#### ⭐⭐ Rotation de 90
| ![logo Imac](img/../img/logo.png "image 1"){: height="200px";width="175px";} | ![logo imac rotation](output/rotation_90.png "image 11"){: height="200px"; width="175px"} |
| ---------------------------------------------------------------------------- | ----------------------------------------------------------------------------------------- |