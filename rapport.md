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
| ![photo 1](img/../img/photo.jpg "image 1"){: height="200px";width="175px";} | ![logo imac split](output/bright.jpg "image 14"){: height="200px";width="175px";} | ![logo imac split rose](output/dark.jpg "image 15"){: height="200px";width="175px";} |
| --------------------------------------------------------------------------- | --------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------ |
| photo classique                                                             | photo éclaircie                                                                   | photo assombrie                                                                      |


#### ⭐⭐ Disque
| ![photo noire](output/black.png "image noire"){: height="200px";width="175px";} | ![disque](output/disc.png "image 16"){: height="200px"; width="175px"} |
| ------------------------------------------------------------------------------- | ---------------------------------------------------------------------- |

## Deuxième journée de workshop

<div style= "text-align: justify;"> Dans la matinée de cette deuxième journée, nous avons créé deux images. </div>

#### ⭐ Cercle
| ![photo noire](output/black.png "image noire"){: height="200px";width="175px";} | ![cercle](output/circle.png "image 17"){: height="200px"; width="175px"} |
| ------------------------------------------------------------------------------- | ------------------------------------------------------------------------ |


#### ⭐⭐⭐ Rosace
| ![photo noire](output/black.png "image noire"){: height="200px";width="175px";} | ![rosace](output/rosace.png "image 18"){: height="200px"; width="175px"} |
| ------------------------------------------------------------------------------- | ------------------------------------------------------------------------ |

<div style= "text-align: justify;margin-top : 25px"> Ensuite dans l'aprés-midi nous avons réalisé une mosaïque ainsi que l'exercice « glitch ». </div>

#### ⭐⭐ Mosaïque
<div style= "text-align: justify;margin-top : 25px"> Pour créer notre mosaïque, nous avons procédé de deux manières différentes. </div>

<div style= "text-align: justify;margin-top : 25px;text-decoration:underline"> 
Méthode 1 : </div>
<div style= "text-align:justify"> Nous avons tout d'abord réduit notre image en gardant 1 pixel sur 5 du logo, puis nous avons dupliqué cette petite image pour remplir notre grande image noire. </div>

| ![logo Imac réduit](output/reduced.png "image 19"){: height="200px";width="175px";} | ![mozaique méthode 1](output/mosaique_reduced.png "image 20"){: height="200px"; width="175px"} |
| ----------------------------------------------------------------------------------- | ---------------------------------------------------------------------------------------------- |

<div style= "text-align: justify;margin-top : 25px;text-decoration:underline"> 
Méthode 2 : </div>
<div style= "text-align:justify"> À l'inverse de la méthode 1, nous avons multiplié par 5 notre image noire, et nous avons dupliqué notre logo dans cette image. On observe donc une mozaïque beaucoup moins pixalisée. Nous avons deux méthodes pour ce programme là.</div>

| ![logo Imac ](img/logo.png "image 1"){: height="200px";width="175px";} | ![mozaique méthode 2](output/mosaique_bigger1.png "image 21"){: height="200px"; width="175px"} |
| ---------------------------------------------------------------------- | ---------------------------------------------------------------------------------------------- |

#### ⭐⭐⭐ Glitch

| ![logo Imac](img/../img/logo.png "image 1"){: height="200px";width="175px";} | ![logo imac glitch raté](output/glitch_rate_mais_style.png "image 22"){: height="200px";width="175px";} | ![logo imac glitch](output/glitch.png "image 23"){: height="200px";width="175px";} |
| ---------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------- | ---------------------------------------------------------------------------------- |
| logo classique                                                               | glitch raté                                                                                             | glitch demandé                                                                     |

## Troisième journée de workshop

#### ⭐⭐⭐ Fractale
<div style= "text-align: justify;margin-top : 25px"> Nous avons obtenu en premier lieu une fractale plus pixelisée, puis nous avons obtenu la bonne fractale. </div>

| ![fractale pixalisée](output/fractal_pixelized.png "image 24"){: height="200px";width="175px";} | ![fractale](output/fractal.png "image 25"){: height="200px"; width="175px"} |
| ----------------------------------------------------------------------------------------------- | --------------------------------------------------------------------------- |
| fractale pixelisée                                                                              | fractale                                                                    |

#### ⭐⭐⭐⭐ Convolutions 
<div style= "text-align: justify;margin-top : 25px"> Aprés avoir réalisé les différents exercices de convolutions, nous avons décidé d'écrire un programme qui peut réaliser toutes les convolutions (blur, outline, sharpen et emboss). À l'aide du 'swap' nous pouvons changer de fonction selon ce l'effet souhaité. </div>

| ![logo Imac](img/../img/logo.png "image 1"){: height="200px";width="150px";} | ![blur](output/blur.png "image 26"){: height="200px";width="150px";} | ![outline](output/outline.png "image 27"){: height="200px";width="150px";} | ![sharpen](output/sharpen.png "image 28"){: height="200px";width="150px";} | ![emboss](output/emboss.png "image 29"){: height="200px";width="150px";} |
| ---------------------------------------------------------------------------- | -------------------------------------------------------------------- | -------------------------------------------------------------------------- | -------------------------------------------------------------------------- | ------------------------------------------------------------------------ |
| logo classique                                                               | blur                                                                 | outline                                                                    | sharpen                                                                    | emboss                                                                   |

#### ⭐⭐⭐(⭐) Tramage

| ![logo Imac ](img/photo.jpg "image 1"){: height="200px";width="175px";} | ![ tramage ](output/tramage.jpg "image 30"){: height="200px"; width="175px"} |
| ----------------------------------------------------------------------- | ---------------------------------------------------------------------------- |

## Quatrième jour de workshop

#### ⭐⭐⭐⭐ Tri de pixels

| ![logo Imac ](img/logo.png "image 1"){: height="200px";width="175px";} | ![ tri ](output/sort.png "image 31"){: height="200px"; width="175px"} |
| ---------------------------------------------------------------------- | --------------------------------------------------------------------- |

##Conclusion

<div style= "text-align: justify; margin-bottom : 25px"> Au-delà de la simple acquisition de compétences techniques, ce workshop nous a permis d'exprimer notre vision artistique à travers le langage du code. Nous avons compris les concepts fondamentaux, expérimenté des techniques de programmations et collaboré par pairs en utilisant git. Ce fut une riche experience éducative qui a su stimuler notre créativité dans le domaine captivant de la programmation d'effets sur images.
