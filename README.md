# FOURNIER_Lab1

## Introduction

Ce TP met en pratique les concepts de conception conjointe vus en cours en travaillant avec une carte DE10-Lite équipée d'un FPGA MAX10 10M50DAF484C7G de la gamme Altera. L'objectif principal est de créer un chenillard de LEDs déclenché par une interruption, avec la possibilité de modifier la vitesse grâce à des switchs.

## Architecture du Système

Le système comprend l'architecture de base avec :
- Un processeur Nios II
- Une mémoire RAM
- Une horloge
- Un port JTAG



Ajouts :
- Un PIO 8 bits pour les LEDs
- Un PIO 8 bits pour les switchs
- Un PIO 1 bit pour le bouton (KEY1)


