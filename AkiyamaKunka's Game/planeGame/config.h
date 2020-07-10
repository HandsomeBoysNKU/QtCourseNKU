#ifndef CONFIG_H
#define CONFIG_H

//here you can set the configuration of the game
#define GAME_WID 512

#define GAME_LEN 768
#define GAME_TITEL "Love and Peace"
#define PLANE_ICON ":/image/飞机大战素材/hero2.png"
#define MAP_LOCAT ":/image/飞机大战素材/img_bg_level_5.jpg"
#define BULLET_LOCAT ":/image/飞机大战素材/bullet_11.png"
#define BULLET_SPEED 3
#define BULLET_REFRESH_RATE 25 //the smaller, the faster
#define BULLET_NUM 100000
#define BULLET_INTERVAL 1

#define ENEMY_PATH  ":/image/飞机大战素材/img-plane_5.png"
#define ENEMY_SPEED 5
#define ENEMY_NUM   20
#define ENEMY_INTERVAL  30


#define BOMB_PATH  ":/image/飞机大战素材/bomb-%1.png"
#define BOMB_NUM  20
#define BOMB_MAX  7      //the maximum index of bomb pictures
#define BOMB_INTERVAL 1


#define PLANE_WID 100
#define PLANE_LEN 100
#define PLANE_MOVE_SPEED 4
#define REFRESH_RATE 5
#define MAP_SPEED 3



#endif // CONFIG_H


