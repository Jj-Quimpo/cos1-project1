## Features Added
* Turn-Based combat system players can choose between attacking, defending, using stored healing items or attempt to flee from a non-boss encounter.
* Enemy tiers & boss floors, added three types of rats lowly rats, elite rats, and rat knights boss types fat rat, roach hunter and abomination
* shady roach merchant so players can buy and spend their saved crumbs for either healing items or permanent upgrades to atk or def
* Inventory healing selection updated the inventory so players start with a spear, shield and stale sugar cystal

## Updates to system design
* Multi file object oriented architecture, usage of class files (player, dungeon, rat, combat system, merchant and helper) so they each manage a single responsibility.
* Floor based difficulty, Updated Dungeon to track floors survived , trigger guaranteed boss floor on multiples of 10, and scale enemy spawn probabilities as the player progresses

## Refactoring Improvements
* encapsulated enemy behavior in rat class, replaced hardcoded enemy health and damage variable with a Rat type enum so each enemy manages its own stats, crumb rewards, and execute turn attack logic
* standardized console input & screen management in helper

## What changed and why
* Separated Rat and combat system from dungeon so it is much cleaner
* Changed healing items to Inventory-based instead of automatically healing the player.
* Added ClearConsoleWindow() Between floors and menus so the terminal is not difficult to read.