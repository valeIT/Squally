#include "Entities/Platformer/Critters/Horse.h"
#include "Entities/Platformer/Enemies/TrainingDummy.h"
#include "Entities/Platformer/Enemies/BallmerPeaks/Cryogen.h"
#include "Entities/Platformer/Enemies/BallmerPeaks/FrostFiend.h"
#include "Entities/Platformer/Enemies/BallmerPeaks/GoblinElf.h"
#include "Entities/Platformer/Enemies/BallmerPeaks/IceGolem.h"
#include "Entities/Platformer/Enemies/BallmerPeaks/PenguinGrunt.h"
#include "Entities/Platformer/Enemies/BallmerPeaks/PenguinWarrior.h"
#include "Entities/Platformer/Enemies/BallmerPeaks/Santa.h"
#include "Entities/Platformer/Enemies/BallmerPeaks/SnowFiend.h"
#include "Entities/Platformer/Enemies/BallmerPeaks/ToySoldierGoblin.h"
#include "Entities/Platformer/Enemies/BallmerPeaks/Viking.h"
#include "Entities/Platformer/Enemies/BallmerPeaks/WaterElemental.h"
#include "Entities/Platformer/Enemies/BallmerPeaks/Yeti.h"
#include "Entities/Platformer/Helpers/BallmerPeaks/Snowman.h"
#include "Entities/Platformer/Helpers/BallmerPeaks/YetiBaby.h"
#include "Entities/Platformer/Npcs/BallmerPeaks/Aspen.h"
#include "Entities/Platformer/Npcs/BallmerPeaks/Aster.h"
#include "Entities/Platformer/Npcs/BallmerPeaks/Bodom.h"
#include "Entities/Platformer/Npcs/BallmerPeaks/Cookie.h"
#include "Entities/Platformer/Npcs/BallmerPeaks/Cooper.h"
#include "Entities/Platformer/Npcs/BallmerPeaks/Irmik.h"
#include "Entities/Platformer/Npcs/BallmerPeaks/Jingles.h"
#include "Entities/Platformer/Npcs/BallmerPeaks/Juniper.h"
#include "Entities/Platformer/Npcs/BallmerPeaks/Kringle.h"
#include "Entities/Platformer/Npcs/BallmerPeaks/Luna.h"
#include "Entities/Platformer/Npcs/BallmerPeaks/Nessie.h"
#include "Entities/Platformer/Npcs/BallmerPeaks/PrincessPepper.h"
#include "Entities/Platformer/Npcs/BallmerPeaks/Theldar.h"
#include "Entities/Platformer/Npcs/BallmerPeaks/Tinsel.h"
#include "Entities/Platformer/Enemies/CastleValgrind/Agnes.h"
#include "Entities/Platformer/Enemies/CastleValgrind/Gorilla.h"
#include "Entities/Platformer/Enemies/CastleValgrind/Jack.h"
#include "Entities/Platformer/Enemies/CastleValgrind/ReanimatedFighter.h"
#include "Entities/Platformer/Enemies/CastleValgrind/Reaper.h"
#include "Entities/Platformer/Enemies/CastleValgrind/Scarecrow.h"
#include "Entities/Platformer/Enemies/CastleValgrind/SkeletalBaron.h"
#include "Entities/Platformer/Enemies/CastleValgrind/SkeletalPirate.h"
#include "Entities/Platformer/Enemies/CastleValgrind/VampireLord.h"
#include "Entities/Platformer/Enemies/CastleValgrind/Vampiress.h"
#include "Entities/Platformer/Enemies/CastleValgrind/Werewolf.h"
#include "Entities/Platformer/Enemies/CastleValgrind/Wraith.h"
#include "Entities/Platformer/Helpers/CastleValgrind/Knight.h"
#include "Entities/Platformer/Npcs/CastleValgrind/Garin.h"
#include "Entities/Platformer/Npcs/CastleValgrind/Gaunt.h"
#include "Entities/Platformer/Npcs/CastleValgrind/KingRedsong.h"
#include "Entities/Platformer/Npcs/CastleValgrind/KingRedsongSlime.h"
#include "Entities/Platformer/Npcs/CastleValgrind/Leopold.h"
#include "Entities/Platformer/Npcs/CastleValgrind/Leroy.h"
#include "Entities/Platformer/Npcs/CastleValgrind/Mabel.h"
#include "Entities/Platformer/Npcs/CastleValgrind/Merlin.h"
#include "Entities/Platformer/Npcs/CastleValgrind/PrincessOpal.h"
#include "Entities/Platformer/Npcs/CastleValgrind/Raven.h"
#include "Entities/Platformer/Npcs/CastleValgrind/Rogas.h"
#include "Entities/Platformer/Npcs/CastleValgrind/Thurstan.h"
#include "Entities/Platformer/Npcs/CastleValgrind/Tyracius.h"
#include "Entities/Platformer/Npcs/CastleValgrind/Zana.h"
#include "Entities/Platformer/Enemies/DaemonsHallow/Asmodeus.h"
#include "Entities/Platformer/Enemies/DaemonsHallow/DemonDragon.h"
#include "Entities/Platformer/Enemies/DaemonsHallow/DemonGhost.h"
#include "Entities/Platformer/Enemies/DaemonsHallow/DemonGrunt.h"
#include "Entities/Platformer/Enemies/DaemonsHallow/DemonRogue.h"
#include "Entities/Platformer/Enemies/DaemonsHallow/DemonShaman.h"
#include "Entities/Platformer/Enemies/DaemonsHallow/DemonSwordsman.h"
#include "Entities/Platformer/Enemies/DaemonsHallow/DemonWarrior.h"
#include "Entities/Platformer/Enemies/DaemonsHallow/FireElemental.h"
#include "Entities/Platformer/Enemies/DaemonsHallow/FireTiger.h"
#include "Entities/Platformer/Enemies/DaemonsHallow/Krampus.h"
#include "Entities/Platformer/Enemies/DaemonsHallow/LavaGolem.h"
#include "Entities/Platformer/Helpers/DaemonsHallow/CritterDemon.h"
#include "Entities/Platformer/Npcs/DaemonsHallow/Ash.h"
#include "Entities/Platformer/Npcs/DaemonsHallow/Brine.h"
#include "Entities/Platformer/Npcs/DaemonsHallow/Celeste.h"
#include "Entities/Platformer/Npcs/DaemonsHallow/Cindra.h"
#include "Entities/Platformer/Npcs/DaemonsHallow/Drak.h"
#include "Entities/Platformer/Npcs/DaemonsHallow/Hades.h"
#include "Entities/Platformer/Npcs/DaemonsHallow/Igneus.h"
#include "Entities/Platformer/Npcs/DaemonsHallow/Lucifer.h"
#include "Entities/Platformer/Npcs/DaemonsHallow/Magnus.h"
#include "Entities/Platformer/Npcs/DaemonsHallow/Pan.h"
#include "Entities/Platformer/Npcs/DaemonsHallow/PrincessMittens.h"
#include "Entities/Platformer/Npcs/DaemonsHallow/Ragnis.h"
#include "Entities/Platformer/Npcs/DaemonsHallow/Rusty.h"
#include "Entities/Platformer/Npcs/DaemonsHallow/Scaldor.h"
#include "Entities/Platformer/Enemies/EndianForest/Centaur.h"
#include "Entities/Platformer/Enemies/EndianForest/Cyclops.h"
#include "Entities/Platformer/Enemies/EndianForest/GoblinGruntBoar.h"
#include "Entities/Platformer/Enemies/EndianForest/GoblinShaman.h"
#include "Entities/Platformer/Enemies/EndianForest/GoblinWarriorPig.h"
#include "Entities/Platformer/Enemies/EndianForest/Gorgon.h"
#include "Entities/Platformer/Enemies/EndianForest/KingGrogg.h"
#include "Entities/Platformer/Enemies/EndianForest/Ogre.h"
#include "Entities/Platformer/Enemies/EndianForest/OrcBomber.h"
#include "Entities/Platformer/Enemies/EndianForest/OrcGrunt.h"
#include "Entities/Platformer/Enemies/EndianForest/OrcSwordsman.h"
#include "Entities/Platformer/Enemies/EndianForest/OrcWarrior.h"
#include "Entities/Platformer/Enemies/EndianForest/Orthrus.h"
#include "Entities/Platformer/Enemies/EndianForest/Troll.h"
#include "Entities/Platformer/Helpers/EndianForest/Scrappy.h"
#include "Entities/Platformer/Helpers/EndianForest/Guano.h"
#include "Entities/Platformer/Npcs/EndianForest/Ara.h"
#include "Entities/Platformer/Npcs/EndianForest/Bard.h"
#include "Entities/Platformer/Npcs/EndianForest/Blackbeard.h"
#include "Entities/Platformer/Npcs/EndianForest/Chiron.h"
#include "Entities/Platformer/Npcs/EndianForest/Elriel.h"
#include "Entities/Platformer/Npcs/EndianForest/Gramps.h"
#include "Entities/Platformer/Npcs/EndianForest/Marcel.h"
#include "Entities/Platformer/Npcs/EndianForest/QueenLiana.h"
#include "Entities/Platformer/Npcs/EndianForest/Lycan.h"
#include "Entities/Platformer/Npcs/EndianForest/Minos.h"
#include "Entities/Platformer/Npcs/EndianForest/Polyphemus.h"
#include "Entities/Platformer/Npcs/EndianForest/Matu.h"
#include "Entities/Platformer/Npcs/EndianForest/Robin.h"
#include "Entities/Platformer/Npcs/EndianForest/Toben.h"
#include "Entities/Platformer/Enemies/LambdaCrypts/BoneFiend.h"
#include "Entities/Platformer/Enemies/LambdaCrypts/Hunter.h"
#include "Entities/Platformer/Enemies/LambdaCrypts/KingZul.h"
#include "Entities/Platformer/Enemies/LambdaCrypts/Lazarus.h"
#include "Entities/Platformer/Enemies/LambdaCrypts/Mystic.h"
#include "Entities/Platformer/Enemies/LambdaCrypts/ReanimatedPig.h"
#include "Entities/Platformer/Enemies/LambdaCrypts/SkeletalCleaver.h"
#include "Entities/Platformer/Enemies/LambdaCrypts/SkeletalKnight.h"
#include "Entities/Platformer/Enemies/LambdaCrypts/SkeletalPriestess.h"
#include "Entities/Platformer/Enemies/LambdaCrypts/Undead.h"
#include "Entities/Platformer/Helpers/LambdaCrypts/Ghost.h"
#include "Entities/Platformer/Helpers/LambdaCrypts/Grim.h"
#include "Entities/Platformer/Enemies/LambdaCrypts/Zombie.h"
#include "Entities/Platformer/Enemies/LambdaCrypts/ZombieElric.h"
#include "Entities/Platformer/Npcs/LambdaCrypts/Amelia.h"
#include "Entities/Platformer/Npcs/LambdaCrypts/Azmus.h"
#include "Entities/Platformer/Npcs/LambdaCrypts/Dudly.h"
#include "Entities/Platformer/Npcs/LambdaCrypts/Elric.h"
#include "Entities/Platformer/Npcs/LambdaCrypts/Garrick.h"
#include "Entities/Platformer/Npcs/LambdaCrypts/Johann.h"
#include "Entities/Platformer/Npcs/LambdaCrypts/Necron.h"
#include "Entities/Platformer/Npcs/LambdaCrypts/PrincessNebea.h"
#include "Entities/Platformer/Npcs/LambdaCrypts/Roger.h"
#include "Entities/Platformer/Npcs/LambdaCrypts/Thion.h"
#include "Entities/Platformer/Npcs/LambdaCrypts/Ursula.h"
#include "Entities/Platformer/Npcs/LambdaCrypts/Vesuvius.h"
#include "Entities/Platformer/Npcs/LambdaCrypts/Viper.h"
#include "Entities/Platformer/Npcs/LambdaCrypts/Zelina.h"
#include "Entities/Platformer/Enemies/DataMines/Barbarian.h"
#include "Entities/Platformer/Enemies/DataMines/EarthElemental.h"
#include "Entities/Platformer/Enemies/DataMines/EarthGolem.h"
#include "Entities/Platformer/Enemies/DataMines/ForestGolem.h"
#include "Entities/Platformer/Enemies/DataMines/LightningGolem.h"
#include "Entities/Platformer/Enemies/DataMines/Rhinoman.h"
#include "Entities/Platformer/Enemies/DataMines/Shaman.h"
#include "Entities/Platformer/Enemies/DataMines/SkeletalArcher.h"
#include "Entities/Platformer/Enemies/DataMines/SkeletalNecromancer.h"
#include "Entities/Platformer/Enemies/DataMines/SkeletalWarrior.h"
#include "Entities/Platformer/Enemies/DataMines/Thug.h"
#include "Entities/Platformer/Enemies/DataMines/TikiGolem.h"
#include "Entities/Platformer/Helpers/DataMines/Gecky.h"
#include "Entities/Platformer/Npcs/DataMines/Alder.h"
#include "Entities/Platformer/Npcs/DataMines/Bonnie.h"
#include "Entities/Platformer/Npcs/DataMines/Brock.h"
#include "Entities/Platformer/Npcs/DataMines/Burch.h"
#include "Entities/Platformer/Npcs/DataMines/Cypress.h"
#include "Entities/Platformer/Npcs/DataMines/Finch.h"
#include "Entities/Platformer/Npcs/DataMines/Fraya.h"
#include "Entities/Platformer/Npcs/DataMines/Jasper.h"
#include "Entities/Platformer/Npcs/DataMines/Mildred.h"
#include "Entities/Platformer/Npcs/DataMines/Olive.h"
#include "Entities/Platformer/Npcs/DataMines/PrincessDawn.h"
#include "Entities/Platformer/Npcs/DataMines/Raka.h"
#include "Entities/Platformer/Npcs/DataMines/Sarude.h"
#include "Entities/Platformer/Npcs/DataMines/Shen.h"
#include "Entities/Platformer/Enemies/UnderflowRuins/AnubisPup.h"
#include "Entities/Platformer/Enemies/UnderflowRuins/AnubisWarrior.h"
#include "Entities/Platformer/Enemies/UnderflowRuins/LionMan.h"
#include "Entities/Platformer/Enemies/UnderflowRuins/Lioness.h"
#include "Entities/Platformer/Enemies/UnderflowRuins/Medusa.h"
#include "Entities/Platformer/Enemies/UnderflowRuins/Mermaid.h"
#include "Entities/Platformer/Enemies/UnderflowRuins/Minotaur.h"
#include "Entities/Platformer/Enemies/UnderflowRuins/MummyPriest.h"
#include "Entities/Platformer/Enemies/UnderflowRuins/MummyWarrior.h"
#include "Entities/Platformer/Enemies/UnderflowRuins/Osiris.h"
#include "Entities/Platformer/Enemies/UnderflowRuins/TigerMan.h"
#include "Entities/Platformer/Enemies/UnderflowRuins/Tigress.h"
#include "Entities/Platformer/Helpers/UnderflowRuins/GuanoPetrified.h"
#include "Entities/Platformer/Npcs/UnderflowRuins/Ajax.h"
#include "Entities/Platformer/Npcs/UnderflowRuins/Angel.h"
#include "Entities/Platformer/Npcs/UnderflowRuins/Aphrodite.h"
#include "Entities/Platformer/Npcs/UnderflowRuins/Ares.h"
#include "Entities/Platformer/Npcs/UnderflowRuins/Athena.h"
#include "Entities/Platformer/Npcs/UnderflowRuins/Cleopatra.h"
#include "Entities/Platformer/Npcs/UnderflowRuins/Geryon.h"
#include "Entities/Platformer/Npcs/UnderflowRuins/Griffin.h"
#include "Entities/Platformer/Npcs/UnderflowRuins/Hera.h"
#include "Entities/Platformer/Npcs/UnderflowRuins/Horus.h"
#include "Entities/Platformer/Npcs/UnderflowRuins/Poseidon.h"
#include "Entities/Platformer/Npcs/UnderflowRuins/Rupert.h"
#include "Entities/Platformer/Npcs/UnderflowRuins/Thor.h"
#include "Entities/Platformer/Npcs/UnderflowRuins/Zeus.h"
#include "Entities/Platformer/Enemies/VoidStar/Abomination.h"
#include "Entities/Platformer/Enemies/VoidStar/Assassin.h"
#include "Entities/Platformer/Enemies/VoidStar/BoneKnight.h"
#include "Entities/Platformer/Enemies/VoidStar/DarkTiger.h"
#include "Entities/Platformer/Enemies/VoidStar/EvilEye.h"
#include "Entities/Platformer/Enemies/VoidStar/Exterminator.h"
#include "Entities/Platformer/Enemies/VoidStar/Gargoyle.h"
#include "Entities/Platformer/Enemies/VoidStar/Shade.h"
#include "Entities/Platformer/Enemies/VoidStar/VoidArcher.h"
#include "Entities/Platformer/Enemies/VoidStar/VoidDemon.h"
#include "Entities/Platformer/Enemies/VoidStar/Warlock.h"
#include "Entities/Platformer/Helpers/VoidStar/Professor.h"
#include "Entities/Platformer/Helpers/VoidStar/Robot.h"
#include "Entities/Platformer/Npcs/VoidStar/Appolo.h"
#include "Entities/Platformer/Npcs/VoidStar/Atreus.h"
#include "Entities/Platformer/Npcs/VoidStar/Bancroft.h"
#include "Entities/Platformer/Npcs/VoidStar/Godiva.h"
#include "Entities/Platformer/Npcs/VoidStar/Illia.h"
#include "Entities/Platformer/Npcs/VoidStar/Leon.h"
#include "Entities/Platformer/Npcs/VoidStar/Mara.h"
#include "Entities/Platformer/Npcs/VoidStar/Piper.h"
#include "Entities/Platformer/Npcs/VoidStar/QueenElise.h"
#include "Entities/Platformer/Npcs/VoidStar/Radon.h"
#include "Entities/Platformer/Npcs/VoidStar/Ralston.h"
#include "Entities/Platformer/Npcs/VoidStar/Thatcher.h"
#include "Entities/Platformer/Npcs/VoidStar/Xenon.h"
#include "Entities/Platformer/Npcs/VoidStar/Ysara.h"
#include "Entities/Platformer/Squally/Squally.h"
