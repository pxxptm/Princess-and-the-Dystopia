#ifndef DEFINITION_H
#define DEFINITION_H

#define WIDTH 1500
#define HEIGHT 900

#define SPLASH_STATE_SHOWTIME 3.25

/// background file path ///

#define GAME_BACKGROUND      "resource/objects/background.jpg"
#define GAMEOVER_BACKGROUND  "resource/objects/Wallpaper.png"
#define Wallpaper            "resource/objects/Wallpaper.png"
#define TP_BLACK             "resource/objects/transparent black.png"
#define MainMenuWallpaper    "resource/objects/MainMenuWallpaper.png"
#define WinnerStateWallpaper "resource/objects/WinnerWallpaper.png"

/// font file path///

#define BARCHELLLA           "resource/fonts/Barchella_Drumal.otf"
#define EDGE_OF_THE_GALAXY   "resource/fonts/EdgeOfTheGalaxyRegular.otf"
#define DAY28                "resource/fonts/28 Days Later.ttf"
#define BARBARO              "resource/fonts/barbaro.ttf"

/// object file path ///

#define BARRIER_UP_SHORT     "resource/objects/BarrierUp_short.png"
#define FLOOR                "resource/objects/floor.png"
#define PLAYER_INDEX_1       "resource/objects/player_1.png"
#define PLAYER_INDEX_2       "resource/objects/player_2.png"
#define PLAYER_STAND         "resource/objects/player_stand.png"
#define PLAYER_INDEX_SLIDE   "resource/objects/player_slide.png"
#define THORN                "resource/objects/thorn.png"
#define GUIDE                "resource/objects/GUIDE.png"
#define CAUION               "resource/objects/CAUTION.png"
#define PAUSE_RESUME         "resource/objects/Pause Button.png"
#define PLAYER_POWER         "resource/objects/player_bullet.png"
#define ENEMY_POWER          "resource/objects/enemy_bullet.png"
#define SMALL_ROCK           "resource/objects/rock_small.png"
#define EXPLOSION            "resource/objects/Explosion.png"
#define ENEMY_LEVEL_1        "resource/objects/enemy_level1.png"
#define ENEMY_LEVEL_2        "resource/objects/enemy_level2.png"
#define HP                   "resource/objects/HP.png"
#define AMOUR                "resource/objects/amour.png"

/// object movement speed ///

#define BARRIER_UP_MOVEMENT_SPEED  300.0f
#define THORN_MOVEMENT_SPEED       300.0f
#define ENEMY_1_SPEED              400.0f
#define ENEMY_2_SPEED              400.0f
#define POWER_SPEED                1000.0f
#define THORN_POWER_SPEED          500.0f
#define Hp_MOVEMENT_SPEED          300.0f

/// object scale adjustment ///

#define BARRIERUP_SCALE     0.75f
#define THORN_SCALE         1.5f
#define ENEMY_1_SCALE       0.3f
#define ENEMY_2_SCALE       0.25f
#define PINK_POWER_SCALE    0.2f
#define THORN_BULLET_SCALE  0.2f
#define Hp_SCALE            0.05f

/// object spawning - frequency ///

#define BARRIERUP_SPAWNING_FREQ     1.5f
#define THORN_SPAWNING_FREQ         1.5f
#define ENEMY_1_SPAWNING_FREQ       0.75f
#define ENEMY_2_SPAWNING_FREQ       0.75f
#define BULLET_COOLDOWN             0.2f

/// player animation ///

#define PLAYER_SCALE   0.45f
#define PLAYER_ANIMATION_DURATION 0.5f

#define PLAYER_BOTTOM  1
#define PLAYER_JUMP    2
#define PLAYER_SLIDE   3
#define PLAYER_FALLING 4

#define JUMP_SPEED     500.0f
#define JUMP_DURATION  1.0f

/// game status ///

enum GameStates
{
    ePlaying ,
    eGameOver ,
    ePause ,
    ewin
};

/// flash : when game over ///

#define FLASH_SPEED 2000.0f

/// scoring ///

#define SCORING_FREQ 0.1f

#define BARRIER_UP_POSITION_Y  100

/// player things ///

#define PLAYER_HP   500.00   // using in GAMESTATE_H
#define DROP_HP     200.00

/// enemy
#define LV1_HP      200
#define LV2_HP      300
#define ENDSTAGE    15

/// etc
#define DEGTORAD 0.017453f

/// attack
#define FOR_ENEMY_1    50

/// AUDIO FILE PATH
#define BGM         "resource/audio/backgroundmusic.ogg"
#define COLLECT     "resource/audio/collect.wav"
#define GAMEOVER    "resource/audio/gameover.wav"
#define WINNING     "resource/audio/winning.ogg"
#define JUMP        "resource/audio/jump.wav"
#define ROAR        "resource/audio/roar.wav"
#define SLIDE       "resource/audio/slide.wav"
#define HIT         "resource/audio/hit.wav"
#define SHOOT       "resource/audio/shoot.wav"

#endif // DEFINITION_H
